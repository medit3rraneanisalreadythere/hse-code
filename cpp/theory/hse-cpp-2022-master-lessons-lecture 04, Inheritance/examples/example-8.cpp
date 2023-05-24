#include <iostream>

template <typename vt>
struct comparable {
    virtual bool compare_to(const vt& other) const = 0;
};

struct vector_2d : comparable<vector_2d> {
    vector_2d(const int x, const int y): x(x), y(y) {}

    bool compare_to(const vector_2d& other) const override {
        return x == other.x && y == other.y;
    }

private:
    int x, y;
};

struct number : comparable<number> {
    explicit number(const int num): num(num) {}

    bool compare_to(const number& other) const override {
        return num == other.num;
    }

private:
    int num;
};

template <typename vt>
bool compare(const vt& first, const vt& second) {
    return first.compare_to(second);
}

int main () {
    std::cout << compare(vector_2d(1, 2), vector_2d(2, 3)) << std::endl;
    std::cout << compare(number(2), number(2)) << std::endl;
}
