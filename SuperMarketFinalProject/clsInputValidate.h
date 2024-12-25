#pragma once
#include <iostream>
#include <string>
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsInputValidate
{
public:
	static bool IsNumberBetweenNumbersRange(int N1, int N2 ,int Number)
	{
		return (Number >= N1) && (Number <= N2);
	}
	static bool IsNumberValid(string Number)
	{
		for (int i = 0; i < Number.length(); i++)
		{
			if (int(Number[i]) < 48 || int(Number[i] > 57))
				return false;
		}
		return true;
	}
	static int ReadNumber()
	{
		int Number = 0;
		cin >> Number;
		return Number;
	}
	static float ReadFloatNumber()
	{
		float Number = 0;
		cin >> Number;
		return Number;
	}
	static string ReadString()
	{
		string Choice = "";
		getline(cin >> ws, Choice);
		return Choice;
	}
	static bool ValidateInputNumber(int N1, int N2, string Number)
	{
		if (!IsNumberValid(Number))
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Invalid Number, Please try again.\n";
			system("pause > 0");
			return false;
		}
		else if (!IsNumberBetweenNumbersRange(N1, N2, stoi(Number)))
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Number out of range, Please enter Number Choice between " 
				<< N1 << " and " << N2 << endl;
			system("pause > 0");
			return false;
		}
		return true;
	}
};

