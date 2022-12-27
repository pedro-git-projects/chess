#include "circular_linked_coords.h"
#include "matrix.h"
#include <board.h>
#include <utility>
#include <vector>
#include <iostream>

// TODO: Rotate vector
Board::Board() : 
	positions_vector() 
{
	std::vector<std::vector<std::pair<std::string, int>>> pv(8, std::vector<std::pair<std::string, int>>(8));
	CircularLinkedCoords clc{"a"};
	int coord = 8;

	for(int i = 0; i < pv.size(); i++) {
		for(int j = 0; j < pv.size(); j++) {
			pv[i][j].first = clc.current->value;
			pv[i][j].second = coord;
			clc.current = clc.current->next;
			std::cout << pv[i][j].first << pv[i][j].second << " ";
		}
		std::cout << std::endl;
		coord--;
	}
}
