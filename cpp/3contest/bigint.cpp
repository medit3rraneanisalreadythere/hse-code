#include <iostream>
#include <vector>
#include <string>

class bigint
{
    std::vector<int> num;

public:
    bigint() = default;
    bigint(const bigint& t) = default;
    bigint& operator= (const bigint& t) = default;
    ~bigint() = default;
};