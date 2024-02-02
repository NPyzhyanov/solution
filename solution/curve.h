#ifndef CURVE_H
#define CURVE_H

class curve
{
public:
    virtual std::array<double, 3> get_point(double t) {return {t, t, t}; }
    virtual std::array<double, 3> get_ders(double t) {return {t, t, t}; }
    
    virtual std::string get_info() {return "";}
    
    virtual double get_radius() {return 0.0;}
};

#endif // CURVE_H
