#pragma once
#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class clsDate
{
	struct stDate
	{
		int Day = 0;
		int Month = 0;
		int Year = 0;
		int Hour = 0;
		int Minute = 0;
		int Second = 0;
		string AM_PM = "";
	};
	static string IsTimeAM_Or_PM(int Hour)
	{
		return (Hour < 12) ? "AM" : "PM";
	}
	static stDate GetDate()
	{
		stDate Date;
		time_t t = time(0); // get time now
		tm* now = localtime(&t);
		Date.Day = now->tm_mday;
		Date.Month = now->tm_mon + 1;
		Date.Year = now->tm_year + 1900;
		Date.Hour = now->tm_hour;
		Date.Minute = now->tm_min;
		Date.AM_PM = IsTimeAM_Or_PM(Date.Hour);
		return Date;
	}
	static string ConvertDateToString()
	{
		stDate Date = GetDate();
		string DateString = "";
		DateString = to_string(Date.Month) + "/" + to_string(Date.Day) + "/" + to_string(Date.Year);
		return DateString;
	}
	static string ConvertTimeToString()
	{
		stDate Date = GetDate();
		string TimeString = "";
		TimeString = to_string(Date.Hour) + ":" + to_string(Date.Minute) + " " + Date.AM_PM;
		return TimeString;
	}
	friend class clsPurchaseProductScreen;
};

