import serial
import threading
import time


def readFromPort(ser):
    while True:
        if ser.in_waiting > 0:
            print("rx: ", ser.readline())


def writeToPort(ser):
    while True:
        command = input()
        ser.write(str.encode('<'+command+'>'))


def simulation(ser):
    time.sleep(4)
    send = '<1>'
    ser.write(str.encode(send + '\n'))
    print('tx: ' + send)
    time.sleep(2)
    while 1:
        send = '<t1 13 5 1>\n'
        ser.write(str.encode(send))
        time.sleep(12)
        send = '<t1 13 15 0>\n'
        ser.write(str.encode(send))
        time.sleep(12)
        send = '<t1 13 1 0>'
        ser.write(str.encode(send))
        time.sleep(2)
        send = '<0>\n'
        ser.write(str.encode(send))
        time.sleep(1)
        send = '<1>\n'
        ser.write(str.encode(send))



ser = serial.Serial("/dev/ttyACM0", baudrate=115200, timeout=1)

thread_rx = threading.Thread( target=readFromPort, args=(ser,) )
thread_tx = threading.Thread( target=writeToPort, args=(ser,) )
thread_simulation = threading.Thread( target=simulation, args=(ser,) )

thread_rx.start()
thread_tx.start()
thread_simulation.start()

