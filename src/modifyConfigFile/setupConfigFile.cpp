#include <configJsonFile.hpp>

static bool wrongConfig(Json::Value configFile)
{
	const std::vector<std::string> validDistros = \
	{
		"Ubuntu", "Debian", "kali-linux",
		"Ubuntu-16.04", "Ubuntu-18.04", "Ubuntu-20.04"
	};

	for (const auto& distro : validDistros)
	{
    	if (configFile["distro"].asString() == distro)
        	return false;
	}
	return true;
}

bool createFileIfNotExists(bool forced)
{
    if (!std::filesystem::exists(CONFIG_FILE_PATH) || forced == true)
	{
        std::ofstream file(CONFIG_FILE_PATH);
		if (!file.is_open())
		{
			std::cerr << "Error: Can't open file or is not accessible" << std::endl;
			return false;
		}
		const std::string buffer = DEFAULT_CONFIG;
		file << buffer;
        file.close();
		return true;
    }
	return true;
}

bool modifyIfEmpty(std::ifstream& input)
{
	if (input.peek() == std::ifstream::traits_type::eof())
	{
		if (!createFileIfNotExists(FORCED))
		{
			input.close();
			return false;
		}
	}
	return true;
}

bool modifyIfWrong(std::ifstream& input, Json::Value configFile)
{
	if (wrongConfig(configFile))
	{
		if (!askUserForConfig(configFile))
		{
			input.close();
			return false;
		}
	}
	return true;
}