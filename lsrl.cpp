#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::vector<float> x;
    std::vector<float> y;

    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);
    x.push_back(6);
    x.push_back(7);

    y.push_back(1);
    y.push_back(4);
    y.push_back(9);
    y.push_back(16);
    y.push_back(25);
    y.push_back(36);
    y.push_back(49);

    if (x.size() != y.size())
    {
        std::cerr << "X data must be the same size as Y data\n";
        exit(1);
    }

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

    float b = numerator / denominator;
    
    float a = (y_sum - b * x_sum) / x.size();

    std::cout << "The LSRL equation is y = " << a << " + " << b << "x" "\n";

    return 1;
}