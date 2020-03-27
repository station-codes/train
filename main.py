import serial
import threading
import time


def readFromPort(ser):
    while True:
        if ser.in_waiting > 0:
            read = ser.readline()
            if "Qx" in str(read):
                ser.write( str.encode("<X 0 8>\n") )
            elif "qx" in str(read):
                ser.write( str.encode("<X 0 1>\n") )
            elif "Q2" in str(read):
                ser.write( str.encode("<1>\n") )
            elif "q2" in str(read):
                ser.write( str.encode("<0>\n") )
            
            print("rx: ", read)
        
        
def writeToPort(ser):
    while True:
        command = input()
        ser.write(str.encode('<'+command+'>'))

def signalToggler(ser):
    signal = 0
    while True:
        ser.write(str.encode('<X 1 ' + str(signal) + '>\n'))
        if signal < 8:
            signal += 1
        else:
            signal = 0
        time.sleep(0.1)

ser = serial.Serial("/dev/ttyACM0", baudrate=115200, timeout=1)

thread_rx = threading.Thread( target=readFromPort, args=(ser,) )
thread_tx = threading.Thread( target=writeToPort, args=(ser,) )
thread_signal = threading.Thread( target=signalToggler, args=(ser,) )

thread_rx.start()
thread_tx.start()
#thread_signal.start()

