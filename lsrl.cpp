#include "stats.h"
#include <assert.h>
#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<std::vector<float>, std::vector<float>> list_pair;
typedef std::pair<std::string, std::string> list_title_pair;

std::pair<list_pair, list_title_pair> read_data(std::string path)
{
    /* first = titles (x, y), second = data (x, y) */
    std::ifstream data;
    data.open(path);
    assert(data.is_open());

    std::string line;

    std::vector<float> x;
    std::vector<float> y;
    std::string x_title;
    std::string y_title;

    std::getline(data, line);
    try {
        std::stof(line.substr(0, line.find(","))); // are we able to turn the first half of line 1 into a float?
        data.clear();
        data.seekg(0);
        y_title = "y";
        x_title = "x";
    } catch (const std::invalid_argument& err) { // titles are in the first line.
        x_title = line.substr(0, line.find(","));
        y_title = line.substr(line.find(",") + 1, line.length());
    }

    while (std::getline(data, line))
    {
        x.push_back(std::stof(line.substr(0, line.find(","))));
        y.push_back(std::stof(line.substr(line.find(",") + 1, line.length())));
    }

    data.close();

    list_pair pair_of_lists = std::make_pair(x, y);
    list_title_pair pair_of_titles = std::make_pair(x_title, y_title);

    return std::make_pair(pair_of_lists, pair_of_titles);
}

int main(int argc, char** argv)
{
    std::vector<float> x;
    std::vector<float> y;

    auto data = read_data("data.csv");
    x = data.first.first;
    y = data.first.second;

    std::optional<linear_equation> lsrl = linreg(x, y);
    std::optional<float> correlation_coefficient = r(x,y);

    if (lsrl.has_value())
        std::cout << "The LSRL equation is " << data.second.second << " = " << lsrl->a << " + " << lsrl->b << "(" << data.second.first << ") with an r=" << correlation_coefficient.value() << "\n";
    else { std::cerr << "X and Y must be the same size.\n"; exit(1); }

    return 1;
}