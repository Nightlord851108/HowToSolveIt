require 'test/unit'
require './main'

class UnitTest < Test::Unit::TestCase

    # Test add function
    def testADD_Positive
        assert_equal(2, add(1, 1))
    end
    def testAdd_Negative
        assert_equal(-1, add(1, -2))
    end
    def testSub_Positive
        assert_equal(1, sub(2, 1))
    end
    def testSub_Negative
        assert_equal(-3, sub(1, 4))
    end
    def testMul_Positive
        assert_equal(2, mul(1, 2))
    end
    def testMul_Negative
        assert_equal(-1, mul(1, -1))
    end
    def testMaxNum
        assert_equal(2, maxNum(2, 1))
    end
end
