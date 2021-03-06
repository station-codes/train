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


ser = serial.Serial("/dev/ttyACM0", baudrate=115200, timeout=1)

thread_rx = threading.Thread( target=readFromPort, args=(ser,) )
thread_tx = threading.Thread( target=writeToPort, args=(ser,) )

thread_rx.start()
thread_tx.start()

