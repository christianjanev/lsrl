#ifndef STATS
#define STATS

#include <optional>
#include <vector>

struct linear_equation
{
    float a;
    float b;
};

std::optional<linear_equation> linreg(std::vector<float> x, std::vector<float> y);

#endif