# 588. Design In-Memory File System
# https://leetcode.com/problems/design-in-memory-file-system/

class File:

    def __init__(self, name: str, content: str = None):
        self.name = name
        self.content = content

    def add(self, content: str):
        self.content += content

class Directory:

    def __init__(self):
        self.children = dict()

    def add(self, key: str, value: Union[File, Directory]):
        if key not in self.children:
            self.children[key] = value

    def exist(self, key: str):
        return key in self.children

    def getNames(self) -> List[str]:
        return [n for n in self.children.keys()]

class FileSystem:

    def __init__(self):
        self.root = Directory()

    def ls(self, path: str) -> List[str]:
        node = self.root

        for n in path.split("/")[1:]:
            if n != "":
                node = node.children[n]

        if isinstance(node, File):
            return [node.name]

        return [n for n in sorted(node.getNames())]

    def mkdir(self, path: str) -> None:
        node = self.root

        for n in path.split("/")[1:]:
            if n not in node.children:
                node.add(n, Directory())
            node = node.children[n]

    def addContentToFile(self, filePath: str, content: str) -> None:
        paths = filePath.split("/")[1:]
        fileName = paths[-1]
        node = self.root

        for n in paths[:-1]:
            node = node.children[n]

        if node.exist(fileName):
            node.children[fileName].add(content)
            return

        node.add(fileName, File(fileName, content))

    def readContentFromFile(self, filePath: str) -> str:
        node = self.root

        for n in filePath.split("/")[1:]:
            node = node.children[n]

        return node.content


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
