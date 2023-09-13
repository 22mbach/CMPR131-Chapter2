#pragma once
#include <random>
#include <iostream>
#include <vector>
#include <iomanip>

class PseudorandomGenerator
{
private:
    int seed;
    int multiplier;
    int modulus;
    int increment;
    int nextNumber;
    std::mt19937 generator;

public:
    PseudorandomGenerator();

    // Accessors and mutators for seed, multiplier, modulus, and increment
    int getSeed() const;
    void setSeed(int newSeed);
    int getMultiplier() const;
    void setMultiplier(int newMultiplier);
    int getModulus() const;
    void setModulus(int newModulus);
    int getIncrement() const;
    void setIncrement(int newIncrement);

    // Function to get the next pseudorandom number
    int getNextNumber();

    // Function to get the next pseudorandom number indirectly (without changing the seed)
    double getIndirectNextNumber() const;

    // Function to run an experiment with different values of multiplier, increment, and modulus
    void runExperiment(int numIterations, int minMultiplier, int maxMultiplier, int minIncrement, int maxIncrement, int minModulus, int maxModulus);
};