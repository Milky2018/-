#include <iostream>
#include <cstdlib>

#define LEN 100
using namespace std;

struct increasinglist {
	int length;
	int elem[LEN];
	increasinglist() {
		length = 0;
		elem[0] = -1;
	}
	~increasinglist() {}
	void insert(int val);
	int thereis(int val);
	void printlist();
	int deleteone(int val);
	void deleteall(int val);
};

void increasinglist::insert(int val)
{
	if (!length) {
		elem[0] = val;
		length++;
		return;
	}
	if (length >= LEN - 1) {
		cout << "顺序表已满" << endl;
		return;
	}
	int i = 0;
	while (elem[i] < val&&i < length)
		i++;
	for (int j = length - 1; i <= j; j--)
		elem[j + 1] = elem[j];
	elem[i] = val;
	length++;
	return;
}

int increasinglist::thereis(int val)
{
	if (!length)
		return -1;
	for (int i = 0; i < length; i++) {
		if (elem[i] == val)
			return i;
	}
	return -1;
}

int increasinglist::deleteone(int val)
{
	int i = thereis(val);
	if (i == -1)
		return 0;
	for (; i < length - 1; i++)
		elem[i] = elem[i + 1];
	length--;
	return 1;
}
void increasinglist::deleteall(int val)
{
	while (deleteone(val));
	return;
}

void increasinglist::printlist()
{
	for (int i = 0; i < length; i++)
		cout << elem[i] << " ";
	cout << endl;
	return;
}

int main()
{
	int a[10] = { 3,9,9,10,5,8,7,10,2,6 };
	int b[8] = { 6,2,9,2,6,8,8,1 };
	int c[7] = { 12,15,6,7,5,8,7 };
	int get;
	struct increasinglist A, B, C;
	while (1) {
		cout << "输入1快速对三个表赋值，输入2打印三个表，输入3从A中删去既在B又在C中的元素" << endl;
		cin >> get;
		switch (get) {
		case 1:
			for (int i = 0; i < 10; i++)
				A.insert(a[i]);
			for (int i = 0; i < 8; i++)
				B.insert(b[i]);
			for (int i = 0; i < 7; i++)
				C.insert(c[i]);
			break;
		case 2:
			A.printlist();
			B.printlist();
			C.printlist();
			break;
		case 3:
			int i = 0, j = 0, k = 0;
			for (; i < A.length; i++) {
				for (; B.elem[j] <= A.elem[i] && j < B.length; j++) {
					for (; C.elem[k] <= A.elem[i] && k < C.length; k++) {
						if (A.elem[i] == B.elem[j] && A.elem[i] == C.elem[k])
							A.deleteall(A.elem[i]);
					}
				}
			}
		}
	}
}