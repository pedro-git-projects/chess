#include "coordinate_matrix.h"
#include "piece.h"
#include <pawn.h>
#include <utility>

Pawn::Pawn(std::pair<std::string, int> starting_position, Color color) {
	starting_position_ = starting_position;
	current_position_ = starting_position_;
	color_ = color;
	was_moved_ = false;
	current_legal_movements_.push_back(CoordinateMatrix::n_foward(starting_position, 2));
}

void Pawn::calculate_legal_movements(std::vector<std::vector<std::pair<std::string, int>>> board_state) {
	 
}

void Pawn::update_position() {
}
