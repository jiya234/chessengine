#include "../include/movegen.h"
void generateallmoves(const Board &board,movelist &movelist){
    movelist.cnt=0;
    for(int row=0;row<8;row++){
        for(int col=0;col<8;col++){
            piece p=board.squares[row][col];
            if(p.type==PAWN &&p.color==WHITE){
                int nextrow=row+1;
                if(nextrow<8 && board.squares[nextrow][col].type==NO_PIECE){
                    move m;
                    m.fromrow=row;
                    m.fromcol=col;
                    m.torow=nextrow;
                    m.tocol=col;
                    movelist.moves[movelist.cnt++]=m;
                }
                if(row==1){
                    int jumprow=row+2;
                    if(board.squares[jumprow][col].type==NO_PIECE){
                        move m2;
                        m2.fromcol=col;
                        m2.fromrow=row;
                        m2.torow=jumprow;
                        m2.tocol=col;
                        movelist.moves[movelist.cnt++]=m2;
                    }
                }
                int caprow=row+1;
                int capcol=col-1;
                if(caprow<8&&capcol>=0){
                    piece target=board.squares[caprow][capcol];
                    if(caprow<8&&capcol>=0){
                        if(target.type!=NO_PIECE&&target.color==BLACK){
                            move m;
                            m.fromrow=row;
                            m.fromcol=col;
                            m.tocol=capcol;
                            m.torow=caprow;
                            movelist.moves[movelist.cnt++]=m;
                        }
                    }
                }

            }
        }
    }

}
