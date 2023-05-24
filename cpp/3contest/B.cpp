#include <bits/stdc++.h>

class layered_matrix
{
    size_t _n;
    std::vector< std::vector<int> > arr;

public:
    layered_matrix() = delete;
    layered_matrix(const layered_matrix& t): _n(t._n), arr(t.arr) {}
    layered_matrix(size_t n)
    {
        _n = n;

        for (size_t i = 0; i < n; ++i)
        {
            arr.emplace_back(std::vector<int>(n));

            for (size_t j = 0; j < n; ++j)
            {
                arr[i][j] = abs(i - j);
            }
        }
    }
    ~layered_matrix() = default;
    
    layered_matrix& operator= (const layered_matrix& t) = default;

    int get_sum(size_t x1, size_t y1, size_t x2, size_t y2) const
    {
        std::swap(x1, y1);
        std::swap(x2, y2);

        if (x1 > x2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }

        else if (x1 == x2 && y1 > y2)
        {
            std::swap(y1, y2);
        }

        int sum = 0;

        for (size_t i = x1; i <= x2; ++i)
        {
            for (size_t j = y1; j <= y2; ++j)
            {
                sum += arr[i][j];
            }
        }

        return sum;
    }

/*
    void print() const
    {
        for (size_t i = 0; i < _n; ++i)
        {
            for (size_t j = 0; j < _n; ++j)
            {
                std::cout << arr[i][j] << " ";
            }
            
            std::cout << std::endl;
        }
    }
*/
};

/*
int main()
{
    layered_matrix test(2);
    test.print();
    std::cout << test.get_sum(0, 0, 1, 1);

    return 0;
}
*/