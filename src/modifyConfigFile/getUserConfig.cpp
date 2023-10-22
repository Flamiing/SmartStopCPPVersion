#include <configJsonFile.hpp>

static void getWinterminalBoolean(bool& winterminal)
{
	while (true)
	{
		std::cout << "WINTERMINAL: ";
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

	std::cout << "WARNING: Config file needs to be modified." << std::endl;
	std::cout << "WARNING: Please enter your preferences one by one:" << std::endl;
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
		std::cerr << "Error: Can't open file or is not accessible" << std::endl;
		return false;
	}
	output << configFile;
	output.close();
	std::cout << "Everything is properly configured." << std::endl;
	std::cout << "Please, launch again Smart Stop to turn off WSL. Enjoy 😊!" << std::endl;
	return true;
}
