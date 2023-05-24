#include <iostream>
#include <vector>


template <typename vt>
class logger_allocator {
public:
    typedef vt value_type;

    explicit logger_allocator () {
        _start_log();
        std::cout << "created" << std::endl;
    }

    logger_allocator (const logger_allocator& other) {
        _start_log();
        std::cout << "copied from " << &other << std::endl;
    }

    vt* allocate (const std::size_t n) {
        vt* const ptr = reinterpret_cast<vt*>(new char[n * sizeof(vt)]);
        _log_allocation_or_deallocation(ptr, n, true);
        return ptr;
    }

    void deallocate (vt* const ptr, const std::size_t n) {
        _log_allocation_or_deallocation(ptr, n, false);
        delete[] ptr;
    }

private:
    void _start_log () {
        std::cout << "[logger at" << this << "]: ";
    }

    void _log_allocation_or_deallocation (const vt* const ptr, const std::size_t n, const bool is_allocation) {
        _start_log();
        std::cout <<
                  (is_allocation ? "allocated" : "deallocated") << " " <<
                  (n * sizeof(vt)) << " bytes of data at " <<
                  ptr << std::endl;
    }
};

int main () {
    logger_allocator<int> logger;
    std::vector<int, logger_allocator<int>> vec_1(logger);
    std::vector<int, logger_allocator<int>> vec_2(logger);

    vec_1.push_back(123);
    vec_2.push_back(321);
}
