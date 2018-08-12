from unittest import TestCase

from leetcodepy.text_justification import *

solution1 = Solution1()

words1 = ["This", "is", "an", "example", "of", "text", "justification."]

max_width1 = 16

expected1 = [
    "This    is    an",
    "example  of text",
    "justification.  "
]

words2 = ["What", "must", "be", "acknowledgment", "shall", "be"]

max_width2 = 16

expected2 = [
    "What   must   be",
    "acknowledgment  ",
    "shall be        "
]

words3 = ["Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
          "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"]

max_width3 = 20

expected3 = [
    "Science  is  what we",
    "understand      well",
    "enough to explain to",
    "a  computer.  Art is",
    "everything  else  we",
    "do                  "
]


class TestTextJustification(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.fullJustify(words1, max_width1))
        self.assertListEqual(expected2, solution1.fullJustify(words2, max_width2))
        self.assertListEqual(expected3, solution1.fullJustify(words3, max_width3))
