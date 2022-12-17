#include "matrix.h"
#include <board.h>
#include <utility>
#include <vector>
#include <iostream>

// TODO: Rotate vector
Board::Board() : 
	positions_vector() 
{
	coordinate_matrix pv(8, std::vector<coordinate>(8));
	for(int i = 0; i < pv.size(); i++) {
		for(int j = 0; j < pv.size(); j++) {
			pv[i][j].first = "b";
			pv[i][j].second = i + 1;
			std::cout << pv[i][j].first << pv[i][j].second << " ";
		}
		std::cout << std::endl;
	}

	auto result{ Matrix::rotate_clockwise(pv) };
	result = Matrix::rotate_clockwise(result);
	std::cout << std::endl;
	Matrix::print( result);
}
