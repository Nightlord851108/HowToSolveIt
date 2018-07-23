class Vector
    def initialize(v)
        if (v.length < 1)
            raise ArgumentError, "Dimension Error"
        end
        @comp = v
        @d = v.length
    end

    def component(n = 0)
        if (n == 0)
            return @comp
        end
            @comp[n - 1]
    end

    def dimension
        @d
    end

    def length
        s = 0
        for i in @comp
            s += i **2
        end
        s ** 0.5
    end

end

def getVector(s)
    if ((s[0] != '(') || (s[-1] != ')'))
        raise ArgumentError, "Format Error"
    end
    s = s[1..-1]
    s = s.split(',')
    v = []
    for i in s
        v.push(Decimal(i))
    end
    Vector.new(v)
end
