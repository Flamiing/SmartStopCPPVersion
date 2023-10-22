#ifndef CONFIGJSONFILE_HPP
# define CONFIGJSONFILE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include <jsoncpp/json/json.h>

#define CONFIG_FILE_PATH "./config.json"
#define DEFAULT_CONFIG "{\n	\"distro\": \"default\",\n	\"ide\": \"default\",\n	\"winterminal\": true\n}"
#define FORCED true
#define NOT_FORCED false

bool askUserForConfig(Json::Value configFile);
bool configJsonFile(void);
bool createFileIfNotExists(bool forced);
bool modifyIfEmpty(std::ifstream& input);
bool modifyIfWrong(std::ifstream& input);

#endif