#include "node.h"

Node::Node(std::string value) noexcept {
	this->value = value;
	next = nullptr;
	previous = nullptr;
}
