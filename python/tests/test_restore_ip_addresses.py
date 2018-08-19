from unittest import TestCase

from leetcodepy.restore_ip_addresses import *

solution1 = Solution1()

s = "25525511135"

expected = ["255.255.11.135", "255.255.111.35"]


class TestRestoreIPAddresses(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.restoreIpAddresses(s))
