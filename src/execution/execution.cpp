#include <execution.hpp>

Status execOptionFunc(Parameters& params)
{
	if (params.option == UNKNOWN)
		return unknownParameterError();
	else if (optionFuncMap.find(params.option) != optionFuncMap.end())
		return optionFuncMap[params.option](params);
	else if (optionFuncMapNoParams.find(params.option) != optionFuncMapNoParams.end())
		return (*optionFuncMapNoParams[params.option])();
	return FAILED;
}

Status execute(Parameters& params)
{
	initOptionFuncMap();
	initOptionFuncMapNoParams();
	return execOptionFunc(params);
}