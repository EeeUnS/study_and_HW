import socket
import socks

socks.setdefaultproxy(socks.PROXY_TYPE_SOCKSS,"127.0.0.1",9050)
socket.socket = socks.socksocket

ULR = "v~"
PORT = 80
IP = URL

s = socket.socket()
s.connect((IP,PORT))
r = s.recv(4096)
s.send("data")
print(r)