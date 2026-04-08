import unittest
from Matematica import Matematica

class MatematicaTest(unittest.TestCase):
    def test_fibonacci(self):
        self.assertEqual(Matematica.fibonacci(0), 0)
        self.assertEqual(Matematica.fibonacci(1), 1)
        self.assertEqual(Matematica.fibonacci(2), 1)
        self.assertEqual(Matematica.fibonacci(3), 2)
        self.assertEqual(Matematica.fibonacci(7), 13)
        self.assertEqual(Matematica.fibonacci(10), 55)
        self.assertEqual(Matematica.fibonacci(11), 89)