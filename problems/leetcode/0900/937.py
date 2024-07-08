# 937. Reorder Data in Log Files
# https://leetcode.com/problems/reorder-data-in-log-files/description/

from typing import *


class LogEntity:
    def __init__(self, log: str, index: int):
        self.log = log
        self.index = index
        self.logType = "digit" if log.split(" ")[1].isdigit() else "letter"

    def __lt__(self, other) -> bool:
        if self.logType != other.logType:
            return self.logType == "letter"
        elif self.logType == "letter":
            selfTokens, otherTokens = self.log.split(" "), other.log.split(" ")
            selfIdentifier, otherIdentifier = selfTokens[0], otherTokens[0]
            selfContents, otherContents = selfTokens[1:], otherTokens[1:]

            for i in range(min(len(selfContents), len(otherContents))):
                if selfContents[i] != otherContents[i]:
                    return selfContents[i] < otherContents[i]
            if len(selfContents) != len(otherContents):
                return len(selfContents) < len(otherContents)
            return selfIdentifier < otherIdentifier
        return self.index < other.index


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        logEntities = [LogEntity(log, i) for i, log in enumerate(logs)]
        return [logEntity.log for logEntity in sorted(logEntities)]
