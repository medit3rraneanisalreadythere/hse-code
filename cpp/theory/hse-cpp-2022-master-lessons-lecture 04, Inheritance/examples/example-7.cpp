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

    double get_diagonal() const {
        return std::sqrt(std::pow(a, 2.) + std::pow(b, 2.));
    }

private:
    double a;
    double b;
};


class rhombus : public shape {
public:
    rhombus(const double side, const double angle): side(side), angle(angle) {}
    double area() const override { return std::pow(side, 2.) * std::sin(angle); }

    std::pair<double, double> get_diagonals() const {
        return {
            side * std::sqrt(2. * (1 + std::cos(angle))),
            side * std::sqrt(2. * (1 - std::cos(angle)))
        };
    }

private:
    double side;
    double angle;
};


void print_greatest_diagonal(const shape& s) {
    const rectangle& re = dynamic_cast<const rectangle&>(s);
    std::cout << re.get_diagonal() << std::endl;

    const rhombus& rh = dynamic_cast<const rhombus&>(s);
    std::pair<double, double> diagonals = rh.get_diagonals();
    std::cout << std::max(diagonals.first, diagonals.second) << std::endl;
}

int main () {
    rectangle re(1., 2.);
    rhombus rh(1., std::numbers::pi / 4.);
    print_greatest_diagonal(re);
    print_greatest_diagonal(rh);
}
