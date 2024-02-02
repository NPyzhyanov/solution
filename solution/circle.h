#ifndef CIRCLE_H
#define CIRCLE_H

class circle : public curve
{
public:
    circle(double radius_);
    
    std::array<double, 3> get_point(double t) override;
    std::array<double, 3> get_ders(double t) override;
    
    std::string get_info() override;
    
    double get_radius() override;
    
    bool operator==(const circle& right);
    bool operator<(const circle& right);
    
private:
    double radius;
    
};

#endif // CIRCLE_H
