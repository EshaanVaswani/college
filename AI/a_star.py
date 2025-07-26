import heapq

import heapq

def astar(graph, start, goal, heuristic):
    pq = [(heuristic[start], 0, start)]
    parent = {start: None}
    path_cost = {start: 0}
    visited = set()

    while pq:
        _, current_cost, current_node = heapq.heappop(pq)

        if current_node in visited:
            continue
        print("Visited: ", current_node)
        visited.add(current_node)

        if current_node == goal:
            path = []
            while current_node is not None:
                path.insert(0, current_node)
                current_node = parent[current_node]
            print("\nGoal reached!")
            print("Path:", " -> ".join(path))
            print(f"Total path cost: {path_cost[goal]}")
            return

        for neighbor, edge_cost in graph.get(current_node, []):
            new_cost = current_cost + edge_cost
            if neighbor not in path_cost or new_cost < path_cost[neighbor]:
                path_cost[neighbor] = new_cost
                priority = new_cost + heuristic[neighbor]
                heapq.heappush(pq, (priority, new_cost, neighbor))
                parent[neighbor] = current_node

    print("No path found")

graph = {
    'A': [('B', 2), ('C', 4)],
    'B': [('D', 7), ('E', 3)],
    'C': [('F', 5)],
    'D': [],
    'E': [('G', 2)],
    'F': [],
    'G': []
}

heuristic = {
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

print(f"A* search from {start_node} to {goal_node}:\n")
astar(graph, start_node, goal_node, heuristic)
