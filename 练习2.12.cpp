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
		cout << "����1���ñ�1��Ԫ�أ�����2���ñ�2��Ԫ�أ�����3�Ƚϲ��鿴���" << endl;
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
	cout << "����������Ԫ��ֵ������������-1Ϊ�ضϷ���" << endl;
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
			cout << "��1<��2" << endl;
			return;
		}
		else if (*(a + i) > *(b + i)) {
			cout << "��1>��2" << endl;
			return;
		}
		else if (*(a + i) == *(b + i) && *(a + i) == -1) {
			cout << "��1=��2" << endl;
			return;
		}
		else
			;
	}
	return;
}
