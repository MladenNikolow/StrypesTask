#include "ResultStruct.h"

Result::Result()
{
	nFirstIndex = 0;
	nSecondIndex = 0;
	nThirdIndex = 0;
	nFourthIndex = 0;
	nMaxValue = 0;
}

std::string Result::ToString() const
{
	std::stringstream oStringStream;
	oStringStream << ( *this );

	return oStringStream.str();
}

std::ostream& operator << (std::ostream& oStream, const Result& oResult)
{
	return (oStream << "Result: " << std::endl
		<< "i = " << oResult.nFirstIndex << std::endl
		<< "j = " << oResult.nSecondIndex << std::endl
		<< "k = " << oResult.nThirdIndex << std::endl
		<< "l = " << oResult.nFourthIndex << std::endl
		<< "Max value: " << oResult.nMaxValue << std::endl);
}