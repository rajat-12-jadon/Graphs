# Graphs - Day 02

## Topics Covered
- Revision of BFS
- Connected Components concept
- DFS traversal idea
- Graph traversal practice

Teacher was on leave today, so the focus was mainly on revising the previous concepts and solving a couple of practice problems.

---

# 1. Connected Components

A connected component is a group of nodes where every node is reachable from any other node in the group.

Example:

0 -- 1 -- 2

3 -- 4

Components:

Component 1 → {0,1,2}  
Component 2 → {3,4}

Connected components can be found using:

- **BFS**
- **DFS**

---

# 2. Number of Provinces (LeetCode)

This problem is based on **Connected Components in a Graph**.

Input is given as an **Adjacency Matrix**.

Idea:

1. Traverse every city
2. If city is not visited → start DFS/BFS
3. Mark all connected cities visited
4. Increase province count

Key Insight:
Number of Provinces = Number of Connected Components


---

# 3. Keys and Rooms (LeetCode)

Rooms represent nodes in a graph.

Keys represent edges that allow you to visit other rooms.

Goal: check if **all rooms can be visited starting from room 0**.

Approach:

1. Start from room 0
2. Use DFS/BFS
3. Visit rooms using keys
4. Check if all rooms are visited

Key Idea:

---

# 3. Keys and Rooms (LeetCode)

Rooms represent nodes in a graph.

Keys represent edges that allow you to visit other rooms.

Goal: check if **all rooms can be visited starting from room 0**.

Approach:

1. Start from room 0
2. Use DFS/BFS
3. Visit rooms using keys
4. Check if all rooms are visited

Key Idea:
Graph Reachability Problem


---

# Problems Solved

1. **Number of Provinces** – LeetCode
2. **Keys and Rooms** – LeetCode

---

# Key Learnings

- Connected components can be found using BFS or DFS
- Graphs can be represented using adjacency matrix or adjacency list
- DFS is useful for traversal and reachability problems
- Many graph problems reduce to traversal of nodes

