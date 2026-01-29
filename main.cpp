#include <iostream>
#include "include/movegen.h"
using namespace std;
#include "include/board.h"
void printboard(const Board& board) {
    for (int row = 7; row >= 0; row--) {
       
        cout << row + 1 << " ";

        for (int col = 0; col < 8; col++) {
            piece p = board.squares[row][col];
            char c = '.';
            
            if (p.type != NO_PIECE) {
                switch (p.type) {
                    case PAWN:   c = 'p'; break;
                    case KNIGHT: c = 'n'; break; 
                    case BISHOP: c = 'b'; break;
                    case ROOK:   c = 'r'; break; 
                    case QUEEN:  c = 'q'; break;
                    case KING:   c = 'k'; break;
                    default: break;
                }
                
                
                if (p.color == WHITE) 
                    c = toupper(c);
                else 
                    c = tolower(c);
            }
            cout << c << " ";
        }
        cout << endl; 
    }
    cout << "  A B C D E F G H\n";
}

int main() {
    Board board;
    initBoard(board); 
    printboard(board);
    movelist movelist;
    generateallmoves(board,movelist);
cout<<movelist.cnt;
    return 0;
}