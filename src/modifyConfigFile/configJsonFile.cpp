#include <configJsonFile.hpp>

bool configJsonFile(void)
{

	if (!createFileIfNotExists(NOT_FORCED))
		return false;
	std::ifstream input(CONFIG_FILE_PATH);
	if (!input.is_open())
	{
		std::cerr << "Error: Can't open file or is not accessible" << std::endl;
		return false;
	}
	if (!modifyIfEmpty(input) || !modifyIfWrong(input))
		return false;
	input.close();
	return true;
}

/* int	main(void)
{
	if (!configJsonFile())
		return (1);
	return (0);
} */