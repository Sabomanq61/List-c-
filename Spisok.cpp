#include "pch.h"
#include "Spisok.h"

Spisok::Spisok()
{
	head = new Usel;
	tail = new Usel;
	head->Next() = tail;
	tail->Prev() = head;
}
Spisok::Spisok(int *a, int n)
{
	head = new Usel;
	tail = new Usel;
	head->Next() = tail;
	tail->Prev() = head;
	for (int i = 0; i < n; i++)
		push_back(a[i]);
}
Spisok::Spisok(const Spisok &t)
{
	head = new Usel;
	tail = new Usel;
	head->Next() = tail;
	tail->Prev() = head;
	Usel *p;
	for (p = t.head->Next(); p != t.tail; p = p->Next())
		push_back(p->Key());
}
//
Spisok::Spisok(char *g)
{
	head = new Usel;
	tail = new Usel;
	head->Next() = tail;
	tail->Prev() = head;
	ifstream file(g);
	if (file.is_open())
	{
		cout << "file is open" << endl;
		int n;
		int temp;
		file >> n;
		for (int i = 0; i < n; i++)
		{
			file >> temp;
			push_back(temp);
		}
	}
	else
	{
		cout << "file is not open" << endl;
	}
}
Spisok::~Spisok()
{
	Usel *temp = head;
	head = head->Next();
	while (head)
	{
		delete temp;
		temp = head;
		head = head->Next();
	}
}

Usel* Spisok::Find(int _key)
{
	Usel *temp;
	for (temp = head->Next(); temp && temp->Key() != _key; temp = temp->Next());
	return temp;
}

Usel& Spisok::operator[](int id)
{
	if (id >= 0)
	{
		Usel *temp = head->Next();
		for (int i = 0; i != id && temp != tail; temp = temp->Next(), i++);
		return *temp;
	}
}

Spisok& Spisok::operator=(const Spisok &t)
{
	if (this != &t)
	{
		del();
		Usel *p;
		for (p = t.head->Next(); p != t.tail; p = p->Next())
			push_back(p->Key());
	}
	return *this;
}

Spisok Spisok::operator+(const Spisok &t)
{
	Spisok temp(*this);
	temp += t;
	return temp;
}

Spisok& Spisok::operator+=(const Spisok &t)
{
	Usel *p;
	for (p = t.head->Next(); p != t.tail; p = p->Next())
		push_back(p->Key());
	return *this;
}
void Spisok::push_back(int _key)
{
	Usel *temp = new Usel(_key, tail->Prev(), tail);
	tail->Prev()->Next() = temp;
	tail->Prev() = temp;
}

void Spisok::push_front(int _key)
{
	Usel *temp = new Usel(_key, head, head->Next());
	head->Next()->Prev() = temp;
	head->Next() = temp;
}

void Spisok::after_key(int _key, int key1)
{
	Usel *p = Find(_key);
	if (p)
	{
		Usel* temp = new Usel(key1, p, p->Next());
		p->Next()->Prev() = temp;
		p->Next() = temp;
	}
}

void Spisok::add(Usel *q, int _key)
{
	if (q)
	{
		Usel *q1 = q->Next(), *p;
		p = new Usel(_key, q, q1);
		q->Next() = p;
		q1->Prev() = p;
	}
}

void Spisok::delhead()
{
	Usel *q = head->Next();
	if (q != tail)
	{
		head->Next() = q->Next();
		q->Next()->Prev() = head;
		delete q;
	}

}

void Spisok::deltail()
{
	Usel *q = tail->Prev();
	if (q != head)
	{
		q->Prev()->Next() = tail;
		tail->Prev() = q->Prev();
		delete q;
	}
}

void Spisok::delkey(int _key)
{
	Usel *q = Find(_key);
	if (q)
	{
		Usel *p = q->Prev(), *p1 = q->Next();
		p->Next() = p1;
		p1->Prev() = p;
		delete q;
	}

}

void Spisok::del_id(int id)
{
	if (id >= 0)
	{
		Usel *p = head->Next();
		for (int i = 0; p != tail && i != id; p = p->Next(), i++);
		if (p != tail)
		{
			Usel *p1 = p->Next(), *p2 = p->Prev();
			p1->Prev() = p2;
			p2->Next() = p1;
			delete p;
		}
	}
}

void Spisok::del()
{
	Usel *q = head->Next(), *p;
	head->Next() = tail;
	tail->Prev() = head;
	while (q != tail)
	{
		p = q;
		q = q->Next();
		delete p;
	}
}
void Spisok::Show()
{
	Usel *temp;
	for (temp = head->Next(); temp != tail; temp = temp->Next())
		cout << temp->Key() << "  ";
	/*for (temp =tail->Prev(); temp != head; temp = temp->Prev())
		cout << temp->Key() << "  ";*/
	cout << endl;
}

istream& operator>>(istream &r, Spisok &t)
{
	int n;
	int _key;
	cout << "enter n =";
	r >> n;
	t.del();
	for (int i = 0; i < n; i++)
	{
		cout << "enter key = ";
		r >> _key;
		t.push_back(_key);
	}
	return r;
}

ostream& operator<<(ostream &r, Spisok &t)
{
	Usel *temp;
	for (temp = t.head->Next(); temp != t.tail; temp = temp->Next())
		r << temp->Key() << "  ";
	r << endl;

	/*for (temp = t.tail->Prev(); temp != t.head; temp = temp->Prev())
		r << temp->Key() << "  ";
	r << endl;*/
	return r;
}






