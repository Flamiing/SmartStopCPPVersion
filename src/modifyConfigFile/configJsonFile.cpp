#include <configJsonFile.hpp>

static bool getJsonFile(std::ifstream& input, Json::Value& configFile)
{
	Json::CharReaderBuilder jsonReader;
    jsonReader["strictMode"] = false; // Suppress errors
	JSONCPP_STRING parseErrors;
    if (!Json::parseFromStream(jsonReader, input, &configFile, &parseErrors))
	{
		if (!createFileIfNotExists(FORCED))
		{
			input.close();
			return false;
		}
	}
	return true;
}

bool configJsonFile(Option modify, int mode)
{
	Json::Value configFile;
	if (!createFileIfNotExists(NOT_FORCED))
		return false;
	std::ifstream input(CONFIG_FILE_PATH);
	if (!input.is_open())
	{
		std::cerr << ERROR_CANNOT_OPEN_FILE << std::endl;
		return false;
	}
	if (!modifyIfEmpty(input))
		return false;
	getJsonFile(input, configFile);
	if (modifyIfWrong(input, configFile) != NOT_MODIFIED)
		return false;
	if (mode == MODIFY_OPTION)
	{
		if (!modifySpecificParam(input, modify, configFile))
			return false;
	}
	input.close();
	return true;
}