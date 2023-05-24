#include <bits/stdc++.h>

struct no_such_move: std::exception
{
    no_such_move (const char* _str): description(_str) {}

    const char* what () const noexcept override
    {
        return description;
    }

private:
    const char* description;
};

std::vector< std::vector<int> > map;

struct figure
{
    int x, y;
    std::pair<int, int> ref;

    figure (): figure(0, 0) {}
    figure (const int& _x, const int & _y)
    {
        x = _x;
        y = _y;
        ref = {x, y};
    }

    const std::pair<int, int>& get_coordinates () const
    {
        return ref;
    }
    virtual std::vector< std::pair<int, int> > get_possible_moves () const = 0;
    void make_move (const std::pair<int, int>& move)
    {
        for (auto t: get_possible_moves())
        {
            if (t.first == move.first && t.second == move.second)
            {
                x = t.first;
                y = t.second;
                ref = {x, y};
                return;
            }
        }

        throw no_such_move("You made a wrong move!");
    }
};

class warrior: public figure
{

public:
    warrior (): figure() {}
    warrior (const std::pair<int, int>& coords): figure(coords.first, coords.second) {}

    warrior (const warrior& t) = default;
    warrior& operator= (const warrior& t) = default;
    ~warrior () = default;

    std::vector< std::pair<int, int> > get_possible_moves () const override
    {
        return {{x - 1, y + 1}, {x, y + 1}, {x + 1, y + 1}, {x + 1, y},{x + 1, y - 1}, {x, y - 1}, {x - 1, y - 1}, {x - 1, y}};
    }
};

class witch: public figure
{

public:
    witch (): figure() {}
    witch (const std::pair<int, int>& coords): figure(coords.first, coords.second) {}

    witch (const witch& t) = default;
    witch& operator= (const witch& t) = default;
    ~witch () = default;

    std::vector< std::pair<int, int> > get_possible_moves () const override
    {
        return {{x, y + 1}, {x, y + 2}, {x + 1, y}, {x + 2, y}, {x, y - 1}, {x, y - 2}, {x - 1, y}, {x - 2, y}};
    }
};

class jumper: public figure
{

public:
    jumper (): figure() {}
    jumper (const std::pair<int, int>& coords): figure(coords.first, coords.second) {}

    jumper (const jumper& t) = default;
    jumper& operator= (const jumper& t) = default;
    ~jumper () = default;

    std::vector< std::pair<int, int> > get_possible_moves () const override
    {
        return {{x - 2, y + 1}, {x - 1, y + 2}, {x + 1, y + 2}, {x + 2, y + 1}, {x + 2, y - 1}, {x + 1, y - 2}, {x - 1, y - 2}, {x - 2, y - 1}};
    }
};