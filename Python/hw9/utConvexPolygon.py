import unittest
import ConvexPolygon
import Vector

class ConvexPolygonTestCase(unittest.TestCase):
    def testConvexPolygon(self):
        v = [
            Vector.Vector([0, 0]),
            Vector.Vector([1, 0]),
            Vector.Vector([1, 1]),
            Vector.Vector([0, 1])
        ]
        cp = ConvexPolygon.ConvexPolygon(v)
        self.assertEqual(cp.verticesNum(), 4)
        self.assertEqual(cp.vertices(), [[0, 0], [1, 0], [1, 1], [0, 1]])
        self.assertEqual(cp.vertices(0).comp, [0, 0])
        self.assertEqual(cp.vertices(1).comp, [1, 0])
        self.assertEqual(cp.vertices(2).comp, [1, 1])
        self.assertEqual(cp.vertices(3).comp, [0, 1])

    def testPerimeter(self):
        v = [
            Vector.Vector([0, 0]),
            Vector.Vector([1, 0]),
            Vector.Vector([1, 1]),
            Vector.Vector([0, 1])
        ]
        cp = ConvexPolygon.ConvexPolygon(v)
        self.assertEqual(cp.perimeter(), 4)

    def testArea(self):
        v = [
            Vector.Vector([0, 0]),
            Vector.Vector([1, 0]),
            Vector.Vector([1, 1]),
            Vector.Vector([0, 1])
        ]
        cp = ConvexPolygon.ConvexPolygon(v)
        self.assertAlmostEqual(cp.area(), 1)

    def testCreateConvexPolygon(self):
        s = "(0,0)/(3,0)/(3,4)"
        cp = ConvexPolygon.createConvexPolygon(s)
        self.assertEqual(cp.verticesNum(), 3)
        self.assertEqual(cp.vertices(0).comp, [0, 0])
        self.assertEqual(cp.vertices(1).comp, [3, 0])
        self.assertEqual(cp.vertices(2).comp, [3, 4])

    def testCreateConvexPolygonUnsorted(self):
        s = "(0,0)/(1,1)/(1,0)/(0,1)"
        cp = ConvexPolygon.createConvexPolygon(s)
        self.assertEqual(cp.verticesNum(), 4)
        self.assertEqual(cp.vertices(0).comp, [0, 0])
        self.assertEqual(cp.vertices(1).comp, [1, 0])
        self.assertEqual(cp.vertices(2).comp, [1, 1])
        self.assertEqual(cp.vertices(3).comp, [0, 1])

    def testCreateConvexPolygonException(self):
        s = "(0,0)/(1,1)"
        self.assertRaisesRegex(Exception, "Less than 3 vertices", ConvexPolygon.createConvexPolygon, s)

    def testDescription(self):
        s = "(0,0)/(1,1)/(1,0)/(0,1)"
        cp = ConvexPolygon.createConvexPolygon(s)
        self.assertEqual(cp.description(), '{convex polygon, 4, (0,0)/(1,0)/(1,1)/(0,1)}')

    def testDescriptionFloat(self):
        s = "(0.5,1.5)/(1.5,1.5)/(1.5,0)"
        cp = ConvexPolygon.createConvexPolygon(s)
        self.assertEqual(cp.description(), '{convex polygon, 3, (0.5,1.5)/(1.5,0)/(1.5,1.5)}')
