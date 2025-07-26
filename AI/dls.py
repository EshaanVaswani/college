def depth_limited_search(graph, start, goal, depth_limit):
    if start == goal:
        return [start]
    if depth_limit == 0:
        return None
    for neighbor in graph.get(start, []):
        path = depth_limited_search(graph, neighbor, goal, depth_limit - 1)
        if path:
            return [start] + path
    return None

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
depth_limit = 3

path = depth_limited_search(graph, start_node, goal_node, depth_limit)

if path:
    print(f"Path found: {' -> '.join(path)}")
else:
    print(f"No path found within depth limit {depth_limit}.")
