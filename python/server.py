import os
import socket
import threading
from pyngrok import ngrok
from dotenv import load_dotenv

load_dotenv()
NGROK_TOKEN = os.getenv("NGROK_AUTHTOKEN")
ngrok.set_auth_token(NGROK_TOKEN)

PORT = 5000

# Lista global para almacenar las conexiones de todos los clientes conectados
clientes = []
# Lock para evitar problemas de concurrencia al modificar la lista de clientes
clientes_lock = threading.Lock()

def retransmitir(mensaje, cliente_origen):
    """Envía un mensaje a todos los clientes excepto al que lo envió."""
    with clientes_lock:
        for cliente in clientes:
            if cliente != cliente_origen:
                try:
                    cliente.sendall(mensaje)
                except Exception:
                    # Si falla el envío, asumimos que el cliente se desconectó
                    remover_cliente(cliente)

def manejar_cliente(conn, addr):
    """Maneja la comunicación individual con un cliente específico."""
    print(f"👥 [NUEVA CONEXIÓN] {addr} se ha unido a la sala.")
    
    # Notificar a los demás que alguien entró
    notificacion = f"📢 Alguien nuevo se ha unido desde {addr}\n".encode('utf-8')
    retransmitir(notificacion, conn)

    while True:
        try:
            data = conn.recv(1024)
            if not data:
                break
            
            # Formatear el mensaje para que todos sepan quién lo envió
            mensaje_formateado = f"\n👤 [{addr[1]}]: {data.decode('utf-8')}".encode('utf-8')
            print(f"Retransmitiendo mensaje de {addr}")
            retransmitir(mensaje_formateado, conn)
            
        except Exception:
            break

    # Si sale del bucle, el cliente se desconectó
    print(f"❌ [DESCONECTADO] {addr} abandonó la sala.")
    remover_cliente(conn)
    notificacion_salida = f"🚪 El usuario [{addr[1]}] ha salido del chat.\n".encode('utf-8')
    retransmitir(notificacion_salida, conn)
    conn.close()

def remover_cliente(conn):
    """Remueve un cliente de la lista de forma segura."""
    with clientes_lock:
        if conn in clientes:
            clientes.remove(conn)

def aceptar_conexiones(server):
    """Bucle infinito dedicado exclusivamente a recibir nuevos clientes."""
    while True:
        try:
            conn, addr = server.accept()
            with clientes_lock:
                clientes.append(conn)
            
            # Crear un hilo independiente para este cliente en específico
            hilo_cliente = threading.Thread(target=manejar_cliente, args=(conn, addr), daemon=True)
            hilo_cliente.start()
        except Exception as e:
            print(f"Error aceptando conexiones: {e}")
            break

try:
    # 1. Levantar el túnel global
    public_url = ngrok.connect(PORT, "tcp")
    print(f"\n🚀 [SALA DE CHAT] ¡Túnel global activo!")
    print(f"🔗 Comparte esta dirección con todos: {public_url.public_url}\n")
    
    # 2. Configurar el socket del servidor
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost', PORT))
    server.listen() # Sin límite estricto de conexiones en cola
    print("🏠 Servidor escuchando y listo para recibir múltiples usuarios...")
    
    # 3. Hilo principal para aceptar conexiones sin bloquear el script del servidor
    hilo_aceptar = threading.Thread(target=aceptar_conexiones, args=(server,), daemon=True)
    hilo_aceptar.start()

    # Mantener el servidor vivo controlando comandos desde la consola del servidor si quieres
    while True:
        comando = input()
        if comando.lower() == 'apagar':
            break

except KeyboardInterrupt:
    print("\nApagando la sala de chat...")
finally:
    ngrok.disconnect(public_url.public_url)
    print("👋 Servidor cerrado.")