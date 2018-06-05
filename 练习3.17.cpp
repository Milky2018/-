#include <iostream>
#define LEN 100
using namespace std;

typedef struct {
	char data[LEN];
	int top;
}stack;

void initstack(stack *s)
{
	s->top = -1;
}

int isempty(stack *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

char pop(stack *s)
{
	if (!isempty(s))
		return s->data[s->top--];
	return '\0';
}

void push(stack *s, char val)
{
	if (s->top >= LEN - 1) {
		cout << "栈满了" << endl;
		return;
	}
	s->top++;
	s->data[s->top] = val;
}

int main()
{
	stack *s = new stack;
	initstack(s);
	char str[LEN];
	char p;
	int i=0;
	cin.getline(str, LEN);
	while(1) {
		switch (str[i]) {
		case '@':
			cout << "不属于模式" << endl;
			return 0;
			break;
		case '\n':
			cout << "不属于模式" << endl;
			return 0;
			break;
		case '&':
			i++;
			while (1) {
				p = pop(s);
				if (p == '\0' && str[i]=='@') {
					cout << "属于模式" << endl;
					return 0;
				} 
				if (p != str[i]) {
					cout << "不属于模式" << endl;
					return 0;
				}
				if (str[i] == '@') {
					cout << "不属于模式" << endl;
					return 0;
				}
				i++;
			}
			break;
		default:
			push(s, str[i++]);
			break;
		}
	}
}