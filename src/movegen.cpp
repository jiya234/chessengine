#include "../include/movegen.h"

void generateallmoves(const Board &board, movelist &movelist) {
    movelist.cnt = 0;

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            piece p = board.squares[row][col];

            // --- WHITE PAWN ---
            if (p.type == PAWN && p.color == WHITE) {
                int nextrow = row + 1;
                if (nextrow < 8 && board.squares[nextrow][col].type == NO_PIECE) {
                    move m;
                    m.fromrow = row; m.fromcol = col;
                    m.torow = nextrow; m.tocol = col;
                    movelist.moves[movelist.cnt++] = m;
                }

                if (row == 1) {
                    int jumprow = row + 2;
                    if (board.squares[jumprow][col].type == NO_PIECE) {
                        move m;
                        m.fromrow = row; m.fromcol = col;
                        m.torow = jumprow; m.tocol = col;
                        movelist.moves[movelist.cnt++] = m;
                    }
                }

                int caprow = row + 1;
                if (col - 1 >= 0) {
                    piece target = board.squares[caprow][col - 1];
                    if (target.type != NO_PIECE && target.color == BLACK) {
                        move m;
                        m.fromrow = row; m.fromcol = col;
                        m.torow = caprow; m.tocol = col - 1;
                        movelist.moves[movelist.cnt++] = m;
                    }
                }

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

            // --- BLACK PAWN ---
            if (p.type == PAWN && p.color == BLACK) {
                int nextrow = row - 1;
                if (nextrow >= 0 && board.squares[nextrow][col].type == NO_PIECE) {
                    move m;
                    m.fromrow = row; m.fromcol = col;
                    m.torow = nextrow; m.tocol = col;
                    movelist.moves[movelist.cnt++] = m;
                }

                if (row == 6) {
                    int jumprow = row - 2;
                    if (board.squares[jumprow][col].type == NO_PIECE) {
                        move m;
                        m.fromrow = row; m.fromcol = col;
                        m.torow = jumprow; m.tocol = col;
                        movelist.moves[movelist.cnt++] = m;
                    }
                }

                int caprow = row - 1;
                if (col - 1 >= 0) {
                    piece target = board.squares[caprow][col - 1];
                    if (target.type != NO_PIECE && target.color == WHITE) {
                        move m;
                        m.fromrow = row; m.fromcol = col;
                        m.torow = caprow; m.tocol = col - 1;
                        movelist.moves[movelist.cnt++] = m;
                    }
                }

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
        } 
    } 
}