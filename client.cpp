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
	cout << "��ӭ�����绰����ϵͳ��\n";
	cout << "1�����\n"
		<< "2������\n"
		<< "3��ɾ��\n"
		<< "4���޸�\n"
		<< "5���˳�\n";
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
		cout << "�绰��";
		cin >> s;
		drop (s);
		return true;
	}
	case 4: {
		cout << "�绰��";
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
	cout << "������";
	cin >> s;
	p.setName (s);
	do {
		cout << "���䣺";
		cin >> i;
	} while (!p.setAge (i));
	do {
		cout << "�绰��";
		cin >> s;
	} while (!p.setNumber (s));
	cout << "��ע��";
	cin >> s;
	p.setNote (s);
	v.push_back (p);
	cout << "��ӳɹ���\n";
	system ("pause");
	system ("cls");
}

void Client::show () {
	cout << "����\t\t����\t\t�绰\t\t��ע\n";
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
			cout << "ɾ���ɹ���\n";
			system ("pause");
			system ("cls");
			return;
		}
	}
	cout << "�õ绰�����ڣ�\n";
	system ("pause");
	system ("cls");
}

void Client::change (string number) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getNumber() == number) {
			Phone p = Phone ();
			string s;
			int i;
			cout << "������";
			cin >> s;
			p.setName (s);
			do {
				cout << "���䣺";
				cin >> i;
			} while (!p.setAge (i));
			do {
				cout << "�绰��";
				cin >> s;
			} while (!p.setNumber (s));
			cout << "��ע��";
			cin >> s;
			p.setNote (s);
			v[i] = p;
			cout << "����ɹ���\n";
			system ("pause");
			system ("cls");
			return;
		}
	}
	cout << "�õ绰�����ڣ�\n";
	system ("pause");
	system ("cls");
}