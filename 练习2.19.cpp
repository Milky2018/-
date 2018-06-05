#include <iostream>
#include <cstdlib>

using namespace std;

struct Header {
	int length;
	struct Node *next;
	Header() {
		length = 0;
		next = NULL;
	}
	~Header() {}
};

struct Node {
	int data;
	struct Node *next;
	Node() {
		data = 0;
		next = NULL;
	}
	~Node() {}
};

typedef struct Node List;
typedef struct Header pHead;

void print(pHead *ph);
pHead *createList();
int Size(pHead *ph);
void Insert(pHead *ph, int val);
List *Delete(pHead *ph, int val);
void Destroy(pHead *ph);
List *find(pHead *ph, int val);
void intervaldelete(pHead *ph, int min, int max);

pHead *createList()
{
	pHead *ph = new pHead;
	ph->length = 0;
	ph->next = NULL;
	return ph;
}

int Size(pHead *ph)
{
	if (ph == NULL) {
		cout << "������������" << endl;
		return 0;
	}
	return ph->length;
}

void Insert(pHead *ph, int val)
{
	List *pval = new List;
	pval->data = val;
	if (!ph->length) 
		ph->next = pval;
	else {
		List *pCur = ph->next;
		for (int i = 1; i < ph->length; i++) {
			if (pCur->next == NULL)
				break;
			else if (pCur->next->data >= val)
				break;
			else
				pCur = pCur->next;
		}
		pval->next = pCur->next;
		pCur->next = pval;
	}
	ph->length++;
	return;
}

void intervaldelete(pHead *ph, int min, int max)
{
	List *p, *q, *prev = NULL;
	if (min > max) {
		cout << "mink��maxk��" << endl;
		return;
	}
	p = ph->next;
	prev = p;
	p = p->next;
	while (p&&p->data<=max) {
		if (p->data < min) {
			prev = p;
			p = p->next;
		} else {
			prev->next = p->next;
			q = p;
			p = p->next;
			delete q;
		}
	}
	return;
}

List *Delete(pHead *ph, int val)
{
	if (ph == NULL) {
		cout << "����������" << endl;
		return NULL;
	}
	List *pval = find(ph, val);
	if (pval == NULL) {
		cout << "����������" << endl;
		return NULL;
	}
	List *pRe = ph->next;
	List *pCur = NULL;
	if (pRe->data == val) {
		ph->next = pRe->next;
		ph->length--;
		return pRe;
	}
	else {
		for (int i = 0; i < ph->length; i++) {
			pCur = pRe->next;
			if (pCur->data == val) {
				pRe->next = pCur->next;
				ph->length--;
				return pCur;
			}
			pRe = pRe->next;
		}
	}
	return NULL;
}

void Destroy(pHead *ph)
{
	List *pCur = ph->next;
	List *pTmp;
	if (ph == NULL)
		cout << "������������" << endl;
	while (pCur->next != NULL) {
		pTmp = pCur->next;
		delete pCur;
		pCur = pTmp;
	}
	ph->length = 0;
	ph->next = NULL;
}

List *find(pHead *ph, int val)
{
	if (ph == NULL) {
		cout << "������������" << endl;
		return NULL;
	}
	List *pTmp = ph->next;
	do {
		if (pTmp->data == val)
			return pTmp;
		pTmp = pTmp->next;
	} while (pTmp->next != NULL);
	cout << "û�����Ԫ��" << endl;
	return NULL;
}

void print(pHead *ph)
{
	if (ph == NULL)
		cout << "������������" << endl;
	List *pTmp = ph->next;
	while (pTmp != NULL) {
		cout << pTmp->data << " ";
		pTmp = pTmp->next;
	}
	cout << endl;
}

int main()
{
	pHead *ph = createList();
	if (ph == NULL)
		cout << "��������ʧ�ܣ�" << endl;
	while (1) {
		cout << "����1���Ԫ�أ�����2ɾ�����д���minkС��maxk��Ԫ�أ�����3��ӡ����" << endl;
		int c, x, min, max;
		cin >> c;
		switch (c) {
		case 1:
			cout << "������Ҫ��ӵ�Ԫ��ֵ" << endl;
			cin >> x;
			Insert(ph, x);
			break;
		case 2:
			cout << "��������mink��maxk" << endl;
			cin >> min >> max;
			intervaldelete(ph, min, max);
			break;
		case 3:
			print(ph);
			break;
		default:
			cout << "��������ȷ������" << endl;
		}
	}
	system("pause");
	return 0;
}