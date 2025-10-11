#include <vector>
#include <assert.h>
#include <string>
#include <fstream>


typedef std::pair<std::vector<float>, std::vector<float>> list_pair;
typedef std::pair<std::string, std::string> list_title_pair;

std::pair<list_pair, list_title_pair> read_data(std::string path);