#include <iostream>
using namespace std;
#include "include/board.h"
int main() {
  Board board;
  initBoard(board);
  void printboard(const Board& board);
  {
  for(int rank=7;rank>=0;rank--){
    cout<<rank+1<<endl;
  
  for(int file=0;file<8;file++){
    piece p=board.squares[rank][file];
    char c='.';
    if(p.type!=NO_PIECE){
        switch(p.type){
            case PAWN:
            c ='p';
            break;
case KNIGHT:
c='k';
break;
case BISHOP:
c='b';
break;
case ROOK:
c='h';
case QUEEN:
c='q';
case KING:
c='k';
        }
        if(p.color==BLACK)
        c=toupper(c);
    }
    cout<<c<<" ";
  }
  cout<<endl;

  }
  cout<< "  A B C D E F G H\n";
}
}


