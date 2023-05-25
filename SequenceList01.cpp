#include <iostream>
using namespace std;

typedef struct slist {
	int *data;
	int length;
	int capacity;
}slist;

void Initsize(slist &L) {
	L.data = new int[5];
	L.data[0] = 1;
	L.data[1] = 3;
	L.data[2] = 4;
	L.data[3] = 5;
	L.data[4] = 6;

	L.capacity = 5;
	L.length = 5;
}

bool enterlist(slist &L,int x,int y) {
	if (L.length == L.capacity) {
		cout << "表中已无空位" << endl;
		return 0;
	}
	for (int i = L.length-1; i >= x; i--) {
		L.data[i + 1] = L.data[i];
	}
	L.data[x] = y;
	L.length++;
	cout << "插入成功" << endl;
	return 1;
}

bool deletelist(slist &L,int x) {
	if (L.length == 0) {
		cout << "该位置无数据" << endl;
		return 0;
	}
	for (int i = x; i < L.length-1; i++) {
		L.data[i] = L.data[i + 1];
	}
	L.data[L.length - 1] = 1111;
	L.length--;
	cout << "删除成功" << endl;
	return 0;
}

int listlength(slist L) {
	cout << "表长为:" << L.length << endl;
	return 1;
}

int readlist(slist L,int x) {
	if (L.length == 0) {
		cout << "表内无数据" << endl;
		return 0;
	}
	cout << "此位置数据为: "<< L.data[x] << endl;
}

bool clearlist(slist &L) {
	if (L.length == 0) {
		cout << "表内无数据" << endl;
		return 0;
	}
	for (int i = 0; i < L.length; i++) {
		L.data[i] = 1111;
	}
	L.length = 0;
	return 1;
}

bool judgeempty(slist L) {
	if (L.length == 0) {
		cout << "表是空的" << endl;
		return 1;
	}
	else {
		cout << "表不为空" << endl;
		return 0;
	}
}

bool checklist(slist L) {
	if (L.length == 0) {
		cout << "表内无数据" << endl;
		return 0;
	}
	cout << "表中数据为:";
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
	return 1;
}

int main()
{
	slist L;
	Initsize(L);
	char con;
	while(true) {
		cout << "请选择操作命令：i(插入)、d( 删除)、 l(求表长)、t(遍历)、g(读取第i个元素)、c(清空)、m(判空)、x(退出程序)" << endl;
		cin >> con;
		if (con == 'i') {
			int locin, datain;
			cout << "请输入插入位置" << endl;
			cin >> locin;
			cout << "请输入要插入的值" << endl;
			cin >> datain;
			enterlist(L, locin, datain);
			checklist(L);
		}
		else if (con == 'd') {
			int delin;
			cout << "请输入删除的位置" << endl;
			cin >> delin;
			deletelist(L, delin);
			checklist(L);
		}
		else if (con == 'l') {
			listlength(L);
		}
		else if (con == 't') {
			checklist(L);
		}
		else if (con == 'g') {
			int readx;
			cout << "请输入读取元素位数" << endl;
			cin >> readx;
			readlist(L, readx);
		}
		else if (con == 'c') {
			clearlist(L);
		}
		else if (con == 'm') {
			judgeempty(L);
		}
		else if (con == 'x') {
			return 0;
		}
	}
	return 0;
}

