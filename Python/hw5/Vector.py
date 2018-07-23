import math

class Vector():
    def __init__(self, comp):
        if len(comp) <= 0:
            raise Exception('Dimension Error')
        self.dim = len(comp)
        self.comp = comp

    def dimension(self):
        return self.dim

    def component(self, index):
        return self.comp[index - 1]

    def __add__(self, v):
        if self.dim != v.dim:
            raise Exception('Dimension Error')
        i = 1
        l = []
        while i <= self.dim:
             l.append(self.component(i) + v.component(i))
             i+=1
        return Vector(l)

    def __sub__(self, v):
        if self.dim != v.dim:
            raise Exception('Dimension Error')
        i = 1
        l = []
        while i <= self.dim:
            l.append(self.component(i) - v.component(i))
            i += 1
        return Vector(l)


    def __mul__(self, v):
        t = v.__class__.__name__
        if t == 'Vector':
            return self.innerProduct(v)
        elif t == 'int':
            return self.productScalar(v)

    __rmul__ = __mul__
    
    def innerProduct(self, v):
        if self.dim != v.dim:
            raise Exception('Dimension Error')
        i = 0
        result = 0
        while i < self.dim:
            result += self.comp[i] * v.comp[i]
            i += 1
        return result

    def length(self):
        result = 0
        for i in self.comp:
            result += i ** 2
        return math.sqrt(result)

    def productScalar(self, a):
        l = []
        for i in self.comp:
            l.append(i * a)
            i += 1
        return Vector(l)
