import unittest
import main

class MainTestCase(unittest.TestCase):
    def setUp(self):
        print ("beginning")

    def tearDown(self):
        print ("end")

    def testAdd(self):
        self.assertEqual(main.add(1, 2), 3)
        self.assertEqual(main.add(1.5, 1.5), 3.0)

    def testSub(self):
        self.assertEqual(main.sub(2, 1), 1)
        self.assertEqual(main.sub(2.5, 1.5), 1)

    def testMul(self):
        self.assertEqual(main.mul(50, 100), 5000)

    def testMaxNum(self):
        self.assertEqual(main.maxNum(100, 200), 200)
        self.assertEqual(main.maxNum(100, 50), 100)
        self.assertEqual(main.maxNum(20, 20), 20)

    def testMinimum(self):
        self.assertEqual(main.minimum(2, 1), 1)
        self.assertEqual(main.minimum(2, 3), 2)
        self.assertEqual(main.minimum(1, 1), 1)
