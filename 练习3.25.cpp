#include <iostream>
using namespace std;

int F(int n)
{
	if (n == 0)
		return 1;
	else
		return n * F(n / 2);
}

int f(int n)
{
	int product = 1;
	while (n != 0) {
		product *= n;
		n /= 2;
	}
	return product;
}

int main()
{
	int n;
	cin >>  n;
	cout << f(n) << endl << F(n) << endl;
	return 0;
}