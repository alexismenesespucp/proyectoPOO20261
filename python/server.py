import os
import socket
from pyngrok import ngrok

from dotenv import load_dotenv
load_dotenv()

NGROK_TOKEN = os.getenv("NGROK_AUTHTOKEN")

if not NGROK_TOKEN:
    raise ValueError("Error: No se encontró NGROK_AUTHTOKEN en el archivo .env")

ngrok.set_auth_token(NGROK_TOKEN)

PORT = 5000

try:
    public_url = ngrok.connect(PORT,"tcp")
    print(f"Dirección: {public_url.public_url}")
    server  = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost',PORT))
    server.listen(1)
    print(f"Servidor escuchando en el puerto {PORT}")
    while True:
        conn, addr = server.accept()
        conn.sendall(b"Hola, desde la pucp")
        conn.close()

except KeyboardInterrupt:
    print("Cerrando el servidor y el tunel")

finally: 
    ngrok.disconnect(public_url.public_url)