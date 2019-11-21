from socket import *

IP = "127.0.0.1"
PORT = 4980
s = socket()
s.bind((IP,PORT))
s.listen(10)
cs,addr = s.accept()
print(cs.recv(1024).decode())