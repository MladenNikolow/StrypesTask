#include "ConsoleInputReader.h"
#include <iostream>

/* static */
void ConsoleInputReader::ReadVector( std::vector< int >& vInputNumbers )
{
	std::cout << "Please enter the count of the numbers you wish to include in the calculation: ";

    int nCountOfNumbers = 0;
    std::cin >> nCountOfNumbers;

    vInputNumbers.resize( nCountOfNumbers );

    std::cout << std::endl;
    std::cout << "Please enter your numbers, separated by space or enter: ";

    int nInputNumber = 0;

    for( int nInputIndex = 0; nInputIndex < nCountOfNumbers; ++nInputIndex )
    {
        std::cin >> nInputNumber;
        vInputNumbers[ nInputIndex ] = nInputNumber;
    }

    std::cout << std::endl;
}