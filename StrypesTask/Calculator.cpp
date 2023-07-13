#include <iostream>
#include <algorithm>
#include <iterator>
#include "Calculator.h"

#define MINIMUM_COUNT_OF_NUMBERS        4

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

bool Calculator::Calculate( const std::vector< int >& vNumbers, Result& oResult )
{
    if ( vNumbers.size() < MINIMUM_COUNT_OF_NUMBERS )
    {
        std::cout << "The count of numbers is not enough to perform the calculation. Please try again, entering at least "
                  << MINIMUM_COUNT_OF_NUMBERS
                  << " numbers.";
        return false;
    }

    const int szNumbersArraySize = static_cast< int >( vNumbers.size() );

    std::vector< int > vMaxValues( szNumbersArraySize + 1  , INT_MIN);
    std::vector< int > vMinDifferences( szNumbersArraySize      , INT_MIN);
    std::vector< int > vMinDifferencesPlusMaxValue( szNumbersArraySize - 1  , INT_MIN);
    std::vector< int > vMinDifferencesPlusMinDifferences( szNumbersArraySize - 2  , INT_MIN);

    // In We store the maximum value for A[i]
    for ( int nIndex = szNumbersArraySize - 1; nIndex >= 0; nIndex-- )
        vMaxValues[ nIndex ] = abs( std::max( vMaxValues[ nIndex + 1 ], vNumbers[ nIndex ] ) );
       
    // We store the maximum valuse for A[i] - A[j]
    for ( int nIndex = szNumbersArraySize - 2; nIndex >= 0; nIndex-- )
        vMinDifferences[ nIndex ] = abs( std::max( vMinDifferences[ nIndex + 1 ]
                                     , vMaxValues[ nIndex + 1 ] - vNumbers[ nIndex ] ) );

    // We store the maximum valuse for A[i] - A[j] + A[k]
    for ( int nIndex = szNumbersArraySize - 3; nIndex >= 0; nIndex--)
        vMinDifferencesPlusMaxValue[ nIndex ] = abs( std::max( vMinDifferencesPlusMaxValue[ nIndex + 1 ]
                                     , vMinDifferences[ nIndex + 1 ] + vNumbers[ nIndex ] ) );

    // We store the maximum valuse for A[i] - A[j] + A[k] - A[l]
    for ( int nIndex = szNumbersArraySize - 4; nIndex >= 0; nIndex-- )
        vMinDifferencesPlusMinDifferences[ nIndex ] = abs( std::max( vMinDifferencesPlusMinDifferences[ nIndex + 1]
                                     , vMinDifferencesPlusMaxValue[ nIndex + 1] - vNumbers[ nIndex ] ) );

    // We get the first index in the vector with max value
    // The reason why we use -1 is the conversation of the reverse itertor into a regular one. 
    // The relation between them is &*(reverse_iterator(i)) == &*(i - 1)
    oResult.nFirstIndex = static_cast< int >( std::distance( vMaxValues.begin()
                                            , std::max_element( vMaxValues.rbegin()
                                                              , vMaxValues.rend() ).base() ) - 1 );

    oResult.nSecondIndex = static_cast< int >( std::distance( vMinDifferences.begin()
                                             , std::max_element( vMinDifferences.rbegin()
                                                               , vMinDifferences.rend() ).base() ) - 1 );

    oResult.nThirdIndex = static_cast< int >( std::distance( vMinDifferencesPlusMaxValue.begin()
                                            , std::max_element( vMinDifferencesPlusMaxValue.rbegin()
                                                              , vMinDifferencesPlusMaxValue.rend() ).base() ) - 1 );

    oResult.nFourthIndex = static_cast< int >( std::distance( vMinDifferencesPlusMinDifferences.begin()
                                                            , std::max_element( vMinDifferencesPlusMinDifferences.rbegin()
                                                            , vMinDifferencesPlusMinDifferences.rend() ).base() ) - 1 );

    oResult.nMaxValue = vMinDifferencesPlusMinDifferences.front();

	return true;
}
