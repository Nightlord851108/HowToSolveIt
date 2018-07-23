import unittest
import Vector
import Circle
import math

class CircleTestCase(unittest.TestCase):
    def testCircle(self):
        c = Vector.Vector([0, 0])
        r = 1
        o = Circle.Circle(c, r)
        self.assertEqual(o.description(), "{circle, (0,0), 1}")
        self.assertEqual(o.r, 1)
        self.assertEqual(o.o.comp, [0,0])

    def testCircleException(self):
        c = Vector.Vector([0, 0])
        r = -1
        self.assertRaisesRegex(Exception, "Radius less than zero", Circle.Circle, c, r)

    def testPerimeter(self):
        c = Vector.Vector([0, 0])
        r = 1
        o = Circle.Circle(c, r)
        self.assertEqual(o.perimeter(), 2 * math.pi)

    def testArea(self):
        c = Vector.Vector([0, 0])
        r = 1
        o = Circle.Circle(c, r)
        self.assertEqual(o.area(), math.pi)

    def testCreateCircle(self):
        so = "(0,0)"
        sr = " 1"
        o = Circle.createCircle(so, sr)
        self.assertEqual(o.description(), "{circle, (0,0), 1}")
