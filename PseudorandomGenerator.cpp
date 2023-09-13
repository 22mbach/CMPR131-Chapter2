#include "PseudorandomGenerator.h"
using namespace std;

//precon: None
//postcon:  Constructs a PseudorandomGenerator object with default values for seed, multiplier, modulus,
//          and increment. It also initializes the random number generator with the seed value.
PseudorandomGenerator::PseudorandomGenerator() : seed(1), multiplier(40), modulus(729), increment(725), nextNumber(seed)
{
    // Initialize the random number generator with the seed
    generator.seed(seed);
}

//precon: None
//postcon: Returns the current value of the seed used for initializing the PseudorandomGenerator.
int PseudorandomGenerator::getSeed() const
{
    return seed;
}

//precon: None
//postcon: Sets the seed of the PseudorandomGenerator to the provided 'newSeed' value.
//         It also updates the 'nextNumber' with the new seed value and reinitializes the random number generator.
//         with the new seed.
void PseudorandomGenerator::setSeed(int newSeed)
{
    seed = newSeed;
    nextNumber = seed;
    generator.seed(seed);
}

//precon: None
//postcon: Returns the current value of the multiplier used in the PseudorandomGenerator.
int PseudorandomGenerator::getMultiplier() const
{
    return multiplier;
}

//precon: None
//postcon: Sets the multiplier of the PseudorandomGenerator to the provided 'newMultiplier' value.
//         It also updates the 'nextNumber' with the current seed value.
void PseudorandomGenerator::setMultiplier(int newMultiplier)
{
    multiplier = newMultiplier;
    nextNumber = seed;
}

//precon: None
//postcon: Returns the current value of the modulus used in the PseudorandomGenerator.
int PseudorandomGenerator::getModulus() const
{
    return modulus;
}

//precon: None
//postcon: Sets the modulus of the PseudorandomGenerator to the provided 'newModulus' value.
//         It also updates the 'nextNumber' with the current seed value.
void PseudorandomGenerator::setModulus(int newModulus)
{
    modulus = newModulus;
    nextNumber = seed;
}

//precon: None
//postcon: Returns the current value of the increment used in the PseudorandomGenerator.
int PseudorandomGenerator::getIncrement() const
{
    return increment;
}

//precon: None
//postcon: Sets the increment of the PseudorandomGenerator to the provided 'newIncrement' value.
//         It also updates the 'nextNumber' with the current seed value.
void PseudorandomGenerator::setIncrement(int newIncrement)
{
    increment = newIncrement;
    nextNumber = seed;
}

//precon: None
//postcon: Computes and returns the next pseudorandom number based on the current values of
//         multiplier, increment, modulus, and nextNumber. It also updates the nextNumber for the next call.
int PseudorandomGenerator::getNextNumber()
{
    nextNumber = (multiplier * nextNumber + increment) % modulus;
    return nextNumber;
}

//precon: None.
//postcon: Computes and returns an indirectly calculated pseudorandom double number based on the current
//         values of seed, multiplier, increment, and modulus. The function returns a value in the range [0...1).
//Unfinished: The function somehow only return 0 as result
double PseudorandomGenerator::getIndirectNextNumber() const
{
    int indirectNumber = (multiplier * seed + increment) % modulus;
    double indirectNumberDouble = static_cast<double>(indirectNumber) / static_cast<double>(modulus);
    return indirectNumberDouble;
}

//precon: None
//postcon: The function computes and displays the distribution of numbers returned by the pseudorandom generator for a specified number of iterations,
//         using the provided ranges for multiplier, increment, and modulus.
void PseudorandomGenerator::runExperiment(int numIterations, int minMultiplier, int maxMultiplier, int minIncrement, int maxIncrement, int minModulus, int maxModulus)
{
    const int numIntervals = 10;
    const double intervalSize = 1.0 / numIntervals;
    vector<int> intervalCounts(numIntervals, 0);

    // Generate random values for multiplier, increment, and modulus
    multiplier = uniform_int_distribution<int>(minMultiplier, maxMultiplier)(generator);
    increment = uniform_int_distribution<int>(minIncrement, maxIncrement)(generator);
    modulus = uniform_int_distribution<int>(minModulus, maxModulus)(generator);

    // Ensure that modulus is at least 2 to prevent division by zero
    modulus = max(modulus, 2);

    cout << "\n\tExperiment of pseudorandom with random multiplier, increment and modulus:";
    cout << "\n" << string(100, char(196));
    cout << "\n\tMultiplier = " << multiplier << ", Increment = " << increment << ", Modulus = " << modulus << "\n\n";
    cout << left << setw(30) << "Range" << "Number of Occurrences\n";

    for (int i = 0; i < numIterations; i++)
    {
        double randomNumber = static_cast<double>(getNextNumber()) / static_cast<double>(modulus);

        // Calculate interval index and ensure it's within bounds
        int intervalIndex = static_cast<int>(randomNumber / intervalSize);
        intervalIndex = max(0, min(intervalIndex, numIntervals - 1));

        intervalCounts[intervalIndex]++;
    }

    for (int i = 0; i < numIntervals; i++)
    {
        double lowerBound = i * intervalSize;
        double upperBound = (i + 1) * intervalSize;
        cout << "[" << fixed << setprecision(1) << lowerBound << " ... " << upperBound << ")\t\t\t" << setw(20) << intervalCounts[i] << "\n";
    }

    double mean = 0.0;
    for (int i = 0; i < numIntervals; i++)
    {
        double lowerBound = i * intervalSize;
        double upperBound = (i + 1) * intervalSize;
        double midPoint = (lowerBound + upperBound) / 2.0;
        mean += intervalCounts[i] * midPoint;
    }
    mean /= numIterations;
    double approximateGaussian = mean * 2.0 - 1.0;

    cout << setprecision(6); // Set precision to 6 decimal places
    cout << "\nWith 10 uniformly distributed rand numbers in the range [0...1.0),\n";
    cout << "the approximate Gaussian distribution is " << approximateGaussian << ".\n";
}