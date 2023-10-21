#include <classes/Parameters.hpp>

Parameters::Parameters(int numArgs, std::vector<std::string> args)
	: _numArgs(numArgs), _parameters(args) {}

Parameters::~Parameters(void) {}

void Parameters::parseParameters(void)
{
	if (this->_numArgs > 1)
	{
		_getOption(this->_parameters[1]);
		if (this->_numArgs > 2)
		{
			this->optionParameter = this->_parameters[2];
			this->hasOptionParameter = true;
		}
		else
			this->hasOptionParameter = false;
	}
	else
		this->option = SMART_STOP;
}

Parameters::Parameters(void) {}

void Parameters::_getOption(std::string argument)
{
	std::map<std::string, Option> options = \
	{
		{"-t", TERMINAL}, {"-T", TERMINAL}, {"-d", DISTRO},
		{"-D", DISTRO}, {"-i", IDE}, {"-I", IDE}, {"-v", VERSION},
		{"-V", VERSION}, {"--version", VERSION}, {"--uninstall", UNINSTALL},
		{"-h", HELP}, {"-H", HELP}, {"--help", HELP}
	};

	if (options.find(argument) != options.end())
		this->option = options[argument];
	else
		this->option = UNKNOWN;
}