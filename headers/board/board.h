#ifndef CHESS_HEADERS_BOARD_BOARD_H_
#define CHESS_HEADERS_BOARD_BOARD_H_ 

#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "piece.h"

class Board {
	public:
		Board();
		std::vector<std::vector<std::pair<std::string, int>>>& positions_matrix();
	private:
		std::vector<std::vector<std::pair<std::string, int>>> positions_matrix_;
		std::pair<std::unique_ptr<Piece>, std::pair<std::string, int>> taken_positions_;
		const std::vector<std::pair<std::unique_ptr<Piece>, std::pair<std::string, int>>> initial_taken_positions_;
};

#endif
