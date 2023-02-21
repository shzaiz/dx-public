from sympy import *

N_STEP=2

M = [
    [str("a"+str(i)+"_"+str(j)) for i in range(1,N_STEP+1)] for j in range(1,N_STEP+1)
]


def square(M):
    if(len(M)==0):
        return 0
    init_wid = len(M)
    if(init_wid != len(M[0])):
        return -1
    for i in range(len(M)):
        if(len(M[i])!=init_wid):
            return -1
        for j in range(len(M[i])):
            if(type(M[i][j])== type([])):
                return -1
    return init_wid
            

def get_sign(i,j):
    if ((i+j)%2):
        return 1
    else:
        return -1

def unfold(M,i,j):
    step = square(M)
    if(step==-1):
        print("Not a square!")
        return None
    MM=[]
    for ii in range(step):
        if ii==i:
            continue
        tmp = []
        for jj in range(step):
            if jj!= j:
                tmp.append(M[ii][jj])
        MM.append(tmp)
    return MM

def add_bracket(str):
    if(str==""):
        return ""
    return "("+str+")"

def cal_det_expr(M,row=0):
    step = square(M)
    if(step == -1):
        return None
    if step==1:
        return add_bracket(str(M[0][0]))
    else:
        expr = ""
        for i in range(step):
            expr=expr + "("
            expr=expr +(add_bracket(str(M[row][i]))+"*"+add_bracket(str(get_sign(row,i)))+"*")
            expr=expr + "("+cal_det_expr(unfold(M,row,i))+")"
            expr=expr + ")"
            if(i != step-1):
                expr = expr+"+"
        return expr


def cal_det_val(M):
    return eval(cal_det_expr(M))
    
for i in M:
    for j in i:
        exec(j+"=Symbol(\""+j+"\")")

# print(cal_det_expr(M))
# print("Solving...")
print(eval(cal_det_expr(M)).expand())






# Time compleity 
