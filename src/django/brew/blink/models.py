from django.db import models

# Create your models here.
import serial

def turnOn():
    try:
        ser = serial.Serial('/dev/ttyUSB0')  # open serial port
        # print(ser.name)         # check which port was really used
        ser.write(1)
        ser.close()             # close port
    
    except:
        pass

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