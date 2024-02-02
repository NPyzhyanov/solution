#include <cmath>
#include <array>
#include <string>
#include <stdexcept>

#include "consts.h"
#include "curve.h"
#include "helix.h"

helix::helix(double radius_, double step_)
{
    if (radius_ <= 0)
    {
        throw std::invalid_argument("helix::helix(double, double): radius must be positive");
    }
    if (step_ <= 0)
    {
        throw std::invalid_argument("helix::helix(double, double): step must be positive");
    }
    radius = radius_;
    step = step_;
}

std::array<double, 3> helix::get_point(double t)
{
    return { radius * cos(t) , radius * sin(t) , step * t / 2.0 / consts::pi };
}

std::array<double, 3> helix::get_ders(double t)
{
    return { -radius * sin(t) , radius * cos(t) , step / 2.0 / consts::pi };
}

std::string helix::get_info()
{
    const std::string output_string = "Helix, radius = " + std::to_string(radius) + ", step = " + std::to_string(step);
    return output_string; 
}
