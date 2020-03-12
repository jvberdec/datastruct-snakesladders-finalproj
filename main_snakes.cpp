#include "Board.h"
#include "Tree.h"
#include <iostream>
using namespace std;

int main(){

  Tree * tree = new Tree();
  Board * board = new Board();

  // TEST:: Returns a vector representing the 6 dice roll possibilities from place 1.
std::vector<int> neighbors = tree->getNeighbors(1); // Get access to all neighbors from each spot in board game... just change parameter integer to a different spot in game. 
cout << "TESTING NEIGHBOR DISPLAY: ";

	// TEST:: DISPLAYING NEIGHBORS
   for (int i = 0; i < neighbors.size(); ++i){
     cout << neighbors[i] << " ";
  }
 
 cout << endl << endl;

  map<int, int> parent;
  	cout << "~!!!::BEGINNING BFS::!!!~" << endl;

  tree->BFS(1, parent); // Implementing BFS, starting at place 1.
  tree->orig_printPath_UsingStack(100, parent); // Print winning path BFS
  cout << endl << endl;

  int count = 1;

  parent.clear();
  unordered_set<int> visited;
  	cout << "~!!!::BEGINNING DFS::!!!~" << endl;

  cout << "Beginning at spot 1." << endl;
  if (tree->DFS(1, parent, count, visited) ) { // Implementing DFS, starting at place 1.
      cout<< count << " nodes were considered in the DFS." << endl;
  }
  else {
	  cout << "100 not found" << endl;
  }
  tree->orig_printPath_UsingStack(100, parent); // Print winning path DFS
  cout << endl << endl;


  parent.clear();

  cout << "~!!!::BEGINNING IDS::!!!~" << endl;
  cout << "Beginning at spot 1." << endl;
  int depth = tree->iter_DFS(1, parent); // Implementing DFS, starting at place 1.
  tree->IDS_printPath_UsingStack(100, parent, depth); // Print winning path IDS


  delete tree;
  delete board;

  return 0;

}
