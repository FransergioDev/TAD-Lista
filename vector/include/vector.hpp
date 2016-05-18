#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
#include <memory>
#include <stdexcept>


using size_type = unsigned long long;

template < class T >
class Vector
{

    public:

    // -------------Class of iterator--------------
        class Iterator
        {
            friend class Vector;
            public:

                Iterator(T * vec = nullptr);
                Iterator & operator++(int k);
                Iterator & operator--(int x);
                Iterator operator++(char);
                Iterator operator--(char);
                bool operator==( const Iterator & it2) const;
                bool operator!=( const Iterator & it2) const;

            protected:
                T * it_ptr;
        };

        class Const_Iterator
        {
            friend class Vector;
            public:

                Const_Iterator(T * vec = nullptr);
                bool operator==( const Const_Iterator & it2) const;
                bool operator!=( const Const_Iterator & it2) const;

            protected:
                T * const_it_ptr;
        };

    // --------Constructor and destructor-----------
        Vector(size_type = 1);
        Vector(Vector & arr);
        ~Vector();

    // -------------Public Methods------------------

        // Esses métodos são unicos do Vector
        T & operator[] (size_type idx) const;
        T & at(size_type idx);
        size_type capacity() const;
        void reserve(size_type new_capacity);

        // Métodos comuns a todas as listas
        size_type size() const;
        void clear();
        bool empty();
        void push_back( const T & x );
        void pop_back();
        const T & back() const;
        const T & front() const;
        void assign(const T & x);
        void resize(size_type);

        Iterator begin();
        Iterator end();

        // Métodos comuns que utilizam o iterator


    private:
    // -------------Class Variables-----------------

        size_type arrSz;
        size_type arrCapacity;
        std::unique_ptr<T[]> arr;
};

#include "vector.inl"
#include "iterator.inl"


#endif
