#include "circular_linked_coords.h"
#include "matrix.h"
#include <board.h>
#include <utility>
#include <vector>
#include <iostream>

// TODO: Populate initial positions && create game objects 
Board::Board() {

	std::vector<std::vector<std::pair<std::string, int>>> b(8, std::vector<std::pair<std::string, int>>(8));
	CircularLinkedCoords clc{"a"};
	int coord = 8;

	for(int i = 0; i < b.size(); i++) {
		for(int j = 0; j < b.size(); j++) {
			b[i][j].first = clc.current->value;
			b[i][j].second = coord;
			clc.current = clc.current->next;
			std::cout << b[i][j].first << b[i][j].second << " ";
		}
		std::cout << std::endl;
		coord--;
	}

	positions_matrix_ = b;
}

std::vector<std::vector<std::pair<std::string, int>>>&  Board::positions_matrix() {
	return positions_matrix_;
}
