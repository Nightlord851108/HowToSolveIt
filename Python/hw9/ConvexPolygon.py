import math
import Vector
import VectorInput
import Shape


class ConvexPolygon(Shape.Shape):
    def __init__(self, v):
        self.n = len(v)
        self.v = []
        for i in v:
            self.v.append(i)

    def verticesNum(self):
        return self.n

    def vertices(self, n = None):
        if n is None:
            l = []
            for i in self.v:
                l.append(i.comp)
            return l
        else:
            return self.v[n]

    def perimeter(self):
        i = -1
        p = 0
        while i < self.n - 1:
            p += (self.v[i+1]-self.v[i]).length()
            i += 1
        return p

    def area(self):
        o = Vector.centroid(self.v)
        i = -1
        result = 0
        while i < self.n - 1:
            a = (o - self.v[i]).length()
            b = (o - self.v[i+1]).length()
            c = (self.v[i+1] - self.v[i]).length()
            s = (a + b + c) / 2
            result += math.sqrt(s * (s - a) * (s - b) * (s - c))
            i += 1
        return result

    def description(self):
        s = '{convex polygon, '
        s += str(self.n) + ', '
        for i in range(0, len(self.v)):
            s += '('
            for j in range(1, self.v[i].dimension()):
                s += str(self.v[i].component(j)) + ','
            s += str(self.v[i].comp[-1]) + ')/'
        s = s[0:-1]
        s += '}'
        return s


def createConvexPolygon(s):
    v = VectorInput.getVectorList(s)
    if len(v) < 3:
        raise Exception("Less than 3 vertices")
    Vector.sortVector(v)
    return ConvexPolygon(v)
