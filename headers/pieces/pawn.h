#ifndef CHESS_HEADERS_PAWN_H_
#define CHESS_HEADERS_PAWN_H_ 

#include "piece.h"

class Pawn : public Piece {
	void calculate_legal_movements() override;  
	void update_position() override;
};

#endif
