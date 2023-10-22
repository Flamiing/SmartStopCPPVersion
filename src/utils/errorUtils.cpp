#include <smartStop.hpp>

int wrongNumberArguments(void)
{
	std::cerr << "Error: Wrong number of arguments." << std::endl;
	std::cerr << "Use 'smart-stop -h' or 'smart-stop --help' to see how to use the program." << std::endl;
	return 1;
}