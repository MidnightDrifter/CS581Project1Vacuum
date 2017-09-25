#ifndef AGENT_H
#define AGENT_H
#include "definitions.h"
#include <vector>
enum class Direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

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
			graph.push_back( std::vector<Node>());

			for (int j = 0; j < wallSize; j++)
			{
				graph.at(i).push_back( Node(i, j));
			}
		}
	}

	~NodeGraph() {}
	bool isValidNode(int x, int y) { return (x >= 0 && y >= 0 && x < wallSize && y < wallSize); }

	Node& getNode(int x, int y) { return graph[x][y]; }

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
	int currentX, currentY;
	//Assume heading defaults to NORTH
	//REMEMBER:  NORTH = UP, UP = X INCREASES
	//			SOUTH = DOWN, DOWN = X DECREASES
	//			EAST = RIGHT, RIGHT = Y INCREASES
	//			WEST = LEFT, LEFT = Y DECREASES
	Direction dir;// = Direction::NORTH;
	NodeGraph maze;
	std::vector<Node> openList;
};

#endif

