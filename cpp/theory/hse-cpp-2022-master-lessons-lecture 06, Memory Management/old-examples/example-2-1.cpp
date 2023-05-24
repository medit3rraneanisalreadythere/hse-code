#include <iostream>
#include <memory>


struct logger {
    explicit logger (const std::size_t id): _id(id) { std::cout << "Constructed at " << this << std::endl; }
    ~logger () { std::cout << "Destructed at " << this << std::endl; }
    void print (const std::string &str) const { std::cout << _id << ": " << str << std::endl; }

private:
    std::size_t _id; /// 8B
};

int main () {
    std::allocator<logger> alloc;

    const std::size_t n = 2;

    logger* chunk = alloc.allocate(n);

    for (size_t i = 0; i < n; i ++)
        alloc.construct(&chunk[i], i + 1);

    chunk[0].print("hello");
    chunk[1].print("bye");

    for (size_t i = 0; i < n; i ++)
        alloc.destroy(&chunk[i]);

    alloc.deallocate(chunk, n);
}
