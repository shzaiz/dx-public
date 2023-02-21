class Algo1:

    halt = 0

    x=0    

    @thread
    def t1(self):
        a=self.x
        a=a+5
        self.x=a

    @thread
    def t2(self):
        b=self.x
        b=b+10
        self.x=b
