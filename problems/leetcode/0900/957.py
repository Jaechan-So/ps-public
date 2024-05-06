# 957. Prison Cells After N Days
# https://leetcode.com/problems/prison-cells-after-n-days/description/

# 1. Naive Approach: O(n) (8n) 만큼 순회하면서 규칙대로 전부 바꿈. n이 1e9까지 가능하므로 TLE 예상됨
# 2. 2^8 = 256가지의 경우의 수가 있고, transition은 반드시 단방향이다. (Directed Graph)
# 그렇기 때문에 규칙성 비스무리한게 있지 않을까 생각됨.
# 처음으로 Cycle을 감지하면, 나머지를 이용해서 쉽게 알 수 있을듯 함.

from typing import *


class Solution:
    def cell_to_int(self, cells: List[int]) -> int:
        result = 0

        for i, cell in enumerate(cells):
            result += cell * (1 << (7 - i))

        return result

    def int_to_cell(self, n: int) -> List[int]:
        cell_state = []

        for i in range(0, 8):
            cell_state.append((n // (1 << (7 - i))) % 2)

        return cell_state

    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:
        cell_to_index = dict()

        def transit_cell_state(cells: List[int]):
            new_cell_state = [0]

            for i in range(1, 7):
                new_cell_state.append(1 if cells[i - 1] == cells[i + 1] else 0)

            new_cell_state.append(0)
            return new_cell_state

        while n > 0:
            cell_state_int = self.cell_to_int(cells)

            if cell_state_int in cell_to_index:
                start, end = cell_to_index[cell_state_int], n + 1
                cycle_size = start - end + 1
                remainder = n % cycle_size
                final_index = start - remainder

                for cell_int, index in cell_to_index.items():
                    if index == final_index:
                        return self.int_to_cell(cell_int)

                return cells
            else:
                cell_to_index[cell_state_int] = n

            n -= 1
            cells = transit_cell_state(cells)

        return cells
