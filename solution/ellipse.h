#ifndef ELLIPSE_H
#define ELLIPSE_H

class ellipse : public curve
{
public:
    ellipse(double x_radius_, double y_radius_);
    
    std::array<double, 3> get_point(double t) override;
    std::array<double, 3> get_ders(double t) override;
    
    std::string get_info() override;
    
private:
    double x_radius;
    double y_radius;
    
};

#endif // ELLIPSE_H
