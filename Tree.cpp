#include "Tree.h"
#include "Board.h"
#include <queue>
#include <stack>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> Tree::getNeighbors(int pos){ // Function to return following dice roll results..
  vector<int> neighbors;
  if(pos == 100){
	  return neighbors;
  }
  int * boardState = board->getBoardState();
  for(int i = 1; i <= 6; ++i){
	int moveBack;
	int inPos = pos + i;
	if (inPos == 97){inPos = 87;}
	if((inPos) > 100){
		moveBack = inPos - 100;
		inPos = 100 - moveBack;
	}
    neighbors.push_back( boardState[inPos] );
  }
  return neighbors;
}

void Tree::orig_printPath_UsingStack(int neighbor, map<int, int> parent){
	cout << "FASTEST PATH TO VICTORY: " << endl;
	stack<int> n; // Push winning place 100 first to print + pop last...
	n.push(neighbor);
	while(true){
		n.push(parent[neighbor]);
		if (parent[neighbor] == 1){
			break;
		}
		neighbor = parent[neighbor];
	}

	int count = 0;
	while (!n.empty()){
		cout << "Move "<< count << ", spot "<< n.top() << endl;
		n.pop();
		++count;
	}
	cout << "Using this search, " << count - 1 << " moves are needed to win this game at the very least." << endl;
}

void Tree::IDS_printPath_UsingStack(int neighbor, map<int, int> parent, int depth){
	cout << "FASTEST PATH TO VICTORY: " << endl;
	stack<int> n;
	int count = 0;
	while(count < depth){
		n.push(neighbor);
		neighbor = parent[neighbor];
		count++;
	}
		n.push(1); // Push starting place 1 to print + pop first...
	count = 0;
	while (!n.empty()){
		cout << "Move "<< count << ", spot "<< n.top() << endl;
		n.pop();
		++count;
	}
	cout << "Using this search, " << count - 1 << " moves are needed to win this game at the very least." << endl;
}


int Tree::BFS(int root, map<int, int> &parent){

	queue<int> queue;
	queue.push(root);
	cout << "Beginning at spot " << root << "." << endl;
	unordered_set<int> queuedUp; // In other words, what has been visited. Unordered set can be faster to find/retrieve elements...
	bool gameFinished = false;
	int count = 0;
	while(queue.size()){ // While queue isn't empty, that is
		if(gameFinished){return count;}
		int node = queue.front();
		queue.pop();
		count++;
		int c = count - 1;
		int Roll = c % 6; // Getting result of every 6 rolls...
		if (Roll == 0){Roll = 6;}
		if (node != 1){cout << "Roll " << Roll << ": Consider landing at spot " << node << "." << endl;}

		std::vector<int> neighbors = getNeighbors(node);
		for (int i = 0; i < neighbors.size(); ++i){
			int neighbor = neighbors[i]; // This will help me use the parent map to print the shortest path to victory...
			if(isWin(neighbor)){
				parent[neighbor] = node; // Parent of the neighbor is the node already popped off the queue... Now populating parent map...
				cout << "Landed in winning position " << neighbor << "!" << endl;
				cout << count << " nodes were considered in the BFS." << endl;

				return count;
			}
			if (queuedUp.find(neighbor) == queuedUp.end()) { // That is, if the neighbor has not been visited...
				queue.push(neighbor); // Added to queue...
				queuedUp.insert(neighbor); // Marking as visited, basically.
				parent[neighbor] = node; // Still populating parent map...
			}
		}
	}
}

bool Tree::DFS(int root, map<int, int> &parent, int &count, unordered_set<int> &visited){
	int Roll = (count - 1) % 6;
	if (Roll == 0){Roll = 6;}
	if (root != 1){cout << "Roll " << Roll << ": Consider landing at spot " << root << "." << endl;}

	if (isWin(root)){
		return true;
	}
	visited.insert(root);
	std::vector<int> neighbors = getNeighbors(root);
	for (int i = 0; i < neighbors.size(); ++i){
		int neighbor = neighbors[i];
		if(visited.find(neighbor) == visited.end()){
			count++;
			parent[neighbor] = root;
			bool foundWin = DFS(neighbor, parent, count, visited);
			if(foundWin){
				return true;
			}
		}
	}
	return false;
}

int Tree::iter_DFS(int root, map<int, int> &parent){
	int maxDepth = 0;
	bool foundWin;
	while(true){
		parent.clear();
		int depth = 0;
		int count = 0;
		int nodesConsidered = 0;
		foundWin = max_depth_DFS(root, parent, count, nodesConsidered, depth, maxDepth);
		if(foundWin == true){
			cout << maxDepth << " is the max Depth...." << endl;
			cout << "Nodes considered: " << nodesConsidered << endl;

			return maxDepth;
		}
		maxDepth++;
	}
}

bool Tree::max_depth_DFS(int root, map<int, int> &parent, int &count, int &nodesConsidered, int depth, int maxDepth){
int roll = count % 6;
if (roll == 0){roll = 6;}
// NOTE: YOU WILL GO THROUGH MANY NODES if you uncomment statement below!!! Shows all nodes considered!!!
// if (root != 1){cout << "Roll " << roll << ": Consider landing at spot " << root << "." << endl;}

	if(maxDepth < 1){
		return false;
	}
	if(isWin(root)){
		return true;
	}
	if(depth == maxDepth){
		return false;
	}
	std::vector<int> neighbors = getNeighbors(root);

	for(int i = 0; i < neighbors.size(); ++i){
		int neighbor = neighbors[i];
			count++;
			nodesConsidered++;
			parent[neighbor] = root;
			bool foundWin = max_depth_DFS(neighbor, parent, count, nodesConsidered, depth + 1, maxDepth);
			if(foundWin){
				//cout << "Nodes considered: " << nodesConsidered << endl;

				return true;
			}
	}
	return false;
}
