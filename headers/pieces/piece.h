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
		virtual void calculate_legal_movements() = 0; 
		virtual void update_position() = 0;

	protected:
		std::pair<std::string, int> starting_position;
		std::pair<std::string, int> current_position;
		std::vector<std::pair<std::string, int>> legal_movements;
		Color color;
};

#endif
