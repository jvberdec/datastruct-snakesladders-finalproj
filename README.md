# datastruct-snakesladders-finalproj
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		SNAKES AND LADDERS
================================================
Algorithms: BFS, DFS and Iterative Deepening Search

Running 'main_snakes.cpp' will execute the program. 
You will discover the number of nodes considered, paths to victory and the maxDepth for the IDS search.

In file 'main_snakes.cpp', you may gain access to all neighbors beginning at LINE 12:

std::vector<int> neighbors = tree->getNeighbors(1);
cout << "TESTING NEIGHBOR DISPLAY: ";
   // TEST:: DISPLAYING NEIGHBORS
   for (int i = 0; i < neighbors.size(); ++i){
     cout << neighbors[i] << " ";
  } 

Note: Entering tree->getNeighbors(100) returns an empty vector as 100 is the winning place and no other moves are allowed

BFS and IDS can accept integer parameters: 1, 14, 74, 76, 98, 100 since that is along the parent path created that is the fastest path to victory. You may modify this in the 'main_snakes.cpp' file.

If you'd like to actually SEE all nodes considered in IDS, in 'tree.cpp' file, uncomment line 163. You will go through MANY nodes.
