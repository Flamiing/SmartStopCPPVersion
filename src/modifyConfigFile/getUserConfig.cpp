#include <configJsonFile.hpp>

static void getWinterminalBoolean(bool& winterminal)
{
	while (true)
	{
		std::cout << "TERMINAL: ";
		std::cin >> std::boolalpha >> winterminal;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter true or false." << std::endl;
    	}
		else
        	break;
	}
}

bool askUserForConfig(Json::Value configFile)
{
	std::string distro;
	std::string ide;
	bool winterminal;

	std::cout << WARNING_ONE << std::endl;
	std::cout << WARNING_TWO << std::endl;
	std::cout << "DISTRO: ";
	std::cin >> distro;
	std::cout << "IDE: ";
	std::cin >> ide;
	getWinterminalBoolean(winterminal);
	configFile["distro"] = distro;
	configFile["ide"] = ide;
	configFile["winterminal"] = winterminal;
	std::ofstream output(CONFIG_FILE_PATH);
	if (!output.is_open())
	{
		std::cerr << ERROR_CANNOT_OPEN_FILE << std::endl;
		return false;
	}
	output << configFile;
	output.close();
	std::cout << "Everything is properly configured." << std::endl;
	std::cout << "Please, launch again Smart Stop to turn off WSL. Enjoy 😊!" << std::endl;
	return true;
}

bool modifySpecificConfig(Json::Value configFile, std::string modify)
{
	std::cout << "Please enter your preference: " << std::endl;
	if (modify == "winterminal")
	{
		bool modifiedParam;
		getWinterminalBoolean(modifiedParam);
		configFile[modify] = modifiedParam;
	}
	else
	{
		std::string modifiedParam;
		if (modify == "distro")
			std::cout << "DISTRO: ";
		else if (modify == "ide")
			std::cout << "IDE: ";
		std::cin >> modifiedParam;
		configFile[modify] = modifiedParam;
	}
	std::ofstream output(CONFIG_FILE_PATH);
	if (!output.is_open())
	{
		std::cerr << ERROR_CANNOT_OPEN_FILE << std::endl;
		return false;
	}
	output << configFile;
	output.close();
	std::cout << "Everything is properly configured." << std::endl;
	std::cout << "Please, launch again Smart Stop to turn off WSL. Enjoy 😊!" << std::endl;
	return true;
}
