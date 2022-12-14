#ifndef CHESS_HEADERS_ALPHABET_H_
#define CHESS_HEADERS_ALPHABET_H_

#include <string>

// TODO: AlphabeticLinkedList singleton
class Node {
	public:
		Node(std::string letter);
		std::string letter;
		class Node* next;
};

class AlphabeticLinkedList {
	AlphabeticLinkedList();
	std::string letter;
	Node* next_letter;
};


#endif
