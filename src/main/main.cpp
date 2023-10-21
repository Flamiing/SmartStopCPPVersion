#include <smartStopGeneral.hpp>

/* static void testParametersClass(Parameters& parameters)
{
	if (parameters.option == SMART_STOP)
		std::cout << "SMART_STOP" << std::endl;
	else if (parameters.option == TERMINAL)
		std::cout << "TERMINAL" << std::endl;
	else if (parameters.option == DISTRO)
		std::cout << "DISTRO" << std::endl;
	else if (parameters.option == IDE)
		std::cout << "IDE" << std::endl;
	else if (parameters.option == VERSION)
		std::cout << "VERSION" << std::endl;
	else if (parameters.option == UNINSTALL)
		std::cout << "UNINSTALL" << std::endl;
	else if (parameters.option == HELP)
		std::cout << "HELP" << std::endl;
	else if (parameters.option == UNKNOWN)
		std::cout << "UNKNOWN" << std::endl;
	if (!parameters.optionParameter.empty())
		std::cout << parameters.optionParameter << std::endl;
} */

int main(int argc, char **argv)
{
	if (argc > 3)
		return wrongNumberArguments();

	std::vector<std::string> argsVector = charArrayToVector(argv);
	Parameters parameters(argc, argsVector);
	parameters.parseParameters();

	//testParametersClass(parameters);
	
	//if (SmartStop::execute(parameters) == FAILED)
		//return 1;

	return 0;
}