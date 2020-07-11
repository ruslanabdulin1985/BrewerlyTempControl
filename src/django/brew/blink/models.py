from django.db import models
import time

# Create your models here.
import serial

def turnOn():
    print('Turning on')
    # try:
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=2)  # open serial port
    # print(ser.name)         # check which port was really used
    data = b'1'
    # data = (49).to_bytes(1, byteorder='big')
    time.sleep(2)
    #print(data[0])
    while 1:
        ser.write(data)
        time.sleep(3)

    print("sending", data)
    time.sleep(1)
    line = ser.read(2)
    print("recieving", line)
    ser.close()             # close port
       
    # except:
    #     print('Couldnot turn on. Passing.. ')
    #     pass

def getData():
    line = ""
    try:
        ser = serial.Serial('/dev/ttyUSB0')  # open serial port
        # print(ser.name)         # check which port was really used
        line = ser.read(4)
        line = ser.read(4)
        print (line)
        ser.close()             # close port
    
    except:
        line = "not available"

    return line
