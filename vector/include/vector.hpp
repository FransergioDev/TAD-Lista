#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
#include <memory>

using size_type = size_t;

template < class T >
class Vector
{
    private:
    // -------------Class Variables-----------------
        size_type arrSz;
        size_type arrCapacity;
        std::unique_ptr<T[]> arr;

    public:
    // --------Constructor and destructor-----------
        Vector();
        Vector(size_type = 10);
        Vector(Vector & arr);
        ~Vector();

    // -------------Public Methods------------------
        T & operator[] (size_type idx) const;
        T & at(size_type idx);
        size_type capacity() const;
        void reserve(size_type new_capacity);

        size_type size() const;
        void clear();
        bool empty();
        void push_back( const T & x );
        void pop_back();
        const T & back() const;
        const T & front() const;
        void assign(const T & x);
        void resize(size_type);
};

#include "vector.inl"

#endif
