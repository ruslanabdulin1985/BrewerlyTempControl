import serial
import time

def turnOn():
    print('Turning on')
    
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=2)  # open serial port
    # print(ser.name)         # check which port was really used
    time.sleep(3)
    data = b'1'
    # data = (49).to_bytes(1, byteorder='big')

    #print(data[0])
    ser.write(data)
    print("sending", data)
    time.sleep(3)
    line = ser.read(2)
    print("recieving", line)
    ser.close()             # close port
       
    # except:
    #     print('Couldnot turn on. Passing.. ')
    #     pass

if __name__ == "__main__":
    turnOn()