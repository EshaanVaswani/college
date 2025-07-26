import random

def genetic_algorithm(population_size, mutation_rate, crate, n):
    initial_population = [[random.randint(0, 10) for _ in range(n)] for _ in range(population_size)]
    print("Initial Population:")
    for chromosome in initial_population:
        print(chromosome)

    population = initial_population
    generation = 0  

    while True:
        generation += 1
        fitness_values = [fitness(chromosome) for chromosome in population]
        best_chromosome = population[fitness_values.index(min(fitness_values))]

        if min(fitness_values) == 0:
            print("\nFinal Population:")
            for chromosome in population:
                print(chromosome)
            print(f"\n Optimal Solution found after {generation} 1Generations!")
            return best_chromosome

        weights = [1 / (f + 1) for f in fitness_values]
        selected_population = random.choices(population, weights=weights, k=population_size)

        next_generation = []
        for _ in range(population_size // 2):
            p1, p2 = random.sample(selected_population, 2)
            child1, child2 = crossover(p1, p2, crate)
            next_generation.extend([child1, child2])

        for individual in next_generation:
            mutation(individual, mutation_rate)

        population = next_generation

def fitness(variables):
    a, b, c, d = variables
    return abs((a + 2 * b + 3 * c + 4 * d) - 30)

def crossover(p1, p2, crate):
    if random.random() < crate:
        crossover_point = random.randint(1, len(p1) - 1)
        return p1[:crossover_point] + p2[crossover_point:], p2[:crossover_point] + p1[crossover_point:]
    return p1[:], p2[:]

def mutation(individual, mutation_rate):
    for i in range(len(individual)):
        if random.random() < mutation_rate:
            individual[i] = random.randint(0, 10)


population_size = 6
mutation_rate = 0.1
crate = 0.8
num_variables = 4
best_chromosome = genetic_algorithm(population_size, mutation_rate, crate, num_variables)
print("\nBest solution:", best_chromosome)


