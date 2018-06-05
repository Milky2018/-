#include <iostream>
#define LEN 100
using namespace std;

int main()
{
	cout << "输入多项式阶数" << endl;
	int n;
	cin >> n;
	int a[LEN];
	for (int i = 0; i <= n; i++) {
		cout << "输入系数a" << i << endl;
		cin >> a[i];
	}
	cout << "输入自变量x" << endl;
	int x;
	cin >> x;
	int value = 0;
	int pow = 1;
	for (int i = 0; i <= n; i++) {
		value += pow * a[i];
		pow *= x;
	}
	cout << "多项式的值为" << value << endl;
	return 0;
}