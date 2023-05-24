#include <iostream>



template <typename vt>
struct simple_array {
    explicit simple_array (const std::size_t size): _size(size), _data(new vt[size]) {}

    ~simple_array () {
        if (_data != nullptr)
            delete[] _data;
    }

    simple_array (const simple_array& other): simple_array(other._size) {
        /// Deep copy here, takes O(_size) time.
        for (std::size_t i = 0; i < _size; i ++)
            _data[i] = other._data[i]; /// Calling the operator= for every object in the array
    }

    simple_array& operator= (const simple_array& other) {
        if (this != &other) {
            this->~simple_array();
            new (this) simple_array(other);
        }

        return *this;
    }

    simple_array (simple_array&& other) noexcept: _data(other._data), _size(other._size) {
        other._data = nullptr;
        other._size = 0;
    }

    simple_array& operator= (simple_array&& other) noexcept {
        if (this != &other) {
            this->~simple_array();
            /// I want to explicitly call the move constructor here.
            new (this) simple_array(std::move(other));
        }

        return *this;
    }

    vt& operator[] (const std::size_t i) { return _data[i]; }
    const vt& operator[] (const std::size_t i) const { return _data[i]; }

    std::size_t size () const { return _size; }

private:
    vt* _data;
    std::size_t _size;
};


int main () {
    simple_array<int> a(3);

    for (std::size_t i = 0; i < a.size(); i ++)
        a[i] = i + 1;


    simple_array<int> b(std::move(a));

    for (std::size_t i = 0; i < b.size(); i ++)
        std::cout << b[i] << " ";

    std::cout << std::endl;


    simple_array<int> c(5);
    c = std::move(b);

    for (std::size_t i = 0; i < c.size(); i ++)
        std::cout << c[i] << " ";

    std::cout << std::endl;

    return 0;
}
