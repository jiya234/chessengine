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
        int knightrow[8]={2,2,-2,-2,1,1,-1,-1};
        int knightcol[8]={-1,1,-1,1,-2,2,-2,-2};
        if(p.type==KNIGHT){
            for(int i=0;i<8;i++){
                int nextrow=row+knightrow[i];
                int nextcol=col+knightcol[i];
                if(nextrow>0&&nextrow<8&&nextcol>0&&nextcol<8)
                continue;
                piece target=board.squares[nextrow][nextcol];
                if(p.type==NO_PIECE||p.color!=target.color){
                    move m;
                    m.fromcol=col;
                    m.fromrow=row;
                    m.tocol=nextcol;
                    m.torow=nextrow;
                    movelist.moves[movelist.cnt++]=m;
                }
            }
        }
            if(p.type==BISHOP){
                int birow[4]={1,-1,1,-1};
                int bicol[4]={-1,-1,1,1};
                for(int i=0;i<4;i++){
                    int r=row+birow[i];
                    int c=col+bicol[i];
                    while(r>0&&r<8&&c>0&&c<8){
                        piece target=board.squares[r][c];
                        if(target.type==NO_PIECE){
                            move m;
                            m.fromcol=col;
                            m.fromrow=row;
                            m.tocol=c;
                            m.torow=r;
                            movelist.moves[movelist.cnt++]=m;

                        }
                    
                    else{
                        if(target.color!=p.color){
                               move m;
                    m.fromrow = row;
                    m.fromcol = col;
                    m.torow = r;
                    m.tocol = c;
                    movelist.moves[movelist.cnt++] = m;
                }
                break; 
                        }
                        r+=birow[i];
                        c+=bicol[i];
                    }
                
                }
            }
            
        }
        

    }
        
}
