#pragma once
#include "Include.h"

class Test
{
public:
	Test() = default;

	//Add test
	void Add_Test();
	//Add test import
	void Add_Test_Import();
	//Add quastion in choise test
	void Add_QuastionInTest(string choise);
	//Print Choise test
	void Print_Test(string choise);
	//Add in file test name
	void Add_TestInFile_NameTest(string name);
};


