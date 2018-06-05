#include <iostream>
#define LEN 1000
using namespace std;

int Fbnc(int k, int m);

int main()
{
	int k, m;
	cout << "请输入阶数k: ";
	cin >> k;
	cout << "请输入项序号m: ";
	cin >> m;
	cout << "结果为: " << Fbnc(k, m) << endl;
}

int Fbnc(int k, int m)
{
	int f[LEN];
	for (int i = 0; i < k - 1; i++)
		f[i] = 0;
	if (m < k - 1)
		return 0;
	else if (m == k - 1)
		return 1;
	else if (m >= LEN)
		return -1;
	else {
		f[k - 1] = 1;
		for (int i = k; i <= m; i++) {
			f[i] = 0;
			for (int j = i - 1; j >= i - k; j--)
				f[i] += f[j];
		}
		return f[m];
	}
}