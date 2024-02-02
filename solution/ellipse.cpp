#include <cmath>
#include <array>
#include <string>
#include <stdexcept>

#include "curve.h"
#include "ellipse.h"

ellipse::ellipse(double x_radius_, double y_radius_)
{
    if (x_radius_ <= 0 || y_radius_ <= 0)
    {
        throw std::invalid_argument("ellipse::ellipse(double, double): both radii must be positive");
    }
    x_radius = x_radius_;
    y_radius = y_radius_;
}

std::array<double, 3> ellipse::get_point(double t)
{
    return { x_radius * cos(t) , y_radius * sin(t) , 0.0 };
}

std::array<double, 3> ellipse::get_ders(double t)
{
    return { -x_radius * sin(t) , y_radius * cos(t) , 0.0 };
}

std::string ellipse::get_info()
{
    const std::string output_string = "Ellipse, x_radius = " + std::to_string(x_radius) + ", y_radius = " + std::to_string(y_radius);
    return output_string; 
}
