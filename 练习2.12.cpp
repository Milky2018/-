#include <iostream>
#define LEN 100
using namespace std;

void set(int *);
void comp(int *, int *);
int main()
{
	int a[LEN] = { -1 };
	int b[LEN] = { -1 };
	while (1) {
		cout << "输入1设置表1的元素，输入2设置表2的元素，输入3比较并查看结果" << endl;
		int c;
		cin >> c;
		switch (c) {
		case 1:
			set(a);
			break;
		case 2:
			set(b);
			break;
		case 3:
			comp(a, b);
			break;
		}
	}
	return 0;
}

void set(int* a)
{
	cout << "依次输入表的元素值（正整数），-1为截断符号" << endl;
	int c;
	int i = 0;
	cin >> c;
	while (c != -1 && i < LEN-1) {
		*(a + i) = c;
		i++;
		cin >> c;
	}
	*(a + i) = -1;
	return;
}

void comp(int *a, int *b)
{
	for (int i = 0; i < LEN; i++) {
		if (*(a + i) < *(b + i)) {
			cout << "表1<表2" << endl;
			return;
		}
		else if (*(a + i) > *(b + i)) {
			cout << "表1>表2" << endl;
			return;
		}
		else if (*(a + i) == *(b + i) && *(a + i) == -1) {
			cout << "表1=表2" << endl;
			return;
		}
		else
			;
	}
	return;
}
