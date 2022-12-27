#include "board.h"
#include "matrix.h"
#include <utility>
#include <iostream>

int main() {
	auto board = Board{};
	auto right_diagonal = Matrix::left_diagonal(board.positions_matrix(), std::make_pair("c", 1));
	for(int i = 0; i < right_diagonal.size(); i++) {
		std::cout << right_diagonal[i].first << right_diagonal[i].second << std::endl;
	}
}
