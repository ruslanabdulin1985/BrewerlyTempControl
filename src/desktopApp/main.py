from tkinter import *
import time
import threading 
import atexit
import datetime
import program
import status

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

       

class actions:
    
    a = 1

    def check(self): 
        programTemp = 20
        print(programTemp)
    
    def program1():   
        if status.isStarted is False:
            status.isStarted=True
            print("Starting")
            threading.Thread(target=program.main.runProgram("program1.conf")).start()

        else:
            status.isStarted = False
            print("Stopping")
            
        
if __name__ == "__main__":
        # pass
    root = Tk()
    intterface = Interface(root)
    root.protocol("WM_DELETE_WINDOW", Interface.on_closing)
    root.mainloop()
    
    atexit.register(actions.killthreds)

