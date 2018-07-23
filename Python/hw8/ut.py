import unittest
import main

class utTestCase(unittest.TestCase):
    def testFind(self):
        n = [-3, 9, 3, 0, 5, -7, 3, 6, -6, 1]
        self.assertEqual(-7 in n, True)

    def testIsPoitive(self):
        self.assertTrue(main.isPositive(2), True)
        self.assertEqual(main.isPositive(-1.5), False)

    def testFindAll(self):
        n = [-3, 9, 3, 0, 5, -7, 3, 6, -6, 1]
        ans = main.findAll(n, main.isPositive)
        self.assertEqual(ans, [9, 3, 0, 5, 3, 6, 1])
