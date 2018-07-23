require ('test/unit')
require ('./Vector')

class TestVector < Test::Unit::TestCase
    def testConstructor
        v = Vector.new([1, 2])
        assert_equal([1, 2], v.component)
        assert_equal(2, v.dimension)
        assert_equal(1, v.component(1))
        assert_equal(2, v.component(2))
    end
    def testConstructorException
        assert_raise_message("Dimension Error", ArgumentError) do
            Vector.new([])
        end
    end

    def testLength
        v = Vector.new([3, 4])
        assert_equal(5, v.length)
    end

    def testGetVector
        s = "(1, 2)"
        assert_equal([1, 2], getVector(s).component)
    end
end
