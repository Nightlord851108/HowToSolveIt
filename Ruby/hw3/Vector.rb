def sum(v1, v2)
    if (v1.length != v2.length)
        raise ArgumentError, "Dimension Error"
    end
    v = []
    for i in 0..v1.length-1
        v.push(v1[i] + v2[i])
    end
    v
end

def product(v1, v2)
    if (v1.length != v2.length)
        raise ArgumentError, "Dimension Error"
    end
    result = 0
    for i in 0..v1.length-1
        result += v1[i] * v2[i]
    end
    result
end

def length(v)
    if (v.length < 1)
        raise ArgumentError, "Dimension less than 1"
    end
    result = 0
    for i in v
        result += i ** 2
    end
    result ** 0.5
end

def scalar(a, v)
    if (v.length < 1)
        raise ArgumentError, "Dimension less than 1"
    end
    result = []
    for i in v
        result.push(a * i)
    end
    result
end
