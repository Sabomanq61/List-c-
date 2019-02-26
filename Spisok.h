#pragma once
#include "Usel.h"
#include <iostream>
#include <fstream>
using namespace std;

class Spisok
{
public:
	Spisok();
	Spisok(const Spisok&);
	Spisok(char *);
	Spisok(int *, int);
	~Spisok();
	Usel* Find(int);
	Usel& operator[](int);
	Spisok& operator=(const Spisok&);
	Spisok operator+(const Spisok&);
	Spisok& operator+=(const Spisok&);
	void push_back(int);
	void push_front(int);
	void after_key(int,int);
	void add(Usel *q, int _key);
	void delhead();
	void deltail();
	void delkey(int);
	void del_id(int);
	void Show();
	void del();
	friend istream& operator>>(istream &, Spisok &);
	friend ostream& operator<<(ostream &, Spisok&);
private:
	int size;
	Usel *head, *tail;
};

