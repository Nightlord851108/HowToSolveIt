require ('test/unit')
require ('./Vector')

class TestVector < Test::Unit::TestCase
    def testSum
        v = [1, 1]
        u = [2, 2]
        assert_equal([3, 3], sum(v, u))
    end
    def testSumException
        v = [1, 2]
        u = [1, 2, 2]
        assert_raise_message("Dimension Error", ArgumentError) do
            sum(v, u)
        end
    end

    def testProduct
        v = [1, 2]
        u = [3, 4]
        assert_equal(11, product(v, u))
    end
    def testProductException
        v = [1, 2, 2]
        u = [2, 3]
        assert_raise_message("Dimension Error", ArgumentError) do
            product(v, u)
        end
    end

    def testProve
        u = [1, 2]
        v = [3, 4]
        w = [5, 6]
        left = product(u, sum(v, w))
        right = product(u, v) + product(u, w)
        assert_equal(left, right)
    end
end
