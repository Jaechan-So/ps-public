# 227. Basic Calculator II
# https://leetcode.com/problems/basic-calculator-ii/description/

class Solution:
    def calculate(self, s: str) -> int:
        numbers, operators = [], []

        for ch in s:
            if ch == " ":
                continue
            elif ch.isdigit():
                if len(numbers) == len(operators):
                    numbers.append(int(ch))
                else:
                    numbers[-1] *= 10
                    numbers[-1] += int(ch)
            else:
                while len(operators) > 0 and (operators[-1] == "*" or operators[-1] == "/"):
                    numbers[-2] = numbers[-2] * numbers[-1] if operators[-1] == "*" else numbers[-2] // numbers[-1]
                    numbers.pop()
                    operators.pop()
                operators.append(ch)

        while len(operators) > 0 and (operators[-1] == "*" or operators[-1] == "/"):
            numbers[-2] = numbers[-2] * numbers[-1] if operators[-1] == "*" else numbers[-2] // numbers[-1]
            numbers.pop()
            operators.pop()

        result = numbers[0]
        for i in range(len(operators)):
            if operators[i] == "+":
                result += numbers[i + 1]
            else:
                result -= numbers[i + 1]

        return result
