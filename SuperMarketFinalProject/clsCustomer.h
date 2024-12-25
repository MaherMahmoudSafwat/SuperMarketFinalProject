#pragma once
#include <iostream>

using namespace std;

class clsCustomer
{
private:
	int _CustomerID = 0;
	string _CustomerName = "";
	string _CustomerPassword = "";
	string _CustomerEmail = "";
	string _CustomerPhoneNumber = "";
public:
	clsCustomer(int CustomerID, string CustomerName, string CustomerPassword, string CustomerEmail, string CustomerPhoneNumber)
	{
		_CustomerID = CustomerID;
		_CustomerName = CustomerName;
		_CustomerPassword = CustomerPassword;
		_CustomerEmail = CustomerEmail;
		_CustomerPhoneNumber = CustomerPhoneNumber;
	}
	void SetCustomerID(int CustomerID)
	{
		_CustomerID = CustomerID;
	}
	int GetCustomerID()
	{
		return _CustomerID;
	}
	_declspec(property(put = SetCustomerID, get = GetCustomerID))int CustomerID;
	void SetCustomerName(string CustomerName)
	{
		_CustomerName = CustomerName;
	}
	string GetCustomerName()
	{
		return _CustomerName;
	}
	_declspec(property(put = SetCustomerName, get = GetCustomerName))string CustomerName;
	void SetCustomerPassword(string CustomerPassword)
	{
		_CustomerPassword = CustomerPassword;
	}
	string GetCustomerPassword()
	{
		return _CustomerPassword;
	}
	_declspec(property(put = SetCustomerPassword, get = GetCustomerPassword))string CustomerPassword;
	void SetCustomerEmail(string CustomerEmail)
	{
		_CustomerEmail = CustomerEmail;
	}
	string GetCustomerEmail()
	{
		return _CustomerEmail;
	}
	_declspec(property(put = SetCustomerEmail, get = GetCustomerEmail))string CustomerEmail;
	void SetCustomerPhoneNumber(string CustomerNumber)
	{
		_CustomerPhoneNumber = CustomerNumber;
	}
	string GetCustomerPhoneNumber()
	{
		return _CustomerPhoneNumber;
	}
	_declspec(property(put = SetCustomerPhoneNumber, get = GetCustomerPhoneNumber))string CustomerPhoneNumber;
};

