#include <iostream>
#define LEN 100
using namespace std;

template <class T> class LinkStack;
template <class T>
class StackNode {
	friend class LinkStack<T>;
private:
	T data;
	StackNode<T> *next;
public:
	StackNode(StackNode<T> *nextp = NULL):next(nextp){}
	StackNode(const T& item, StackNode<T> *nextp=NULL):data(item), next(nextp){}
	~StackNode() {}
};

template <class T>
class LinkStack {
private:
	StackNode<T> *head;
	int size;
public:
	LinkStack();
	~LinkStack();
	void push(const T& item);
	T pop();
	T gettop()const;
	int notempty()const;
};

template <class T>
LinkStack<T>::LinkStack()
{
	head = new StackNode<T>;
	size = 0;
}

template <class T>
LinkStack<T>::~LinkStack()
{
	StackNode<T> *p, *q;
	p = head;
	while (p != NULL) {
		q = p;
		p = p->next;
		delete q;
	}
}

template <class T>
int LinkStack<T>::notempty()const
{
	if (size)
		return 1;
	else
		return 0;
}

template <class T>
void LinkStack<T>::push(const T& item) {
	StackNode<T> *newnode = new StackNode<T>(item, head->next);
	head->next = newnode;
	size++;
}

template <class T>
T LinkStack<T>::pop()
{
	if (!size) {
		cout << "栈空" << endl;
		return 0;
	}
	StackNode<T> *p = head->next;
	T data = p->data;
	head->next = head->next->next;
	delete p;
	size--;
	return data;
}

template <class T>
T LinkStack<T>::gettop()const
{
	return head->next->data;
}

template <class T> class LinkQueue;

template <class T>
class QueueNode {
	friend class LinkQueue<T>;
private:
	QueueNode<T> *next;
	T data;
public:
	QueueNode(const T& item, QueueNode<T> *nextp = NULL)
		:data(item), next(nextp) {}
	~QueueNode() {};
};

template <class T>
class LinkQueue {
private:
	QueueNode<T> *front;
	QueueNode<T> *rear;
	int count;
public:
	LinkQueue();
	~LinkQueue();
	void append(const T &);
	T deleteelem();
	T getfront()const;
	int notempty()const
	{
		return count != 0;
	}
};

template <class T>
LinkQueue<T>::LinkQueue()
{
	front = rear = NULL;
	count = 0;
}

template <class T>
LinkQueue<T>::~LinkQueue()
{
	QueueNode<T> *p, *q;
	p = front;
	while (!p) {
		q = p;
		p = p->next;
		delete p;
	}
	count = 0;
	front = rear = NULL;
}

template <class T>
void LinkQueue<T>::append(const T &item)
{
	QueueNode<T> *newnode = new QueueNode<T>(item, NULL);
	if (rear != NULL)
		rear->next = newnode;
	rear = newnode;
	if (front == NULL)
		front = newnode;
	count++;
}

template <class T>
T LinkQueue<T>::deleteelem()
{
	if (count == 0) {
		cout << "队列空" << endl;
		return 0;
	}
	QueueNode<T> *p = front->next;
	T data = front->data;
	delete front;
	front = p;
	count--;
	return data;
}

template <class T>
T LinkQueue<T>::getfront()const
{
	if (count == 0) {
		cout << "队列空" << endl;
		return 0;
	}
	return front->data;
}

void readback(char str[])
{
	LinkStack<char> mystack;
	LinkQueue<char> myqueue;
	int n = strlen(str);
	for (int i = 0; i < n-1; i++) {
		myqueue.append(str[i]);
		mystack.push(str[i]);
	}
	while (myqueue.notempty() && mystack.notempty()) {
		if (myqueue.deleteelem() != mystack.pop()) {
			cout << "不是回文" << endl;
			return;
		}
	}
	cout << "是回文" << endl;
	return;
}

int main()
{
	char s[LEN];
	cin.getline(s, LEN, '@');
	cout << s;
	readback(s);
	return 0;
}