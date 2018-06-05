#include <iostream>
using namespace std;

void comp(int &, int &);
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	comp(x, y);
	comp(y, z);
	comp(x, y);
	cout << x << " " << y << " " << z << endl;
	return 0;
}

void comp(int &x, int &y) {
	int temp;
	if (x < y) {
		temp = y;
		y = x;
		x = temp;
	}
}