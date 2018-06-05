#include <iostream>
#include <cstdlib>
#define LEN 100
#define CNUM 10
using namespace std;

class chart {
private:
	struct line {
		int item;
		int sex;
		int collegename;
		int grade;
		int poingts;
	}l[LEN];
	struct college {
		int malepoints;
		int femalepoints;
	}c[CNUM];
	int linenum;
	struct line *linep;
	void addtocollege(int, int, int);
public:
	chart() {
		for (int i = 0; i < CNUM; i++) {
			c[i].malepoints = 0;
			c[i].femalepoints = 0;
		}
		linenum = 0;
		linep = NULL;
	}
	chart(int n) {
		if (n = 0) {
			for (int i = 0; i < CNUM; i++) {
				c[i].malepoints = 0;
				c[i].femalepoints = 0;
			}
			linenum = n;
			linep = NULL;
		}
		else if (n < 0 || n>LEN)
			cout << "行数超出限制" << endl;
		else {
			for (int i = 0; i < CNUM; i++) {
				c[i].malepoints = 0;
				c[i].femalepoints = 0;
			}
			linenum = n;
			linep = l;
		}
	}
	~chart() {
		delete linep;
		delete l;
	}
	void addline(int, int, int, int, int);
	void modiline(int);
	void printmarks();
	void printchart();
};

void chart::addtocollege(int name, int s, int p)
{
	if (s == 0)
		c[name].malepoints += p;
	else
		c[name].femalepoints += p;
	return;
}
void chart::addline(int it, int s, int name, int g, int p)
{
	if (linenum < LEN) {
		linep->item = it;
		linep->sex = s;
		linep->collegename = name;
		linep->grade = g;
		linep->poingts = p;
		addtocollege(name, s, p);
		linenum++;
		linep++;
		return;
	}
}

void chart::modiline(int n)
{
	if (n <= linenum && n >= 1) {
		addtocollege(l[n - 1].collegename, l[n - 1].sex, -l[n - 1].poingts);
		cout << "请依次输入项目名称、性别、学校名称、成绩和得分" << endl;
		cin >> l[n - 1].item >> l[n - 1].sex >> l[n - 1].collegename >> l[n - 1].grade >> l[n - 1].poingts;
		addtocollege(l[n - 1].collegename, l[n - 1].sex, l[n - 1].poingts);
		return;
	}
}

void chart::printmarks()
{
	cout << "学校名称 男生总分 女生总分 团体总分" << endl;
	for (int i = 0; i < CNUM; i++) {
		cout << "  " << i << "        " << c[i].malepoints << "        " << c[i].femalepoints << "        " << c[i].malepoints + c[i].femalepoints << endl;
	}
	return;
}

void chart::printchart()
{
	cout << "行数 项目名称 性别 校名 成绩 得分" << endl;
	for (int i = 0; i < linenum; i++) {
		cout << "  " << i + 1 << "      " << l[i].item << "      " << l[i].sex << "    " << l[i].collegename << "    " << l[i].grade << "    " << l[i].poingts << endl;
	}
	return;
}
int main()
{
	cout << "输入需要创建列表的行数（最大为100）" << endl;
	int n;
	cin >> n;
	chart chart0(n);
	system("cls");
	while (1) {
		chart0.printchart();
		cout << endl;
		chart0.printmarks();
		cout << endl << "0~9代表学校名称，0代表男性，1代表女性" << endl;
		cout << "输入1添加下一行内容，输入2更改某一行内容" << endl;
		int cmd;
		cin >> cmd;
		switch (cmd) {
		case 1:
			cout<< "请依次输入项目名称、性别、学校名称、成绩和得分" << endl;
			int it, s, name, g, p;
			cin >> it >> s >> name >> g >> p;
			chart0.addline(it, s, name, g, p);
			break;
		case 2:
			cout << "需要修改第几行?" << endl;
			int n;
			cin >> n;
			chart0.modiline(n);
			break;
		}
		system("cls");
	}
}

