#ifndef CHESS_HEADERS_PIECE_H_
#define CHESS_HEADERS_PIECE_H_ 

#include <map>
#include <string>
#include <vector>

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
		std::map<std::string, int> starting_position;
		std::map<std::string, int> current_position;
		std::vector<std::map<std::string, int>> legal_movements;
		Color color;
};

#endif
