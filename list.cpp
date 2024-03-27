#include <iostream>

class List
{
public:
	size_t size = 0;
	struct Node
	{
		int wartosc;
		Node* next;
		Node(int x) : wartosc(x), next(nullptr){}
	};

	//do obslugi indexow
	Node * find(size_t idx) {
		Node* node = first;
		for (int i = 0; i < idx; i++) {
			node = node->next;
		}
		return node;
	}
	//metody dodajace
	void add(int wartosc) { // Dodawanie elementu do listy na koniec.
		Node* node = first;
		if (size == 0) {
			first = new Node(wartosc);
			first->next = nullptr;
			size++;
		}
		else {
			Node* prev = find(size - 1);
			Node* next = new Node(wartosc);
			prev->next = next;
			size++;
		}
	}
	void put(int wartosc, size_t idx) {
		Node* prev = find(idx-1);
		Node* aktualny = prev->next;
		Node* nowy = new Node(wartosc);
		prev->next = nowy;
		nowy->next = aktualny;
		size++;
	}

	//metody usuwajace
	void remove(size_t idx) { // usuwanie elementu o danym indeksie
		Node* prev = find(idx-1);
		Node* doUsuniecia = prev->next;
		if (doUsuniecia->next != nullptr) {
			Node* nastepny = doUsuniecia->next;
			prev->next = nastepny;
			delete(doUsuniecia);
			size--;
		}
		else {
			prev->next = nullptr;
			delete(doUsuniecia);
			size--;
		}

	}
	void removeLast() { //usuwanie ostatniego elementu
		Node* prev = find(size - 1);
		Node* doUsuniecia = prev->next;
		delete(doUsuniecia);
		prev->next = nullptr;
		size--;
	}

	List();
	~List();
	Node* first;

private:

};

List::List():size(0), first(nullptr){}

List::~List()
{
	while (size != 0) {
		Node* usuwanyelement = find(size);
		delete usuwanyelement;
		size--;
	}
}

int main()
{
	List* lista = new List();
	lista->add(2);
	lista->add(3);
	lista->add(6);

	lista->add(7);
	//Do testow 
	/*
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			lista->add(7);
		}
	}
	*/
	lista->put(69, 3);
	delete(lista);
}

