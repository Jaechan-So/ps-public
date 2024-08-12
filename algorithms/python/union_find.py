class UnionFind:
    def __init__(self, n: int):
        self.n = n
        self.parent = list(range(n))
        self.rank = [1] * n

    def find(self, i: int) -> int:
        # Path Compression
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    # Union by Rank
    def merge(self, i: int, j: int) -> None:
        pi, pj = self.find(i), self.find(j)
        if self.rank[pi] < self.rank[pj]:
            pi, pj = pj, pi

        if self.rank[pi] == self.rank[pj]:
            self.rank[pi] += 1
        self.parent[pj] = pi

def test():
    uf = UnionFind(n=5)
    uf.merge(0, 1)
    assert uf.rank[0] == 2
    assert uf.find(0) == 0
    assert uf.find(1) == 0

    uf.merge(2, 3)
    assert uf.find(3) == 2

    uf.merge(1, 3)
    assert uf.find(2) == 0
    assert uf.find(3) == 0
    assert uf.rank[0] == 3

    print("Test Passed!")
    return

if __name__ == "__main__":
    test()
