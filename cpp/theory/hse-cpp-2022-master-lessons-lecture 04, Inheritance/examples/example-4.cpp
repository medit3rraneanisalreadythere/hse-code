#include <numbers>
#include <cmath>
#include <iostream>


struct shape {
    virtual double area () const = 0;
};

class rectangle : public shape {
public:
    rectangle(const double a, const double b): a(a), b(b) {}
    double area() const override { return a * b; }
    double diagonal() const { return std::sqrt(std::pow(a, 2.) + std::pow(b, 2.)); }

private:
    double a;
    double b;
};

class rhombus : public shape {
public:
    rhombus(const double side, const double angle): side(side), angle(angle) {}
    double area() const { return std::pow(side, 2.) * std::sin(angle); }
    double get_angle () const { return angle; }

private:
    double side;
    double angle;
};

void print_area(const shape& s) {
    std::cout << s.area() << std::endl;
}

int main () {
    rectangle re(1, 2);
    rhombus rh(1, std::numbers::pi / 4.);
    print_area(re);
    print_area(rh);
}
