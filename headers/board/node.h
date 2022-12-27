#ifndef CHESS_HEADERS_BOARD_NODE_H_
#define CHESS_HEADERS_BOARD_NODE_H_

#include <string>

class Node {
	public:
		std::string value;
		Node* next;
		Node* previous;
		Node(std::string value) noexcept;
};

#endif
