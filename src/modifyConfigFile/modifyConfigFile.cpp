#include <configJsonFile.hpp>

bool modifySpecificParam(std::ifstream& input, Option modify, Json::Value configFile)
{
	std::map<Option, std::string> configParams =
	{
		{DISTRO, "distro"},
		{IDE, "ide"},
		{TERMINAL, "winterminal"}
	};

	auto it = configParams.find(modify);
	if (it != configParams.end())
	{
		if (!modifySpecificConfig(configFile, it->second))
		{
			input.close();
			return false;
		}
		return true;
	}
	input.close();
	return false;
}

Status modifyParam(Parameters& params)
{
	if (!configJsonFile(params.option, MODIFY_OPTION))
		return FAILED;
	return SUCCESS;
}