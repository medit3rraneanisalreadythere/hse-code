#include <numbers>
#include <cmath>


struct shape_2d {
    std::size_t get_space_dimensions () const { return 2; }
};


class rectangle : public shape_2d {
public:
    rectangle(const double a, const double b): a(a), b(b) {}
    double area() const { return a * b; }

private:
    double a;
    double b;
};


class rhombus : public shape_2d {
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

    /// 1-st problem
    // s.area(); /// CE
    s.rectangle::area();
    s.rhombus::area();

    /// 2-nd problem
    // s.get_space_dimensions(); /// CE
    s.rectangle::get_space_dimensions();
    s.rhombus::get_space_dimensions();
}
