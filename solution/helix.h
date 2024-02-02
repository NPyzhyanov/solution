#ifndef HELIX_H
#define HELIX_H

class helix : public curve
{
public:
    helix(double radius_, double step_);
    
    std::array<double, 3> get_point(double t) override;
    std::array<double, 3> get_ders(double t) override;
    
    std::string get_info() override;
    
private:
    double radius;
    double step;
    
};

#endif // HELIX_H
