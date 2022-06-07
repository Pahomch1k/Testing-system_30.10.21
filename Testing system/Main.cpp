#include "Admin.h"
#include "Student.h"
#include "Test.h"
#include "Include.h"
using namespace std;

//Function for student and admin
//Add student's logins in array and add count login
int Add_students_login_inarray(const int Count_Students, array<string, 11>& Student_array);

//Print all tests name
void Print_list_tests();

//student's choise name test
string Choise_test(int choise);

//Get count tests
int Get_count_tests();

//Shifryet password
string Secret(string str);

//Choise name test
string ChoiseNameTest(int choise);

//Choise name test int
int ChoiseNameTestInt();

//Check student in array
string CheckStudentInArray(const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud, int choise);

//Get student login
string GetStudentLogin(const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud, Student& stud);

//Add student
void AddStudent(const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud);

//ADMIN
//Admin Choise and Prava
void AdminPrava(Admin& admin, int choise, const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud);
//Admin Login
void AdminLog(Admin& admin, int choise, const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud);
//Admin Registr
void AdminRegistr(Admin& admin);


//Function for student and admin
string Secret(string str)
{
	for (int i = 0; i < str.size(); i++) str[i] = str[i] + 3;
	return str;
}
int Add_students_login_inarray(const int Count_Students, array<string, 11>& Student_array)
{
	ifstream in("Students_login.txt");
	string str;
	try
	{
		locale().global(locale(""));
		ifstream h("Students_login.txt");
		string str;
		getline(h, str);
		if (h.eof() && str.empty())
		{
			in.close();
			h.close();
			throw(0);
		}
		else
		{
			int i = 0;
			while (!in.eof())
			{
				str = "";
				getline(in, str);
				Student_array[i] = str;
				i++;
			}
			in.close();
			h.close();
			return i;
		}
	}
	catch (int r)
	{
		in.close();
		return r;
	}
}
void Print_list_tests()
{
	ifstream in("List_tests_name.txt");
	string str;

	//count list
	int i = 1;

	while (!in.eof())
	{
		str = "";
		getline(in, str);
		cout << i << ". " << str << endl;
		i++;
	}
	in.close();
}
string Choise_test(int choise)
{
	ifstream in("List_tests_name.txt");
	string str;

	//count list
	int i = 0;

	while (!in.eof())
	{
		str = "";
		getline(in, str);
		if (i == choise) return str;
		i++;
	}
	in.close();
}
int Get_count_tests()
{
	ifstream in("List_tests_name.txt");
	string str;

	//count list
	int i = 0;

	while (!in.eof())
	{
		str = "";
		getline(in, str);
		i++;
	}
	in.close();
	return i;
}
string ChoiseNameTest(int choise)
{
	string Name_test = Choise_test(choise - 1);
	return Name_test;
}
int ChoiseNameTestInt()
{
	int choise = 0;
	Print_list_tests();
	cin >> choise;
	return choise;
}
string CheckStudentInArray(const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud, int choise)
{
	Student stud;
	string log = stud.GetStudentLogin(choise + 1);

	//Check right login
	int e = 0;
	for (size_t q = 0; q < Count_Students; q++) if (Student_array[q] == log) e++;

	if (e == 1) return log;
	else return "no";
}
string GetStudentLogin(const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud, Student& stud)
{
	int ch;
	stud.PrintListStudent();
	cout << "Who? "; cin >> ch;
	return CheckStudentInArray(Count_Students, Student_array, CountArrStud, ch);
}

//Student  
void StudenPrava(Student& stud, int choise, const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud)
{
	system("cls");
	string log, pas;
	cout << "Login?";
	cin >> log;
	cout << "Password?";
	cin >> pas;

	//Check right login
	int e = 0;
	for (size_t q = 0; q < Count_Students; q++) if (Student_array[q] == log) e++;

	if (e == 1)
	{
		ifstream in(log + ".txt");
		string str;
		pas = Secret(pas);

		//flag while 
		int r = 0;
		while (!in.eof())
		{
			str = "";
			getline(in, str); r++;
			if (r == 2) if (str == pas) e++;
		}
		in.close();
	}

	if (e == 2)
	{
		//flag while
		int x = 0;
		while (x == 0)
		{
			cout << endl
				<< "1. Start Test" << endl
				<< "2. Check last Test" << endl
				<< "3. Exit" << endl;
			cin >> choise;

			switch (choise)
			{
			case 1:
			{
				choise = ChoiseNameTestInt();
				if (choise > 0 || choise < Get_count_tests()) stud.Start_test(ChoiseNameTest(choise), log);
				else cout << "Error. Again please";
			}
			break;
			case 2:
			{
				choise = ChoiseNameTestInt();
				if (choise > 0 || choise < Get_count_tests()) stud.Check_last_test(ChoiseNameTest(choise), log);
				else cout << "Error. Again please";
			}
			break;
			case 3: x = 1;
				break;
			default:
				break;
			}
		}
	}
	else cout << "Password wrong" << endl;
}
void StudentLog(Student& stud, int choise, const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud)
{
	system("cls");
	//flag while
	int y = 0;

	while (y == 0)
	{
		cout << endl
			<< "1. Come" << endl
			<< "2. Registr" << endl
			<< "3. Exit" << endl;
		cin >> choise;

		switch (choise)
		{
		case 1: StudenPrava(stud, choise, Count_Students, Student_array, CountArrStud); break;
		case 2: AddStudent(Count_Students, Student_array, CountArrStud); break;
		case 3: y++; break;
		default: cout << "Error. Again please" << endl; break;
		}
	}
}
void AddStudent(const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud)
{
	Student stud;
	string lg, pss;
	cout << "Login: ";
	cin >> lg;

	//Check double login
	int e = 0;
	for (size_t q = 0; q < Count_Students; q++) if (Student_array[q] == lg) e++;

	if (e == 0)
	{
		Student_array[CountArrStud] = lg;
		CountArrStud++;
		cout << "Password: ";
		cin >> pss;
		pss = Secret(pss);
		stud.Registr_student(lg, pss);
	}
	else cout << "Login is busy" << endl;
}

//Admin
void AdminPrava(Admin& admin, int choise, const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud)
{
	system("cls");
	//flag while
	int x = 0;
	while (x == 0)
	{
		Test test;
		cout << endl
			<< "1. Add Test" << endl
			<< "2. Show Test" << endl
			<< "3. Edit Students" << endl
			<< "4. Edit Login or Password" << endl
			<< "5. Exit" << endl;
		cin >> choise;

		switch (choise)
		{
		case 1:
		{
			choise = 0;
			cout << endl
				<< "1. Add all test?" << endl
				<< "2. Add quastion?" << endl
				<< "3. Import test?" << endl
				<< "4. Exit" << endl;
			cin >> choise;

			switch (choise)
			{
			case 1: test.Add_Test();
				break;
			case 2:
			{
				choise = ChoiseNameTestInt();
				if (choise > 0 || choise < Get_count_tests()) test.Add_QuastionInTest(ChoiseNameTest(choise));
				else cout << "Error. Again please";
			}
			break;
			case 3: test.Add_Test_Import();
				break;
			case 4: x = 1;
				break;
			default:
				break;
			}
		}
		break;
		case 2:
		{
			choise = ChoiseNameTestInt();
			if (choise > 0 || choise < Get_count_tests()) test.Print_Test(ChoiseNameTest(choise));
			else cout << "Error. Again please";
		}
		break;
		case 3:
		{
			choise = 0;
			cout << endl
				<< "1. Add Student?" << endl
				<< "2. Dell Student?" << endl
				<< "3. Edit 1 Student?" << endl
				<< "4. Exit" << endl;
			cin >> choise;

			switch (choise)
			{
			case 1: AddStudent(Count_Students, Student_array, CountArrStud);
				break;
			case 2:
			{
				Student stud;
				string log = GetStudentLogin(Count_Students, Student_array, CountArrStud, stud);
				if (log == "no") cout << "Error. Again please";
				else
				{
					stud.Dell_StudentLogin_InFile(log);
					stud.Dell_Student_File(log);
				}
			}
			break;
			case 3:
			{
				Student stud;
				string log = GetStudentLogin(Count_Students, Student_array, CountArrStud, stud);
				if (log == "no") cout << "Error. Again please";
				else stud.Edit_Student(log);
			}
			break;
			case 4: x = 1;
				break;
			default:
				break;
			}
		}
		break;
		case 4:
		{
			choise = 0;
			cout << endl;
			cout << "1. Edit Login" << endl << "2. Edit Password" << endl;
			cin >> choise;
			if (choise == 1) admin.SetLogin();
			else if (choise == 2) admin.SetPassword();
			else cout << "Error. Again please";
		}
		break;
		case 5: x = 1;
			break;
		default:
			break;
		}
	}
}
void AdminLog(Admin& admin, int choise, const int& Count_Students, array<string, 11>& Student_array, int& CountArrStud)
{
	//flag while
	int y = 0;

	while (y == 0)
	{
		string log, pas;
		cout << "Login?";
		cin >> log;
		cout << "Password?";
		cin >> pas;

		log = Secret(log);
		pas = Secret(pas);

		if (log == admin.GetLogin() && pas == admin.GetPassword())
		{
			AdminPrava(admin, choise, Count_Students, Student_array, CountArrStud);
			y++;
		}
		else
		{
			cout << "Incorrect Password and Login. Try again." << endl;
			y++;
		}
	}
}
void AdminRegistr(Admin& admin)
{
	string l, p;
	cout << "Login:"; cin >> l;
	cout << "Password:"; cin >> p;
	l = Secret(l);
	p = Secret(p);
	admin.Registr_admin(l, p);
}

int main()
{
	setlocale(0, "");

	const int Count_Students = 11;
	array<string, Count_Students> Student_array;

	//Add student's logins in array and add count login
	int CountArrStud = Add_students_login_inarray(Count_Students, Student_array);

	int choise = 0;
	Student stud;
	Admin admin;

	cout << "Add Admin" << endl;
	AdminRegistr(admin);

	//flag while
	int t = 0;
	while (t == 0)
	{
		system("cls");
		cout << "1. Admin" << endl << "2. Student" << endl << "3. Exit" << endl;
		cin >> choise;

		if (choise == 1) AdminLog(admin, choise, Count_Students, Student_array, CountArrStud);
		else if (choise == 2) StudentLog(stud, choise, Count_Students, Student_array, CountArrStud);
		else if (choise == 3) t++;
		else cout << "Error. Again please" << endl;
	}
}