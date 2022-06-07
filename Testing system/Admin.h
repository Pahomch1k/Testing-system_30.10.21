#pragma once
#include "Include.h" 

struct Login_Admin
{
	string Log, Pass;
};

class Admin
{
	Login_Admin login;

public:

	Admin() = default;

	void Registr_admin(string log, string pass);

	//Get Login or Password
	string GetLogin();
	string GetPassword();

	//Set Login or Password
	void SetLogin();
	void SetPassword();
};



