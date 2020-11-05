#include<iostream>
using namespace std;

typedef struct linkst {//����ջ
	int data;
	linkst* next;
	linkst* top;
}*linkstack;

void initstack(linkstack& s) {//��ʼ��ջ
	s = new linkst;
	s->top = s;
	s->next = NULL;
}

bool stackempty(linkstack& s) {//�ж�ջ�Ƿ�Ϊ��
	if (s->top->next == NULL) {
		cout << "ջ�ǿյ�" << endl;
		return true;
	}else {
		cout << "ջ�Ƿǿյ�" << endl;
		return false;
	}
}

bool pushsome(linkstack& s) {//�����ջ
	int x;
	cout << "������������ջ��Ԫ�ظ���" << endl;
	cin >> x;
	int y;
	linkstack p;
	for (int i = 0; i < x; i++) {
		cout << "�������" << i + 1 << "��Ԫ�ص�ֵ" << endl;
		cin >> y;
		p = new linkst;
		p->data = y;
		p->next = s->top;
		s->top = p;
	}
	return true;
}

bool push(linkstack& s, int x) {//��ջ
	linkst* p = new linkst;
	p->data = x;
	p->next = s->top;
	s->top = p;
	return true;
}

bool pop(linkstack& s,int &y) {//��ջ
	if (s->top == s) {
		cout << "ջ�ǿյ� û��ɾ" << endl;
		return false;
	}
	y = s->top->data;
	s->top = s->top->next;
	return true;
}

bool print(linkstack s) {//��ӡ
	if (s->top->next == NULL) {
		cout << "ջ�ǿյ�" << endl;
		return false;
	}
	linkst* p = s->top;
	int i = 1;
	while (p != s) {
		cout << "ջ�е�" << i << "��Ԫ�ص�ֵ��" << p->data << endl;
		p = p->next;
		i++;
	}
	return true;
}

int main() {
	linkstack s;
	initstack(s);
	push(s,5);
	push(s,6);
	int y;
	pop(s, y);
	cout << "y = "<< y << endl;
	print(s);
	
	
	system("pause");
	return 0;
}