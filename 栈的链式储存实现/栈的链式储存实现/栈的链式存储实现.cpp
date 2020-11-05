#include<iostream>
using namespace std;

typedef struct linkst {//定义栈
	int data;
	linkst* next;
	linkst* top;
}*linkstack;

void initstack(linkstack& s) {//初始化栈
	s = new linkst;
	s->top = s;
	s->next = NULL;
}

bool stackempty(linkstack& s) {//判断栈是否为空
	if (s->top->next == NULL) {
		cout << "栈是空的" << endl;
		return true;
	}else {
		cout << "栈是非空的" << endl;
		return false;
	}
}

bool pushsome(linkstack& s) {//多个入栈
	int x;
	cout << "请输入你想入栈的元素个数" << endl;
	cin >> x;
	int y;
	linkstack p;
	for (int i = 0; i < x; i++) {
		cout << "请输入第" << i + 1 << "个元素的值" << endl;
		cin >> y;
		p = new linkst;
		p->data = y;
		p->next = s->top;
		s->top = p;
	}
	return true;
}

bool push(linkstack& s, int x) {//入栈
	linkst* p = new linkst;
	p->data = x;
	p->next = s->top;
	s->top = p;
	return true;
}

bool pop(linkstack& s,int &y) {//出栈
	if (s->top == s) {
		cout << "栈是空的 没得删" << endl;
		return false;
	}
	y = s->top->data;
	s->top = s->top->next;
	return true;
}

bool print(linkstack s) {//打印
	if (s->top->next == NULL) {
		cout << "栈是空的" << endl;
		return false;
	}
	linkst* p = s->top;
	int i = 1;
	while (p != s) {
		cout << "栈中第" << i << "个元素的值是" << p->data << endl;
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