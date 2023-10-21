#include <classes/SmartStop.hpp>

Status SmartStop::execute(Parameters& params)
{

	_initOptionFuncMapNoParams();
	//_initOptionFuncMap();
	/* if (params.hasOptionParameter)
		return _execOptionFunc(params);
	else */
		return _execOptionFuncNoParams(params);
}

/* void SmartStop::_initOptionFuncMap(void)
{
	//optionFuncMap[TERMINAL] = &SmartStop::modifyTerminal;
	//optionFuncMap[DISTRO] = &SmartStop::modifyDistro;
	//optionFuncMap[IDE] = &SmartStop::modifyIde;
} */

void SmartStop::_initOptionFuncMapNoParams(void)
{
	//optionFuncMap[SMART_STOP] = &SmartStop::smartStop;
	//optionFuncMap[VERSION] = &SmartStop::printVersion;
	//optionFuncMap[UNINSTALL] = &SmartStop::uninstall;
	//optionFuncMap[HELP] = &SmartStop::printHelp;
	SmartStop::optionFuncMapNoParams[UNKNOWN] = &SmartStop::_unknownParameterError;
}

/* Status SmartStop::_execOptionFunc(Parameters& params)
{
	if (params.option == UNKNOWN)
		return _unknownParameterError();
	else if (optionFuncMap.find(params.option) != optionFuncMap.end())
		return optionFuncMap[params.option](params);
	return FAILED;
} */

Status SmartStop::_execOptionFuncNoParams(Parameters& params)
{
	if (optionFuncMapNoParams.find(params.option) != optionFuncMapNoParams.end())
		return (*optionFuncMapNoParams[params.option])();
	return FAILED;
}

Status SmartStop::_unknownParameterError(void)
{
	std::cerr << "Error: Wrong parameter passed." << std::endl;
	std::cerr << "Use 'smart-stop -h' or 'smart-stop --help' to see the available parameters." << std::endl;
	return SUCCESS;
}

SmartStop::SmartStop(void) {}
SmartStop::~SmartStop(void) {}