#include <bits/stdc++.h>

template <typename vt>
class smart_ptr
{
    vt* _ptr;

public:
    smart_ptr () noexcept(std::is_nothrow_default_constructible<vt>::value): _ptr((vt*)operator new(sizeof(vt), std::nothrow)) { new (_ptr) vt(); }
    ~smart_ptr () noexcept(std::is_nothrow_destructible<vt>::value) { 
        if (_ptr != nullptr) {
            _ptr->~vt(); 
            operator delete(_ptr, std::nothrow);
        } 
    }
    smart_ptr (const smart_ptr& t) = delete;
    smart_ptr& operator= (const smart_ptr& t) = delete;
    smart_ptr (smart_ptr&& t) noexcept: _ptr(t._ptr) { t._ptr = nullptr; }
    smart_ptr& operator= (smart_ptr&& t) noexcept(std::is_nothrow_destructible<vt>::value) { 
        if (this != &t) {
            this->~smart_ptr();
            _ptr = t._ptr;
            t._ptr = nullptr;
        } return *this; 
    }

    vt* get() const noexcept { return _ptr; }
    vt* operator-> () const noexcept { return _ptr; }
    vt& operator* () const noexcept{ return *(_ptr); }
};