#include <ctime> //for random seed
#include <cmath> 
#include <queue>
#include <stack>
#include "agent.h"

struct Nodes;
struct BoardState;


#define SEARCH_TYPE 0;  //0 = breadth first search, 1 = depth-first search
//#define CONTAINER_TYPE;

#if SEARCH_TYPE==0
#define CONTAINER = std::queue<BoardStates>  //???

#endif

#if SEARCH_TYPE==1

#define CONTAINER = std::stack<BoardStates>

#endif

struct BoardState;


Agent::Agent(int random_seed) : currentX(startingX), currentY(startingY), dir(Direction::NORTH), maze(), openList(1, maze.graph[20][20]) {
  //supplying your own seed may help debugging, same seed will cause 
  //same random number sequence 
  if (random_seed==0) std::srand( static_cast<unsigned>(std::time(0))); // random seed from time
  else                std::srand( random_seed ); // random seed from user
} 




//Search:
/*

1.  Pop board state from openList.  (Assuming initial is pushed on, then immiedately popped)
2.  If goal state, STORE IT SOMEWHERE, return to 1
3.  Else, determine viable, legal moves
4.  Push board state after those moves onto openList (be it a stack or queue).  
5.  LOOP



*/

//Need to keep track of:  # of steps taken, # of dust bunnies cleaned, pointer / reference to previous board state (action taken?)
//ALWAYS ALWAYS ALWAYS end on home space









Action Agent::GetAction(Percept p) {
  //straight-forward beahavior



	if (p.dirt) {
		 return SUCK;
	}


	bool isValid[4] = { maze.isValidNode(currentX+1 , currentY),  maze.isValidNode(currentX-1 , currentY),maze.isValidNode(currentX , currentY + 1),maze.isValidNode(currentX ,currentY - 1) };
	bool isVisited[4] = { (isValid[0]&&maze.getNode(currentX + 1, currentY).isVisited), (isValid[1]&&maze.getNode(currentX - 1,currentY).isVisited),(isValid[2]&& maze.graph[currentX][currentY+1].isVisited),(isValid[3]&& maze.graph[currentX][currentY-1].isVisited) };
	//North node, south node, east node, west node


	//REMEMBER:  NORTH = UP, UP = X INCREASES
	//			SOUTH = DOWN, DOWN = X DECREASES
	//			EAST = RIGHT, RIGHT = Y INCREASES
	//			WEST = LEFT, LEFT = Y DECREASES
	

	if (p.bump) { //return (std::rand() % 5 < 3) ? LEFT : RIGHT;// P(LEFT) = 3/5

		if (dir == Direction::NORTH && isValid[0] )
		{
			maze.graph[currentX + 1][currentY ].isWall = true;
			maze.graph[currentX + 1][currentY].isVisited = true;

		}
		else if (dir == Direction::SOUTH&& isValid[1])
		{
			maze.graph[currentX - 1][currentY ].isWall = true;
			maze.graph[currentX - 1][currentY].isVisited = true;
		}
		else if (dir == Direction::EAST && isValid[2])
		{
			maze.getNode(currentX, currentY + 1).isWall = true;
			maze.getNode(currentX, currentY + 1).isVisited = true;
		}
		else if (dir == Direction::WEST && isValid[3])
		{
			maze.graph[currentX][currentY - 1].isWall = true;
			maze.graph[currentX][currentY - 1].isVisited = true;
		}



	}

  //default rule
  /*
  return (std::rand() % 5 < 3) ? 
               FORWARD :
               ((std::rand() % 2) ? LEFT : RIGHT);

			   */

  if (isValid[0] && !isVisited[0])  //if valid node and north ISN'T VISITED, try and visit north
  {
	  if (dir == Direction::NORTH)
	  {
		    //We must be facing north--onwards!
			  return FORWARD;
		  
	  }

	  if (dir == Direction::EAST)
	  {
		  //Turn to go north--turn left, then forward
		  dir = Direction::NORTH;
		  return LEFT;
	  }
	  else if (dir == Direction::WEST)
	  {
		  //Turn to go north--turn right, then forward
		  dir = Direction::NORTH;
		  return RIGHT;
	  }

	  else   //Must be facing south
	  {//Turn to go north--left, left, forward
		  dir = Direction::EAST;
		  return LEFT;
	  }

	  



  }

  else if(isValid[1] && !isVisited[1])  //"" & south isn't visited, try and visit south
  {
	  if (dir == Direction::SOUTH)
	  {
		  return FORWARD;
	  }

	  else if (dir == Direction::EAST)
	  {
		  //Turn left to face South
		  dir = Direction::SOUTH;
		  return RIGHT;
	  }

	  else if (dir == Direction::WEST)
	  {
		  //Turn right to face South
		  dir = Direction::SOUTH;
		  return LEFT;
	  }

	  else
	  {
		  //Turn left, left to face south
		  dir = Direction::WEST;
		  return LEFT;
	  }
	  
  }

  else if (isValid[2] && !isVisited[2]) //  East isn't visited
  {
	  if (dir == Direction::EAST)
	  {
		  return FORWARD;
	  }

	  else if (dir == Direction::NORTH)
	  {
		  dir = Direction::EAST;
		  return RIGHT;
	  }

	  else if (dir == Direction::SOUTH)
	  {
		  dir = Direction::EAST;
		  return LEFT;
	  }

	  else
	  {
		  dir = Direction::NORTH;
		  return RIGHT;

	  }
  }
  else if (isValid[3] && !isVisited[3])  //West isn't visited
  {
	  if (dir == Direction::WEST)
	  {
		  return FORWARD;
	  }

	  else if (dir == Direction::NORTH)
	  {
		  dir = Direction::WEST;
		  return LEFT;
	  }

	  else if (dir == Direction::SOUTH)
	  {
		  dir = Direction::WEST;
		  return RIGHT;
	  }

	  else
	  {
		  dir = Direction::NORTH;
		  return LEFT;
	  }

  
  
  
  }


  if (p.home) { return  SHUTOFF; }

  //Breadth-first search:  queue

  


}

