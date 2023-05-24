#include <iostream>
#include <array>


int main () {
    std::array<int, 3> arr{1, 2, 3};
    std::array<int, 5> arr2{1, 2, 3, 4, 5};

    /// Copy constructor:
    std::array<int, 3> arr3(arr); /// OK, sizes are the same
    std::array<int, 5> arr4(arr); // CE, sizes are different

    /// Copy constructor:
    arr3 = arr; /// OK, sizes are the same
    arr4 = arr; /// CE, sizes are different
}
