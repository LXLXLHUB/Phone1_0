#include "client.h"

Client::Client () {
	ifstream is;
	string s;
	int i;
	Phone p;
	is.open ("data.txt");
	while (is >> s) {
		p = Phone ();
		p.setName (s);
		is >> i;
		p.setAge (i);
		is >> s;
		p.setNumber (s);
		is >> s;
		p.setNote (s);
		v.push_back (p);
	}
	is.close ();
}

Client::~Client () {
	ofstream os;
	os.open ("data.txt");
	for (Phone p : v) {
		os << p.getName() << "\n";
		os << p.getAge () << "\n";
		os << p.getNumber () << "\n";
		os << p.getNote () << "\n";

	}
	os.close ();
}

bool Client::menu () {
	cout << "欢迎来到电话管理系统！\n";
	cout << "1、添加\n"
		<< "2、遍历\n"
		<< "3、删除\n"
		<< "4、修改\n"
		<< "5、退出\n";
	int i;
	string s;
	cin >> i;
	switch (i) {
	case 1: {
		add ();
		return true;
	}
	case 2: {
		show ();
		return true;
	}
	case 3: {
		cout << "电话：";
		cin >> s;
		drop (s);
		return true;
	}
	case 4: {
		cout << "电话：";
		cin >> s;
		change(s);
		return true;
	}
	default:
		return false;
	}
}

void Client::add () {
	Phone p = Phone ();
	string s;
	int i;
	cout << "姓名：";
	cin >> s;
	p.setName (s);
	do {
		cout << "年龄：";
		cin >> i;
	} while (!p.setAge (i));
	do {
		cout << "电话：";
		cin >> s;
	} while (!p.setNumber (s));
	cout << "备注：";
	cin >> s;
	p.setNote (s);
	v.push_back (p);
	cout << "添加成功！\n";
	system ("pause");
	system ("cls");
}

void Client::show () {
	cout << "姓名\t\t年龄\t\t电话\t\t备注\n";
	for (Phone p : v) {
		cout << p << endl;
	}
	system ("pause");
	system ("cls");
}

void Client::drop (string number) {
	for (int i = 0; i < v.size (); i++) {
		if (v[i].getNumber () == number) {
			v.erase (v.begin()+i);
			cout << "删除成功！\n";
			system ("pause");
			system ("cls");
			return;
		}
	}
	cout << "该电话不存在！\n";
	system ("pause");
	system ("cls");
}

void Client::change (string number) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getNumber() == number) {
			Phone p = Phone ();
			string s;
			int i;
			cout << "姓名：";
			cin >> s;
			p.setName (s);
			do {
				cout << "年龄：";
				cin >> i;
			} while (!p.setAge (i));
			do {
				cout << "电话：";
				cin >> s;
			} while (!p.setNumber (s));
			cout << "备注：";
			cin >> s;
			p.setNote (s);
			v[i] = p;
			cout << "插入成功！\n";
			system ("pause");
			system ("cls");
			return;
		}
	}
	cout << "该电话不存在！\n";
	system ("pause");
	system ("cls");
}