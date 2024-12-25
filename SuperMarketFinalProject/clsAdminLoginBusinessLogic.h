#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsUtil.h"

using namespace std;

string AdminFile = "AdminLoginPassword.txt";

template <typename T>

class clsAdminLoginBusinessLogic
{
public:
	static bool IsAdminPasswordCorrect(string Password)
	{
		fstream NewFile;
		string Line = "";
		NewFile.open(AdminFile, ios::in);
		if (NewFile.is_open())
		{
			getline(NewFile, Line);
			if (clsUtil<string>::DecryptPassword(Line) == Password)
			{
				NewFile.close();
				return true;
			}
		}
		return false;
	}
	static void ChangeAdminPassword(string Password)
	{
		fstream NewFile;
		string Line = "";
		NewFile.open(AdminFile, ios::out);
		if (NewFile.is_open())
		{
			NewFile << clsUtil<string>::EncryptString(Password) << endl;
		}
		NewFile.close();
	}
};

