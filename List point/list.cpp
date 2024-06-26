#include <iostream>
#include "List.h"



List::Node* List::find(const size_t idx)
{
	Node* node = first;

	for (size_t i = 0; i < idx; i++)
	{
		node = node->next;
	}

	return node;
}

void List::push(const Point& point, const size_t idx)
{
	if (idx == 0)
	{
		Node* tail = first;
		first = new Node(point);
		first->next = tail;
	}
	else
	{
		Node* prev = find(idx - 1);
		Node* tail = prev->next;
		prev->next = new Node(point);
		prev->next->next = tail;
	}
	size++;
}

void List::push(const List& list, const size_t idx)
{
	List copy(list);
	Node* it = copy.first;
	if (idx == 0)
	{
		Node* tail = first;
		Node* last = nullptr;
		if (it)
		{
			first = new Node(it->point);
			last = first;
			it = it->next;
		}
		while (it)
		{
			last->next = new Node(it->point);
			last = last->next;
			it = it->next;
		}
		if (last) last->next = tail;
	}
	else
	{
		Node* prev = find(idx - 1);
		Node* tail = prev->next;
		while (it)
		{
			prev->next = new Node(it->point);
			prev = prev->next;
			it = it->next;
		}
		prev->next = tail;
	}
	size += copy.size;
}

void List::pop(const size_t idx)
{
	if (idx == 0)
	{
		Node* tail = first->next;
		delete first;
		first = tail;
	}
	else
	{
		Node* prev = find(idx - 1);
		Node* tail = prev->next->next;
		delete prev->next;
		prev->next = tail;
	}
	size--;
}

List::List() : size(0), first(nullptr) {}

List::List(const List& list) : size(list.size), first(nullptr)
{
	Node* it = list.first;
	Node* last = first;
	if (it)
	{
		first = new Node(it->point);
		last = first;
		it = it->next;
	}
	while (it)
	{
		last->next = new Node(it->point);
		last = last->next;
		it = it->next;
	}
}

List::~List() {
	while (getSize() != 0) {
		Node* usuwanyelement = find(getSize());
		delete usuwanyelement;
		size--;
	}
}

List::Error List::pop_front()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(0);
	}

	return error;
}

size_t List::getSize()
{
	return size;
}

void List::push_back(const Point& punkt) {
	Node* last = find(getSize());
	Node* nowy = new Node(punkt);
	nowy->next = nullptr;
	last->next = nowy;
}

void List::push_back_list(const List& lista) {
	Node* last = find(getSize());
	last->next = lista.first;
}

Point& List::find(Point& punkt, const std::size_t idx) {
	Node* node = first;

	for (size_t i = 0; i < idx; i++)
	{
		if (node->point.x == punkt.x && node->point.y == punkt.y && node->point.z == punkt.z) {
			break;
		}
		node = node->next;
	}

	return node->point;
}


void List::insert(const Point& punkt, const std::size_t idx) {
	Node* prev = find(idx - 1);
	Node* aktualny = prev->next;
	Node* nowy = new Node(punkt);
	prev->next = nowy;
	nowy->next = aktualny;
	size++;
}


List List::operator+(const List& list)
{
	List copy(*this);
	copy.push(list, copy.size);
	return copy;
}

List& List::operator+=(const List& list)
{
	push(list, size);
	return *this;
}

List& List::operator=(const List& list)
{
	List copy(list);
	this->~List();
	push(copy, 0);
	return *this;
}

List& List::operator--() {
	pop(size);
	size--;
	return *this;
}

List List::operator--(int)
{
	List list = *this;
	--*this;
	return list;
}

List List::operator*(size_t n)
{
	for (int i = 0; i < n; i++)
	{
		push_back_list(*this);
	}
	return *this;
}

Point& List::operator[](size_t index)
{
	Node* znaleziony = find(index);
	Point punkt = znaleziony->point;
	return punkt;
}

List& List::operator++() {
	delete this;
	return *this;
}
List List::operator++(int)
{
	List copy(*this);
	--*this;
	return copy;
}

std::ostream& operator<<(std::ostream& out, const List& list)
{
	List::Node* current = list.first;
	while (current != nullptr)
	{
		out << "(" << current->point.x << "," << current->point.y << "," << current->point.z<<") ";
		current = current->next;
	}

	return out;
}
