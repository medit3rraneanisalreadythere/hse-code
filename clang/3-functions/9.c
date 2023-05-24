#include <stdio.h>
#include <math.h>

struct Point
{
    double x, y;
};

struct Vector
{
    double x1, y1;
    double x2, y2;
    double l;
};

void getPoint(struct Point *a)
{
    scanf("%lf %lf", &a->x, &a->y);
}

void makeVector(struct Vector *v, const struct Point a, const struct Point b)
{
    v->x1 = a.x;
    v->y1 = a.y;

    v->x2 = b.x;
    v->y2 = b.y;

    v->l = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void findBisect(const struct Vector s1, const struct Vector s2, const struct Point p1, const struct Point p2)
{
    struct Point o = {0,0};

    o.x = (p1.x + (s1.l / s2.l) * p2.x) / (1 + (s1.l / s2.l));
    o.y = (p1.y + (s1.l / s2.l) * p2.y) / (1 + (s1.l / s2.l));

    printf("%.5lf %.5lf\n", o.x, o.y);
}

int main(void)
{
    // A
    struct Point a = {0,0};
    getPoint(&a);

    // B
    struct Point b = {0,0};
    getPoint(&b);

    // C
    struct Point c = {0,0};
    getPoint(&c);

    struct Vector AB;
    makeVector(&AB, a, b);

    struct Vector AC;
    makeVector(&AC, a, c);

    struct Vector BC;
    makeVector(&BC, b, c);

    findBisect(AC, BC, a, b);
    findBisect(AB, AC, b, c);
    findBisect(AB, BC, a, c);

    return 0;
}
