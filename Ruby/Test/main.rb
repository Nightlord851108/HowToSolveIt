class Circle
    @@count = 0
    def initialize(r)
        @r = r
        @@count = @@count + 1
    end

    def radius()
        @r
    end
    def getNum()
        @@count
    end
end
