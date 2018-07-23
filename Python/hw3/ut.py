import unittest
import VectorCal

class InnerProductTestSuite(unittest.TestCase):

    def testVectorSumNormal(self):
        v = [1, 2]
        u = [3, 4]
        self.assertEqual(VectorCal.vectorSum(v, u), [4, 6])

    def testVectorSumException(self):
        v = [1, 2, 3]
        u = [4, 5]
        w = []
        self.assertEqual(VectorCal.vectorSum(v, u), "Dimensional Error")
        self.assertEqual(VectorCal.vectorSum(v, w), "Dimensional Error")

    def testInnerProductNormal(self):
        v = [1, 2]
        u = [3, 4]
        self.assertEqual(VectorCal.innerProduct(v, u), 11)

    def testInnerProductException(self):
        v = [1, 2]
        u = [3, 4, 5]
        w = []
        self.assertEqual(VectorCal.innerProduct(v, u), "Dimensional Error")
        self.assertEqual(VectorCal.innerProduct(v, w), "Dimensional Error")

    def testProve(self):
        u = [1, 2]
        v = [3, 4]
        w = [5, 6]
        result1 = VectorCal.innerProduct(u, VectorCal.vectorSum(v, w))
        result2 = VectorCal.innerProduct(u, v) + VectorCal.innerProduct(u, w)
        self.assertEqual(result1, result2)

    def testLengthNormal(self):
        v = [3, 4]
        self.assertEqual(VectorCal.length(v), 5)

    def testLengthException(self):
        v = []
        self.assertEqual(VectorCal.length(v), "Dimensional Error")

    def testScalarNormal(self):
        a = 2
        v = [3, 4]
        self.assertEqual(VectorCal.scalar(v, a), [6, 8])

    def testScalarException(self):
        a = 2
        v= []
        self.assertEqual(VectorCal.scalar(v, a), "Dimensional Error")

    def testProveTwo(self):
        u = [1, 2]
        v = [3, 4]
        result1 = VectorCal.length(VectorCal.vectorSum(u, v)) ** 2
        result2 = VectorCal.length(u) ** 2 + 2 * VectorCal.innerProduct(u, v) + VectorCal.length(v) ** 2
        self.assertTrue(abs(result1 - result2) < 0.0000001)
