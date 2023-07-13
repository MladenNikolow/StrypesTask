#pragma once
#include <ostream>
#include <ostream>
#include <sstream>

///	<summary> Contains the result data for  A[i] - A[j] + A[k] - A[l], where i > j > k > l </summary>
struct Result
{
	///	<summary> First index ( i ) </summary>
	int nFirstIndex;

	///	<summary> Second index ( j ) </summary>
	int nSecondIndex;
	
	///	<summary> Third index ( k ) </summary>
	int nThirdIndex;

	///	<summary> Fourth index ( l ) </summary>
	int nFourthIndex;

	///	<summary> Max value </summary>
	int nMaxValue;

	///	<summary> Constructor </summary>
	Result();

	///	<summary> Get string implementation </summary>
	std::string ToString() const;

	friend std::ostream& operator << (std::ostream& oStream, const Result& oResult);
};