#include "stats.h"
#include <cmath>
#include <limits>
#include <optional>

std::optional<float> sum(std::vector<float> x)
{
    if (x.size() == 0) return std::nullopt;

    float sum = 0;

    for (int i = 0; i < x.size(); i++)
    {
        sum += x[i];
    }

    return sum;
}

std::optional<sums> sum_of_two(std::vector<float> x, std::vector<float> y)
{
    if (x.size() == 0 || x.size() != y.size()) return std::nullopt;

    float x_sum = 0;
    float y_sum = 0;

    for (int i = 0; i < x.size(); i++)
    {
        x_sum += x[i];
        y_sum += y[i];
    }

    sums pair;
    pair.first = x_sum;
    pair.second = y_sum;

    return pair;
}

std::optional<float> sum_squard(std::vector<float> x)
{
    if (x.size() == 0) return std::nullopt;

    float sum = 0;

    for (int i = 0; i < x.size(); i++)
    {
        sum += x[i] * x[i];
    }

    return sum;
}

std::optional<sums> sum_of_two_squared(std::vector<float> x, std::vector<float> y)
{
    if (x.size() == 0 || x.size() != y.size()) return std::nullopt;

    float x_sum = 0;
    float y_sum = 0;

    for (int i = 0; i < x.size(); i++)
    {
        x_sum += x[i] * x[i];
        y_sum += y[i] * y[i];
    }

    sums pair;
    pair.first = x_sum;
    pair.second = y_sum;

    return pair;
}

std::optional<float> variance(std::vector<float> x)
{
    if (x.size() == 0) return std::nullopt;

    float variance = 0;
    float mean = sum(x).value() / x.size();

    for (int i = 0; i < x.size(); i++)
    {
        variance += (x[i] - mean) * (x[i] - mean);
    }

    variance /= x.size() - 1;

    return variance;
}

std::optional<float> max(std::vector<float> x)
{
    if (x.size() == 0) return std::nullopt;

    float max = std::numeric_limits<float>::min();

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] > max) max = x[i];
    }

    return max;
}

std::optional<float> min(std::vector<float> x)
{
    if (x.size() == 0) return std::nullopt;

    float min = std::numeric_limits<float>::max();

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] < min) min = x[i];
    }

    return min;
}

std::optional<linear_equation> linreg(std::vector<float> x, std::vector<float> y)
{
    std::optional<sums> pair_sums = sum_of_two(x, y);

    if (x.size() != y.size() || !pair_sums.has_value()) return std::nullopt;

    float x_mean = pair_sums->first;
    float y_mean = pair_sums->second;

    x_mean /= x.size();
    y_mean /= y.size();

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
    std::optional<sums> pair_sums = sum_of_two(x, y);

    if (x.size() != y.size() || !pair_sums.has_value()) return std::nullopt;

    float x_mean = pair_sums->first;
    float y_mean = pair_sums->second;

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
