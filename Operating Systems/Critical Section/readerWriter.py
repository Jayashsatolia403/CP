# Reader Writer Problem


from threading import *



class ReaderWriter:
    
    def __init__(self):
        self.readcount = 0
        self.writecount = 0
        self.mutex = Semaphore(1)
        self.wrt = Semaphore(1)

    def writer(self):
        wait(self.wrt)
        