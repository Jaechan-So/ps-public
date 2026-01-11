# 735. Asteroid Collision
# https://leetcode.com/problems/asteroid-collision/description/

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        result = []

        for asteroid in asteroids:
            if not result or result[-1] < 0 or asteroid > 0:
                result.append(asteroid)
                continue

            while True:
                if not result or result[-1] < 0:
                    result.append(asteroid)
                    break
                elif result[-1] > -asteroid:
                    break
                else:
                    last = result.pop()
                    if last == -asteroid:
                        break

        return result
