import status

class main:
    def runProgram(confFile):
        while status.isStarted is True:
            data = conf.conf.readFile(confFile)
            periods = []
            for p in data:
                periods.append(program.period(int(p[1]), int(p[2])))

            for p in periods:
                p.toString()

            runningProgram = program.program(20, periods)   

            for per in runningProgram.periods:
                while per.time != 0 and actions.isStarted is True:
                    print("running " + str(per.time) + " " + str(per.temp))
                    per.time=per.time-1
                    runningProgram.totalTime=runningProgram.totalTime-1
                    time.sleep(1)
            status.isStarted = False
            

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
