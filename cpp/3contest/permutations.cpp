#include <bits/stdc++.h>

template <size_t n>
class permutation
{
    unsigned p[n];

public:
    permutation()
    {
        for (int i = 0; i < n; ++i)
        {
            p[i] = i;
        }
    }

    permutation(unsigned *array)
    {
        for (int i = 0; i < n; ++i)
        {
            p[i] = array[i];
        }
    }

    permutation(const permutation& t) = default;
    permutation& operator= (const permutation& t) = default;

    permutation operator* (const permutation& f, const permutation& g)
    {
        for (int )
    }
};