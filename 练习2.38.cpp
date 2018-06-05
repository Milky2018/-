#include <malloc.h>
#include <iostream>
#define LEN 100
using namespace std;

typedef struct DNode
{
	int data;
	int freq;
	struct DNode *next;
	struct DNode *prior;
} DinkList;

DinkList *h;
void sort(DinkList *&h)
{
	DinkList *p, *q, *pre;
	p = h->next->next;
	h->next->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		pre = h;
		while (pre->next != NULL && pre->next->freq>p->freq)
			pre = pre->next;
		p->next = pre->next;
		if (pre->next != NULL)
			pre->next->prior = p;
		pre->next = p;
		p->prior = pre;
		p = q;
	}
}

void LocateNode(DinkList *&h, int x)
{
	DinkList *p;
	p = h->next;
	int i = 0;
	while (p != NULL && p->data != x)
	{
		p = p->next;
		++i;
	}
	p->freq++; 
	DinkList *q, *pre;
	p = h->next->next;
	h->next->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		pre = h;
		while (pre->next != NULL && pre->next->freq>p->freq)
			pre = pre->next;
		p->next = pre->next;
		if (pre->next != NULL)
			pre->next->prior = p;
		pre->next = p;
		p->prior = pre;
		p = q;
	}
}

int main()
{
	DinkList *s;
	h = (DinkList *)malloc(sizeof(DinkList));
	int a[10];
	int i;
	for (i = 0; i<10; ++i)
		a[i] = i;
	h->prior = h->next = NULL;
	for (i = 0; i<10; ++i)
	{
		s = (DinkList *)malloc(sizeof(DinkList));
		s->data = a[i];
		s->freq = 0;
		s->next = h->next;
		if (h->next != NULL)
			h->next->prior = s;
		h->next = s;
		s->prior = h;
	}
	cout << "原来：";
	DinkList *p;
	p = h->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	int c;
	while (1) {
		cout << "输入要访问的元素" << endl;
		cin >> c;
		LocateNode(h, c);
		p = h->next;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	return 0;
}