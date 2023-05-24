// #include <bits/stdc++.h>

template <typename T1, typename T2, typename T3>
class triad
{
    T1 first_element;
    T2 second_element;
    T3 third_element;

public:
    triad () = delete;
    triad (const T1 _f, const T2 _s, const T3 _t): first_element(_f), second_element(_s), third_element(_t) {}

    triad (const triad& t) = default;
    triad& operator= (const triad& t) = default;
    ~triad () = default;

    const T1& first () const
    {
        return first_element; 
    }

    const T2& second () const
    {
        return second_element; 
    }

    const T3& third () const
    {
        return third_element; 
    }

    T1& first ()
    {
        return first_element; 
    }

    T2& second ()
    {
        return second_element; 
    }

    T3& third ()
    {
        return third_element; 
    }
};