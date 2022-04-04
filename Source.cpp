#include<iostream>
#include<string>


using namespace std;

//Class used if an invalid day is entered
class invalidDay

{

	string msg;

public:

	invalidDay()

	{

		msg = "The Day input is wrong. Please enter a valid day next time!";

	}

	void showException()

	{

		cout << msg << endl;

	}

};

//Class used if an invalid month is entered
class invalidMonth

{

	string msg;

public:

	invalidMonth()

	{

		msg = "Month input is wrong";

	}

	void showException()

	{

		cout << msg << endl;

	}

};

//Class used if an invalid year is entered
class leapYear

{

	string msg;

public:

	leapYear()

	{

		msg = "year input is wrong";

	}

	void showException()

	{

		cout << msg << endl;

	}

};

void read_date(int& d, int& m, int& y)

{

	cout << "Enter day of the Month:" << endl;

	cin >> d;

	if (d <= 0 || d > 31) //sets parameter of common amount of days in a month

		throw invalidDay(); //calls day message

	cout << "Enter month:" << endl;

	cin >> m;

	if (m <= 0 || m >= 13)

		throw invalidMonth(); //calls month message

	cout << "Enter birth year (4 numbers):" << endl;

	cin >> y;

	if (y % 400 == 0 || (y != 100 && y % 4 == 0)) //Calculates leap year

		if (d >= 30)

			throw leapYear(); //calls leap year message

}
void read_date(int& day, int& month, int& year);

//Main function
int main()

{

	int day, month, year;

	string months[12] = { "January","Feburary","March",

	"April","May","June","July","August","September",

	"October","November","December" };  //String given depending on the month 

	try

	{

		read_date(day, month, year);

		cout << " Your Date of Birth is: " << months[month - 1] << " " << day << ", " << year << endl;
		cout << "Thank you for using the numeric to date calculator!" << endl << "Goodbye!" << endl;

	}

	catch (invalidDay id)

	{

		id.showException();

	}

	catch (invalidMonth im)

	{

		im.showException();

	}

	catch (leapYear ly)

	{

		ly.showException();

	}

	system("pause");

	return 0;

}

