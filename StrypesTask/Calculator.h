#pragma once
#include <vector>
#include "ResultStruct.h"

/// <summary>
///	Calculator that helps to perform given calculations
/// </summary>
class Calculator
{
public:
	Calculator();
	~Calculator();

public:
	/// <summary>
	/// Calculate the maximum value of A[i] - A[j] + A[k] - A[l], where i > j > k > l 
	/// </summary>
	/// <param name="vNumbers"> Vector with numbers </param>
	/// <param name="oResult"> Result data </param>
	/// <returns> true on success and false on error </returns>
	bool Calculate( const std::vector< int >& vNumbers, Result& oResult );
};