# Summer 2019
# Data Structures Final Project: Snakes and Ladders 

Algorithms Implemented: BFS, DFS and Iterative Deepening Search

Running 'main_snakes.cpp' will execute the program. 
Program will indicate number of nodes considered (relaxed), paths to victory and the maxDepth for the IDS search.

In file 'main_snakes.cpp', you may gain access to all neighbors beginning at LINE 12:

std::vector<int> neighbors = tree->getNeighbors(1);
cout << "TESTING NEIGHBOR DISPLAY: ";
   // TEST:: DISPLAYING NEIGHBORS
   for (int i = 0; i < neighbors.size(); ++i){
     cout << neighbors[i] << " ";
  } 

Note: Entering tree->getNeighbors(100) returns an empty vector as 100 is the winning place and no other moves are allowed

BFS and IDS can accept integer parameters: 1, 14, 74, 76, 98, 100 as these nodes are along the parent path created that is the fastest path to victory. You may modify this in the 'main_snakes.cpp' file.

If you'd like to view all nodes considered in IDS, uncomment line 163 in 'tree.cpp' file. You will go through several nodes.
