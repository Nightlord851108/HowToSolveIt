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
    def testProve2
        u = [1, 2]
        v = [3, 4]
        left = length(sum(u, v)) ** 2
        right = length(u) ** 2 + 2 * product(u, v) + length(v) ** 2
        assert_in_delta(left, right)
    end

    def testLength
        v = [3, 4]
        assert_equal(5, length(v))
    end
    def testLengthException
        v = []
        assert_raise_message("Dimension less than 1", ArgumentError) do
            length(v)
        end
    end

    def testScalar
        v = [1, 2]
        assert_equal([2, 4], scalar(2, v))
    end
    def testScalarException
        v = []
        assert_raise_message("Dimension less than 1", ArgumentError) do
            length(v)
        end
    end
end
