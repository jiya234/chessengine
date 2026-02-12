#include "../include/movegen.h"

void generateallmoves(const Board &board, movelist &movelist) {
    movelist.cnt = 0;

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            piece p = board.squares[row][col];

            // --- WHITE PAWN ---
            // --- WHITE PAWN (FIXED) ---
if (p.type == PAWN && p.color == WHITE) {
    int nextrow = row + 1;

    // 1. FORWARD MOVES
    if (nextrow < 8 && board.squares[nextrow][col].type == NO_PIECE) {
        // Simple push
        move m;
        m.fromrow = row; m.fromcol = col;
        m.torow = nextrow; m.tocol = col;
        movelist.moves[movelist.cnt++] = m;

        // Double Jump: Sirf tab check karo jab nextrow (row+1) khaali ho
        if (row == 1) { 
            int jumprow = row + 2;
            if (board.squares[jumprow][col].type == NO_PIECE) {
                move m2;
                m2.fromrow = row; m2.fromcol = col;
                m2.torow = jumprow; m2.tocol = col;
                movelist.moves[movelist.cnt++] = m2;
            }
        }
    }

    // 2. CAPTURES
    int caprow = row + 1;
    if (caprow < 8) { // Safety check
        // Left Capture
        if (col - 1 >= 0) {
            piece target = board.squares[caprow][col - 1];
            if (target.type != NO_PIECE && target.color == BLACK) {
                move m;
                m.fromrow = row; m.fromcol = col;
                m.torow = caprow; m.tocol = col - 1;
                movelist.moves[movelist.cnt++] = m;
            }
        }
        // Right Capture
        if (col + 1 < 8) {
            piece target = board.squares[caprow][col + 1];
            if (target.type != NO_PIECE && target.color == BLACK) {
                move m;
                m.fromrow = row; m.fromcol = col;
                m.torow = caprow; m.tocol = col + 1;
                movelist.moves[movelist.cnt++] = m;
            }
        }
    }
}

            // --- BLACK PAWN ---
            // --- BLACK PAWN (FIXED) ---
if (p.type == PAWN && p.color == BLACK) {
    int nextrow = row - 1;

    // 1. FORWARD MOVES
    // Pehle check karo ki ek kadam aage khaali hai ya nahi
    if (nextrow >= 0 && board.squares[nextrow][col].type == NO_PIECE) {
        move m;
        m.fromrow = row; m.fromcol = col;
        m.torow = nextrow; m.tocol = col;
        movelist.moves[movelist.cnt++] = m;

        // Double Jump: Sirf tabhi check karo jab nextrow (row-1) khaali tha 
        // AND abhi hum starting rank (6) par hain
        if (row == 6) {
            int jumprow = row - 2;
            if (board.squares[jumprow][col].type == NO_PIECE) {
                move m2;
                m2.fromrow = row; m2.fromcol = col;
                m2.torow = jumprow; m2.tocol = col;
                movelist.moves[movelist.cnt++] = m2;
            }
        }
    }

    // 2. CAPTURES (Diagonal)
    int caprow = row - 1;
    if (caprow >= 0) {
        // Left capture
        if (col - 1 >= 0) {
            piece target = board.squares[caprow][col - 1];
            if (target.type != NO_PIECE && target.color == WHITE) {
                move m;
                m.fromrow = row; m.fromcol = col;
                m.torow = caprow; m.tocol = col - 1;
                movelist.moves[movelist.cnt++] = m;
            }
        }
        // Right capture
        if (col + 1 < 8) {
            piece target = board.squares[caprow][col + 1];
            if (target.type != NO_PIECE && target.color == WHITE) {
                move m;
                m.fromrow = row; m.fromcol = col;
                m.torow = caprow; m.tocol = col + 1;
                movelist.moves[movelist.cnt++] = m;
            }
        }
    }
}

            // --- KNIGHT ---
            int knightrow[8] = {2, 2, -2, -2, 1, 1, -1, -1};
            int knightcol[8] = {-1, 1, -1, 1, -2, 2, -2, 2}; // Maine sirf yahan ek -2 ko 2 kiya taki symmetric rahe
            if (p.type == KNIGHT) {
                for (int i = 0; i < 8; i++) {
                    int nextrow = row + knightrow[i];
                    int nextcol = col + knightcol[i];
                    if (nextrow >= 0 && nextrow < 8 && nextcol >= 0 && nextcol < 8) {
                        piece target = board.squares[nextrow][nextcol];
                        if (target.type == NO_PIECE || target.color != p.color) {
                            move m;
                            m.fromcol = col; m.fromrow = row;
                            m.tocol = nextcol; m.torow = nextrow;
                            movelist.moves[movelist.cnt++] = m;
                        }
                    }
                }
            }

            // --- BISHOP ---
            if (p.type == BISHOP) {
                int birow[4] = {1, -1, 1, -1};
                int bicol[4] = {-1, -1, 1, 1};
                for (int i = 0; i < 4; i++) {
                    int r = row + birow[i];
                    int c = col + bicol[i];
                    while (r >= 0 && r < 8 && c >= 0 && c < 8) {
                        piece target = board.squares[r][c];
                        if (target.type == NO_PIECE) {
                            move m;
                            m.fromcol = col; m.fromrow = row;
                            m.tocol = c; m.torow = r;
                            movelist.moves[movelist.cnt++] = m;
                        } else {
                            if (target.color != p.color) {
                                move m;
                                m.fromrow = row; m.fromcol = col;
                                m.torow = r; m.tocol = c;
                                movelist.moves[movelist.cnt++] = m;
                            }
                            break;
                        }
                        r += birow[i]; c += bicol[i];
                    }
                }
            }

            // --- ROOK ---
            if (p.type == ROOK) {
                int dirrow[4] = {1, 0, 0, -1};
                int dircol[4] = {0, 1, -1, 0};
                for (int i = 0; i < 4; i++) {
                    int r = row + dirrow[i];
                    int c = col + dircol[i];
                    while (r >= 0 && r < 8 && c >= 0 && c < 8) {
                        piece target = board.squares[r][c];
                        if (target.type == NO_PIECE) {
                            move m;
                            m.fromrow = row; m.fromcol = col;
                            m.torow = r; m.tocol = c;
                            movelist.moves[movelist.cnt++] = m;
                        } else {
                            if (target.color != p.color) {
                                move m;
                                m.fromrow = row; m.fromcol = col;
                                m.torow = r; m.tocol = c;
                                movelist.moves[movelist.cnt++] = m;
                            }
                            break;
                        }
                        r += dirrow[i]; c += dircol[i];
                    }
                }
            }

            // --- QUEEN ---
            if (p.type == QUEEN) {
                int qrow[8] = {1, -1, 0, 0, 1, 1, -1, -1};
                int qcol[8] = {0, 0, 1, -1, 1, -1, 1, -1};
                for (int i = 0; i < 8; i++) {
                    int r = row + qrow[i];
                    int c = col + qcol[i];
                    while (r >= 0 && r < 8 && c >= 0 && c < 8) {
                        piece target = board.squares[r][c];
                        if (target.type == NO_PIECE) {
                            move m;
                            m.fromrow = row; m.fromcol = col;
                            m.torow = r; m.tocol = c;
                            movelist.moves[movelist.cnt++] = m;
                        } else {
                            if (target.color != p.color) {
                                move m;
                                m.fromrow = row; m.fromcol = col;
                                m.torow = r; m.tocol = c;
                                movelist.moves[movelist.cnt++] = m;
                            }
                            break;
                        }
                        r += qrow[i]; c += qcol[i];
                    }
                }
            }
            if(p.type==KING){
                int krow[8]={1,1,1,0,0,-1,-1,-1};
                int kcol[8]={-1,0,1,-1,1,-1,0,1};
                for(int i=0;i<8;i++){
                    int r=row+krow[i];
                    int c=col+kcol[i];
                    if(r>=0&&r<8&&c>=0&&c<8){
                        piece target = board.squares[r][c];
                        if(target.type==NO_PIECE ||target.color!=p.color){
                            move m;
                            m.fromrow=row;
                            m.fromcol=col;
                            m.tocol=c;
                            m.torow=r;
                            movelist.moves[movelist.cnt++]=m;
                        }
                    }
                }
            }
        } 
    } 
}
bool issquareattacked(const Board &board, int row, int col, Color bycolor) {
    // 1. PAWN ATTACKS
    if (bycolor == WHITE) {
        // White pawns attack from "below" (row-1)
        if (row - 1 >= 0) {
            if (col - 1 >= 0 && board.squares[row - 1][col - 1].type == PAWN && board.squares[row - 1][col - 1].color == WHITE) return true;
            if (col + 1 < 8  && board.squares[row - 1][col + 1].type == PAWN && board.squares[row - 1][col + 1].color == WHITE) return true;
        }
    } else {
        // Black pawns attack from "above" (row+1)
        if (row + 1 < 8) {
            if (col - 1 >= 0 && board.squares[row + 1][col - 1].type == PAWN && board.squares[row + 1][col - 1].color == BLACK) return true;
            if (col + 1 < 8  && board.squares[row + 1][col + 1].type == PAWN && board.squares[row + 1][col + 1].color == BLACK) return true;
        }
    }

    // 2. KNIGHT ATTACKS
    int krow[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int kcol[8] = {-1, 1, 1, -1, 2, -2, 2, -2};
    for (int i = 0; i < 8; i++) {
        int r = row + krow[i];
        int c = col + kcol[i];
        if (r >= 0 && r < 8 && c >= 0 && c < 8) { // Changed to >= 0
            piece p = board.squares[r][c];
            if (p.type == KNIGHT && p.color == bycolor) return true;
        }
    }

    // 3. BISHOP & QUEEN (DIAGONALS)
    int drow[4] = {1, 1, -1, -1};
    int dcol[4] = {1, -1, 1, -1};
    for (int i = 0; i < 4; i++) {
        int r = row + drow[i];
        int c = col + dcol[i];
        while (r >= 0 && r < 8 && c >= 0 && c < 8) {
            piece p = board.squares[r][c];
            if (p.type != NO_PIECE) {
                if (p.color == bycolor && (p.type == BISHOP || p.type == QUEEN)) return true;
                break; // Rasta block ho gaya
            }
            r += drow[i]; c += dcol[i];
        }
    }

    // 4. ROOK & QUEEN (STRAIGHT LINES)
    int srow[4] = {1, -1, 0, 0};
    int scol[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int r = row + srow[i];
        int c = col + scol[i];
        while (r >= 0 && r < 8 && c >= 0 && c < 8) { // Fixed c > 8 to c < 8
            piece p = board.squares[r][c];
            if (p.type != NO_PIECE) {
                if (p.color == bycolor && (p.type == ROOK || p.type == QUEEN)) return true;
                break; 
            }
            r += srow[i]; c += scol[i];
        }
    }

    // 5. KING ATTACKS (1 square away)
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            int r = row + dr;
            int c = col + dc;
            if (r >= 0 && r < 8 && c >= 0 && c < 8) {
                piece p = board.squares[r][c];
                if (p.type == KING && p.color == bycolor) return true;
            }
        }
    }

    return false;
}
void findking(const Board& board,Color color,int &kr,int &kc){
    for(int r=0;r<8;r++){
        for(int c=0;c<8;c++){
            piece p=board.squares[r][c];
            if(p.type==KING&&p.color==color){
                kr=r; kc=c;
                return;
            }
        }
    }
}
void generatelegalmoves(Board &board,movelist &legalmoves){
    movelist temp;
    generateallmoves(board, temp);
    for(int i=0;i<temp.cnt;i++){
        move m=temp.moves[i];
        piece from=board.squares[m.fromrow][m.fromcol];
        piece to=board.squares[m.torow][m.tocol];
        board.squares[m.torow][m.tocol]=from;
        board.squares[m.fromrow][m.fromcol]={NO_PIECE,Color::NONE};
        int kr,kc;
        findking(board,from.color,kr,kc);
        if(!issquareattacked(board,kr,kc,from.color==WHITE?BLACK:WHITE)){
            legalmoves.moves[legalmoves.cnt++]=m;
        }
        board.squares[m.fromrow][m.fromcol]=from;
        board.squares[m.torow][m.tocol]=to;
    }

}
bool iskingcheck(const Board &board,Color color){
    int kr,kc;
    for(int r=0;r<8;r++){
        for(int c=0;c<8;c++){
            piece p=board.squares[r][c];
            if(p.type==KING&&p.color==color){
                kr=r;
                kc=c;
            }
        }
    }
    Color enemy=(color==WHITE)?BLACK:WHITE;
    return issquareattacked(board,kr,kc,enemy);
}
bool ischeckmate(Board &board, Color color){
    if(!iskingcheck(board, color))
        return false;

    movelist legal;
    generatelegalmoves(board, legal);

    return legal.cnt == 0;
}

bool isstalemate(Board &board, Color color){
    if(iskingcheck(board, color))
        return false;

    movelist legal;
    generatelegalmoves(board, legal);

    return legal.cnt == 0;
}

