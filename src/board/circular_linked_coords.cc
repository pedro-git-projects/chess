#include <circular_linked_coords.h>

Node::Node(std::string value) noexcept {
	this->value = value;
	next = nullptr;
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