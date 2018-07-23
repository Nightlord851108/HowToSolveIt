import unittest
import Vector
import VectorInput

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

    def testDiv(self):
        v = Vector.Vector([2, 4])
        self.assertEqual((v/2).comp, [1, 2])

    def testDivException(self):
        v = Vector.Vector([2, 4])
        self.assertRaisesRegex(Exception, "Should not divide Zero", v.__truediv__, 0)


    def testCentroid(self):
        va = Vector.Vector([1, 2])
        vb = Vector.Vector([3, 4])
        self.assertEqual(Vector.centroid(va, vb).comp, [2, 3])

    def testCentroidException(self):
        va = Vector.Vector([1, 2])
        vb = Vector.Vector([1, 2, 3])
        self.assertRaisesRegex(Exception, "Dimension Error", Vector.centroid, va, vb)

    def testCentroidMulti(self):
        v = [
            Vector.Vector([1, 2]),
            Vector.Vector([2, 3]),
            Vector.Vector([3, 4]),
            Vector.Vector([4, 5])
        ]
        self.assertEqual(Vector.centroid(v).comp, [2.5, 3.5])

    def testZout(self):
        v1 = Vector.Vector([2, 1])
        v2 = Vector.Vector([1, 0])
        self.assertEqual(Vector.zout(v1, v2), False)
        self.assertEqual(Vector.zout(v2, v1), True)

    def testZoutException(self):
        v1 = Vector.Vector([2, 1])
        v2 = Vector.Vector([1, 0, 2])
        va = Vector.Vector([2, 1, 1])
        self.assertRaisesRegex(Exception, "Dimension Error", Vector.zout, v1, v2)
        self.assertRaisesRegex(Exception, "Dimension Error", Vector.zout, v2, va)

    def testSmallAngle(self):
        v1 = Vector.Vector([1, 0])
        v2 = Vector.Vector([2, 2])
        self.assertEqual(Vector.SmallAngleInFront(Vector.centroid(v1, v2), v1).compareVector(v1, v2), True)

    def testSmallAngleException(self):
        v1 = Vector.Vector([1, 0, 1])
        v2 = Vector.Vector([2, 2, 2])
        o = Vector.centroid(v1, v2)
        compare = Vector.SmallAngleInFront(o, v1)
        self.assertRaisesRegex(Exception, "Format Error", compare.compareVector, v1, v2)

    def testSortVectors(self):
        v = [
            Vector.Vector([2, 2]),
            Vector.Vector([1, 0]),
            Vector.Vector([0, 0]),
            Vector.Vector([2, 1])
        ]
        Vector.sortVector(v)
        self.assertEqual(v[0].comp, [2, 2])
        self.assertEqual(v[1].comp, [0, 0])
        self.assertEqual(v[2].comp, [1, 0])
        self.assertEqual(v[3].comp, [2, 1])

    def testSortVectorsException(self):
        v = [
            Vector.Vector([0, 0]),
            Vector.Vector([2, 2]),
            Vector.Vector([1, 0]),
            Vector.Vector([2, 1, 0])
        ]
        self.assertRaisesRegex(Exception, 'Dimension Error', Vector.sortVector, v)
