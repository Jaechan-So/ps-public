# 49. Group Anagrams
# https://leetcode.com/problems/group-anagrams/description/

from typing import *

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = dict()

        for s in strs:
            sortedStr = "".join(sorted(s))

            if sortedStr not in anagrams:
                anagrams[sortedStr] = []
            anagrams[sortedStr].append(s)

        return anagrams.values()
