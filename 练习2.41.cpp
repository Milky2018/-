#include <iostream>
using namespace std;

typedef struct node{
	int  coef;
	int  exp;
	struct node *next;
	node() {
		coef = 0;
		exp = 0;
		next = NULL;
	}
} node; 

void insert(node *pa, int coeft, int expt)
{
	if (!pa) {
		cout << "多项式传入有误！" << endl;
		return;
	}
	while (pa->next) {
		pa = pa->next;
	}
	pa->next = new node;
	pa->next->coef = coeft;
	pa->next->exp = expt;
	pa->next->next = NULL;
}

void Difference(node *pa)
{
	node *p, *s;
	p = pa;
	s = p->next;
	while (p->next != NULL) {
		if (s->exp == 0) { 
			p->next = s->next;
			delete s;
			s = p->next; 
		}
		else { 
			s->coef = s->exp * s->coef;
			s->exp--;
			s = s->next;  
			p = p->next;  
		}
	}
}

void printpoly(node *pa)
{
	node *p=pa;
	cout << "P = ";
	while (p->next) {
		if (p->coef) {
			if (p->exp == 1) {
				cout << p->coef << "x + ";
			}
			else if (p->exp == 0) {
				cout << p->coef << " + ";
			}
			else {
				cout << p->coef << "x^" << p->exp << " + ";
			}
		}
		p = p->next;
	}
	if (p->exp == 1) {
		cout << p->coef << "x " << endl;;
	}
	else if (p->exp == 0) {
		cout << p->coef << " " << endl;;
	}
	else {
		cout << p->coef << "x^" << p->exp << endl;;
	}
}

int main()
{
	node *P = new node;
	int exp[6] = { 0,1,2,4,6,8 };
	int coef[6] = { 5, 9,10,4,7,11 };
	int c;
	while (1) {
		cout << "输入1快捷生成多项式，输入2求导，输入3打印多项式" << endl;
		cin >> c;
		switch (c) {
		case 1:
			for (int i = 0; i < 6; i++) {
				insert(P, coef[i], exp[i]);
			}
			break;
		case 2:
			Difference(P);
			break;
		case 3:
			printpoly(P);
			break;
		}
	}
}