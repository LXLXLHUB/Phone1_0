#include "phone.h"

void Phone::setName (string name) {
	(*this).name = name;
}

string Phone::getName () {
	return (*this).name;
}

bool Phone::setNumber (string number) {
	if (number.size () == NUMBET_SIZE) {
		(*this).number = number;
		return true;
	} else {
		cout << "����number����ʧ�ܣ�������\n���ȷǷ���������\n";
		return false;
	}
}

string Phone::getNumber () {
	return (*this).number;
}

void Phone::setNote (string note) {
	(*this).note = note;
}

string Phone::getNote () {
	return (*this).note;
}

bool Phone::setAge (int age) {
	if (age >= AGE_MIN || age <= AGE_MAX) {
		(*this).age = age;
		return true;
	} else {
		cout << "age��������ʧ�ܣ�������\nage������0��130�ķ�Χ�У�����";
		return false;
	}
}

int Phone::getAge () {
	return (*this).age;
}

ostream& operator<<(ostream& os, Phone p) {
	cout << p.name << "\t\t";
	cout << p.age << "\t\t";
	cout << p.number << "\t\t";
	cout << p.note;
	return os;

}