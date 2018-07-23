import Vector
import ConvexPolygon

def getVector(s):
    if not s:
        raise Exception("Input is empty")
    if ((s[0] != '(') | (s[-1] != ')')):
        raise Exception("Invalid input")
    s = s.strip('(')
    s = s.strip(')')
    if not s:
        raise Exception("Input is empty")
    l = s.split(',')

    result = []
    for i in l:
        try:
            n = float(i)
            if (n // 1) == n:
                n = int(n)
            result.append(n)
        except:
            raise Exception("Invalid input")
    return Vector.Vector(result)

def getVectorList(s, separator = '/'):
    s = s.split(separator)
    l = []
    for i in s:
        l.append(getVector(i))
    return l
