The goal is to find the value of `x` that gives the minimum of this function using a probabilistic optimization approach inspired by the physical process of annealing.

## What is Simulated Annealing?

Simulated Annealing is a metaheuristic optimization algorithm inspired by the cooling of metals. It is designed to escape local optima by accepting worse solutions with a probability that decreases over time. As the system "cools," the algorithm becomes more conservative in its choices, ideally converging to a global optimum.

## How the Code Works

- **Objective Function**: `f(x) = x²`, which we aim to minimize.
- **Solution Representation**: A class `State` represents a potential solution `x`.
- **Successor Function**: Generates a nearby solution by adding a small random delta to `x`.
- **Temperature Schedule**: Temperature decreases as `T = 1000 / t`, where `t` is the iteration count.
- **Acceptance Criteria**:
  - If the new state is better, accept it.
  - If worse, accept with probability `exp(deltaE / T)`.

The algorithm terminates after 10,000 iterations or when the temperature approaches zero.
