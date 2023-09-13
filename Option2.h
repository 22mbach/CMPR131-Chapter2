#pragma once
#include "PseudorandomGenerator.h"

void Option2()
{
	//create class object
	PseudorandomGenerator pseudorandom;

	do
	{
		cout << "\n2) Pseudorandom Menu";
		cout << "\n" << string(100, char(205));
		cout << "\n\tA. Get seed";
		cout << "\n\tB. Set seed";
		cout << "\n\tC. Get multiplier";
		cout << "\n\tD. Set multiplier";
		cout << "\n\tE. Get modulus";
		cout << "\n\tF. Set modulus";
		cout << "\n\tG. Get increment";
		cout << "\n\tH. Set increment";
		cout << "\n\tI. Get next number";
		cout << "\n\tJ. Get indirect next number";
		cout << "\n\tK. Run experience with different values (multiplier, increment, and modulus)";
		cout << "\n" << string(100, char(196));
		cout << "\n\t0. Return";
		cout << "\n" << string(100, char(205));
		char option = inputChar("\n\tOption: ", static_cast<string>("ABCDEFGHIJK0"));

		switch (toupper(option))
		{
		case '0': return; break;
		case 'A':
		{
			int seed = pseudorandom.getSeed();
			cout << "\nSeed: " << seed << endl;
			break;
		}

		case 'B':
		{
			int setSeed = inputInteger("\nEnter a value for seed: ", true);
			pseudorandom.setSeed(setSeed);
			cout << "\nSeed: " << setSeed << endl;
			break;
		}

		case 'C':
		{
			int multiplier = pseudorandom.getMultiplier();
			cout << "\nMultiplier: " << multiplier << endl;
			break;
		}

		case 'D':
		{
			int setMultiplier = inputInteger("\nEnter a value for multiplier: ", true);
			pseudorandom.setMultiplier(setMultiplier);
			cout << "\nMultiplier: " << setMultiplier << endl;
			break;
		}

		case 'E':
		{
			int modulus = pseudorandom.getModulus();
			cout << "\nModulus: " << modulus << endl;
			break;
		}

		case 'F':
		{
			int setModulus = inputInteger("\nEnter a value for modulus: ", true);
			pseudorandom.setModulus(setModulus);
			cout << "\nModulus: " << setModulus << endl;
			break;
		}

		case 'G':
		{
			int increment = pseudorandom.getIncrement();
			cout << "\nIncrement: " << increment << endl;
			break;
		}

		case 'H':
		{
			int setIncrement = inputInteger("\nEnter a value for increment: ", true);
			pseudorandom.setIncrement(setIncrement);
			cout << "\nIncrement: " << setIncrement << endl;
			break;
		}

		case 'I':
		{
			int nextNumber = pseudorandom.getNextNumber();
			cout << "\nNext Number: " << nextNumber << endl;
			break;
		}

		case 'J':
		{
			int indirectNextNumber = pseudorandom.getIndirectNextNumber();
			cout << "\nIndirect Next Number: " << indirectNextNumber << endl;
			break;
		}

		case 'K':
		{
			int numIterations = 1000000;  // Number of iterations to run the experiment
			int minMultiplier = 1;        // Minimum value for multiplier
			int maxMultiplier = 100000;     // Maximum value for multiplier
			int minIncrement = 1;         // Minimum value for increment
			int maxIncrement = 100000;      // Maximum value for increment
			int minModulus = 1;        // Minimum value for modulus
			int maxModulus = 100000;       // Maximum value for modulus

			// Run the experiment
			pseudorandom.runExperiment(numIterations, minMultiplier, maxMultiplier, minIncrement, maxIncrement, minModulus, maxModulus);
			break;
		}
		}

		cout << "\n";
		system("pause");
		system("cls");
	} while (true);
}