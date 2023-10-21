#ifndef SMARTSTOP_HPP
# define SMARTSTOP_HPP

# include <iostream>
# include <string>
# include <map>
# include "../smartStopUtils.hpp"
# include "Parameters.hpp"

class Parameters;
class SmartStop;

typedef Status (SmartStop::*optionFunctions)(Parameters& params);
typedef Status (SmartStop::*optionFunctionsNoParams)(void);

class SmartStop
{
	public:
		static Status execute(Parameters& params);

		std::map<Option, optionFunctions> optionFuncMap;
		std::map<Option, optionFunctionsNoParams> optionFuncMapNoParams;
	private:
		SmartStop(void);
		~SmartStop(void);

		//static void _initOptionFuncMap(void);
		static void _initOptionFuncMapNoParams(void);
		//Status _execOptionFunc(Parameters& params);
		static Status _execOptionFuncNoParams(Parameters& params);
		static Status _unknownParameterError(void);
		
};

#endif