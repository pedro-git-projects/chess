#ifndef CHESS_HEADERS_BOARD_CIRCULAR_LINKED_COORDS_H_
#define CHESS_HEADERS_BOARD_CIRCULAR_LINKED_COORDS_H_

#include <string>

class Node {
	public:
		std::string value;
		Node* next;
		Node(std::string value) noexcept;
};

class CircularLinkedCoords {
	public:
		CircularLinkedCoords(std::string initial) noexcept; 
		Node* current;
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

#endif
