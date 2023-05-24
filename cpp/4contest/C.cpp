#include <forward_list>
#include <iostream>

size_t cnt = 0;

template < typename vt >
class reverse_forward_list
{
public:
    static void reverse (std::forward_list<vt>& t)
    {
        auto it_end = t.begin();
        int i = 0;

        for (auto it = t.begin(); it != t.end(); ++it)
        {
            it_end = it;
            ++i;
        }

        int j = 0;
        for (auto it = t.begin(); j < (i / 2); ++j, ++it)
        {
            std::swap(*it, *it_end);

            auto it_prev_end = it_end;
            for (auto it_ = it; it_ != it_prev_end; ++it_)
            {
                it_end = it_;
            }
        }
    }
};

int main()
{
    std::forward_list<int> r({1, 2, 3, 4, 5});
    // r.push_front(1);
    // r.push_front(2);
    // r.push_front(3);
    // r.push_front(4);
    // r.push_front(5);

    // for (const auto &x: r)
    // {
    //     std::cout << x << " ";
    // }

    // std::cout << std::endl;
    reverse_forward_list<int>::reverse(r);

    for (const auto &x: r)
    {
        std::cout << x << " ";
    }

    return 0;
}