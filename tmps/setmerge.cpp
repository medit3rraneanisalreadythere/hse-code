#include <bits/stdc++.h>

class newset
{
    public:
        vector<char> s;

        void scanset()
        {
            string temp = "";

            std::cin >> temp;

            s = temp;
        }

        void printset()
        {
            for (auto t: s)
            {
                std::cout << t;
            }

            std::cout << std::endl;
        }
};

void intersectset(const newset x, const newset y, newset &res)
{
    for (auto t: x.s)
    {
        res.s.emplace_back(t);
    }

    for (auto t: y.s)
    {
        for (auto r: res.s)
        {
            if (t == r)
            {}
        }
    }
}

signed main(int argc, char **argv)
{


    return 0;
}