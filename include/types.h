#ifndef types_h
#define types_h
enum Color{
   WHITE,
   BLACK
};
enum PieceType{
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    NO_PIECE
};
enum Square{
    A1,B1,C1,D1,E1,F1,G1,H1,
    A2,B2,C2,D2,E2,F2,G2,H2,
    A3,B3,C3,D3,E3,F3,G3,H3,
    A4,B4,C4,D4,E4,F4,G4,H4,
    A5,B5,C5,D5,E5,F5,G5,H5,
    A6,B6,C6,D6,E6,F6,G6,H6,
    A7,B7,C7,D7,E7,F7,G7,H7,
    A8,B8,C8,D8,E8,F8,G8,H8,NO_SQUARE
};
struct piece
{
   PieceType type;
   Color color;
   piece():type(NO_PIECE),color(WHITE) {}//default set krdia taki garbage value na ae
   piece(PieceType t,Color c):type(t),color(c){}//parameterized constructor
};

#endif