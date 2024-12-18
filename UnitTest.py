from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testCases = {1: ([8,4,6,2,3], [4,2,4,2,3]), 2: ([1,2,3,4,5], [1,2,3,4,5])}
        self.__obj = Solution()
        return super().setUp()
    
    @timeout(0.5)
    def test_case_1(self):
        prices, output = self.__testCases[1]
        result = self.__obj.finalPrices(prices)
        self.assertIsInstance(result, list)
        self.assertTrue(all(r == o for r, o in zip(result, output)))

    @timeout(0.5)
    def test_case_2(self):
        prices, output = self.__testCases[2]
        result = self.__obj.finalPrices(prices)
        self.assertIsInstance(result, list)
        self.assertTrue(all(r == o for r, o in zip(result, output)))

if __name__ == '__main__': unittest.main()