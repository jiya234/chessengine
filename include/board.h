#ifndef BOARD_H
#define BOARD_H

#include "types.h"  // piece, Color, PieceType

struct Board {
    piece squares[8][8];  // 8x8 chessboard
};
void initBoard(Board &board);
#endif // BOARD_H
