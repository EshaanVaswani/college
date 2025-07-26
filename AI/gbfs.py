import heapq

def gbfs(graph, heuristics, start, goal):
    pq = [(heuristics[start], start)]
    visited = set()
    parent = {start: None}

    while pq:
        _, node = heapq.heappop(pq)
        if node in visited:
            continue
        print(f"Visited: {node}")
        if node == goal:
            path = []
            while node is not None:
                path.append(node)
                node = parent[node]
            path.reverse()
            print(f"\nGoal {goal} reached!")
            print("Path:", " -> ".join(path))
            return
        visited.add(node)

        for neighbor, _ in graph.get(node, []):
            if neighbor not in visited:
                heapq.heappush(pq, (heuristics[neighbor], neighbor))
                if neighbor not in parent:
                    parent[neighbor] = node

    print(f"No path found from {start} to {goal}.")


graph = {
    'A': [('B', 1), ('C', 1)],
    'B': [('D', 1), ('E', 1)],
    'C': [('F', 1)],
    'D': [],
    'E': [('G', 1)],
    'F': [],
    'G': []
}

heuristics = {
    'A': 6,
    'B': 4,
    'C': 5,
    'D': 9,   
    'E': 2,
    'F': 9,   
    'G': 0    
}

start_node = 'A'
goal_node = 'G'

print(f"Greedy Best First Search from {start_node} to {goal_node}:\n")
gbfs(graph, heuristics, start_node, goal_node)
