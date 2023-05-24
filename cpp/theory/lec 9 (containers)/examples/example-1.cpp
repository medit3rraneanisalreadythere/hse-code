#include <iostream>
#include <vector>

struct move_logger {
    explicit move_logger (int) {}

    move_logger (move_logger&) {};
    move_logger& operator= (move_logger&) = delete;

    move_logger (move_logger&& other) noexcept {
        std::cout << "move constructor called" << std::endl;
    }

    move_logger& operator= (move_logger&& other) noexcept {
        std::cout << "move assignment operator called" << std::endl;
        return *this;
    }
};

template <typename vt>
struct my_alloc {
    typedef vt value_type;

    vt* allocate (const std::size_t n) {
        vt* const ptr = reinterpret_cast<vt*>(new char[sizeof(vt) * n]);
        std::cout << "allocate " << n * sizeof(vt) << " bytes at " << ptr << std::endl;
        return ptr;
    }
    void deallocate (vt* const ptr, const std::size_t n) {
        std::cout << "deallocate " << ptr << std::endl;
        return delete[] reinterpret_cast<char*>(ptr);
    }
};


int main () {
    std::vector<move_logger, my_alloc<move_logger>> v;
    v.push_back(move_logger(123));
    v.push_back(move_logger(123));
    v.push_back(move_logger(123));
    v.push_back(move_logger(123));
}
