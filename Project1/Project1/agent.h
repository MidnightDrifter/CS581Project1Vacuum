#ifndef AGENT_H
#define AGENT_H
#include "definitions.h"

class Node
{
public:
	Node(int x, int y) :xCoord(x), yCoord(y), isVisited(false), isWall(false) {}
	~Node() {}
	




	int xCoord, yCoord;
	bool isVisited;
	bool isWall;


};

class NodeGraph
{
public:
	
	NodeGraph() {

		for(int i=0;i<wallSize;i++)
		{
			graph.at(i) = std::vector<Node>();

			for (int j = 0; j < wallSize; j++)
			{
				graph.at(i).at(j) = Node(i, j);
			}
		}
	}

	~NodeGraph() {}
	bool isValidNode(int x, int y) { return (x >= 0 && y >= 0 && x < wallSize && y < wallSize); }


	std::vector<std::vector<Node>> graph;
	const int wallSize = 40;

};





class Agent {
  public:
    Agent(int random_seed);
    Action GetAction(Percept p);

	
	//int dirtSucked;
	const int startingX = 20;
	const int startingY = 20;
};

#endif

