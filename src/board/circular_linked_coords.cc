#include <circular_linked_coords.h>
#include <stdexcept>

Node::Node(std::string value) noexcept {
	this->value = value;
	next = nullptr;
}

CircularLinkedCoords::CircularLinkedCoords() noexcept {
	a = new Node{"a"};
	b = new Node{"b"};
	c = new Node{"c"};
	d = new Node{"d"};
	e = new Node{"e"};
	f = new Node{"f"};
	g = new Node{"g"};
	h = new Node{"h"};

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
	h->next = a;

	current = a; 
}


CircularLinkedCoords::CircularLinkedCoords(std::string initial) noexcept {
	a = new Node{"a"};
	b = new Node{"b"};
	c = new Node{"c"};
	d = new Node{"d"};
	e = new Node{"e"};
	f = new Node{"f"};
	g = new Node{"g"};
	h = new Node{"h"};

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
	h->next = a;

	if(initial == "a") current = a;
	if(initial == "b") current = b;
	if(initial == "c") current = c;
	if(initial == "d") current = d;
	if(initial == "e") current = e;
	if(initial == "f") current = f;
	if(initial == "g") current = g;
	if(initial == "h") current = h;
	else this->current = this->a; 
}

const std::string CircularLinkedCoords::corresponding_string() const {
	if(current->value == "a") return "a";
	if(current->value == "b") return "b";
	if(current->value == "c") return "c";
	if(current->value == "d") return "d";
	if(current->value == "e") return "e";
	if(current->value == "f") return "f";
	if(current->value == "g") return "g";
	if(current->value == "h") return "h";
	else return "a";
}


CircularLinkedCoords Coordinates::str_to_coodrinate(const std::string& value) {
	if(value == "a") return CircularLinkedCoords{"a"};
	if(value == "b") return CircularLinkedCoords{"b"};
	if(value == "c") return CircularLinkedCoords{"c"};
	if(value == "d") return CircularLinkedCoords{"d"};
	if(value == "e") return CircularLinkedCoords{"e"};
	if(value == "f") return CircularLinkedCoords{"f"};
	if(value == "g") return CircularLinkedCoords{"g"};
	if(value == "h") return CircularLinkedCoords{"h"};
	else throw new std::runtime_error("invalid coodrinate char");
}

