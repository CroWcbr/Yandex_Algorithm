#include <iostream>
#include <fstream>

int main()
{
    std::ifstream inputFile("input.txt");
	long long int A, B;
	inputFile >> A >> B;
    inputFile.close();

    std::ofstream outputFile("output.txt");
    outputFile << A + B;
    outputFile.close();

    return 0;
}