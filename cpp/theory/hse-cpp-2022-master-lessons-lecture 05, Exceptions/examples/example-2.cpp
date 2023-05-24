#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

struct point {
    double x, y;
    point (const double x, const double y): x(x), y(y) {}
    point (): x(0), y(0) {}
};
struct segment { point start, end; };

bool operator== (const point& first, const point& second) {
    const double eps = 1e-6;
    return std::fabs(first.x - second.x) < eps && std::fabs(first.y - second.y) < eps;
}

std::istream& operator>> (std::istream& is, point& p) {
    return is >> p.x >> p.y;
}

/// return true if segments intersect on interiors, false otherwise
bool segments_interior_intersect (const segment& first, const segment& second) {
    /// implementation is omitted
    return std::rand() % 2;
};

double calculate_polygon_area (const std::vector<point>& points, int& error_flag) {
    /// check that there is no repetition of points:
    for (std::size_t i = 0; i < points.size(); ++ i)
        for (std::size_t j = i + 1; j < points.size(); ++ j)
            if (points[i] == points[j]) {
                error_flag = 1; /// point repetition error
                return 0.;
            }

    /// check that polygon is not self-intersecting:
    for (std::size_t i = 0; i < points.size(); ++ i)
        for (std::size_t j = i + 1; j < points.size(); ++ j) {
            const segment first_segment{ points[i], points[(i + 1) % points.size()] };
            const segment second_segment{ points[j], points[(j + 1) % points.size()] };

            if (segments_interior_intersect(first_segment, second_segment)) {
                error_flag = 2; /// self-intersection error
                return 0.;
            }
        }

    /// calculating the area, if no error occurred:
    double area = 0.;

    for (std::size_t i = 0; i < points.size(); ++ i)
        /// using the gauss formula:
        area += points[i].x * (points[(i + 1) % points.size()].y - points[(i - 1) % points.size()].y);

    return std::fabs(area) / 2.;
}

int main () {
    std::size_t n;
    std::cin >> n;

    std::vector<point> points;

    for (std::size_t i = 0; i < n; ++ i) {
        point p;
        std::cin >> p;
        points.push_back(p);
    }

    int error_flag = 0;
    const double area = calculate_polygon_area(points, error_flag);

    /// check all possible errors here:
    if (error_flag == 0)
        std::cout << "area is: " << area << std::endl;
    else if (error_flag == 1)
        std::cout << "point repetition" << std::endl;
    else if (error_flag == 2)
        std::cout << "self-intersection" << std::endl;
    else
        std::cout << "unknown error" << std::endl;

    return 0;
}
