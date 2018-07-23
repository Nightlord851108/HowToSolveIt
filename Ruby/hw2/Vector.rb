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
    sum = 0
    for i in v
        sum += i ** 2
    end
    sum.abs
end
