import heapq

def ucs(graph, start, goal):
    visited = set()
    pq = []
    
    heapq.heappush(pq, (0, start, [start]))  
    
    while pq:
        cost, node, path = heapq.heappop(pq)
        
        if node in visited:
            continue
            
        print(f"Visited: {node} with cost: {cost}")
        visited.add(node)
        
        if node == goal:
            print("Goal reached!")
            return cost, path
        
        for neighbour, edge_cost in graph[node]:
            if neighbour not in visited:
                heapq.heappush(pq, (cost + edge_cost, neighbour, path + [neighbour]))
                
    return None, []

graph = {
    'A': [('B', 2), ('C', 4)],
    'B': [('D', 7), ('E', 3)],
    'C': [('F', 5)],
    'D': [],
    'E': [('G', 2)],
    'F': [],
    'G': []
}

start_node = 'A'
goal_node = 'G'

print(f"Running UCS from {start_node} to {goal_node}...\n")
cost, path = ucs(graph, start_node, goal_node)

print("\nFinal path:", " -> ".join(path))
print("Total cost:", cost)
