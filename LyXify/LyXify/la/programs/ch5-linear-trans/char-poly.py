import itertools
from sympy import *
init_printing(use_latex=true)
def charply(M):
    lamda = symbols('lamda')
    p = M.charpoly(lamda)
    return factor(p.as_expr())

START=3
def count_eigens():
    cnteigen = [0,0,0,0]
    for i in itertools.product([114,514,191],repeat=9):
        s = Matrix([[i[0],i[1],i[2]],[i[3],i[4],i[5]],[i[6],i[7],i[8]]])
        ev = s.eigenvals()
        cnteigen[len(ev)] += 1
        print(cnteigen)
    print(cnteigen)

count_eigens()



        
