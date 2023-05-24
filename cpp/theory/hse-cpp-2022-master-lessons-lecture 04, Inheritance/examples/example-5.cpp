#include <numbers>
#include <cmath>
#include <iostream>
#include <vector>


struct shape {
    virtual double area () const = 0;
    virtual ~shape () = default;
};


class rectangle : public shape {
public:
    rectangle(const double a, const double b): a(a), b(b) {}
    double area() const override { return a * b; }
    ~rectangle () { std::cout << "~rectangle" << std::endl; }

private:
    double a;
    double b;
};


class rhombus : public shape {
public:
    rhombus(const double side, const double angle): side(side), angle(angle) {}
    double area() const override { return std::pow(side, 2.) * std::sin(angle); }
    ~rhombus () { std::cout << "~rhombus" << std::endl; }

private:
    double side;
    double angle;
};


void print_area(const shape& s) {
    std::cout << s.area() << std::endl;
}

int main () {
    std::vector<shape* const> vec({
        new rectangle(1., 2.),
        new rhombus(1., std::numbers::pi / 4.)
    });

    for (const shape* const s : vec)
        print_area(*s);

    for (const shape* const s : vec)
        delete s;
}
