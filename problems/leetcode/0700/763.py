# 763. Partition Labels
# https://leetcode.com/problems/partition-labels/description/

from typing import *


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        char_to_start_end = dict()

        for i, ch in enumerate(s):
            if ch in char_to_start_end:
                char_to_start_end[ch][1] = i
            else:
                char_to_start_end[ch] = [i, i]

        ranges = list(char_to_start_end.values())
        current_start, current_end = ranges[0]
        partition = []

        for start, end in sorted(ranges):
            if current_end < start:
                partition.append(current_end - current_start + 1)
                current_start = start
                current_end = end
            else:
                current_end = max(current_end, end)

        partition.append(current_end - current_start + 1)
        return partition
