#include "../include/movegen.h"

void generateallmoves(const Board &board, movelist &movelist){
    movelist.cnt = 0;

    for(int row = 0; row < 8; row++){
        for(int col = 0; col < 8; col++){
            piece p = board.squares[row][col];

            if(p.type == PAWN && p.color == WHITE){
                int nextrow = row + 1;
                if(nextrow < 8 && board.squares[nextrow][col].type == NO_PIECE){
                    move m;
                    m.fromrow = row;
                    m.fromcol = col;
                    m.torow = nextrow;
                    m.tocol = col;
                    movelist.moves[movelist.cnt++] = m;
                }

                if(row == 1){
                    int jumprow = row + 2;
                    if(board.squares[jumprow][col].type == NO_PIECE){
                        move m;
                        m.fromrow = row;
                        m.fromcol = col;
                        m.torow = jumprow;
                        m.tocol = col;
                        movelist.moves[movelist.cnt++] = m;
                    }
                }

                int caprow = row + 1;

                if(col - 1 >= 0){
                    piece target = board.squares[caprow][col - 1];
                    if(target.type != NO_PIECE && target.color == BLACK){
                        move m;
                        m.fromrow = row;
                        m.fromcol = col;
                        m.torow = caprow;
                        m.tocol = col - 1;
                        movelist.moves[movelist.cnt++] = m;
                    }
                }

                if(col + 1 < 8){
                    piece target = board.squares[caprow][col + 1];
                    if(target.type != NO_PIECE && target.color == BLACK){
                        move m;
                        m.fromrow = row;
                        m.fromcol = col;
                        m.torow = caprow;
                        m.tocol = col + 1;
                        movelist.moves[movelist.cnt++] = m;
                    }
                }
            }

            if(p.type == PAWN && p.color == BLACK){
                int nextrow = row - 1;
                if(nextrow >= 0 && board.squares[nextrow][col].type == NO_PIECE){
                    move m;
                    m.fromrow = row;
                    m.fromcol = col;
                    m.torow = nextrow;
                    m.tocol = col;
                    movelist.moves[movelist.cnt++] = m;
                }

                if(row == 6){
                    int jumprow = row - 2;
                    if(board.squares[jumprow][col].type == NO_PIECE){
                        move m;
                        m.fromrow = row;
                        m.fromcol = col;
                        m.torow = jumprow;
                        m.tocol = col;
                        movelist.moves[movelist.cnt++] = m;
                    }
                }

                int caprow = row - 1;

                if(col - 1 >= 0){
                    piece target = board.squares[caprow][col - 1];
                    if(target.type != NO_PIECE && target.color == WHITE){
                        move m;
                        m.fromrow = row;
                        m.fromcol = col;
                        m.torow = caprow;
                        m.tocol = col - 1;
                        movelist.moves[movelist.cnt++] = m;
                    }
                }

                if(col + 1 < 8){
                    piece target = board.squares[caprow][col + 1];
                    if(target.type != NO_PIECE && target.color == WHITE){
                        move m;
                        m.fromrow = row;
                        m.fromcol = col;
                        m.torow = caprow;
                        m.tocol = col + 1;
                        movelist.moves[movelist.cnt++] = m;
                    }
                }
            }
        }
    }
}
