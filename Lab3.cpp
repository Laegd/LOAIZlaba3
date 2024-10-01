#include <iostream>

using namespace std;

struct node
{
	int leps;
	int n;
	node* next;
	node(int s, int m) : leps(s), n(m), next(nullptr) {}
};

struct list
{
	node* first;
	node* last;
	list() : first(nullptr), last(nullptr) {}

	bool is_empty() { return first == nullptr; }
	void add(int s, int m)
	{
		node* p = new node(s, m);
		if (is_empty())
		{
			first = p;
			last = p;
			return;
		}

		node* t1 = first;
		node* t2 = first->next;
		if (first->n < m)
		{
			p->next = first;
			first = p;
			return;
		}
		while (t2 && t2->n < m)
		{
			t2 = t2->next;
			t1 = t1->next;
		}
		t1->next = p;
		p->next = t2;

	}
	void print()
	{
		if (is_empty()) return;
		node* p = first;
		while (p)
		{
			cout << "(" << p->n << ")" << p->leps << " ";
			p = p->next;
		}
		cout << "\n";
	}
	void dlt_first()
	{
		if (is_empty()) return;
		node* p = first;
		first = p->next;
		delete p;
	}
	void dlt_last()
	{
		if (is_empty()) return;
		node* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;
	}
	void dlt(int s)
	{
		if (is_empty()) return;
		while (1)
		{
			if (first->leps == s)
			{
				dlt_first();
			}
			else if (last->leps == s)
			{
				dlt_last();
			}
			node* t1 = first;
			node* t2 = first->next;
			while (t2 && t2->leps != s)
			{
				t2 = t2->next;
				t1 = t1->next;
			}
			if (!t2)
			{
				//cout << "Элемент не был найден." << endl;
				return;
			}
			t1->next = t2->next;
			delete t2;
		}
	}
};
int main()
{
	setlocale(LC_ALL, "");
	list l;
	int k = 0;
	cout << "1. Записать чмсло" << endl << "2. Вывести список" << endl << "3. Удалить число" << endl << "4. Выйти из программы\n";
	while (1)
	{
		cout << endl << "Номер пункта: ";
		cin >> k;
		switch (k)
		{
		case 1:
		{
			int s;
			int n;
			cout << "Введите число: ";
			cin >> s;
			cout << "Введите приоритет: ";
			cin >> n;
			l.add(s, n);
		}continue;
		case 2:
		{
			l.print();
		}continue;
		case 3:
		{
			int z;
			cout << "Введите слово которое нужно удалить: ";
			cin >> z;
			l.dlt(z);
		}continue;
		case 4: { exit(0); };
		}
	}
	return 0;
}