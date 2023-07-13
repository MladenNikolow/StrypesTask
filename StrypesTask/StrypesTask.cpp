#include <iostream>
#include <vector>
#include "ConsoleInputReader.h"
#include "ResultStruct.h"
#include "Calculator.h"

int main()
{
    std::vector< int > vInputNumbers;
    ConsoleInputReader::ReadVector(vInputNumbers);

    Result oResult;
    if (!Calculator().Calculate(vInputNumbers, oResult))
        std::cout << "An error has occurred, please try again following the instructions.";

    std::cout << oResult.ToString();

    return 0;
}