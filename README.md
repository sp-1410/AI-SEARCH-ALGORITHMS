# AI-SEARCH-ALGORITHMS


This repository presents a comprehensive collection of 15 graph search algorithm implementations in C++, applied to a common weighted, undirected graph structure.
The purpose is to demonstrate and compare a variety of Artificial Intelligence search strategies — ranging from exhaustive uninformed methods to efficient heuristic-driven approaches — under consistent conditions.

List of Implemented Algorithms
1. British Museum Search (BMS)
Performs exhaustive enumeration of all possible paths, selecting the shortest one. Guarantees optimality but has high computational cost.

2. Depth-First Search (DFS)
Traverses as deep as possible before backtracking. Space-efficient, but does not guarantee shortest paths.

3. Breadth-First Search (BFS – Uniform Cost Search)
Explores nodes level-by-level or cost-by-cost (in weighted graphs) to guarantee optimal shortest paths.

4. Iterative Deepening Depth-First Search (IDDFS)
Combines DFS’s low memory usage with BFS’s completeness by gradually increasing search depth.

5. DFS with History
DFS enhanced with a visited-node set, preventing cycles and redundant exploration.

6. BFS with History
BFS with visited-node tracking for improved efficiency by avoiding unnecessary re-expansion.

7. Hill Climbing (HC)
Greedy approach that expands the neighbor with the best heuristic value. Fast, but prone to getting stuck in local optima.

8. Hill Climbing with History
HC augmented with visited-node tracking to reduce cycles and improve search robustness.

9. Beam Search (BS)
Keeps only the k most promising nodes at each depth (beam width), trading completeness for efficiency.

10. Beam Search with History
BS combined with visited-node tracking to prevent duplicate exploration.

11. Oracle Search
Assumes perfect knowledge of the shortest path for benchmarking purposes.

12. Branch and Bound (B&B)
Prunes any path whose cost exceeds the best known solution so far, improving search efficiency.

13. Cost + Estimated Heuristics + Branch and Bound
Augments B&B with heuristic estimates to further reduce the search space while maintaining optimality.

14. Branch and Bound + Heuristic + Open/Closed Lists
Combines B&B with heuristic ordering and Node expansion management using open/closed lists.

15. A* Search
Integrates actual cost and heuristic estimates to find the optimal path efficiently. Optimal with admissible heuristics.

Each .cpp file runs independently using the same weighted graph with five nodes and predefined heuristics for search algorithms that require them.
