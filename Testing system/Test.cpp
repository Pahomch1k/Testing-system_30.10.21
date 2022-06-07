#include "Test.h"

//ADD
void Test::Add_Test()
{
	string name;
	int colvo_test;
	cout << "Name Test? ";
	cin >> name;
	cout << "Col_vo tests? ";
	cin >> colvo_test;

	ofstream outQ("Test_" + name + "_Quastions.txt");
	ofstream outA("Test_" + name + "_Answers.txt");

	Add_TestInFile_NameTest(name);

	for (int i = 1; i <= colvo_test; i++)
	{
		cout << i << ". quastion? ";
		cin >> name;
		outQ << name << endl;
		cout << "answer? ";
		cin >> name;
		outA << name << endl;
	}
	outQ.close();
	outA.close();
}
void Test::Add_Test_Import()
{
	string name, str;
	int colvo_test;
	cout << "Name Test? ";
	cin >> name;
	ofstream outQ("Test_" + name + "_Quastions.txt");
	ofstream outA("Test_" + name + "_Answers.txt");

	cout << "Name Test quastion import? ";
	cin >> name;
	ifstream inQ(name);

	cout << "Name Test answers import? ";
	cin >> name;
	ifstream inA(name);

	while (!inQ.eof())
	{
		str = "";
		getline(inQ, str);
		outQ << str << endl;
	}

	while (!inA.eof())
	{
		str = "";
		getline(inA, str);
		outA << str << endl;
	}

	inQ.close();
	inA.close();
	outQ.close();
	outA.close();
}
void Test::Add_QuastionInTest(string choise)
{
	string pathQ = "Test_" + choise + "_Quastions.txt";
	ofstream outQ;
	outQ.open(pathQ, ofstream::app);

	string pathA = "Test_" + choise + "_Answers.txt";
	ofstream outA;
	outA.open(pathA, ofstream::app);

	string name;
	int colvo_test;
	cout << "Col_vo tests you want add? ";
	cin >> colvo_test;

	for (int i = 1; i <= colvo_test; i++)
	{
		cout << i << ". quastion? ";
		cin >> name;
		outQ << name << endl;
		cout << "answer? ";
		cin >> name;
		outA << name << endl;
	}
	outQ.close();
	outA.close();
}
void Test::Add_TestInFile_NameTest(string name)
{
	string path = "List_tests_name.txt";
	ofstream out;
	out.open(path, ofstream::app);
	out << name << endl;
	out.close();
}

//Print
void Test::Print_Test(string choise)
{
	ifstream in("Test_" + choise + "_Quastions.txt");
	string str;
	ifstream in2("Test_" + choise + "_Answers.txt");
	string str2;

	//count list
	int i = 1;

	while (!in.eof() || !in2.eof())
	{
		str = "";
		getline(in, str);
		str2 = "";
		getline(in2, str2);
		cout << i << ". " << str << " - " << str2 << endl;
		i++;
	}
	in.close();
	in2.close();
}


