#include <iostream>
#define LEN 100 
using namespace std;
struct Stack
{
	int top;
	int data[50];
};
void InitStack(Stack& s)
{
	s.top = -1;
}

void Push(Stack& s, char ch)
{
	s.data[++(s.top)] = ch;
}
void Pop(Stack& s, char& ch)
{
	ch = s.data[s.top--];
}

int Top(Stack& s)
{
	return s.data[s.top];
}

bool StackEmpty(Stack& s)
{
	if (s.top == -1)return true;
	else         return false;
}
char* RPNexpression(char* e)
{
	Stack s1, s2;
	InitStack(s1);
	InitStack(s2);

	Push(s1, '#');

	char* p = e, ch;
	int length = 0;
	for (; *p != '\0'; p++)
	{
		switch (*p)
		{
		case '(':
			Push(s1, *p);
			break;
		case ')':
			while (Top(s1) != '(')
			{
				Pop(s1, ch);
				Push(s2, ch);
			}
			Pop(s1, ch);
			break;
		case '+':
		case '-':
			for (ch = Top(s1); ch != '#'; ch = Top(s1))
			{
				if (ch == '(')
				{
					break;
				}
				else
				{
					Pop(s1, ch);
					Push(s2, ch);
				}
			}
			Push(s1, *p);
			length++;
			break;
		case '*':
		case '/':
			for (ch = Top(s1); ch != '#'&&ch != '+'&&ch != '-'; ch = Top(s1))
			{
				if (ch == '(')
					break;
				else
				{
					Pop(s1, ch);
					Push(s2, ch);
				}
			}
			Push(s1, *p);
			length++;
			break;
		default:
			Push(s2, *p);
			length++;
		}
	}
	while (!StackEmpty(s1) && Top(s1) != '#')
	{
		Pop(s1, ch);
		Push(s2, ch);
	}

	char *result;
	result = new char[length + 1];
	result += length;
	*result = '\0';
	result--;
	for (; !StackEmpty(s2); result--)
	{
		Pop(s2, ch);
		*result = ch;
	}
	++result;
	return result;

}
int main()
{
	cout << "输入表达式" << endl;
	char *t = new char[LEN];
	cin.getline(t, LEN);
	char *result = RPNexpression(t);
	Stack tmp;
	InitStack(tmp);
	char a, b;
	for (; *result != '\0'; result++)
	{
		switch (*result)
		{
		case '+':
			Pop(tmp, a);
			Pop(tmp, b);
			Push(tmp, a + b);
			break;
		case '-':
			Pop(tmp, a);
			Pop(tmp, b);
			Push(tmp, a - b);
			break;
		case '*':
			Pop(tmp, a);
			Pop(tmp, b);
			Push(tmp, a*b);
			break;
		case '/':
			Pop(tmp, a);
			Pop(tmp, b);
			Push(tmp, b / a);
			break;
		default:
			Push(tmp, (*result - '0'));
		}
	}
	cout << Top(tmp) << endl;
	return 0;
}