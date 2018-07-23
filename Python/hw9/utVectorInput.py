import unittest
import Vector
import VectorInput

class InnerProductTestSuite(unittest.TestCase):

    def testGetVectorNormal(self):
        self.assertEqual(VectorInput.getVector("( 1, 2)").comp, [1, 2])

    def testGetVectorException(self):
        self.assertRaisesRegex(Exception, "Input is empty", VectorInput.getVector, "")
        self.assertRaisesRegex(Exception, "Input is empty", VectorInput.getVector, "()")
        self.assertRaisesRegex(Exception, "Invalid input", VectorInput.getVector, "(2 (, 3))")
        self.assertRaisesRegex(Exception, "Invalid input", VectorInput.getVector, "2, 3)")
        self.assertRaisesRegex(Exception, "Invalid input", VectorInput.getVector, "(, 3)")
        self.assertRaisesRegex(Exception, "Invalid input", VectorInput.getVector, "(2 a, 3)")

    def testGetVectorList(self):
        s = "(0,0)/(3,0)/(3,4)"
        v = VectorInput.getVectorList(s)
        self.assertEqual(v[0].comp, [0, 0])
        self.assertEqual(v[1].comp, [3, 0])
        self.assertEqual(v[2].comp, [3, 4])
