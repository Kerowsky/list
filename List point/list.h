#include <vector>
#include "Point.h"
class List
{
	size_t size;
	struct Node
	{
		Point point;
		Node* next;
		Node(const Point& p) : point(p.x, p.y, p.z), next(nullptr) {}
	};
	Node* first;

	Node* find(const size_t);
	void push(const Point&, const size_t);
	void push(const List&, const size_t);
	void pop(const size_t);

public:
	List();
	List(const List&);
	~List();
	void pop_back();
	void push_back(const Point&);
	void push_back_list(const List&);
	Point& find(Point&, const std::size_t);
	void insert(const Point&, const std::size_t);
	enum Error
	{
		SUCCESS,
		LIST_EMPTY,
		OUT_OF_BOUNDS
	};
	Error pop_front();
	size_t getSize();
	List operator+(const List&);
	List& operator+=(const List&);
	List& operator=(const List&);
	List& operator--();
	List operator--(int);
	List operator*(size_t);
	Point& operator[](size_t);
	List& operator++();
	List operator++(int);
	friend std::ostream& operator<<(std::ostream&, const List&);
};