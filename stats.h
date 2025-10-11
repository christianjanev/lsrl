#ifndef STATS
#define STATS

#include <optional>
#include <vector>
#include <utility>

struct linear_equation
{
    float a;
    float b;
};

typedef std::pair<float, float> sums;

std::optional<float> sum(std::vector<float> x);
std::optional<sums> sum_of_two(std::vector<float> x, std::vector<float> y);
std::optional<float> sum_squared(std::vector<float> x);
std::optional<sums> sum_of_two_squared(std::vector<float> x, std::vector<float> y);
std::optional<float> max(std::vector<float> x);
std::optional<float> min(std::vector<float> x);

std::optional<linear_equation> linreg(std::vector<float> x, std::vector<float> y);
std::optional<float> r(std::vector<float> x, std::vector<float> y);

#endif