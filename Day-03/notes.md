# Graphs - Day 03

## Topics Covered
- Grid BFS
- Multi-source BFS
- Graph Reachability
- Graph Properties
- Bipartite Graph Concept

Today we solved several graph problems during class and a couple of homework problems to practice BFS-based traversal.

---

# 1. Grid BFS

Many graph problems are represented using a **2D grid**.

Each cell behaves like a **node**, and edges exist between neighboring cells.

Common directions used in grid problems:

Up → (r-1, c)  
Down → (r+1, c)  
Left → (r, c-1)  
Right → (r, c+1)

Sometimes problems also allow **8 directions** (including diagonals).

---

# 2. Multi-Source BFS

Instead of starting BFS from one node, we start BFS from **multiple sources simultaneously**.

Example: **Rotten Oranges**

Idea:

1. Push all rotten oranges into the queue
2. Start BFS from all of them
3. Each level represents **time passing**
4. Convert adjacent fresh oranges into rotten

Key Insight:
# Graphs - Day 03

## Topics Covered
- Grid BFS
- Multi-source BFS
- Graph Reachability
- Graph Properties
- Bipartite Graph Concept

Today we solved several graph problems during class and a couple of homework problems to practice BFS-based traversal.

---

# 1. Grid BFS

Many graph problems are represented using a **2D grid**.

Each cell behaves like a **node**, and edges exist between neighboring cells.

Common directions used in grid problems:

Up → (r-1, c)  
Down → (r+1, c)  
Left → (r, c-1)  
Right → (r, c+1)

Sometimes problems also allow **8 directions** (including diagonals).

---

# 2. Multi-Source BFS

Instead of starting BFS from one node, we start BFS from **multiple sources simultaneously**.

Example: **Rotten Oranges**

Idea:

1. Push all rotten oranges into the queue
2. Start BFS from all of them
3. Each level represents **time passing**
4. Convert adjacent fresh oranges into rotten

Key Insight:
Multi-source BFS helps simulate spreading processes.


---

# 3. Graph Reachability

Some problems ask whether it is possible to **reach one node from another**.

Example: **Check if Valid Path Exists**

Approach:

1. Build adjacency list
2. Use BFS or DFS
3. Check if destination node becomes visited

This is a simple **graph traversal problem**.

---

# 4. Graph Property Problems

Some problems are based on properties of graphs rather than traversal.

Example: **Find the Center of a Star Graph**

In a star graph:

- One node connects to all others
- Center node has degree **n - 1**

So the node appearing in **both edges** is the center.

Example:
Edges = [[1,2], [2,3], [4,2]]

Center = 2


---

# 5. Surrounding Regions

This is a **grid traversal problem**.

Goal: capture regions surrounded by 'X'.

Key idea:

1. Boundary 'O' cells cannot be captured
2. Start BFS/DFS from boundary 'O'
3. Mark them as safe
4. Convert remaining 'O' → 'X'

Insight:
Boundary connected regions must remain unchanged.


---

# Homework Problems

## 1. 01 Matrix

Goal: find the distance of each cell from the nearest **0**.

Approach:

1. Push all cells containing **0** into queue
2. Run **multi-source BFS**
3. Update distance for each neighbor

Insight:
Multi-source BFS gives shortest distance from nearest source.


---

## 2. Is Graph Bipartite?

A graph is **bipartite** if nodes can be divided into **two groups** such that no two adjacent nodes belong to the same group.

Approach:

1. Use BFS or DFS
2. Color nodes with two colors (0 and 1)
3. If two adjacent nodes have same color → not bipartite

Insight:
Bipartite Graph = Graph with no odd length cycle.


---

# Problems Solved

### Class Problems
1. Rotten Oranges
2. Check if Valid Path Exists in Graph
3. Find the Center of a Star Graph
4. Surrounded Regions

### Homework Problems
5. 01 Matrix
6. Is Graph Bipartite?

---

# Key Learnings

- Grid problems can be solved using BFS traversal
- Multi-source BFS is useful when multiple starting points exist
- Graph reachability can be checked using BFS or DFS
- Some graph problems rely on graph properties instead of traversal
- Bipartite graphs can be detected using coloring during traversal
