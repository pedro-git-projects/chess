#ifndef CHESS_HEADERS_PAWN_H_
#define CHESS_HEADERS_PAWN_H_ 

#include "piece.h"
#include <string>
#include <utility>

class Pawn : public Piece {
	Pawn(std::pair<std::string, int> starting_position, Color color);
	void calculate_legal_movements(std::vector<std::vector<std::pair<std::string, int>>> board_state) override;  
	void update_position() override;
	bool was_moved_;
};

#endif
