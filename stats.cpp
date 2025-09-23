#include "stats.h"

std::optional<linear_equation> linreg(std::vector<float> x, std::vector<float> y)
{
    if (x.size() != y.size()) return std::nullopt;

    float x_sum = 0;
    float y_sum = 0;

    for (int i = 0; i < x.size(); i++)
    {
        x_sum += x[i];
        y_sum += y[i];
    }

    float x_mean = x_sum / x.size();
    float y_mean = y_sum / y.size();

    float numerator = 0;
    float denominator = 0;

    for (int i = 0; i < x.size(); i++)
    {
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += ( (x[i] - x_mean) * (x[i] - x_mean) );
    }

    linear_equation lsrl;

    lsrl.b = numerator / denominator;
    
    lsrl.a = (y_sum - lsrl.b * x_sum) / x.size();

    return lsrl;
}