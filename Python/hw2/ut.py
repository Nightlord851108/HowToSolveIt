import unittest
import VectorCal

class InnerProductTestSuite(unittest.TestCase):

    def testVectorSumNormal(self):
        v = [1, 2]
        u = [3, 4]
        self.assertEqual(VectorCal.vectorSum(v, u, 2, 2), [4, 6])

    def testVectorSumException(self):
        v = [1, 2, 3]
        u = [4, 5]
        w = []
        self.assertEqual(VectorCal.vectorSum(v, u, 3, 2), "Dimensional Error")
        self.assertEqual(VectorCal.vectorSum(v, w, 3, 0), "Dimensional Error")

    def testInnerProductNormal(self):
        v = [1, 2]
        u = [3, 4]
        self.assertEqual(VectorCal.innerProduct(v, u, 2, 2), 11)

    def testInnerProductException(self):
        v = [1, 2]
        u = [3, 4, 5]
        w = []
        self.assertEqual(VectorCal.innerProduct(v, u, 2, 3), "Dimensional Error")
        self.assertEqual(VectorCal.innerProduct(v, w, 2, 0), "Dimensional Error")

    def testProve(self):
        u = [1, 2]
        v = [3, 4]
        w = [5, 6]
        result1 = VectorCal.innerProduct(u, VectorCal.vectorSum(v, w, 2, 2), 2, 2)
        result2 = VectorCal.innerProduct(u, v, 2, 2) + VectorCal.innerProduct(u, w, 2, 2)
        self.assertEqual(result1, result2)
