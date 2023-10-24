#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include "../smartStopUtils.hpp"

# define NUM_OPTIONS 8

class Parameters
{
	public:
		Parameters(int numArgs, std::vector<std::string> args);
		~Parameters(void);

		void parseParameters(void);
		Option option;

	private:
		Parameters(void);

		void _getOption(std::string argument);

		int _numArgs;
		std::vector<std::string> _parameters;
};

#endif