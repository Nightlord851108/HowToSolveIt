import Vector
import VectorInput
import Shape
import math

class Circle(Shape.Shape):
    def __init__(self, o, r):
        if r <= 0:
            raise Exception("Radius less than zero")
        self.o = o
        self.r = r

    def description(self):
        s = "{circle, "
        s += "(" + str(self.o.component(1)) + "," + str(self.o.component(2)) + ')'
        s += ', ' + str(self.r) + '}'
        return s

    def perimeter(self):
        return self.r * 2 * math.pi

    def area(self):
        return self.r * self.r * math.pi

def createCircle(so, sr):
    v = VectorInput.getVector(so)
    r = float(sr)
    if (r // 1) == r:
        r = int(r)
    o = Circle(v, r)
    return o
