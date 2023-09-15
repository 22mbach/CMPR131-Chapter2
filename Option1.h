#pragma once
#include "Quadratic.h"

// Displays the Option1 submenu
void Option1()
{
    // Create Class object
    Quadratic quadratic;


    do
    {
        // Display Menu
        cout << "\n1> Quadratic Menu";
        cout << "\n" << string(100, 205);
        cout << "\n\tD. Display the expression";
        cout << "\n\tA. Set coefficient (a)";
        cout << "\n\tB. Set coefficient (b)";
        cout << "\n\tC. Set coefficient (c)";
        cout << "\n\tE. Get evaluation (x)";
        cout << "\n\tN. Get the number of real roots";
        cout << "\n\tR. Get real root(s)";
        cout << "\n" << string(100, 196);
        cout << "\n\t0. Return";
        cout << "\n" << string(100, 205);
        char option = inputChar("\n\tOption: ", static_cast<string>("ABCDENR0"));

        switch (toupper(option))
        {
        case '0': return; break;
        case 'D': quadratic.displayExpression(); break;
        case 'A': quadratic.setA(inputInteger("\n\tEnter a value and set coefficient (a): ")); break;
        case 'B': quadratic.setB(inputInteger("\n\tEnter a value and set coefficient (b): ")); break;
        case 'C': quadratic.setC(inputInteger("\n\tEnter a value and set coefficient (c): ")); break;
        case 'E': quadratic.getEvaluation(inputInteger("\n\tEnter a value of x: ")); break;
        case 'N': quadratic.getNumRoots(); break;
        case 'R': quadratic.getRealRoots(); break;
        }

        cout << "\n";
        system("pause");
        system("cls");


    } while (true);



}