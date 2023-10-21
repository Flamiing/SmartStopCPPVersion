#include <smartStopGeneral.hpp>

// Transform the char array to vector;
std::vector<std::string> charArrayToVector(char **charArray)
{
    std::vector<std::string> stringVector;
	int count = 0;
	while (charArray[count])
	{
        stringVector.push_back(charArray[count]);
		count++;
	}
    return stringVector;
}