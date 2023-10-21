#ifndef SMARTSTOPUTILS_HPP
# define SMARTSTOPUTILS_HPP

// Possible parameters:
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

// General utils:
void printHelpMsg(void);
std::vector<std::string> charArrayToVector(char **charArray);

// Error utils:
int wrongNumberArguments(void);

#endif