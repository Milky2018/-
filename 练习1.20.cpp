#include <iostream>
#define LEN 100
using namespace std;

int main()
{
	cout << "�������ʽ����" << endl;
	int n;
	cin >> n;
	int a[LEN];
	for (int i = 0; i <= n; i++) {
		cout << "����ϵ��a" << i << endl;
		cin >> a[i];
	}
	cout << "�����Ա���x" << endl;
	int x;
	cin >> x;
	int value = 0;
	int pow = 1;
	for (int i = 0; i <= n; i++) {
		value += pow * a[i];
		pow *= x;
	}
	cout << "����ʽ��ֵΪ" << value << endl;
	return 0;
}