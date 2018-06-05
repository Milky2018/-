#include <iostream>
#include <cstdlib>

using namespace std;

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

void print(List *ph);
List *createList();
int Insert(List *ph, int pos, int val);
List *Delete(List *ph, int val);
List *find(List *ph, int val);

List *createList()
{
	List *ph = new List;
	ph->data = 0;
	ph->next = NULL;
	return ph;
}

int Insert(List *ph, int pos, int val)
{
	List *pval = new List;
	pval->data = val;
	List *pCur = ph->next;
	if (!pos) {
		ph->next = pval;
		pval->next = pCur;
	}
	else {
		for (int i = 1; i < pos; i++)
			pCur = pCur->next;
		pval->next = pCur->next;
		pCur->next = pval;
	}
	return 1;
}

List *Delete(List *ph, int val)
{
	if (ph == NULL) {
		cout << "����������" << endl;
		return NULL;
	}
	List *pval = find(ph, val);
	if (pval == NULL) {
		cout << "����������" << endl;
	}
	List *pRe = ph->next;
	List *pCur = NULL;
	if (pRe->data == val) {
		ph->next = pRe->next;
		return pRe;
	}
	else {
		for (int i = 0; ph->next!=NULL; i++) {
			pCur = pRe->next;
			if (pCur->data == val) {
				pRe->next = pCur->next;
				return pCur;
			}
			pRe = pRe->next;
		}
	}
	return NULL;
}

List *find(List *ph, int val)
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

void print(List *ph)
{
	if (ph == NULL)
		cout << "������������" << endl;
	List *pTmp = ph->next;
	while (pTmp != NULL) {
		cout << pTmp->data<<" ";
		pTmp = pTmp->next;
	}
	cout << endl;
}

int main()
{
	List *ph = createList();
	if (ph == NULL)
		cout << "��������ʧ�ܣ�" << endl;
	while (1) {
		cout << "����1���Ԫ�أ�����2ɾ��Ԫ�أ�����3��ӡ����" << endl;
		int c, x, n;
		cin >> c;
		switch (c) {
		case 1:
			cout << "����������Ҫ��ӵ�Ԫ��ֵx��λ��n" << endl;
			cin >> x >> n;
			Insert(ph, n, x);
			break;
		case 2:
			cout << "������Ҫɾ����Ԫ��ֵx" << endl;
			cin >> x;
			Delete(ph, x);
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