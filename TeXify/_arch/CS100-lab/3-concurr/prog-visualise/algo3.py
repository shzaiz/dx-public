class Algo2:

    halt = 0

    turn='' 
    x=0

    @thread
    def t1(self):
        self.turn='t1'
        while self.turn == 't2':
            pass
        a = self.x
        a=a+5
        self.x=a
        self.turn='t2'
        


    
    @thread
    def t2(self):
        self.turn='t2'
        while self.turn == 't1':
            pass
        b=self.x
        b=b+10
        self.x=b
        self.turn = 't1'
    
