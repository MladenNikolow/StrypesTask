#pragma once
#include <vector>

/// <summary>
///	Class that reads the input from the console
/// </summary>
class ConsoleInputReader
{
private:
	ConsoleInputReader()
	{
	}

	~ConsoleInputReader()
	{
	}

public:
	/// <summary>
	/// Read vector with numbers from the console
	/// </summary>
	/// <param name="vInputNumbers"> Vector that will be initialized with the input values </param>
	static void ReadVector( std::vector< int >& vInputNumbers );
};
