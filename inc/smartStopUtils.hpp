#ifndef SMARTSTOPUTILS_HPP
# define SMARTSTOPUTILS_HPP

# include <vector>
# include <string>

enum Option
{
	SMART_STOP,
	TERMINAL,
	DISTRO,
	IDE,
	VERSION,
	UNINSTALL,
	HELP,
	UNKNOWN
};

enum Status
{
	FAILED,
	SUCCESS
};

// General utils:
void printHelpMsg(void);
std::vector<std::string> charArrayToVector(char **charArray);

// Error utils:
int wrongNumberArguments(void);

#endif