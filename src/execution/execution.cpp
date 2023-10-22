#include <execution.hpp>

Status execute(Parameters& params)
{
	//initOptionFuncMap();
	initOptionFuncMapNoParams();
	/* if (params.hasOptionParameter)
		return _execOptionFunc(params);
	else */
		return execOptionFuncNoParams(params);
}

/* Status execOptionFunc(Parameters& params)
{
	if (params.option == UNKNOWN)
		return _unknownParameterError();
	else if (optionFuncMap.find(params.option) != optionFuncMap.end())
		return optionFuncMap[params.option](params);
	return FAILED;
} */

Status execOptionFuncNoParams(Parameters& params)
{
	if (optionFuncMapNoParams.find(params.option) != optionFuncMapNoParams.end())
		return (*optionFuncMapNoParams[params.option])();
	return FAILED;
}