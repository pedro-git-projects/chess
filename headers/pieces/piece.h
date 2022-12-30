#ifndef CHESS_HEADERS_PIECE_H_
#define CHESS_HEADERS_PIECE_H_ 

#include <string>
#include <vector>
#include <utility>

enum class Color  {
	white,
	black
};

class Piece {
	public:
		virtual ~Piece() = default;
		virtual void calculate_legal_movements(std::vector<std::vector<std::pair<std::string, int>>> board_state) = 0; 
		virtual void update_position() = 0;

	protected:
		std::pair<std::string, int> starting_position_;
		std::pair<std::string, int> current_position_;
		std::vector<std::pair<std::string, int>> current_legal_movements_;
		Color color_;
};

#endif
