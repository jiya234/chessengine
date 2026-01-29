#include "../include/board.h" // Path fixed

void initBoard(Board &board) {
    // 1. Empty squares
    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            // Default: No Piece, White color (dummy)
            board.squares[row][col] = {NO_PIECE, WHITE}; 
        }
    }

    // 2. Pawns (Soldiers)
    for(int file = 0; file < 8; file++){
        board.squares[1][file] = {PAWN, WHITE}; // Curly braces use karein
        board.squares[6][file] = {PAWN, BLACK};
    }

    // 3. White Pieces (Rank 0)
    // Curly braces {} standard C++ struct initialization hai
    board.squares[0][0] = {ROOK, WHITE};
    board.squares[0][1] = {KNIGHT, WHITE};
    board.squares[0][2] = {BISHOP, WHITE};
    board.squares[0][3] = {QUEEN, WHITE};
    board.squares[0][4] = {KING, WHITE};
    board.squares[0][5] = {BISHOP, WHITE};
    board.squares[0][6] = {KNIGHT, WHITE};
    board.squares[0][7] = {ROOK, WHITE};

    // 4. Black Pieces (Rank 7)
    board.squares[7][0] = {ROOK, BLACK};
    board.squares[7][1] = {KNIGHT, BLACK};
    board.squares[7][2] = {BISHOP, BLACK};
    board.squares[7][3] = {QUEEN, BLACK};
    board.squares[7][4] = {KING, BLACK};
    board.squares[7][5] = {BISHOP, BLACK};
    board.squares[7][6] = {KNIGHT, BLACK};
    board.squares[7][7] = {ROOK, BLACK};
}