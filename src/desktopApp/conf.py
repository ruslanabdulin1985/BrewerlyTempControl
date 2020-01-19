class conf:
    def cleanLine(line): # Remove \n sign
        newline = ""
        for char in line:
            if char=="\n":
                pass
            else:
                newline=newline+char
        return newline                
    
    def readFile(path):
        print(path)
        f = open(path, "r")
        lines = f.readlines()
        data = []

        for line in lines:
            dataline = conf.cleanLine(line).split(",") 
            data.append(dataline)
        return data

# if __name__ == "__main__":
#     print(conf.readFile("program1.conf"))