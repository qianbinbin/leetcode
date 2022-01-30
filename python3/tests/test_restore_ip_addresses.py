from unittest import TestCase

from leetcodepy.restore_ip_addresses import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

S1 = "25525511135"
EXPECTED1 = ["255.255.11.135", "255.255.111.35"]

S2 = "0000"
EXPECTED2 = ["0.0.0.0"]

S3 = "101023"
EXPECTED3 = ["1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"]


class TestRestoreIPAddresses(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.restoreIpAddresses(S1))
        self.assertListEqual(EXPECTED2, SOLUTION1.restoreIpAddresses(S2))
        self.assertListEqual(EXPECTED3, SOLUTION1.restoreIpAddresses(S3))

    def test2(self):
        self.assertListEqual(EXPECTED1, SOLUTION2.restoreIpAddresses(S1))
        self.assertListEqual(EXPECTED2, SOLUTION2.restoreIpAddresses(S2))
        self.assertListEqual(EXPECTED3, SOLUTION2.restoreIpAddresses(S3))
