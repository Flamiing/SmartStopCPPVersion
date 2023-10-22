#include <smartStop.hpp>
#include <execution.hpp>

Status printHelp(void)
{
	std::cout << std::endl;
	std::cout << "                                      ##########################" << std::endl;
	std::cout << "                                      ## AVAILABLE PARAMETERS ##" << std::endl;
	std::cout << "###############################################################################################################" << std::endl;
	std::cout << "##                                                                                                           ##" << std::endl;
	std::cout << "##                               If you just want to launch the program                                      ##" << std::endl;
	std::cout << "##                               simply use 'smart-stop' without parameters.                                 ##" << std::endl;
	std::cout << "##                                                                                                           ##" << std::endl;
	std::cout << "##                                                                                                           ##" << std::endl;
	std::cout << "##  -t true/false                # Used to turn on/off the option to close the terminal                      ##" << std::endl;
	std::cout << "##  -d DISTRO_process_name       # Used to change the name of your DISTRO process name in the Task Manager   ##" << std::endl;
	std::cout << "##  -i IDE_process_name          # Used to change the name of your IDE process name in the Task Manager      ##" << std::endl;
	std::cout << "##  --version                    # Used to get the Version of the program                                    ##" << std::endl;
	std::cout << "##  --uninstall                  # Used to safely uninstall the program                                      ##" << std::endl;
	std::cout << "##                                                                                                           ##" << std::endl;
	std::cout << "##                                            For more info visit:                                           ##" << std::endl;
	std::cout << "##                                   https://github.com/Flamiing/SmartStop                                   ##" << std::endl;
	std::cout << "##                                                                                                           ##" << std::endl;
	std::cout << "###############################################################################################################" << std::endl;
	std::cout << std::endl;
	return SUCCESS;
}

Status printVersion(void)
{
	std::cout << std::endl;
	std::cout << PROGRAM_NAME << " " << VERSION << std::endl;
	std::cout << std::endl;
	std::cout << LICENSE << std::endl;
	std::cout << std::endl;
	std::cout << COPYRIGHT << std::endl;
	std::cout << std::endl;
	return SUCCESS;
}

Status unknownParameterError(void)
{
	std::cerr << "Error: Wrong parameter passed." << std::endl;
	std::cerr << "Use 'smart-stop -h' or 'smart-stop --help' to see the available parameters." << std::endl;
	return SUCCESS;
}