#include <iostream>
#include <array>


int main () {
    /**
     * This constructor uses aggregate initialization
     *
     * Double-braces required in C++11 prior to the CWG 1270 revision
     * (not needed in C++11 after the revision and in C++14 and beyond)
     *
     * OLD SYNTAX: std::array<int, 3> arr{ {1, 2, 3} };
     */
    std::array<int, 3> arr{1, 2, 3};

    /**
     * Also aggregate initialization.
     * Double-braces never required after =
     */
    std::array<int, 3> arr2 = {1, 2, 3};
}

