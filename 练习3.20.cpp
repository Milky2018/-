#include <iostream>
using namespace std;

int g[5][5] = {
	0,0,0,0,0,
	0,1,1,0,1,
	2,2,1,0,1,
	0,2,1,1,1,
	0,2,2,2,0
};

int change(int x, int y, int pclr, int clr)
{
	if (x < 0 || x>4 || y < 0 || y>4) {
		return 0;
	}
	else if (g[x][y] != pclr) {
		return 0;
	}
	else {
		g[x][y] = clr;
		change(x + 1, y, pclr, clr);
		change(x, y + 1, pclr, clr);
		change(x - 1, y, pclr, clr);
		change(x, y - 1, pclr, clr);
		return 1;
	}
}

void print()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << " " << g[i][j];
		cout << endl;
	}
}

int main()
{
	int i, j, clr;
	while (1) {
		print();
		cout << "依次输入i0,j0和想要换成的颜色" << endl;
		cin >> i >> j >> clr;
		change(i-1, j-1, g[i-1][j-1], clr);
	}
}