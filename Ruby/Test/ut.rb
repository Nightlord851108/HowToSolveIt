require 'test/unit'
require './main'

class MyTest < Test::Unit::TestCase
    def testCircle
        c1 = Circle.new(1)
        assert_equal(1, c1.radius())
        c2 = Circle.new(2)
        assert_equal(2, c1.getNum())
    end
end


#
# Test::Unit::UI::Console::TestRunner.run(MyTest)
