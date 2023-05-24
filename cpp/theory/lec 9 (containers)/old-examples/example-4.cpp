#include <iostream>
#include <array>

template <typename array_t>
void print_array_info (const array_t& arr) {
    std::cout <<
        arr.empty() << " " <<
        arr.size() << " " <<
        arr.max_size() << " " <<
        std::endl;
}

int main () {
    print_array_info(std::array<int, 3>{1, 2, 3});
    print_array_info(std::array<int, 0>{});
}
