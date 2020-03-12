#ifndef TREE_GUARD
#define TREE_GUARD
#include <vector>
#include <map>
#include <unordered_set>
#include "Board.h"

using std::vector;
using std::map;
using std::unordered_set;

class Tree{
private:
   Board *board;
public:
  Tree() { board = new Board(); } // Creates board instance
  vector<int> getNeighbors(int pos); // Returns a vector of 6 possible board states.
  bool isWin(int pos) { return pos == 100;} // Boolean function to check win.
  
  int BFS(int root, map<int, int> &parent); // Breadth First Search
  bool DFS(int root, map<int, int> &parent, int &count, unordered_set<int> &visited); // Depth First Search
  
 
  int iter_DFS(int root, map<int, int> &parent); // Iterative Deepening Search... NOTE: YOU WILL GO THROUGH MANY NODES if you uncomment "Consider nodes..."
  bool max_depth_DFS(int root, map<int, int> &parent, int &count, int &nodesConsidered, int depth, int maxDepth); // Helper function for IDS
  
  
  void orig_printPath_UsingStack(int neighbor, map<int, int> parent); // Prints winning path by reversing the stack for BFS and DFS.
  void IDS_printPath_UsingStack(int neighbor, map<int, int> parent, int depth); // Prints winning path by reversing the stack for IDS.
};

#endif
