import ConvexPolygon
import Circle

def getInputFromFile(filename):
    f = open(filename, 'r')
    s = f.readline()
    f.close()
    if (s[0] != '{') | (s[-1] != '}'):
        raise Exception("Format Error")
    s = s.strip('{')
    s = s.strip('}')
    return s

def getShapeFromFile(filename):
    s = getInputFromFile(filename)
    s = s.split(';')
    if s[0] == "convex polygon":
        cp = ConvexPolygon.createConvexPolygon(s[2][1:])
        return cp
    elif s[0] == "circle":
        o = Circle.createCircle(s[1][1:], s[2][1:])
        return o
    else:
        raise Exception("Invalid Shape")
