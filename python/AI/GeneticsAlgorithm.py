
# Import the random module
import random

# Define a function to generate a random initial population of 15 solutions
def generate_population():
    population = []
    for i in range(15):
        solution = []
        for j in range(8):
            solution.append(random.randint(0, 7)) # Append a random number between 0 and 7
        population.append(solution)
    return population

# Define a function to calculate the fitness score of a solution
def fitness_score(solution):
    score = 0
    for i in range(8):
        for j in range(i + 1, 8):
            # Check if two queens are in the same row, column or diagonal
            if solution[i] == solution[j] or abs(i - j) == abs(solution[i] - solution[j]):
                score += 1
    return score

# Define a function to perform the crossover operation on two parents
def crossover(parent1, parent2):
    # Choose a random crossover point
    point = random.randint(1, 6)
    # Create two offspring by swapping the parts of the parents
    child1 = parent1[:point] + parent2[point:]
    child2 = parent2[:point] + parent1[point:]
    return child1, child2

# Define a function to perform the mutation operation on a child
def mutation(child):
    # Choose a random position and a random value
    position = random.randint(0, 7)
    value = random.randint(0, 7)
    # Replace the value at the position with the new value
    child[position] = value
    return child

# Define a function to find the best solution in a population
def find_best(population):
    best_score = float('inf')
    best_solution = None
    for solution in population:
        score = fitness_score(solution)
        if score < best_score:
            best_score = score
            best_solution = solution
    return best_solution, best_score

# Define a function to solve the 8 queens problem using genetic algorithm
def solve_8_queens():
    # Generate an initial population
    population = generate_population()
    # Set a maximum number of iterations
    max_iter = 100
    # Set a flag to indicate if a solution is found
    found = False
    # Loop until a solution is found or the maximum number of iterations is reached
    for i in range(max_iter):
        # Find the best solution and its score in the current population
        best_solution, best_score = find_best(population)
        # Print the best solution and its score
        print(f"Iteration {i + 1}: {best_solution}, score: {best_score}")
        # Check if the best score is zero, meaning a solution is found
        if best_score == 0:
            found = True
            break
        # Select the two best solutions as parents
        parent1 = best_solution
        parent2 = find_best([s for s in population if s != parent1])[0]
        # Perform the crossover operation on the parents
        child1, child2 = crossover(parent1, parent2)
        # Perform the mutation operation on the children
        child1 = mutation(child1)
        child2 = mutation(child2)
        # Replace the two worst solutions in the population with the children
        population.sort(key=fitness_score, reverse=True)
        population[0] = child1
        population[1] = child2
    # Return the best solution and the flag
    return best_solution, found

# Call the solve_8_queens function and print the result

solution, found = solve_8_queens()
if found:
    print(f"A solution is found: {solution}")
else:
    print("No solution is found")

