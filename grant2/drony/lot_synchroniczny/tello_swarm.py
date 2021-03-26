#!/usr/bin/env python3
import socket
import time
import threading

PORT = 8889
drones = ['192.168.1.4', '192.168.1.12']
is_emergency = False
last_response = ''

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(('', PORT))

def _receive_thread():
    while True:
        response, ip = s.recvfrom(1024)
        print(f'Received from {ip}: {response}')

def send_command(ip, command):
    s.sendto(command.encode('utf-8'), (ip, PORT))

def emergency_stop():
    global is_emergency
    is_emergency = True
    for x in drones:
        # send_command(x, 'emergency')
        send_command(x, 'stop')
        time.sleep(2)
        send_command(x, 'land')

def execute_plan(ip, plan):
    print('Executing plan for', ip)
    try:
        for cmd in plan:
            if not is_emergency:
                if cmd == 'delay':
                    time.sleep(8)
                else:
                    send_command(ip, cmd)
                    time.sleep(8)
            else:
               return 
            time.sleep(2)
    except KeyboardInterrupt:
        emergency_stop()
        time.sleep(5)

receive_thread = threading.Thread(target=_receive_thread, daemon=True)
receive_thread.start()

# Set SDK mode in every drone
for x in drones:
    send_command(x, 'command')
time.sleep(2)

# commands1 = ['takeoff', 'up 150', 'ccw 180', 'forward 100', 'ccw 90', 'forward 100', 'ccw 90', 'forward 100', 'up 100', 'ccw 90', 'forward 300', 'cw 540', 'land']

# commands2 = ['takeoff', 'up 150', 'delay', 'forward 100', 'ccw 90', 'forward 100', 'ccw 90', 'forward 100', 'down 100', 'ccw 90', 'forward 300', 'cw 540', 'land']

# commands1 = ['takeoff', 'rc 50 0 0 -70', 'delay', 'delay', 'delay', 'delay', 'rc 0 0 0 0', 'land']
# commands2 = ['takeoff', 'rc 50 0 0 -70', 'delay', 'delay', 'delay', 'delay', 'rc 0 0 0 0', 'land']

# plan1 = threading.Thread(target=execute_plan, args=(drones[0], commands1,), daemon=True)
# plan2 = threading.Thread(target=execute_plan, args=(drones[1], commands2,), daemon=True)
# try:
#     plan1.start()
#     plan2.start()
#     plan1.join()
#     plan2.join()
# except KeyboardInterrupt:
#     emergency_stop()
#     time.sleep(10) # wait to receive all messages
    

cmd = ''
while cmd != 'q':
    try:
        cmd = input()
        for x in drones:
            send_command(x, cmd)
    except KeyboardInterrupt:
        emergency_stop()

