#include "board.h"
#include "coordinate_matrix.h"
#include <utility>
#include <iostream>

int main() {
	auto board = Board{};
	auto right_diagonal = CoordinateMatrix::l(board.positions_matrix(), std::make_pair("d", 5));
	for(int i = 0; i < right_diagonal.size(); i++) {
		std::cout << right_diagonal[i].first << right_diagonal[i].second << std::endl;
	}
}
