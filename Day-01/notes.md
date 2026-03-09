# Graphs - Day 01

## Topics Covered
- Graph Basics
- Graph Representation
- Adjacency Matrix
- Adjacency List
- Breadth First Search (BFS)
- Connected Components
- Number of Islands

---

## Graph Basics

A **Graph** consists of:
- **Vertices (Nodes)**
- **Edges (Connections)**

Example:

0 -- 1  
|  
2 -- 3

---

## Graph Representation

### 1. Adjacency Matrix

A 2D matrix where:

matrix[i][j] = 1 → edge exists  
matrix[i][j] = 0 → no edge

Space Complexity:

O(V²)

---

### 2. Adjacency List

Each vertex stores a list of its neighbors.

Example:

0 → 1 2  
1 → 0  
2 → 0  

Space Complexity:

O(V + E)

---

## Breadth First Search (BFS)

BFS explores nodes **level by level**.

It uses a **Queue**.

### Algorithm

1. Mark source as visited
2. Push source into queue
3. While queue is not empty:
   - Pop node
   - Visit neighbors
   - Push unvisited neighbors

Time Complexity:

O(V + E)

---

## Connected Components

A connected component is a group of nodes where every node is reachable from another.

Example:

0 -- 1 -- 2 -- 3

4

Components:

Component 1 → {0,1,2,3}  
Component 2 → {4}

---

## Number of Islands

This problem is equivalent to **Connected Components in a Grid**.

Grid cells act as nodes.

Connections can be in **8 directions**.

Idea:

1. Traverse grid
2. If land ('L') found → islands++
3. Run BFS/DFS
4. Mark entire island visited

Key Insight:

Number of Islands = Connected Components in a Grid

---

## Problems Solved

1. Graph Introduction Question
2. Number of Islands (GFG)

---

## Key Learnings

- Graphs can be represented using matrix or list
- BFS uses a queue
- Connected components can be found using BFS
- Grid problems can be solved using graph traversal