#include <iostream>


template <typename T>
class linear_allocator {
public:
    typedef T value_type;

    explicit linear_allocator (const std::size_t buffer_size = k_buffer_size) noexcept:
        _buffer_size(buffer_size),
        _buffer(reinterpret_cast<T*>(new (std::nothrow) char[sizeof(T) * k_buffer_size])),
        _allocations_count(0)
    {}

    ~linear_allocator () { delete[] reinterpret_cast<char*>(_buffer); }

    T* allocate (const std::size_t n) {
        std::cout << "Allocating memory for storing n = " << n << " objects" << std::endl;

        /// We dont have enough space for allocating n objects:
        if (_allocations_count + n > _buffer_size)
            throw std::bad_alloc(); /// No space left, so we need to throw an exception.

        const std::size_t current_allocations_count = _allocations_count;
        _allocations_count += n;
        return _buffer + current_allocations_count;
    }

    void deallocate (T*, const std::size_t n) const noexcept {
        std::cout << "Deallocating memory with n = " << n << " objects" << std::endl;
    }

    std::size_t max_size () const noexcept { return _buffer_size; }

private:
    const static std::size_t k_buffer_size = 1024;

    std::size_t _buffer_size;
    T* _buffer;
    std::size_t _allocations_count;
};

struct logger {
    explicit logger (const std::size_t id): _id(id) { std::cout << "Constructed at " << this << std::endl; }
    ~logger () { std::cout << "Destructed at " << this << std::endl; }
    void print (const std::string &str) const { std::cout << _id << ": " << str << std::endl; }

private:
    std::size_t _id;
};

int main () {
    typedef std::allocator_traits<linear_allocator<logger>> alloc_traits;

    typename alloc_traits::allocator_type alloc;

    std::cout << "Max size supported by an allocator: " << alloc_traits::max_size(alloc) << std::endl;

    typename alloc_traits::std::size_type n = 32;
    typename alloc_traits::pointer chunk = alloc_traits::allocate(alloc, n);

    for (std::size_t i = 0; i < n; i ++)
        alloc_traits::construct(alloc, chunk + i, i + 1);

    chunk[0].print("hello");
    chunk[1].print("bye");

    for (std::size_t i = 0; i < n; i ++)
        alloc_traits::destroy(alloc, chunk + i);

    alloc_traits::deallocate(alloc, chunk, n);
}
