from unittest import TestCase

from leetcodepy.text_justification import *

SOLUTION1 = Solution1()

WORDS1 = ["This", "is", "an", "example", "of", "text", "justification."]
MAXWIDTH1 = 16
EXPECTED1 = [
    "This    is    an",
    "example  of text",
    "justification.  "
]

WORDS2 = ["What", "must", "be", "acknowledgment", "shall", "be"]
MAXWIDTH2 = 16
EXPECTED2 = [
    "What   must   be",
    "acknowledgment  ",
    "shall be        "
]

WORDS3 = ["Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
          "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"]
MAXWIDTH3 = 20
EXPECTED3 = [
    "Science  is  what we",
    "understand      well",
    "enough to explain to",
    "a  computer.  Art is",
    "everything  else  we",
    "do                  "
]


class TestTextJustification(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.fullJustify(WORDS1, MAXWIDTH1))
        self.assertListEqual(EXPECTED2, SOLUTION1.fullJustify(WORDS2, MAXWIDTH2))
        self.assertListEqual(EXPECTED3, SOLUTION1.fullJustify(WORDS3, MAXWIDTH3))
