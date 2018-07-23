def getVector(s):
    if not s:
        return ("Input is empty")
    if ((s[0] != '(') | (s[-1] != ')')):
        return ("Invalid input")
    s = s.strip('(')
    s = s.strip(')')
    if not s:
        return ("Input is empty")
    l = s.split(',')

    result = []
    for i in l:
        try:
            result.append(float(i))
        except:
            return ("Invalid input")
    return result
