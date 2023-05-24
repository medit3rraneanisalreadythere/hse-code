#include <numbers>
#include <cmath>


struct shape_2d {
    std::size_t get_space_dimensions () const { return 2; }
};


class rectangle : public virtual shape_2d {
public:
    rectangle(const double a, const double b): a(a), b(b) {}
    double area() const { return a * b; }

private:
    double a;
    double b;
};


class rhombus : public virtual shape_2d {
public:
    rhombus(const double side, const double angle): side(side), angle(angle) {}
    double area() const { return std::pow(side, 2.) * std::sin(angle); }

private:
    double side;
    double angle;
};


struct square : public rectangle, public rhombus {
public:
    square(const double side): rectangle(side, side), rhombus(side, std::numbers::pi / 2.) {}
};


int main () {
    square s(1.);
    s.get_space_dimensions(); /// OK
}
