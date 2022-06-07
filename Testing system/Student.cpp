#include "Student.h"

//Regisrtation and profil
void Student::Registr_student(string Logg, string Pas)
{
	ofstream out(Logg + ".txt");

	this->login.Log = Logg;
	out << this->login.Log << endl;
	this->login.Pass = Pas;
	out << this->login.Pass << endl;

	cout << "Name:";
	cin >> this->FIO.Name;
	out << this->FIO.Name << endl;
	cout << "Female:";
	cin >> this->FIO.Surname;
	out << this->FIO.Surname << endl;
	cout << "Name2:";
	cin >> this->FIO.Female;
	out << this->FIO.Female << endl;
	cout << "Adress:";
	cin >> this->Adress;
	out << this->Adress << endl;
	cout << "Phone:";
	cin >> this->Phone;
	out << this->Phone << endl;

	out.close();

	Add_loginInFile(Logg);
}
void Student::Add_loginInFile(string log)
{
	string path = "Students_login.txt";
	ofstream out;
	out.open(path, ofstream::app);
	out << log << endl;
	out.close();
}
void Student::PrintListStudent()
{
	ifstream in("Students_login.txt");
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
string Student::GetStudentLogin(int choise)
{
	ifstream in("Students_login.txt");
	string str, log;
	//count list
	int i = 1;

	while (!in.eof())
	{
		str = "";
		getline(in, str);
		i++;
		if (i == choise) log = str;
	}
	in.close();

	return log;
}
void Student::Edit_Student(string log)
{
	ifstream in(log + ".txt");
	string str;

	//count list
	int i = 1;
	int choise;
	string l, pas, n, s, f, a, p;

	for (i; i <= 7; i++)
	{
		str = "";
		getline(in, str);

		switch (i)
		{
		case 1:
		{
			cout << i << ". Login " << str << endl;
			l = str;
		}
		break;
		case 2:
		{
			cout << i << ". Password " << str << endl << endl;
			pas = str;
		}
		break;
		case 3:
		{
			cout << i << ". Name " << str << endl;
			n = Edit_Student_2(str);
		}
		break;
		case 4:
		{
			cout << i << ". Surname " << str << endl;
			s = Edit_Student_2(str);
		}
		break;
		case 5:
		{
			cout << i << ". Female " << str << endl;
			f = Edit_Student_2(str);
		}
		break;
		case 6:
		{
			cout << i << ". Adres " << str << endl;
			a = Edit_Student_2(str);
		}
		break;
		case 7:
		{
			cout << i << ". Phone " << str << endl;
			p = Edit_Student_2(str);
		}
		break;
		default:
			break;
		}
	}
	in.close();

	ofstream out(log + ".txt");

	out << l << endl;
	out << pas << endl;
	out << n << endl;
	out << s << endl;
	out << f << endl;
	out << a << endl;
	out << p << endl;

	out.close();
}
string Student::Edit_Student_2(string str)
{
	int choise;
	string x;
	cout << "Edit?" << endl << "1 - yes\t2 - no" << endl;
	cin >> choise;
	if (choise == 1)
	{
		cout << "new?" << endl;
		cin >> x;
		return x;
	}
	else return str;

}

//Tests
void Student::Start_test(string choise, string log)
{
	ofstream out(log + " - Test_" + choise + "_Answers.txt");

	ifstream in("Test_" + choise + "_Quastions.txt");
	string str;

	ifstream A_in("Test_" + choise + "_Answers.txt");
	string strA;

	//count list
	int i = 1;
	int grade = 0;

	while (!in.eof())
	{
		str = "";
		getline(in, str);
		cout << i << ". " << str << "\t";
		cin >> choise;

		strA = "";
		getline(A_in, strA);
		if (choise == strA)
		{
			grade++;
			out << str << " - " << choise << " /RIGHT" << endl;
		}
		else out << str << " - " << choise << " /WRONG" << endl;
		i++;
	}
	in.close();
	A_in.close();
	grade = Get_Right_grade(i, grade);
	out << "GRADE - " << grade << endl;
	cout << "GRADE - " << grade << endl;
	out.close();
}
void Student::Check_last_test(string choise, string log)
{
	ifstream in(log + " - Test_" + choise + "_Answers.txt");
	string str;

	//count list
	int i = 1;

	while (!in.eof())
	{
		str = "";
		getline(in, str);
		cout << i << ". " << str << endl;
	}
	in.close();
}
int Student::Get_Right_grade(int count_quest, int grade)
{
	double G = grade;
	G = G / count_quest * 12;
	grade = G;
	G = G - grade;
	if (G >= 0.5) grade++;
	return grade;
}

//Delete
void Student::Dell_Student_File(string log)
{
	string str = log + ".txt";
	char Mass[30];
	strncpy_s(Mass, str.c_str(), str.length() + 1);
	remove(Mass);

	Dell_StudentLogin_InFile(log);
}
void Student::Dell_StudentLogin_InFile(string log)
{
	ifstream file_in;
	file_in.open("Students_login.txt");

	ifstream in("Students_login.txt");
	string str;

	int i = 0;
	int i_number_line_delete = 0;

	while (!in.eof())
	{
		i++;
		str = "";
		getline(in, str);
		if (str == log)
		{
			i_number_line_delete = i;
			break;
		}
	}
	in.close();

	int i_number_line_now = 0; //счётчик строк
	string line; //для хранения строки
	string line_file_text; //для хранения текста файла

	while (getline(file_in, line))
	{
		i_number_line_now++;
		if (!(i_number_line_now == i_number_line_delete))
		{
			line_file_text.insert(line_file_text.size(), line);
			line_file_text.insert(line_file_text.size(), "\r\n");
		}
	}
	file_in.close();
	ofstream file_out;
	file_out.open("Students_login.txt", ios::trunc | ios::binary);
	file_out.write(line_file_text.c_str(), line_file_text.size());
	file_out.clear();
}



