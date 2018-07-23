import math

def vectorSum(v, u):
    if (len(v) != 0) & (len(v) == len(u)):
        i = 0
        ans = []
        while i < len(v):
            ans.append(v[i] + u[i])
            i = i + 1
        return ans
    return "Dimensional Error"

def innerProduct(v, u):
    if (len(v) != 0) & (len(v) == len(u)):
        i = 0
        sum = 0
        while i < len(v):
            sum = sum + v[i] * u[i]
            i = i + 1
        return sum
    return "Dimensional Error"

def length(v):
    if len(v) == 0:
        return "Dimensional Error"
    sum = 0
    for i in v:
        sum = sum + i ** 2
    return math.sqrt(sum)

def scalar(v, a):
    if len(v) == 0:
        return "Dimensional Error"
    result = []
    for i in v:
        result.append(a * i)
    return result
