#include <iostream>


template <typename vt, vt num, vt den>
struct rational {
private:
    template <vt a, vt b, bool pred /* = false */>
    struct gcd_inner {
        const static vt value = a;
    };

    template <vt a, vt b>
    struct gcd_inner<a, b, true> {
        const static vt value = gcd_inner<b, a % b, (a % b > 0)>::value;
    };

    template <vt a, vt b>
    struct gcd {
        const static vt value = gcd_inner<a, b, (b > 0)>::value;
    };

    static_assert(den != vt(0), "Denominator should not be equal to zero");
    const static vt num_abs = num < 0 ? -num : num;
    const static vt den_abs = den < 0 ? -den : den;
    const static bool is_negative = (num < 0) != (den < 0);
    const static vt k = gcd<num_abs, den_abs>::value;

public:
    typedef vt value_type;
    const static vt numerator = (is_negative ? -1 : 1) * num_abs / k;
    const static vt denominator = den_abs / k;
};

template <typename vt>
using rational_zero = rational<vt, vt(0), vt(1)>;

template <typename vt>
using rational_one = rational<vt, vt(1), vt(1)>;

template <typename rat>
struct rational_neg : rational<typename rat::value_type, - rat::numerator, rat::denominator> {};

template <typename rat>
struct rational_inv : rational<typename rat::value_type, rat::denominator, rat::numerator> {};

template <typename rat1, typename rat2>
struct rational_pair_types_validation {
    static_assert(std::is_same_v<typename rat1::value_type, typename rat2::value_type>);
};

template <typename rat1, typename rat2>
struct rational_add :
    rational_pair_types_validation<rat1, rat2>,
    rational<
        typename rat1::value_type,
        rat1::numerator * rat2::denominator + rat2::numerator * rat1::denominator,
        rat1::denominator * rat2::denominator
    >
{};

template <typename rat1, typename rat2>
struct rational_mul :
    rational_pair_types_validation<rat1, rat2>,
    rational<
        typename rat1::value_type,
        rat1::numerator * rat2::numerator,
        rat1::denominator * rat2::denominator
    >
{};

template <typename rat1, typename rat2>
struct rational_sub : rational_add<rat1, rational_neg<rat2>> {};

template <typename rat1, typename rat2>
struct rational_div : rational_mul<rat1, rational_inv<rat2>> {};

template <typename rat, std::size_t pow>
struct rational_pow : rational_mul<rat, rational_pow<rat, pow - 1>> {};

template <typename rat>
struct rational_pow<rat, 0> : rational_one<typename rat::value_type> {};

template <typename rat>
constexpr void rational_print() { std::cout << rat::numerator << "/" << rat::denominator << std::endl; }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                      EXAM                                                        ///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** Корень один, причем строго внутри отрезка (не интервала!) [a, b]
 *
 * @tparam func – compile-time функция, принимающая рациональный аргумент
 * @tparam rat_a – параметр a
 * @tparam rat_b – параметр b
 * @tparam k – параметр "измельчения". Равен двоичному логарифму количества подотрезков, на которые будет разделен
 *             переданный отрезок [a, b]. Например, если k = 10, то отрезок [a, b] должен быть разделен на (как минимум)
 *             2 ^ 10 = 1024 отрезка. В случае бинпоиска, этот параметр равен глубине рекурсии
 */

template <template <typename> typename func, typename rat_a, typename rat_b, unsigned k>
struct rational_func_root : rational_pair_types_validation<rat_a, rat_b> {
public:
    typedef typename rat_a::value_type value_type;

private:
    /** Your code goes here **/

public:
    const static value_type numerator = /* Your code goes here instead 0 */ 0;
    const static value_type denominator = /* Your code goes here instead 0 */ 0;
};

template <typename rat, unsigned k>
struct rational_sqrt {
public:
    typedef typename rat::value_type value_type;

private:
    static_assert(rat::numerator >= 0);

    template <typename x>
    struct helper_func {
    private:
        static_assert(std::is_same_v<value_type, typename x::value_type>);
        /** Your code goes here **/

    public:
        const static value_type numerator = /* Your code goes here instead 0 */ 0;
        const static value_type denominator = /* Your code goes here instead 0 */ 0;
    };

    typedef rational_func_root<
        helper_func,
        rational_zero<value_type>,
        std::conditional_t<
            (rat::numerator < rat::denominator),
            rational_one<value_type>,
            rat
        >, /// max(1, rat)
        k
    > res;

public:
    const static value_type numerator = res::numerator;
    const static value_type denominator = res::denominator;
};


template <typename rat, unsigned n, unsigned k>
struct rational_nthrt {
public:
    typedef typename rat::value_type value_type;

private:
    /** Your code goes here **/

    template <typename x>
    struct helper_func {
    private:
        static_assert(std::is_same_v<value_type, typename x::value_type>);
        /** Your code goes here **/

    public:
        const static value_type numerator = /* Your code goes here instead 0 */ 0;
        const static value_type denominator = /* Your code goes here instead 0 */ 0;
    };

public:
    const static value_type numerator = /* Your code goes here instead 0 */ 0;
    const static value_type denominator = /* Your code goes here instead 0 */ 0;
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                      TESTS                                                       ///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// Функция f(x) = x - 1/3, корень – 1/3
template <typename x>
struct test_func : rational_sub<x, rational<typename x::value_type, 1, 3>> {};

/// При компиляции добавьте эту строчку в CMakeLists.txt (без `): `SET(CMAKE_CXX_FLAGS "-ftemplate-backtrace-limit=0")`
int main () {
    rational_print<rational_func_root<test_func, rational_zero<long long>, rational_one<long long>, 12>>();
    /// Should be close to 0.3333...

    rational_print<rational_sqrt<rational<long long, 2, 1>, 12>>();
    /// Should be close to 1.4142...

    rational_print<rational_nthrt<rational<long long, 2, 3>, 5, 12>>();
    /// Should be close to 0.9221...

    return 0;
}
