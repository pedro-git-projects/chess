#ifndef CHESS_HEADERS_BOARD_H_
#define CHESS_HEADERS_BOARD_H_ 

#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "piece.h"

/*TODO abstract coordinates into a class proper */
using coordinate = std::pair<std::string, int>; 
using coordinate_matrix = std::vector<std::vector<coordinate>>;

class Board {
	public:
		Board();
	private:
		std::vector<coordinate> positions_vector;
		std::pair<std::unique_ptr<Piece>, coordinate> taken_positions;
		const std::vector<std::pair<std::unique_ptr<Piece>, coordinate>> initial_taken_positions;
};


#endif
