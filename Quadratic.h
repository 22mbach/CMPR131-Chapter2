#pragma once
class Quadratic
{
private:
	int a;
	int b;
	int c;
	int x;

public:
	Quadratic();

	void displayExpression() const;

	void setA(int num);
	void setB(int num);
	void setC(int num);

	int getA() const;
	int getB() const;
	int getC() const;

	void getEvaluation(int num);

	void getNumRoots() const;
	void getRealRoots() const;

};

