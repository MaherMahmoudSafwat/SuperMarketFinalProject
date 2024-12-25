#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template <typename T>

class clsUtil
{
public:
	static string NumberOfTabs(int NumberOfTabs = 0)
	{
		string Tabs = "";
		for (int i = 0; i < NumberOfTabs; i++)
		{
			Tabs += "\t";
		}
		return Tabs;
	}
	static string NumberOfSpaces(int SpaceNumbers = 0)
	{
		string Spaces = "";
		for (int i = 0; i < SpaceNumbers; i++)
		{
			Spaces += " ";
		}
		return Spaces;
	}
	static string EncryptString(string Passwords)
	{
		for (int i = 0; i < Passwords.length(); i++)
		{
			Passwords[i] = char(int(Passwords[i]) + 3);
		}
		return Passwords;
	}
	static string DecryptPassword(string Passwords)
	{
		for (int i = 0; i < Passwords.length(); i++)
		{
			Passwords[i] = char(int(Passwords[i]) - 3);
		}
		return Passwords;
	}
	static vector<string>SplitString(string Line, string Separator = "#//#")
	{
		string Word = "";
		int Pos = 0;
		vector<string>Words;
		while (Line.find(Separator) != std::string::npos)
		{
			Pos = Line.find(Separator);
			Word = Line.substr(0, Pos);
			if (Word != "")
			{
				Words.push_back(Word);
			}
			Line.erase(0, Pos + Separator.length());
		}
		if (Line != "")
		{
			Words.push_back(Line);
		}
		return Words;
	}
	static int GetRandomNumber(int From, int To)
	{
		int RandomNumber = 0;
		RandomNumber = rand() % ((To - From) + 1) + To;
		return RandomNumber;
	}
};

