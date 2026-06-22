import socket

HOST = "8.tcp.ngrok.io"
PORT = 22095

try:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((HOST,PORT))
    respuesta = client.recv(1024)
    print(respuesta)
except ConnectionRefusedError:
    print("Conección rechazada")
except socket.gaierror:
    print("error con el host")
except Exception as e:
    print(f"Ocurrio un error inesperado: {e}")
finally:
    client.close()
    

