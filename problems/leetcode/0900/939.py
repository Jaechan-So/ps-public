# 939. Minimum Area Rectangle
# https://leetcode.com/problems/minimum-area-rectangle/description/

from typing import *


class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        x_to_y = dict()
        for x, y in points:
            if x in x_to_y:
                x_to_y[x].append(y)
            else:
                x_to_y[x] = [y]

        y_pair_to_x = dict()
        for x, ys in x_to_y.items():
            for i in range(len(ys)):
                for j in range(i + 1, len(ys)):
                    y1, y2 = min(ys[i], ys[j]), max(ys[i], ys[j])

                    if (y1, y2) in y_pair_to_x:
                        y_pair_to_x[(y1, y2)].append(x)
                    else:
                        y_pair_to_x[(y1, y2)] = [x]

        min_area = 1e10
        for (y1, y2), xs in y_pair_to_x.items():
            sorted_xs = sorted(xs)
            for i in range(len(sorted_xs) - 1):
                min_area = min(
                    min_area, abs(y1 - y2) * abs(sorted_xs[i] - sorted_xs[i + 1])
                )

        return min_area if min_area != 1e10 else 0
