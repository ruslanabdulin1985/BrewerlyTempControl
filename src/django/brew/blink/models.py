from django.db import models

# Create your models here.
import serial

def getData():
    ser = serial.Serial('/dev/ttyUSB0')  # open serial port
    print(ser.name)         # check which port was really used
    line = ser.readline()
    ser.close()             # close port
    return line