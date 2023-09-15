#pragma once
#include "Rational.h"

void Option3()
{
	//create class object
	Rational R1;
	Rational R2;

	do
	{
		cout << "\n3) Rational Number Menu";
		cout << "\n" << string(100, char(205));
		cout << "\n\tA. Enter values of rational number R1";
		cout << "\n\tB. Display R1";
		cout << "\n\tC. Enter values of rational number R2";
		cout << "\n\tD. Display R2";
		cout << "\n\tE. Multiplication of 2 rational numbers (R1 * R2)";
		cout << "\n\tF. Division of 2 rational numbers (R1 / R2)";
		cout << "\n\tG. Addition of 2 rational numbers (R1 + R2)";
		cout << "\n\tH. Subtraction of 2 rational numbers (R1 - R2)";
		cout << "\n\tI. (R1 == R2)"; //return true if R1 == R2, if not, return false
		cout << "\n\tJ. (R1 < R2)"; //return true if R1 < R2, if not, return false
		cout << "\n" << string(100, char(196));
		cout << "\n\t0. Return";
		cout << "\n" << string(100, char(205));
		char option = inputChar("\n\tOption: ", static_cast<string>("ABCDEFGHIJ0"));

        switch (toupper(option))
        {
        case '0': return; break;

        case 'A':
        {
            int num = inputInteger("\nEnter the numerator of R1: ");
            int denom = inputInteger("\nEnter the denominator of R1: ");
            R1 = Rational(num, denom);
            R1.normalize();
            break;
        }

        case 'B':
        {
            cout << "\nRational Number R1: " << R1 << endl;
            break;
        }

        case 'C':
        {
            int num = inputInteger("\nEnter the numerator of R2: ");
            int denom = inputInteger("\nEnter the denominator of R2: ");
            R2 = Rational(num, denom);
            R2.normalize();
            break;
        }

        case 'D':
        {
            cout << "\nRational Number R2: " << R2 << endl;
            break;
        }

        case 'E':
        {
            Rational result = R1.multiply(R2);
            cout << "\nR1 * R2 = " << result << endl;
            break;
        }

        case 'F':
        {
            Rational result = R1.divide(R2);
            cout << "\nR1 / R2 = " << result << endl;
            break;
        }

        case 'G':
        {
            Rational result = R1.add(R2);
            cout << "\nR1 + R2 = " << result << endl;
            break;
        }

        case 'H':
        {
            Rational result = R1.subtract(R2);
            cout << "\nR1 - R2 = " << result << endl;
            break;
        }

        case 'I':
        {
            bool equal = R1.isEqual(R2);
            cout << "\nR1 == R2: " << (equal ? "true" : "false") << endl;
            break;
        }

        case 'J':
        {
            bool lessThan = R1.isLessThan(R2);
            cout << "\nR1 < R2: " << (lessThan ? "true" : "false") << endl;
            break;
        }
        }

		cout << "\n";
		system("pause");
		system("cls");
	} while (true);
}