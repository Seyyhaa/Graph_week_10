# Graph_week_10
# Graph Traversal: DFS and BFS

## Overview
This repository contains the implementation of Depth-First Search (DFS) and Breadth-First Search (BFS) algorithms for traversing a graph.

### Graph
The graph used:
- **Vertices**: `{0, 1, 2, 3, 4}`
- **Edges**: `{(0, 1), (0, 4), (1, 2), (1, 3), (3, 4)}`

### Graph Representation
The graph is represented using an adjacency list for efficiency.

## Implementation
### Algorithms
1. **DFS (Recursive and Iterative)**:
   - Traverses as far as possible along each branch before backtracking.
2. **BFS**:
   - Explores neighbor nodes level by level.

### Results
- **DFS (Recursive)**: `0 1 2 3 4`
- **DFS (Iterative)**: `0 1 2 3 4`
- **BFS**: `0 1 4 2 3`

