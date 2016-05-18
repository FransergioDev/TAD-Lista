#ifndef _FORWARD_LIST_HPP_
#define _FORWARD_LIST_HPP_

#include <iostream>
#include <memory>
#include <stdexcept>

using size_type = long long unsigned;

template <class T>
class Forward_list {
    private:
        struct Node {
          T data;
          Node * next;

          Node ( const T & d = T( ), Node * n = nullptr ) : data ( d ), next ( n )
          { /* Empty */ }
        };

    public:

        Forward_list();

        // -------------Class of iterator--------------
        class Iterator
        {
            friend class Forward_list;
            public:

                Iterator(T * vec = nullptr);
                Iterator & operator++(int k);
                Iterator & operator--(int x);
                Iterator operator++(char);
                Iterator operator--(char);
                void operator= ( const Iterator & it2);
                bool operator==( const Iterator & it2) const;
                bool operator!=( const Iterator & it2) const;

            protected:
                T * it_ptr;
        };

        class Const_Iterator
        {
            friend class Forward_list;
            public:

                Const_Iterator(T * vec = nullptr);
                void operator=( const Const_Iterator & it2);
                bool operator==( const Const_Iterator & it2) const;
                bool operator!=( const Const_Iterator & it2) const;

            protected:
                T * const_it_ptr;
        };


        // Métodos comuns as TADs lista
        size_type size() const;
        void clear();
        bool empty();
        void push_back( const T & x );
        void pop_back();
        const T & back() const;
        const T & front() const;
        bool insert(Node* _pAnte, int _newVal );
        bool remove(Node* _pAnte, int & _retrievedVal );
        void assign(const T & x);

        // Métodos específicos das listas encadeadas
        void push_front( const T & x );
        void pop_front();
        size_type length();
        void print();

    private:
        size_type m_size;
        // typedef struct Node* NPtr; // no less SNPtr = NPtr
        Node *m_head;
        Node *m_tail;

};

#include "Forward_List.inl"
#endif
