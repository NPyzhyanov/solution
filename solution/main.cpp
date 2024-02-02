#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <vector>
#include <map>
#include <memory>
#include <typeinfo>
#include <algorithm>

#include "consts.h"
#include "data_types.h"
#include "curve_types.h"
#include "curve.h"
#include "circle.h"
#include "ellipse.h"
#include "helix.h"
#include "print_array.h"

int main()
{
    std::vector<std::shared_ptr<curve>> my_curves;
    
    bool continue_filling = true;
    int loop_breaker = 0;
    while (continue_filling && loop_breaker < 50)
    {
        loop_breaker++;
        
        std::cout << "Enter a type of a curve ('1' or 'c' for circle, '2' or 'e' for ellipse, '3' or 'h' for helix) or enter '0' or 'exit' to stop filling the container: ";
        std::string curve_type_input;
        std::cin >> curve_type_input;
        
        curve_types::curve_types chosen_type;
        if (curve_type_input == "0" || curve_type_input == "exit")
        {
            continue_filling = false;
            break;
        }
        else if (curve_type_input == "1" || curve_type_input == "c")
        {
            chosen_type = curve_types::circle;
        }
        else if (curve_type_input == "2" || curve_type_input == "e")
        {
            chosen_type = curve_types::ellipse;
        }
        else if (curve_type_input == "3" || curve_type_input == "h")
        {
            chosen_type = curve_types::helix;
        }
        else
        {
            std::cout << "Incorrect input! Try again." << std::endl;
            continue;
        }
        
        try
        {
            switch (chosen_type)
            {
            
            case curve_types::circle:
            {
                std::cout << "Enter the radius: ";
                std::string user_radius_input;
                std::cin >> user_radius_input;
                double circle_radius = std::stod(user_radius_input);
                
                my_curves.push_back(std::make_shared<circle>(circle_radius));
            }
                break;
                
            case curve_types::ellipse:
            {
                std::cout << "Enter the x-axis radius: ";
                std::string user_x_radius_input;
                std::cin >> user_x_radius_input;
                double x_radius = std::stod(user_x_radius_input);
                std::cout << "Enter the y-axis radius: ";
                std::string user_y_radius_input;
                std::cin >> user_y_radius_input;
                double y_radius = std::stod(user_y_radius_input);
                
                my_curves.push_back(std::make_shared<ellipse>(x_radius, y_radius));
            }
                break;
                
            case curve_types::helix:
            {
                std::cout << "Enter the radius: ";
                std::string user_radius_input;
                std::cin >> user_radius_input;
                double helix_radius = std::stod(user_radius_input);
                std::cout << "Enter the z-axis step: ";
                std::string user_step_input;
                std::cin >> user_step_input;
                double helix_step = std::stod(user_step_input);
                
                my_curves.push_back(std::make_shared<helix>(helix_radius, helix_step));
            }
                break;
                
            default:
                std::cerr << "Cannot construct a curve" << std::endl;
                break;
            }
        }
        catch (const std::invalid_argument &ex)
        {
            std::cerr << "Invalid argument exception! " << ex.what() << std::endl;
            continue;
        }
        catch (const std::exception &ex_other)
        {
            std::cerr << "Exception! " << ex_other.what() << std::endl;
            continue;
        }
        catch(...)
        {
            std::cerr << "Unknown exception..." << std::endl;
        }
    }
    
    std::cout << "\n\tCoordinates and its derivatives at parameter t = pi / 4" << std::endl;
    
    double t1 = consts::pi / 4.0;
    for (auto it = my_curves.begin(); it != my_curves.end(); it++)
    {
        auto coords = (*it)->get_point(t1);
        auto ders = (*it)->get_ders(t1);
        
        print_array((*it)->get_info(), coords, data_types::coords);
        print_array((*it)->get_info(), ders, data_types::ders);
    }
    
    std::cout << "\n\tCircles sorted by radii:" << std::endl;
    
    std::vector<std::shared_ptr<curve>> sorted_circles;
    
    for (auto it = my_curves.begin(); it != my_curves.end(); it++)
    {
        if (typeid(**it) == typeid(circle))
        {
            sorted_circles.push_back(*it);
        }
    }
    
    std::sort(sorted_circles.begin(), sorted_circles.end(), 
              [] (const std::shared_ptr<curve>& lhs, const std::shared_ptr<curve>& rhs) {return lhs->get_radius() < rhs->get_radius();});
    
    for (auto it = sorted_circles.begin(); it != sorted_circles.end(); it++)
    {
        std::cout << (*it)->get_info() << std::endl;
    }
    
    std::cout << "\n\tSum of radii of all circles:" << std::endl;
    
    double sum = 0.0;
    std::for_each(sorted_circles.begin(), sorted_circles.end(), 
        [&sum] (const std::shared_ptr<curve>& elem) {sum += elem->get_radius();});
    std::cout << "sum = " << sum << std::endl;

    return 0;
}
