#include <iostream>

template <typename vt>
struct counter {
    counter() { ++ alive; }
    counter(const counter&) { ++ alive; }

    static int alive_counter() { return alive; }

protected:
    static inline int alive = 0;
    ~counter() { -- alive; }
};

struct vector_2d : counter<vector_2d> {
    vector_2d (const int x, const int y): x(x), y(y) {}
    int x, y;
};

struct vector_3d : counter<vector_3d> {
    vector_3d (const int x, const int y, const int z): x(x), y(y), z(z) {}
    int x, y, z;
};

void print_cnt() {
    std::cout << vector_2d::alive_counter() << " " << vector_3d::alive_counter() << std::endl;
}

int main () {
    print_cnt();

    {
        vector_2d a(1, 2);
        vector_2d b(3, 4);
        print_cnt();
        vector_3d c(1, 2, 3);
        vector_3d d(4, 5, 6);
        print_cnt();
    }

    print_cnt();
}
