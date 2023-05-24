#include <iostream>
#include <memory>


struct logger {
    explicit logger (const std::size_t id): _id(id) { std::cout << "Constructed at " << this << std::endl; }
    ~logger () { std::cout << "Destructed at " << this << std::endl; }
    void print (const std::string &str) const { std::cout << _id << ": " << str << std::endl; }

private:
    std::size_t _id; /// 8B
};

template <typename alloc_t>
typename std::allocator_traits<alloc_t>::difference_type test_ptr_diff (const alloc_t& alloc) {
    typedef std::allocator_traits<alloc_t> alloc_traits;
    typename alloc_traits::const_pointer ptr1 = alloc.allocate(1);
    typename alloc_traits::const_pointer ptr2 = alloc.allocate(1);
    typename alloc_traits::difference_type diff = ptr2 - ptr1;
    return diff;
}

int main () {
    typedef std::allocator_traits<std::allocator<logger>> alloc_traits;
    std::allocator<logger> alloc;

    const std::size_t n = 2;

    logger* chunk = alloc_traits::allocate(alloc, n);

    for (size_t i = 0; i < n; i ++)
        alloc_traits::construct(alloc, &chunk[i], i + 1);

    chunk[0].print("hello");
    chunk[1].print("bye");

    for (size_t i = 0; i < n; i ++)
        alloc_traits::destroy(alloc, &chunk[i]);

    alloc_traits::deallocate(alloc, chunk, n);
}
