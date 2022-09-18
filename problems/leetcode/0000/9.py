# 9. Palindrome Number
# https://leetcode.com/problems/palindrome-number/

class Solution:
    def isPalindrome(self, x: int) -> bool:
        l = list(str(x))
        l.reverse()
        return list(str(x)) == l
