#include "../../include/board.h"
void initBoard(Board &board) {
    //empty ones
    for(int rank = 0; rank < 8; rank++) {
        for(int file = 0; file < 8; file++) {
            board.squares[rank][file] = piece(); // default constructor
        }
    }
    //soilders
    for(int file = 0; file < 8; file++){
        board.squares[1][file] = piece(PAWN, WHITE);
        board.squares[6][file] = piece(PAWN, BLACK);
    }
    //white pieces
    board.squares[0][0] = piece(ROOK, WHITE);
    board.squares[0][1] = piece(KNIGHT, WHITE);
    board.squares[0][2] = piece(BISHOP, WHITE);
    board.squares[0][3] = piece(QUEEN, WHITE);
    board.squares[0][4] = piece(KING, WHITE);
    board.squares[0][5] = piece(BISHOP, WHITE);
    board.squares[0][6] = piece(KNIGHT, WHITE);
    board.squares[0][7] = piece(ROOK, WHITE);

    // Black pieces
    board.squares[7][0] = piece(ROOK, BLACK);
    board.squares[7][1] = piece(KNIGHT, BLACK);
    board.squares[7][2] = piece(BISHOP, BLACK);
    board.squares[7][3] = piece(QUEEN, BLACK);
    board.squares[7][4] = piece(KING, BLACK);
    board.squares[7][5] = piece(BISHOP, BLACK);
    board.squares[7][6] = piece(KNIGHT, BLACK);
    board.squares[7][7] = piece(ROOK, BLACK);
}
