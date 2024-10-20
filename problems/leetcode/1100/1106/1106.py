# 1106. Parsing A Boolean Expression
# https://leetcode.com/problems/parsing-a-boolean-expression/description

class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        n = len(expression)
        return self.parseBoolExprRecurr(expression, 0)[0]

    def parseBoolExprRecurr(self, expression: str, left: str) -> tuple[bool, int]:
        if expression[left] == "t":
            return True, left + 1
        elif expression[left] == "f":
            return False, left + 1
        elif expression[left] == "!":
            result, right = self.parseBoolExprRecurr(expression, left + 2)
            return not result, right + 1
        elif expression[left] in ["&", "|"]:
            result = True if expression[left] == "&" else False
            index = left + 1

            while expression[index] != ")":
                index += 1
                innerResult, index = self.parseBoolExprRecurr(expression, index)
                result = result and innerResult if expression[left] == "&" else result or innerResult

            return result, index + 1
