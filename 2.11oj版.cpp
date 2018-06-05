#include <vector>
#include <iostream>
#define LIST_INIT_SIZE 1000

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

int main(void)
{
	Sqlist list;
	vector<int> inputs;
	int n = 0;
	int i;
	cin >> i;
	inputs.push_back(i);
	while (cin.get() != '\n') {
		cin >> i;
		inputs.push_back(i);
		n++;
	}
	for (int j = 0; j<n; j++)
		list.addelem(inputs[j]);
	list.addelem(inputs[n]);
	list.printlist();
	return 0;
}

void Sqlist::addelem(int x)
{
	if (!length)
		*elem = x;
	else {
		int i = 0;
		while (*(elem + i) <= x && i < length)
			i++;
		for (int j = length - 1; i <= j; j--)
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
	for (int i = 0; i < length-1; i++) {
		cout << *(elem + i) << " ";
	}
	cout << *(elem + length-1);
	cout << endl;
}