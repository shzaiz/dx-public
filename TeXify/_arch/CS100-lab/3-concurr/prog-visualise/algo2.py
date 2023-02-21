class Algo2:

    halt = 0

    x=5
    y=10
    z=30
    sum=0

    @thread
    def t1(self):
        val1 = self.sum+self.x
        self.sum = val1

    
    @thread
    def t2(self):
        val2 = self.sum+self.y
        self.sum = val2

    @thread
    def t3(self):
        val3 = self.sum+self.z
        self.sum = val3
    
