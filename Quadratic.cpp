#include "Quadratic.h"
#include <iostream>
using namespace std;

// Class Constructor
Quadratic::Quadratic()
{
	a = 0;
	b = 0;
	c = 0;
	x = 0;
}

// Precondition: None
// Postcondition: returns value of 'a'
int Quadratic::getA() const
{
	return a;
}

// Precondition: None
// Postcondition: returns value of 'b'
int Quadratic::getB() const
{
	return b;
}

// Precondition: None
// Postcondition: returns value of 'c'
int Quadratic::getC() const
{
	return c;
}

// Precondition: Needs any integer
// Postcondition: sets value of 'a' to 'num'
void Quadratic::setA(int num)
{
	a = num;
}

// Precondition: Needs any integer
// Postcondition: sets value of 'b' to 'num'
void Quadratic::setB(int num)
{
	b = num;
}

// Precondition: Needs any integer
// Postcondition: sets value of 'c' to 'num'
void Quadratic::setC(int num)
{
	c = num;
}

// Precondition: None
// Postcondition: Displays the expression
void Quadratic::displayExpression() const
{
	cout << "\n\t" << a << "x^2 + " << b << "x + " << c << endl;
}

// Precondition: Needs any integer
// Postcondition: sets value of 'x' to 'num', Displays the expression and results
void Quadratic::getEvaluation(int num)
{
	x = num;
	Quadratic::displayExpression();

	int total = (a * (pow(x, 2))) + (b * x) + c;

	cout << "\n\tEvaluation result: " << total << endl;
}

//Precondition: None
//Postcondition: Calculates and prints the number of real roots
void Quadratic::getNumRoots() const
{
	int discriminant = (pow(b, 2)) - ((4 * a) * c);

	int numRoots;

	if (a == 0 and b == 0 and c == 0)
	{
		cout << "\n\tNumber of real roots: Infinity" << endl;
	}

	else if (discriminant > 0)
	{
		numRoots = 2; 
		cout << "\n\tNumber of real roots: " << numRoots << endl;
	}

	else if (discriminant == 0)
	{
		numRoots = 1;
		cout << "\n\tNumber of real roots: " << numRoots << endl;
	}

	else if (discriminant < 0) cout << "\n\tNo real roots." << endl;

}

//Precondition: None
//Postcondition: Calculates and prints the value of the real roots
void Quadratic::getRealRoots() const
{
	int discriminant = (pow(b, 2)) - ((4 * a) * c);

	double qPlus;
	double qMinus;

	qPlus = (-b + sqrt(discriminant)) / (2 * a);
	qMinus = (-b - sqrt(discriminant)) / (2 * a);

	// If all coefficients are zero
	if (a == 0 and b == 0 and c == 0) cout << "\n\tEvery value of x is a real root." << endl;
	
	// If two roots
	else if (discriminant > 0) cout << "\n\tTwo real roots are: " << qMinus << " and " << qPlus << endl;
	
	// If one root
	else if (discriminant == 0) cout << "\n\tOnly real root: " << qPlus << endl;
	
	// If no roots
	else if (discriminant < 0) cout << "\n\tNo real roots." << endl;
}
