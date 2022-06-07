#pragma once
#include "Include.h" 

struct Login
{
	string Log, Pass;
};

struct FIO
{
	string Name, Surname, Female;
};

class Student
{
	FIO FIO;
	string Adress, Phone;
	Login login;

public:
	Student() = default;

	//Registration student
	void Registr_student(string Log, string Pass);

	//Algorithm return right grade
	int Get_Right_grade(int count_quest, int grade);

	//Star test, add test studenta in file, give grade
	void Start_test(string choise, string log);

	//Add student's login in Fila Students_login.txt
	void Add_loginInFile(string log);

	//Print student's tests and logins
	void Check_last_test(string choise, string log);
	void PrintListStudent();

	//Edit student's profile
	void Edit_Student(string log);
	string Edit_Student_2(string str);

	//Delete student File and login
	void Dell_Student_File(string log);
	void Dell_StudentLogin_InFile(string log);

	//return student's login
	string GetStudentLogin(int choise);
};


