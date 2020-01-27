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
        
        rightFrame = Frame(master, width=500)
        leftFrame = Frame(master)
        bottomFrame = Frame(master)

        self.thelablel = Label(rightFrame, text="Programs:")
        self.thelablel.pack()


        self.w = Canvas(leftFrame, width=300, height=150)
        self.w.pack()
        self.w.create_rectangle(20, 20, 280, 130, fill="green", outline = 'black')

        self.programName = self.w.create_text((140,20), text=status.currStat, anchor=N)
        self.targetCLable = self.w.create_text((40,60), text="Target C*", anchor=NW)
        self.targetC = self.w.create_text((220,60), text=status.targetC, anchor=NE)
        self.currentCLable= self.w.create_text((40,80), text="Current C*", anchor=NW)
        self.currentC = self.w.create_text((220,80), text=status.currentC, anchor=NE)
        self.currentTimeLabel= self.w.create_text((40,100), text="Time Left*", anchor=NW)
        self.currentTime = self.w.create_text((220,100), text=status.currentTime, anchor=NE)
        #self.programName.pack()

        self.button1 = Button(rightFrame, text="Program 1", bg='grey', state="normal", command=self.program1)
        self.button1.pack()
        
        self.button2 = Button(rightFrame, text="Program 2", bg='grey', state="normal", command=self.changeText) 
        self.button2.pack()

        self.button4 = Button(rightFrame, text="Program 3", bg='grey')
        self.button4.pack()

        spaceFrame = Frame(rightFrame, width=100)
        spaceFrame.pack(side=RIGHT, expand=True)
        # spaceFrame.place(relx=.5, rely=.5, anchor="c")

        rightFrame.pack(side=RIGHT, expand=False)
        leftFrame.pack(side=LEFT)
        bottomFrame.pack(side=BOTTOM)
        
       
        
       

    def on_closing():
        status.isStarted = False
        root.destroy()


    def changeText(self):
        print("we are here")
        status.currStat = "fuckYea!!!"
        self.w.itemconfig(self.programName, text=status.currStat)
        if self.button2['bg'] == "blue":
            self.button2['bg'] = "red"
        else:
            self.button2['bg'] = "blue"

    def program1(self):   
    
        if status.isStarted is False:
            status.isStarted=True
            self.w.itemconfig(self.programName, text="Program 1 Started")
            self.button1["bg"] = "green"
            self.button2["state"] = "disabled"
            self.button4["state"] = "disabled"
            threading.Thread(target=lambda: program.main.runProgram(confFile="program1.conf")).start()
            
        else:
            status.isStarted = False
            self.button1["bg"] = "gray"
            self.button2["state"] = "normal"
            self.button4["state"] = "normal"
            self.w.itemconfig(self.programName, text="Program 1 Stopped")

class actions:

    def check(self): 
        programTemp = 20
        print(programTemp)
    


    def exit():
        status.isStarted = False        
    
if __name__ == "__main__":
        # pass
    root = Tk()
    intterface = Interface(root)
    root.title("Brewery Application")
    root.protocol("WM_DELETE_WINDOW", Interface.on_closing)
    
    root.mainloop()
    
    
    atexit.register(actions.exit)

