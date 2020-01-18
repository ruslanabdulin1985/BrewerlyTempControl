from tkinter import *
import time
import threading 
import atexit
import datetime


class Interface:
    def __init__(self, master):
        
        topFrame = Frame(master)
        bottomFrame = Frame(master)

        thelablel = Label(topFrame, text="Brewery Application")
        
        button1 = Button(topFrame, text="Program1", bg='green', command=actions.program1)
        

        
        button2 = Button(topFrame, text="Program2", fg='green', command=actions.program2) 
        button4 = Button(topFrame, text="Program3", fg='green')

        topFrame.pack(side=TOP)
        thelablel.pack()
        button1.pack()
        button2.pack()
        button4.pack()

class program:
    def __init__(self, totalTime, periods):
        self.totalTime = totalTime
        self.periods = periods

class period:
    def __init__(self, time, temp):
        self.time = time
        self.temp = temp


class actions:
    isStarted = False
    a = 1

    def check(self): 
        programTemp = 20
        print(programTemp)
    
    def program1():   
        if actions.isStarted is False:
            actions.isStarted=True
            print("Starting")
            threading.Thread(target=actions.runProgram1).start()

        else:
            actions.isStarted = False
            print("Stopping")

    def runProgram1():
        while actions.isStarted is True:
            runningProgram = program(10, [period(5,22), period(5,32)])   
            for per in runningProgram.periods:
                while per.time != 0 and actions.isStarted is True:
                    print("running"+str(per.time) + " " + str(per.temp))
                    per.time=per.time-1
                    runningProgram.totalTime=runningProgram.totalTime-1
                    time.sleep(1)
            actions.isStarted = False
            
            

            # runningProgram.totalTime=runningProgram.totalTime-1
            # time.sleep(1)



        #time.sleep(10);

    def program2():    
        print("Program2")
        #time.sleep(10);

    def timer2(self):
        while actions.a == 1:
            #print(actions.a)
            print(datetime.datetime.now())
            time.sleep(1)

    def timer(self): 
        timer = threading.Timer(2.0, actions.timer)
        if actions.a == 1:
            print(actions.a)
            timer.start()  

    def doThings(self):
        
        print("Hey")
        time.sleep(2)

    def doSomethingElse(self, a=2):
        print("Works")
        actions.a=2

if __name__ == "__main__":
        # pass
    root = Tk()
    intterface = Interface(root)
    root.mainloop()
    
    atexit.register(actions.killthreds)

