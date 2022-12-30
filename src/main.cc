#include "board.h"
#include "coordinate_matrix.h"
#include <utility>
#include <iostream>

int main() {
	auto board = Board{};
	auto result = CoordinateMatrix::extremities(board.positions_matrix());
	for(int i = 0; i < result.size(); i++) {
		std::cout << result[i].first << result[i].second << " ";
	}
}
