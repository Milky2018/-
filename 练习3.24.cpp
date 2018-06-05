#include <iostream>
using namespace std;

int g(int m, int n)
{
	if (m == 0)
		return 0;
	else
		return g(m - 1, 2 * n) + n;
}

int main()
{
	int m, n;
	cin >> m >> n;
	cout << g(m, n) << endl;
	return 0;
}