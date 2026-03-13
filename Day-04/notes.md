# Graphs - Day 04

## Topics Covered
- Depth First Search (DFS)
- Graph Traversal using DFS
- Connected Components
- Grid Traversal using DFS

Today’s focus was understanding **Depth First Search (DFS)** and applying it to different graph and grid problems.

---

# 1. Depth First Search (DFS)

DFS is a graph traversal algorithm that explores a path **as deep as possible before backtracking**.

DFS is usually implemented using:

- **Recursion**
- **Stack (implicitly via recursion)**

### DFS Algorithm

1. Start from a source node
2. Mark it as visited
3. Recursively visit all unvisited neighbors

Example:
0 -- 1 -- 2
|
3


DFS Traversal starting from `0`:


0 → 1 → 2 → backtrack → 3


### Time Complexity


O(V + E)


Where:

- `V` = number of vertices
- `E` = number of edges

---

# 2. DFS of a Graph

Goal: Traverse all vertices of the graph using DFS.

Approach:

1. Start DFS from node `0`
2. Visit neighbors recursively
3. Mark nodes as visited to avoid cycles

This produces a **DFS traversal order**.

---

# 3. Number of Connected Components

Connected components represent groups of nodes where each node is reachable from any other node in the group.

Example:


0 -- 1 -- 2

3 -- 4


Connected Components:


Component 1 → {0,1,2}
Component 2 → {3,4}


Approach:


for each node
if not visited
run DFS
components++


---

# 4. Number of Islands

This problem is a **grid version of connected components**.

Grid cells represent nodes.

DFS is used to explore all connected land cells.

Approach:

1. Traverse the grid
2. If land (`1`) is found
3. Run DFS to mark the entire island visited
4. Increase island count

Key Idea:


Number of Islands = Connected Components in Grid


---

# 5. Flood Fill

Flood Fill is a classic **DFS/BFS grid traversal problem**.

Goal: Change the color of a region starting from a given pixel.

Approach:

1. Start DFS from the starting cell
2. Replace the original color with the new color
3. Continue DFS for neighboring cells with the same color

Applications:

- Image editing tools
- Region detection

---

# 6. 01 Matrix

Goal: Find the **distance of each cell to the nearest 0**.

Observation:

Using DFS or naive BFS from each cell leads to **Time Limit Exceeded (TLE)**.

Optimal solution:


Multi-source BFS


Idea:

1. Push all `0` cells into queue
2. Run BFS simultaneously
3. Update distances for neighboring cells

---

# 7. Rotting Oranges

This problem is another example of **multi-source BFS**.

Goal: Determine the minimum time required to rot all oranges.

Approach:

1. Push all rotten oranges into the queue
2. Run BFS level by level
3. Each level represents **one minute**
4. Convert adjacent fresh oranges into rotten

Key Idea:


Spread simulation using BFS levels


---

# Problems Solved

### DFS Practice
1. DFS of a Graph
2. Number of Connected Components

### Grid DFS Problems
3. Number of Islands
4. Flood Fill

### BFS / Grid Problems
5. 01 Matrix
6. Rotting Oranges

---

# Key Learnings

- DFS explores paths deeply before backtracking
- DFS can be used to find connected components
- Many grid problems are equivalent to graph traversal
- Some problems (like 01 Matrix and Rotting Oranges) are better solved using **multi-source BFS**