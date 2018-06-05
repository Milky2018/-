#include <iostream>
#define arrsize 300
#define MAXINT 65535
using namespace std;

int main()
{
	int n, cut;
	int a[arrsize];
	cin >> n;
	n += 1;
	cut = n;
	a[0] = 1;
	if (n == 1)
		cut = 1;
	else
	{
		for (int k = 1; k < n; k++) {
			a[k] = a[k - 1] * k * 2;
			if (a[k - 1] >= MAXINT) {
				cut = k-1;
				break;
			}
		}
	}
	cout << a[cut-1] << endl;
	return 0;
}
