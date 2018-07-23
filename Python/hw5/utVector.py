import unittest
import Vector

class VectorTestCase(unittest.TestCase):

    def testVectorNormal(self):
        v = Vector.Vector([1, 2])
        self.assertEqual(v.dimension(), 2)
        self.assertEqual(v.component(1), 1)
        self.assertEqual(v.component(2), 2)
        u = Vector.Vector([1.5, 2.5])
        self.assertEqual(u.dimension(), 2)
        self.assertEqual(u.component(1), 1.5)
        self.assertEqual(u.component(2), 2.5)

    def testVectorException(self):
        self.assertRaisesRegex(Exception, "Dimension Error", Vector.Vector, [])

    def testVectorAdd(self):
        v = Vector.Vector([1, 2])
        u = Vector.Vector([1, 2])
        ans = v + u;
        self.assertEqual(ans.component(1), 2)
        self.assertEqual(ans.component(2), 4)

    def testVectorAddException(self):
        v = Vector.Vector([1, 2])
        u = Vector.Vector([1, 2, 3])
        self.assertRaisesRegex(Exception, "Dimension Error", v.__add__, u)

    def testVectorSub(self):
        v = Vector.Vector([3, 4])
        u = Vector.Vector([1, 2])
        ans = v - u;
        self.assertEqual(ans.component(1), 2)
        self.assertEqual(ans.component(2), 2)

    def testVectorSubException(self):
        v = Vector.Vector([1, 2])
        u = Vector.Vector([1, 2, 3])
        self.assertRaisesRegex(Exception, "Dimension Error", v.__sub__, u)

    def testVectorInnerproduct(self):
        v = Vector.Vector([1, 2])
        u = Vector.Vector([3, 4])
        self.assertEqual(v * u, 11)
        self.assertEqual(v.innerProduct(u), 11)

    def testVectorinnerProductException(self):
        v = Vector.Vector([1, 2])
        u = Vector.Vector([3, 4, 5])
        self.assertRaisesRegex(Exception, "Dimension Error", v.__mul__, u)

    def testVectorLength(self):
        v = Vector.Vector([3, 4])
        self.assertEqual(v.length(), 5)

    def testProductScalar(self):
        v = Vector.Vector([1, 2])
        self.assertEqual(v.productScalar(2).comp, [2, 4])
        self.assertEqual((v * 2).comp, [2, 4])
        self.assertEqual((2*v).comp, [2, 4])
