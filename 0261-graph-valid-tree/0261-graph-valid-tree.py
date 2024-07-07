
class Solution:
    has_cycle = False
    visited = []
    def dfs(self, graph: List[List[int]], node: int):
        if self.visited[node]:
            self.has_cycle = True
        if self.has_cycle:
            return 
        self.visited[node] = True
        for neighbor in graph[node]:
            graph[neighbor].remove(node)
            self.dfs(graph, neighbor)

    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        self.has_cycle = False
        self.visited = [False for _ in range(n)]
        # build graph
        graph = [[] for _ in range(n)]
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
        # has cycle
        self.dfs(graph, 0)
        for v in self.visited:
            if not v: return False
        if self.has_cycle or not self.visited:
            return False
        return True