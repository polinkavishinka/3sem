// задание 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;

class Date {
	int day;
	int month;
	int year;
public:
	Date(int d = 0, int m = 0, int y = 0) { day = d; month = m; year = y; };
};

class Passenger {
	char* name;
	char* destination;
	Date arrival;
	unsigned int number;
public:
	Passenger(unsigned int num = 0, Date ar = *(new Date), char* n = nullptr, char* des = nullptr) { name = n; destination = des; arrival = ar; number = num; };
};

template  <class  Data>  class  List {
	class  Node {
	public:
		Data  d;
		Node  *next;
		Node(Data  dat = 0) {
			d = dat;
			next = 0;
		}
	};
	Node  *pbeg;
public:
	List() { pbeg = 0; }
	~List();
	void add(Data d);
	Node* find(Data i);
	Node* insert(Data  key, Data d);
	bool  remove(Data key);
	void  print();
};

template <class  Data>  List  <Data>::~List() {
	if (pbeg != 0) {
		Node *pv = pbeg;
		while (pv) {
			pv = pv->next;
			delete  pbeg;
			pbeg = pv;
		}
	}
}

template <class Data> void List <Data>::print() {
	Node *pv = pbeg;
	cout << endl << "list: ";
	while (pv) {
		cout << pv->d << ' ';
		pv = pv->next;
	}
	cout << endl;
}

template <class Data> void List <Data>::add(Data d) {
	Node *pv = new Node(d);
	Node *temp = pbeg;
	if (pbeg == 0)
		pbeg = pv;
	else {
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = pv;
	}
}

template <class Data> typename List<Data>::Node* List<Data>::find(Data d) {
	Node *pv = pbeg;
	while (pv) {
		if (pv->d == d)
			break;
		pv = pv->next;
	}
	return pv;
}

template <class Data>  typename List<Data>::Node* List <Data>::insert(Data key, Data d) {
	if (Node *pkey = find(key)) {
		Node *pv = new Node(d);
		pv->next = pkey->next;
		pkey->next = *pv;
		return  pv;
	}
	return  0;
}

template  <class  Data>  bool  List  <Data>::remove(Data  key) {
	if (Node  *pkey = find(key)) {
		Node* temp = pbeg;
		if (pkey == pbeg) {
			pbeg = pbeg->next;
		}
		else {
			while (temp->next != pkey) {
				temp = &(temp->next);
			}
			temp->next = pkey->next;
		}
		delete  pkey;
		return  true;
	}
	return  false;
}

int main()
{
	List<Passenger> Listt;
	Passenger Bob;
	Listt(Bob);
}
