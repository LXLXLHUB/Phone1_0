#pragma once
#ifndef _CLIENT_H_
#define _CLINET_H_

#include <vector>
#include <fstream>
#include "phone.h"

class Client {
public:
	bool menu ();
	Client ();
	~Client ();
private:

	vector<Phone> v = vector<Phone> ();

	void add();
	void show ();
	void drop (string number);
	void change (string number);
};

#endif