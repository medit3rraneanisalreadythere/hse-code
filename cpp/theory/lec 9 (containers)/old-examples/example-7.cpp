#include <iostream>
#include <array>
#include <vector>


template <typename sequence_container_t>
void print_sequence_container_data (const sequence_container_t& arr) {
    for (
        /**
         * Not std::size_t here, because the
         * size_type might be different!
         * It depends on the implementation of
         * the array_t class, it's not known
         * beforehand.
         */
        typename sequence_container_t::size_type i = 0;
        i < arr.size();
        ++ i
    ) {
        typename sequence_container_t::value_type value = arr[i];
        std::cout << value << " ";
    }

    std::cout << std::endl;
}

/// A simple non-allocator-aware container example
template <typename vt>
struct triplet {
    typedef vt value_type;
    typedef uint8_t size_type;
    int values[3];

    static size_type size () noexcept {
        return size_type(3);
    }

    int& operator[] (const size_type index) {
        return values[index];
    }

    const int& operator[] (const size_type index) const {
        return values[index];
    }
};

int main () {
    print_sequence_container_data(triplet<int>{1, 2, 3});
    print_sequence_container_data(std::array<bool, 3>{false, true, false});
    print_sequence_container_data(std::vector<double>({ 1.1, 2.2, 3.5 }));
}
