# 1233. Remove Sub-Folders from the Filesystem
# https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description

from typing import *

# 1. Trie
# 각 노드가 폴더 이름인 Trie를 구성한다.
# Trie에서 DFS를 통해서 각 경로별로 1번째로 만나는 폴더를 반환한다.

# 2. startswith
# 폴더 리스트를 길이 순으로 오름차순 정렬하면, 정확한 폴더 깊이별 비교가 되는 것은 아니지만, 적어도 서브폴더가 부모폴더보다는 뒤에 위치한다.
# 부모폴더를 일일이 비교하게 되면 O(n^2)이 되므로 시간 복잡도 측면에서 좋지 않음.

# 3. 순회하면서 직접 비교
# 마찬가지로 오름차순 정렬
# 문자열을 직접 탐색하면서 기존에 나왔는지 비교한다.

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        visited = set()

        for f in sorted(folder):
            parentExists = False

            for i in range(1, len(f)):
                if i < len(f) and f[i] == "/" and f[:i] in visited:
                    parentExists = True
                    break

            if not parentExists:
                visited.add(f)

        return list(visited)
