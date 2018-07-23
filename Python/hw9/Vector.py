import math

class Vector:
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

    def __truediv__(self, a):
        if a == 0:
            raise Exception("Should not divide Zero")
        l = []
        for i in self.comp:
            l.append(i/a)
        return Vector(l)

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

def centroid(v1, v2 = None):
    if v2 is not None:
        if v1.dimension() != v2.dimension():
            raise Exception('Dimension Error')
        i = 1
        l = []
        while i <= v1.dimension():
            l.append((v1.component(i) + v2.component(i)) / 2)
            i += 1
        return Vector(l)
    else:
        i = 1
        l = []
        while i <= v1[0].dimension():
            j = 0
            s = 0
            while j < len(v1):
                s += v1[j].component(i)
                j += 1
            l.append(s)
            i += 1
        return Vector(l)/len(v1)

def zout(v1, v2):
    if (v1.dimension() != v2.dimension()) | (v1.dimension() != 2):
        raise Exception("Dimension Error")
    return (v1.component(1) * v2.component(2)) >= (v2.component(1) * v1.component(2))

class SmallAngleInFront():
    def __init__(self, o, refv):
        self.o = o
        self.r = refv

    def compareVector(self, v1, v2):
        vr = self.r - self.o
        va = v1 - self.o
        vb = v2 - self.o

        if v1.dimension() != 2:
            raise Exception('Format Error')

        theta_a = math.acos(vr * va / (vr.length() * va.length()))
        theta_b = math.acos(vr * vb / (vr.length() * vb.length()))
        if not zout(vr, va): theta_a = 2*math.pi - theta_a
        if not zout(vr, vb): theta_b = 2*math.pi - theta_b
        return theta_a < theta_b

def sortVector(v):
    i = 0
    compare = SmallAngleInFront(centroid(v), v[0])
    while i < len(v)-1:
        j = i+1
        while j < len(v):
            if not compare.compareVector(v[i], v[j]):
                temp = v[i]
                v[i] = v[j]
                v[j] = temp
            j += 1
        i += 1
