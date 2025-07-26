def depth_limited_search(graph, node, goal, limit):
    if node == goal:
        return [node]
    if limit <= 0:
        return None
    for neighbor in graph.get(node, []):
        path = depth_limited_search(graph, neighbor, goal, limit - 1)
        if path:
            return [node] + path
    return None

def dfid(graph, start, goal):
    depth = 0
    while True:
        path = depth_limited_search(graph, start, goal, depth)
        if path:
            return path
        depth += 1


graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['G'],
    'F': [],
    'G': []
}

start_node = 'A'
goal_node = 'G'

path = dfid(graph, start_node, goal_node)
print("Path:", path)
