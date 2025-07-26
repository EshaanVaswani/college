import heapq

def bestfs(graph, start, goal, heuristic):
    open_list = []

    heapq.heappush(open_list, (heuristic[start], start))
    
    parent = {start: None}
    
    while open_list:
        _, current_node = heapq.heappop(open_list)
        
        print(f"Visited: {current_node}")
        
        if current_node == goal:
            path = []
            while current_node is not None:
                path.append(current_node)
                current_node = parent[current_node]
            path.reverse()
            return path
        
        for neighbor in graph[current_node]:
            if neighbor not in parent:
                heapq.heappush(open_list, (heuristic[neighbor], neighbor))
                parent[neighbor] = current_node
    
    return None

graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'G'],
    'F': ['C'],
    'G': ['E']
}

heuristic = {
    'A': 6,
    'B': 5,
    'C': 4,
    'D': 3,
    'E': 2,
    'F': 1,
    'G': 0
}


start_node = 'A'
goal_node = 'G'

path = bestfs(graph, start_node, goal_node, heuristic)

print("\nPath from", start_node, "to", goal_node, ":")
print(" -> ".join(path) if path else "No path found")
