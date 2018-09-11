/*
 * main.cpp
 *
 *  Created on: 09.08.2018
 *      Author: Henry
 */
#include<iostream>
#include"Klasse1.h"

int main() {
	tes::Klasse1 Klasse1(2);
	tes::Klasse2 *klass2;

	//klass2 = &Klasse1;
	Klasse1.setName("hallo");
	std::cout << Klasse1.getName() << std::endl;
	//klass2->printName();
	Klasse1.~Klasse1();
	return 0;

}

