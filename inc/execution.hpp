#ifndef EXECUTION_HPP
# define EXECUTION_HPP

# include <iostream>
# include <string>
# include <map>
# include "smartStopUtils.hpp"
# include "configJsonFile.hpp"
# include "classes/Parameters.hpp"

class Parameters;

typedef Status (*optionFunctions)(Parameters& params);
typedef Status (*optionFunctionsNoParams)(void);
typedef std::map<Option, optionFunctions> OptionFuncWithParams;
typedef std::map<Option, optionFunctionsNoParams> OptionFuncNoParams;

extern OptionFuncWithParams optionFuncMap;
extern OptionFuncNoParams optionFuncMapNoParams;

Status execute(Parameters& params);

void initOptionFuncMap(void);
void initOptionFuncMapNoParams(void);
Status execOptionFunc(Parameters& params);
Status unknownParameterError(void);
Status printHelp(void);
Status printVersion(void);
		
#endif