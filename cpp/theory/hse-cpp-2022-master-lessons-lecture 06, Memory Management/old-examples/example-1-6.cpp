#include <iostream>

struct point { /// 2 * 4B = 8B
    point (int x, int y): _x(x), _y(y) {};

private:
    int _x, _y;
};

int main () {
    /**
     * -- ALLOCATE --
     *
     * We're using cast here in order to get the pointer of the needed type (point)
     * so we'll be able to interact with the needed object.
     */
    point* const obj_ptr = reinterpret_cast<point*>(new char[sizeof(point)]);

    /**
     * -- CONSTRUCT --
     */
    // ???

    /**
     * -- DESTRUCT --
     */
    obj_ptr->~point();

    /**
     * -- DEALLOCATE --
     *
     * Cast here is necessary!
     * We've allocated object as buffer of chars,
     * so we must deallocate it in the same way.
     */
    delete[] reinterpret_cast<char*>(obj_ptr);

    return 0;
}

