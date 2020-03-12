#ifndef BOARD_GUARD
#define BOARD_GUARD

class Board{
private:
  int *boardState; // dynamic memory
public:
  Board(); // default constructor creating board
  ~Board(); // destructor
  int *getBoardState(){return boardState;}
};
#endif
