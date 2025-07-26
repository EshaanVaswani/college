import random

def get_random_start():
    return random.uniform(-10, 10)

def get_neighbour(x):
    step = 0.1
    neighbors = []
    if x + step <= 10:
        neighbors.append(x + step)
    if x - step >= -10:
        neighbors.append(x - step)
    return neighbors

def heuristic(x):
    return -x**2 + 10

def hill_climbing(max_iterations=100):
    current = get_random_start()
    print(f"Starting point: {current:.2f} with value {heuristic(current):.2f}")
    
    for i in range(max_iterations):
        neighbours = get_neighbour(current)
        if not neighbours:
            print("No neighbors to explore. Terminating.")
            break
        
        next_state = max(neighbours, key=heuristic)
        
        if heuristic(next_state) <= heuristic(current):
            print(f"Iteration {i+1}: No better neighbor found. Stopping.")
            break
        
        print(f"Iteration {i+1}: Moving from {current:.2f} ({heuristic(current):.2f}) -> {next_state:.2f} ({heuristic(next_state):.2f})")
        current = next_state
    
    print(f"Final state: {current:.2f} with value {heuristic(current):.2f}")
    return current, heuristic(current)

if __name__ == "__main__":
    result, value = hill_climbing()
