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
	UNKNOWN,
	NONE
};

enum Status
{
	FAILED,
	SUCCESS,
	MODIFIED,
	NOT_MODIFIED
};

// General utils:
std::vector<std::string> charArrayToVector(char **charArray);

// Error utils:
int wrongNumberArguments(void);

#endif