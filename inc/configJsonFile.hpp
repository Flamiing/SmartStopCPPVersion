#ifndef CONFIGJSONFILE_HPP
# define CONFIGJSONFILE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <filesystem>
# include <vector>
# include <jsoncpp/json/json.h>
# include "smartStopUtils.hpp"
# include "classes/Parameters.hpp"

# define CONFIG_FILE_PATH "./config.json"
# define DEFAULT_CONFIG "{\n	\"distro\": \"default\",\n	\"ide\": \"default\",\n	\"winterminal\": true\n}"
# define FORCED true
# define NOT_FORCED false
# define NORMAL 0
# define MODIFY_OPTION 1

class Parameters;

bool askUserForConfig(Json::Value configFile);
bool configJsonFile(Option modify, int mode);
bool createFileIfNotExists(bool forced);
bool modifyIfEmpty(std::ifstream& input);
bool modifyIfWrong(std::ifstream& input, Json::Value configFile);
bool modifySpecificConfig(Json::Value configFile, std::string modify);
bool modifySpecificParam(std::ifstream& input, Option modify, Json::Value configFile);
Status modifyParam(Parameters& params);

#endif