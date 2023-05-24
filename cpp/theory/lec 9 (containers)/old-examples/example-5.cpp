#include <iostream>
#include <array>


int main () {
    std::array<int, 3> arr{1, 2, 3};
    std::array<int, 3> arr2{7, 8, 9};
    std::array<int, 3> arr3{1, 2, 3};

    std::cout <<
        /// Compare non equal containers
        "arr == arr2 returns " << (arr == arr2) << std::endl <<
        "arr != arr2 returns " << (arr != arr2) << std::endl <<
        "arr < arr2 returns " << (arr < arr2) << std::endl <<
        "arr <= arr2 returns " << (arr <= arr2) << std::endl <<
        "arr > arr2 returns " << (arr > arr2) << std::endl <<
        "arr >= arr2 returns " << (arr >= arr2) << std::endl <<
        // Compare equal containers
        "arr == arr3 returns " << (arr == arr3) << std::endl <<
        "arr != arr3 returns " << (arr != arr3) << std::endl <<
        "arr < arr3 returns " << (arr < arr3) << std::endl <<
        "arr <= arr3 returns " << (arr <= arr3) << std::endl <<
        "arr > arr3 returns " << (arr > arr3) << std::endl <<
        "arr >= arr3 returns " << (arr >= arr3) << std::endl;
}
