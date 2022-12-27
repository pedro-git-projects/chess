#include "linked_coords.h"
#include <algorithm>
#include <stdexcept>

LinkedCoords::LinkedCoords() noexcept {
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
	h->next = nullptr;

	a->previous = nullptr;
	b->previous = a;
	c->previous = b;
	d->previous = c;
	e->previous = d;
	f->previous = e;
	g->previous = f;
	h->previous = g;

	current = a; 
}


LinkedCoords::LinkedCoords(std::string initial) noexcept {
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
	h->next = nullptr;

	a->previous = nullptr;
	b->previous = a;
	c->previous = b;
	d->previous = c;
	e->previous = d;
	f->previous = e;
	g->previous = f;
	h->previous = g;

	if(initial == "a") { current = a; }
	else if(initial == "b") { current = b; }
	else if(initial == "c") { current = c; }
	else if(initial == "d") { current = d; }
	else if(initial == "e") { current = e; }
	else if(initial == "f") { current = f; }
	else if(initial == "g") { current = g; }
	else if(initial == "h") { current = h; }
	else {
		current = a;
	}
}

const std::string LinkedCoords::corresponding_string() const {
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


LinkedCoords LinkedCoordinates::str_to_coodrinate(const std::string& value) {
	if(value == "a") return LinkedCoords{"a"};
	if(value == "b") return LinkedCoords{"b"};
	if(value == "c") return LinkedCoords{"c"};
	if(value == "d") return LinkedCoords{"d"};
	if(value == "e") return LinkedCoords{"e"};
	if(value == "f") return LinkedCoords{"f"};
	if(value == "g") return LinkedCoords{"g"};
	if(value == "h") return LinkedCoords{"h"};
	else throw new std::runtime_error("invalid coodrinate char");
}

