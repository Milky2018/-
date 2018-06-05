#include <iostream>

using namespace std;

struct node {
	int data;
	struct node *next;
	node() {
		data = 0;
		next = NULL;
	}
	~node() {
		delete next;
	}
};

void add(struct node *hea,int dat)
{
	struct node *head = hea;
	for (int i = 0; i <= hea->data; i++) {
		head = head->next;
	}
	hea->data++;
	head->data = dat;
	head->next = new struct node;
	return;
}

void printlist(struct node *hea)
{
	struct node *head;
	if (hea->data == 0) {
		cout << "链表为空" << endl;
		return;
	}
	else {
		head = hea;
		for (int i = 0; i < hea->data; i++) {
			head = head->next;
			cout << head->data << " ";
		}
	}
	cout << endl;
	return;
}

void link(struct node *ha, struct node *hb)
{
	struct node *head=ha;
	for (int i = 0; i < ha->data; i++) 
		head = head->next;
	head->next = hb->next;
	ha->data = ha->data + hb->data;
	return;
}

int main()
{
	int c;
	struct node *ha, *hb;
	ha = new struct node;
	hb = new struct node;
	ha->data = hb->data = 0;
	ha->next = new struct node;
	hb->next = new struct node;
	while (1) {
		cout << "输入1为链表添加元素，输入2打印链表，输入3将长链表接在短链表之后" << endl;
		cin >> c;
		switch (c) {
		case 1:
			cout << "输入1为ha添加元素，输入2为hb添加元素" << endl;
			cin >> c;
			int dat;
			cin >> dat;
			switch (c) {
			case 1:
				add(ha, dat);
				break;
			case 2:
				add(hb, dat);
				break;
			}
			break;
		case 2:
			cout << "ha:";
			printlist(ha);
			cout << "hb:";
			printlist(hb);
			break;
		case 3:
			if (ha->data <= hb->data) {
				link(ha, hb);
				cout << "ha:";
				printlist(ha);
			}
			else {
				link(hb, ha);
				cout << "hb:";
				printlist(hb);
			}
		}
	}
	return 0;
}