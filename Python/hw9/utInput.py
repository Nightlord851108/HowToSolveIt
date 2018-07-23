import unittest
import Input

class InputTestSuite(unittest.TestCase):
    def testGetInputFromFile(self):
        filename = "file1.txt"
        s = Input.getInputFromFile(filename)
        self.assertEqual(s, "convex polygon; 3; (0,0)/(3,0)/(3,4)")

    def testGetShapeFromFile(self):
        filename = "file1.txt"
        s = Input.getShapeFromFile(filename)
        self.assertEqual(s.description(), "{convex polygon, 3, (0,0)/(3,0)/(3,4)}")

    def testGetShapeFromFileException(self):
        filename = "file2.txt"
        self.assertRaisesRegex(Exception, "Invalid Shape", Input.getShapeFromFile, filename)

    def testGetShapeFromFile(self):
        filename = "file3.txt"
        s = Input.getShapeFromFile(filename)
        self.assertEqual(s.description(), "{circle, (0,0), 1}")

    def testGetInputFromFileException(self):
        filename = "file4.txt"
        self.assertRaisesRegex(Exception, "Invalid Shape", Input.getShapeFromFile, filename)
