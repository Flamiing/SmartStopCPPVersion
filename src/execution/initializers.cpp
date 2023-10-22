#include <execution.hpp>

OptionFuncWithParams optionFuncMap;
OptionFuncNoParams optionFuncMapNoParams;

/* void initOptionFuncMap(void)
{
	//optionFuncMap[TERMINAL] = &modifyTerminal;
	//optionFuncMap[DISTRO] = &modifyDistro;
	//optionFuncMap[IDE] = &modifyIde;
} */

void initOptionFuncMapNoParams(void)
{
	//optionFuncMapNoParams[SMART_STOP] = &smartStop;
	optionFuncMapNoParams[VERSION] = &printVersion;
	//optionFuncMapNoParams[UNINSTALL] = &uninstall;
	optionFuncMapNoParams[HELP] = &printHelp;
	optionFuncMapNoParams[UNKNOWN] = &unknownParameterError;
}