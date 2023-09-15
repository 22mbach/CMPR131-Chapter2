//Isaac Bach
//Date: 9/6/2023
//Description: assignment 2

#include <iostream>
#include "input.h"
#include "Quadratic.h"
#include "Option1.h"
#include "PseudorandomGenerator.h"
#include "Option2.h"
#include "Rational.h"
#include "Option3.h"
using namespace std;

int menuOption();
void option1();
void option2();
void option3();

int main()
{
	do
	{
		switch (menuOption())
		{
		case 'X': exit(1); break;
		case '1': option1(); break;
		case '2': option2(); break;
		case '3': option3(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

int menuOption()
{
	cout << "\nChapter 2 Assignment by Isaac Bach";
	cout << "\n" << string(100, char(205));
	cout << "\n\t1) Quadratic Expresstion";
	cout << "\n\t2) Pseudorandom";
	cout << "\n\t3) Rational Number";
	cout << "\n" << string(100, char(196));
	cout << "\n\tX) Exit";
	cout << "\n" << string(100, char(205));

	return toupper(inputChar("\n\tOption: ", static_cast<string>("123X")));
}

void option1()
{
	Option1();

	return;
}

void option2()
{
	Option2();

	return;
}

void option3()
{
	Option3();

	return;
}