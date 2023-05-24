#include <iostream>
#include <vector>
#include <unordered_set>

int main(int argc, char **argv)
{
    size_t a_size, b_size;
    int c;
    
    std::cin >> a_size;
    std::vector<int> a(a_size);

    for (size_t i = 0; i < a_size; ++i)
    {
        std::cin >> a[i];
    }

    std::cin >> b_size;
    std::unordered_set<int> b;
    int t;

    for (size_t i = 0; i < b_size; ++i)
    {
        std::cin >> t;
        b.insert(t);
    }

    t = 0;
    std::cin >> c;

    for (size_t i = 0; i < a_size; ++i)
    {
        if (b.find(c - a[i]) == b.end())
        {
            continue;
        }

        t++;
    }

    std::cout << t;

    return 0;
}