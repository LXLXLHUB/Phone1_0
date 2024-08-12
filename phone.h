#pragma once
#ifndef _PHONE_H_
#define _PHONE_H_

#include <iostream>

#include "mystruct.h"

using namespace std;

class Phone {
public:
	void setName (string name);
	string getName ();
	bool setNumber (string number);
	string getNumber ();
	void setNote (string note);
	string getNote ();
	bool setAge (int age);
	int getAge ();
	friend ostream& operator<<(ostream& os, Phone p);
private:
	string name;
	string number;
	string note;
	int age;
};

#endif