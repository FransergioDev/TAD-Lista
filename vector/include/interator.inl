template < class T >
Vector<T>::Iterator::Iterator(T * vec) : it_ptr(vec)
        {}

template < class T >
typename Vector<T>::Iterator &  Vector<T>::Iterator::operator++(int k)
{
    it_ptr++;
    return *this;
}

template < class T >
typename Vector<T>::Iterator &  Vector<T>::Iterator::operator--(int x)
{
    it_ptr--;
    return *this;
}

template < class T >
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(char k)
{
    Iterator old(it_ptr);
    ++it_ptr;
    return old;
}

template < class T >
typename Vector<T>::Iterator Vector<T>::Iterator::operator--(char x)
{
    Iterator old(it_ptr);
    --it_ptr;
    return old;
}

template < class T >
bool Vector<T>::Iterator::operator==( const Iterator & it2) const
{
    return (it_ptr == it2.it_ptr);
}

template < class T >
bool Vector<T>::Iterator::operator!=( const Iterator & it2) const
{
    return (it_ptr != it2.it_ptr);
}


template < class T >
Vector<T>::Const_Iterator::Const_Iterator(T * vec) : const_it_ptr(vec)
        {}

template < class T >
bool Vector<T>::Const_Iterator::operator==( const Const_Iterator & it2) const
{
    return (const_it_ptr == it2.const_it_ptr);
}

template < class T >
bool Vector<T>::Const_Iterator::operator!=( const Const_Iterator & it2) const
{
    return (const_it_ptr != it2.const_it_ptr);
}
