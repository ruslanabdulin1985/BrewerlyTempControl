from tkinter import *
import time
import threading 
import atexit
import datetime

import conf


class Interface:
    def __init__(self, master):
        
        topFrame = Frame(master)
        bottomFrame = Frame(master)

        thelablel = Label(topFrame, text="Brewery Application")
        
        button1 = Button(topFrame, text="Program1", bg='green', command=actions.program1)
        

        
        button2 = Button(topFrame, text="Program1", fg='green', command=actions.program1) 
        button4 = Button(topFrame, text="Program1", fg='green')

        topFrame.pack(side=TOP)
        thelablel.pack()
        button1.pack()
        button2.pack()
        button4.pack()

    def on_closing():
        actions.isStarted = False
        root.destroy()

class program:
    def __init__(self, totalTime, periods):
        self.totalTime = totalTime
        self.periods = periods

class period:
    def __init__(self, time, temp):
        self.time = time
        self.temp = temp
    
    def toString(self):
        print("time="+str(self.time)+", temp="+str(self.temp))
       

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
            data = conf.conf.readFile("program1.conf")
            periods = []
            for p in data:
                periods.append(period(int(p[1]), int(p[2])))

            for p in periods:
                p.toString()

            runningProgram = program(20, periods)   

            for per in runningProgram.periods:
                while per.time != 0 and actions.isStarted is True:
                    print("running " + str(per.time) + " " + str(per.temp))
                    per.time=per.time-1
                    runningProgram.totalTime=runningProgram.totalTime-1
                    time.sleep(1)
            actions.isStarted = False
            
        
if __name__ == "__main__":
        # pass
    root = Tk()
    intterface = Interface(root)
    root.protocol("WM_DELETE_WINDOW", Interface.on_closing)
    root.mainloop()
    
    atexit.register(actions.killthreds)

