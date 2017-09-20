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


Agent::Agent(int random_seed) : dirtSucked(0) { 
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
		dirtSucked++; return SUCK;
	}
	if (p.bump) { return (std::rand() % 5 < 3) ? LEFT : RIGHT; } // P(LEFT) = 3/5
  if (p.home && dirtSucked>0) { return  SHUTOFF; }
  //default rule
  return (std::rand() % 5 < 3) ? 
               FORWARD :
               ((std::rand() % 2) ? LEFT : RIGHT);



  //Breadth-first search:  queue

  


}

