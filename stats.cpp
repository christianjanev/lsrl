#include "stats.h"
#include <cmath>
#include <optional>

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
    
    lsrl.a = (y_mean - lsrl.b * x_mean);

    return lsrl;
}

std::optional<float> r(std::vector<float> x, std::vector<float> y)
{
    if (x.size() != y.size()) return std::nullopt;

    float x_mean = 0;
    float y_mean = 0;

    for (int i = 0; i < x.size(); i++)
    {
        x_mean += x[i];
        y_mean += y[i];
    }

    x_mean /= x.size();
    y_mean /= y.size();

    float x_variance = 0;
    float y_variance = 0;

    for (int i = 0; i < x.size(); i++)
    {
        x_variance += (x[i] - x_mean) * (x[i] - x_mean);
        y_variance += (y[i] - y_mean) * (y[i] - y_mean);
    }

    x_variance /= x.size() - 1;
    y_variance /= y.size() - 1;

    float s_x = std::sqrt(x_variance);
    float s_y = std::sqrt(y_variance);

    float sum_product_z_score = 0;

    for (int i = 0; i < x.size(); i++)
    {
        sum_product_z_score += ((x[i] - x_mean) / s_x) * ((y[i] - y_mean) / s_y);
    }

    return sum_product_z_score / (x.size() - 1);
}
