#!/usr/bin/env python3
import time
import socket

HOST1 = '192.168.1.3'
HOST2 = '192.168.1.4'
PORT = 8889
s1 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

s1.connect((HOST1, PORT))
s2.connect((HOST2, PORT))

s1.sendall(b'command')
s2.sendall(b'command')
data1 = s1.recv(1024)
data2 = s2.recv(1024)
print('Received1', repr(data1))
print('Received2', repr(data2))

time.sleep(1)
s1.sendall(b'battery?')
s2.sendall(b'battery?')
bat1 = s1.recv(1024)
bat2 = s2.recv(1024)
print('Battery1:', repr(bat1))
print('Battery2:', repr(bat2))

s1.sendall(b'takeoff')
s2.sendall(b'takeoff')
time.sleep(10)
s1.sendall(b'cw 360')
s2.sendall(b'cw 360')
time.sleep(10)
s1.sendall(b'land')
s2.sendall(b'land')

s1.shutdown()
s2.shutdown()
s1.close()
s2.close()
