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
		cout << "设置number属性失败！！！！\n长度非法！！！！\n";
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
		cout << "age属性设置失败！！！！\nage必须在0到130的范围中！！！";
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