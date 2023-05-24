#include <iostream>
#include <array>

int main () {
    std::array<int, 3> arr{1, 2, 3};

    /// method at and operator[] both return refs:
    int& ref = arr.at(0);
    int& ref2 = arr[0];
    std::cout << ref << " " << ref2 << std::endl;
    ref = 123;
    std::cout << ref << " " << ref2 << std::endl;

    /**
     * method at throws exception if the index
     * is out of the array's bounds:
     */
    const int r1 = arr[5]; /// UB

    try {
        const int r2 = arr.at(5); /// RE
    } catch (const std::out_of_range& ex) {
        std::cout << ex.what() << std::endl;
    }

    /**
     * Both method at and the operator[] have non
     * const-qualified and const-qualified versions:
     * (same is true for the methods data, front and back)
     */
    const std::array<int, 3> arr2{1, 2, 3};

    /**
     * CE, method "at" is const-qualified
     * due to the array being so
     */
    int& ref3 = arr2.at(0);
    const int& ref4 = arr2.at(0); /// OK

    /**
     * Method data allows to obtain the raw-pointer on
     * the array's data. The data is guaranteed to be
     * stored contiguously:
     */
    int* const data = arr.data();

    /// pointer should be const, otherwise the CE occur:
    const int* const data2 = arr2.data();
    int* const data3 = arr2.data(); /// CE
}
