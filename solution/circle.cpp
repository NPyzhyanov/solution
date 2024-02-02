#include <cmath>
#include <array>
#include <string>
#include <stdexcept>

#include "curve.h"
#include "circle.h"

circle::circle(double radius_)
{
    if (radius_ <= 0)
    {
        throw std::invalid_argument("cirle::circle(double): radius must be positive");
    }
    radius = radius_;
}

std::array<double, 3> circle::get_point(double t)
{
    return { radius * cos(t) , radius * sin(t) , 0.0 };
}

std::array<double, 3> circle::get_ders(double t)
{
    return { -radius * sin(t) , radius * cos(t) , 0.0 };
}

std::string circle::get_info()
{
    const std::string output_string = "Circle, radius = " + std::to_string(radius);
    return output_string; 
}

double circle::get_radius()
{
    return radius;
}

bool circle::operator==(const circle& right)
{
    return (radius == right.radius);
}

bool circle::operator<(const circle& right)
{
    return (radius < right.radius);
}
