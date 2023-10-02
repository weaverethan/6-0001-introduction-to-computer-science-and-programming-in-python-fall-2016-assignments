
def f(L1,L2):
    newlist = []
    for i in L1:
        newlist.append((L1[i-1]**L2[i-1]))
    return newlist

L1= [1,2,3]
L2= [2,3,4]

print(f(L1, L2))