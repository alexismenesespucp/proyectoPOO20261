import os
import socket
import threading
import sys

# 1. Cargar configuración del .env
HOST = "8.tcp.ngrok.io"
PORT_ENV = 26408

if not HOST or not PORT_ENV:
    print("❌ Error: Configura SERVER_HOST y SERVER_PORT en tu archivo .env")
    sys.exit(1)

# 2. Pedir el nombre del usuario para el chat
username = input("👤 Introduce tu nombre/nick para el chat: ").strip()
if not username:
    username = "Anónimo"

# Función secundaria: Escuchar lo que el servidor retransmite de otros usuarios
def recibir_mensajes(sock):
    while True:
        try:
            data = sock.recv(1024)
            if not data:
                print("\n🔌 Te has desconectado del servidor.")
                break
            
            # Limpiar la línea actual para que el mensaje recibido no se mezcle con lo que estás escribiendo
            mensaje = data.decode('utf-8')
            print(f"{mensaje}")
            print(f"✍️ {username}: ", end="", flush=True)
        except Exception:
            break
    sock.close()

# 3. Conexión al servidor global
try:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print(f"🔄 Conectando a la sala de chat en {HOST}:{PORT_ENV}...")
    client.connect((HOST, int(PORT_ENV)))
    print(f"✅ ¡Conectado con éxito! Bienvenido, {username}.\n")
    
    # Crear e iniciar el hilo para escuchar a los demás
    hilo_recibir = threading.Thread(target=recibir_mensajes, args=(client,), daemon=True)
    hilo_recibir.start()
    
    # 4. Bucle principal: Enviar mensajes con tu nombre integrado
    while True:
        text = input(f"✍️ {username}: ")
        if text.lower() == 'salir':
            break
        if text.strip():
            # Enviamos el mensaje con el formato "Nombre: Mensaje"
            mensaje_completo = f"👤 [{username}]: {text}"
            client.sendall(mensaje_completo.encode('utf-8'))

except Exception as e:
    print(f"❌ Error de conexión: {e}")
finally:
    client.close()
    print("👋 Has salido de la sala de chat.")