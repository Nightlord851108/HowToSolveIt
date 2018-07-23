def vectorSum(v, u, d1, d2):
    if (d1 != 0) & (d1 == d2):
        i = 0
        ans = []
        while i < d1:
            ans.append(v[i] + u[i])
            i = i + 1
        return ans
    return "Dimensional Error"

def innerProduct(v, u, d1, d2):
    if (d1 != 0) & (d1 == d2):
        i = 0
        sum = 0
        while i < d1:
            sum = sum + v[i] * u[i]
            i = i + 1
        return sum
    return "Dimensional Error"
