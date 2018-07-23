def isPositive(n):
    return n >= 0

def findAll(n, foo):
    l = []
    for i in n:
        if foo(i):
            l.append(i)
    return l
