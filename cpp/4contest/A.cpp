#include <bits/stdc++.h>

template <typename T>
class bucket_allocator
{
    struct bucket
    {
        void* address;
        size_t size;
        size_t allocated;
        size_t deallocated;

        bucket (void* _address, size_t _size, size_t _allocated, size_t _deallocated): address(_address), size(_size), allocated(_allocated), deallocated(_deallocated) {}
    };

    size_t tsize;
    std::vector<bucket> data;

public:
    typedef T value_type;

    bucket_allocator (const size_t threshold_size = 1024): tsize(threshold_size) {}

    bucket_allocator (const bucket_allocator& t) = delete;
    bucket_allocator& operator= (const bucket_allocator& t) = delete;
    ~bucket_allocator () = default;

    T* allocate(const size_t n)
    {
        if (n > tsize)
        {
            data.push_back(bucket(reinterpret_cast<T*>(new char[n * sizeof(T)]), n, n, 0));
            return (T*)data.back().address;
        }

        for (size_t i = 0; i < data.size(); ++i)
        {
            if (data[i].size - data[i].allocated >= n)
            {
                const size_t cur_allocated = data[i].allocated;
                data[i].allocated += n;
                return (T*)data[i].address + cur_allocated;
            }
        }

        data.push_back(bucket(reinterpret_cast<T*>(new char[tsize * sizeof(T)]), tsize, n, 0));
        return (T*)data.back().address;
    }

    void deallocate(T* ptr, const size_t n)
    {
        for (size_t i = 0; i < data.size(); ++i)
        {
            if ((T*)data[i].address <= ptr && (T*)data[i].address + data[i].size + 1 >= ptr)
            {
                data[i].deallocated += n;

                if (data[i].deallocated == data[i].allocated)
                {
                    delete [] reinterpret_cast<char*>(data[i].address);
                    data.erase(data.begin() + i);
                }

                return;
            }
        }
    }
};