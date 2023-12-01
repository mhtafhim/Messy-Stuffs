import heapq

class Node:
    def __init__(self, state, parent, cost, heuristic):
        self.state = state
        self.parent = parent
        self.cost = cost
        self.heuristic = heuristic

    def __lt__(self, other):
        return (self.cost + self.heuristic) < (other.cost + other.heuristic)

def best_first_search(start, goal, heuristic):
    closed_list = set()
    open_list = [Node(start, None, 0, heuristic(start))]
    
    while open_list:
        current_node = heapq.heappop(open_list)
        current_state = current_node.state
        
        if current_state in closed_list:
            continue

        closed_list.add(current_state)

        if current_state == goal:
            path = []
            while current_node:
                path.append(current_node.state)
                current_node = current_node.parent
            return path[::-1]

        for successor, cost in successors(current_state):
            if successor not in closed_list:
                new_node = Node(successor, current_node, current_node.cost + cost, heuristic(successor))
                heapq.heappush(open_list, new_node)

    return None


def successors(state):
    graph = {'A': [('B', 5), ('C', 2)], 'B': [('D', 3)], 'C': [('D', 4)], 'D': []}
    return graph.get(state, [])

def heuristic(state):
    distances = {'A': 2, 'B': 1, 'C': 1, 'D': 0}
    return distances[state]

start_state = 'A'
goal_state = 'D'

result = best_first_search(start_state, goal_state, successors, heuristic)

if result:
    print(f"Path from {start_state} to {goal_state}: {result}")
else:
    print("Goal not reachable.")
