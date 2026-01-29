#ifndef MOVEGEN_H
#define MOVEGEN_H
#include "move.h"
#include "board.h"
const int maxmoves=256;
struct movelist{//stores all moves
    move moves[maxmoves];//box to store all moves
    int cnt;
};
void generateallmoves(const Board &board,movelist &movelist);//how many moves are done
#endif