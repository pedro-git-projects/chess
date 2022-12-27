#ifndef CHESS_HEADERS_BOARD_CIRCULAR_LINKED_COORDS_H_
#define CHESS_HEADERS_BOARD_CIRCULAR_LINKED_COORDS_H_

#include <string>
#include "node.h"

class CircularLinkedCoords {
	public:
		CircularLinkedCoords(std::string initial) noexcept; 
		CircularLinkedCoords() noexcept; 
		Node* current;
		const std::string corresponding_string() const;
	private:
		Node* a;
		Node* b;
		Node* c;
		Node* d;
		Node* e;
		Node* f;
		Node* g;
		Node* h;
};

namespace Coordinates {
	CircularLinkedCoords str_to_coodrinate(const std::string& value);
};

#endif
