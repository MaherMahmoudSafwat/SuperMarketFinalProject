#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsCustomer.h"
#include "clsUtil.h"

using namespace std;

string FileName = "Customers.txt";

class clsCustomerLoginBusinessLogic : public clsCustomer
{
private:
	static string _ConvertCustomerInfoObjectToLine(clsCustomer CustomerInfoObject, string Separator = "#//#")
	{
		string CustomerInfoLine = "";
		CustomerInfoLine += to_string(CustomerInfoObject.GetCustomerID()) + Separator;
		CustomerInfoLine += CustomerInfoObject.GetCustomerName() + Separator;
		CustomerInfoLine += clsUtil<string>::EncryptString(CustomerInfoObject.GetCustomerPassword()) + Separator;
		CustomerInfoLine += CustomerInfoObject.GetCustomerEmail() + Separator;
		CustomerInfoLine += CustomerInfoObject.GetCustomerPhoneNumber();
		return CustomerInfoLine;
	}
	static clsCustomerLoginBusinessLogic _ConvertCustomerInfoLineToObject(string Line)
	{
		vector<string>CustomerInfoData;
		CustomerInfoData = clsUtil<string>::SplitString(Line);
		return clsCustomerLoginBusinessLogic(stoi(CustomerInfoData[0]), CustomerInfoData[1], 
			clsUtil<string>::DecryptPassword(CustomerInfoData[2]), CustomerInfoData[3],CustomerInfoData[4]);
	}
public:
	clsCustomerLoginBusinessLogic(int CustomerID, string CustomerName, string CustomerPassword, string CustomerEmail,
		string CustomerPhoneNumber) :clsCustomer(CustomerID, CustomerName, CustomerPassword, CustomerEmail, CustomerPhoneNumber) {}
	static vector <clsCustomerLoginBusinessLogic> GetAllCustomerInfoData()
	{
		fstream NewFile;
		string Line = "";
		vector < clsCustomerLoginBusinessLogic> AllCustomersInfo;
		clsCustomerLoginBusinessLogic CustomerInfo(0, "", "", "", "");
		NewFile.open(FileName, ios::in);
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				CustomerInfo = _ConvertCustomerInfoLineToObject(Line);
				AllCustomersInfo.push_back(CustomerInfo);
			}
		}
		NewFile.close();
		return AllCustomersInfo;
	}
	static bool IsCustomerCredentianlsCorrect(string Email , string Password)
	{
		vector<clsCustomerLoginBusinessLogic>AllCustomerInfo = GetAllCustomerInfoData();
		for (clsCustomerLoginBusinessLogic& CustomerInfo : AllCustomerInfo)
		{
			if (CustomerInfo.CustomerEmail == Email && CustomerInfo.CustomerPassword == Password)
				return true;
		}
		return false;
	}
	void AddNewCustomerLoginSignUp()
	{
		fstream NewFile;
		NewFile.open(FileName, ios::out | ios::app);
		if (NewFile.is_open())
		{
			NewFile << _ConvertCustomerInfoObjectToLine(*this) << endl;
		}
		NewFile.close();
	}
	static bool IsCustomerIdExists(int CustomerID)
	{
		vector<clsCustomerLoginBusinessLogic>AllCustomerInfo = GetAllCustomerInfoData();
		for (clsCustomerLoginBusinessLogic& CustomerInfo : AllCustomerInfo)
		{
			if (CustomerInfo.CustomerID == CustomerID)
				return true;
		}
		return false;
	}
	static bool IsCustomerPasswordExists(string CustomerPassword)
	{
		vector<clsCustomerLoginBusinessLogic>AllCustomerInfo = GetAllCustomerInfoData();
		for (clsCustomerLoginBusinessLogic& CustomerInfo : AllCustomerInfo)
		{
			if (CustomerInfo.CustomerPassword == CustomerPassword)
				return true;
		}
		return false;
	}
	static bool IsCustomerEmailExists(string CustomerEmail)
	{
		vector<clsCustomerLoginBusinessLogic>AllCustomerInfo = GetAllCustomerInfoData();
		for (clsCustomerLoginBusinessLogic& CustomerInfo : AllCustomerInfo)
		{
			if (CustomerInfo.CustomerEmail == CustomerEmail)
				return true;
		}
		return false;
	}
	static bool IsCustomerPhoneNumberExists(string CustomerPhoneNumber)
	{
		vector<clsCustomerLoginBusinessLogic>AllCustomerInfo = GetAllCustomerInfoData();
		for (clsCustomerLoginBusinessLogic& CustomerInfo : AllCustomerInfo)
		{
			if (CustomerInfo.CustomerPhoneNumber == CustomerPhoneNumber)
				return true;
		}
		return false;
	}
	static int ReturnCustomerID(string Email, string Password)
	{
		vector<clsCustomerLoginBusinessLogic>AllCustomerInfo = GetAllCustomerInfoData();
		for (clsCustomerLoginBusinessLogic& CustomerInfo : AllCustomerInfo)
		{
			if (CustomerInfo.CustomerEmail == Email && CustomerInfo.CustomerPassword == Password)
				return CustomerInfo.CustomerID;
		}
		return 0 ;
	}
	void UpdateCustomerPersonalInfo()
	{
		vector<clsCustomerLoginBusinessLogic>AllCustomerInfo = GetAllCustomerInfoData();
		fstream NewFile;
		string Line = "";
		clsCustomerLoginBusinessLogic UpdateCustomerData = *this;
		NewFile.open(FileName, ios::out);
		if (NewFile.is_open())
		{
			for (clsCustomerLoginBusinessLogic& PersonalInfo : AllCustomerInfo)
			{
				if (PersonalInfo.CustomerID == UpdateCustomerData.CustomerID)
				{
					NewFile << _ConvertCustomerInfoObjectToLine(UpdateCustomerData) << endl;
				}
				else
				{
					NewFile << _ConvertCustomerInfoObjectToLine(PersonalInfo) << endl;
				}
			}
		}
		NewFile.close();
	}
	static clsCustomerLoginBusinessLogic FindCustomerInfo(int ID)
	{
		vector<clsCustomerLoginBusinessLogic>AllCustomerInfo = GetAllCustomerInfoData();
		for (clsCustomerLoginBusinessLogic& PersonalInfo : AllCustomerInfo)
		{
			if (PersonalInfo.CustomerID == ID)
				return PersonalInfo;
		}
		return clsCustomerLoginBusinessLogic(0, "", "", "", "");
	}
	void DeleteCustomerInfo()
	{
		vector<clsCustomerLoginBusinessLogic>AllCustomerInfo = GetAllCustomerInfoData();
		fstream NewFile;
		string Line = "";
		clsCustomer UpdateCustomerData = *this;
		NewFile.open(FileName, ios::out);
		if (NewFile.is_open())
		{
			for (clsCustomer& PersonalInfo : AllCustomerInfo)
			{
				if (PersonalInfo.CustomerID == UpdateCustomerData.CustomerID)
				{
					continue;
				}
				NewFile << _ConvertCustomerInfoObjectToLine(PersonalInfo) << endl;
			}
		}
		NewFile.close();
	}
};

