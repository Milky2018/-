#include <iostream>
#define LIST_INIT_SIZE 100

using namespace std;

class Sqlist {
private:
	int *elem;
	int length;
	int listsize;
public:
	Sqlist() {
		elem = new int[LIST_INIT_SIZE];
		length = 0;
		listsize = LIST_INIT_SIZE;
	}
	~Sqlist() {
		delete elem;
	}
	void addelem(int a);
	void delelem(int n);
	void printlist();
};
int main()
{
	class Sqlist list;
	while (1) {
		cout << "����1�������������2ɾ��Ԫ�أ�����3��ӡ��\n";
		int c;
		cin >> c;
		switch (c) {
		case 1:
			cout << "������Ҫ��ӵ���ֵ ";
			int x;
			cin >> x;
			list.addelem(x);
			break;
		case 2:
			cout << "��Ҫɾ���ڼ���Ԫ�أ� ";
			int n;
			cin >> n;
			list.delelem(n);
			break;
		case 3:
			list.printlist();
			break;
		}
	}
	return 0;
}

void Sqlist::addelem(int x)
{
	if (!length)
		*elem = x;
	else {
		int i=0;
		while (*(elem + i) <= x && i < length)
			i++;
		for (int j = length-1; i <= j; j--) 
			*(elem + j + 1) = *(elem + j);
		*(elem + i) = x;
	}
	length++;
	return;
}

void Sqlist::delelem(int n)
{
	for (int i = n; i <= length; i++)
		*(elem + i) = *(elem + i + 1);
	length--;
}

void Sqlist::printlist()
{
	for (int i = 0; i < length; i++) {
		cout << *(elem + i) << " ";
	}
	cout << endl;
}