#include "Admin.h"

void Admin::Registr_admin(string log, string pass)
{
	this->login.Log = log;
	this->login.Pass = pass;
}

//Get Login or Password
string Admin::GetLogin()
{
	return this->login.Log;
}
string Admin::GetPassword()
{
	return this->login.Pass;
}

//Set Login or Password
void Admin::SetLogin()
{
	cout << "Login?";
	cin >> this->login.Log;
}
void Admin::SetPassword()
{
	cout << "Password?";
	cin >> this->login.Pass;
}

