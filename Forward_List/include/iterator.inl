/*!
 *	@file iterator.inl
 *
 *  Arquivo que contém as implementações dos métodos das classes Iterator e
 *  Const_Iterator, contidas na classe Forward_list
 */

/*!
 *	@brief Construtor da classe.
 *  @param flis um ponteiro para um objeto do tipo da lista
 *
 *  atribui o ponteiro à variável  it_ptr
 */
template < class T >
Forward_list<T>::Iterator::Iterator(T * flis) : it_ptr(flis)
        {}

/*!
 *	@brief Sobrecarga do operador it++.
 *  @param k inutilizado
 *
 *  @return o ponteiro incrementado
 */
template < class T >
typename Forward_list<T>::Iterator &  Forward_list<T>::Iterator::operator++(int k)
{
    it_ptr++;
    return *this;
}

/*!
 *	@brief Sobrecarga do operador it--.
 *  @param x inutilizado
 *
 *  @return o ponteiro decrementado
 */
template < class T >
typename Forward_list<T>::Iterator &  Forward_list<T>::Iterator::operator--(int x)
{
    it_ptr--;
    return *this;
}

/*!
 *	@brief Sobrecarga do operador ++it.
 *  @param k inutilizado
 *
 *  @return O ponteiro no estado antes de ser incrementado
 */
template < class T >
typename Forward_list<T>::Iterator Forward_list<T>::Iterator::operator++(char k)
{
    Iterator old(it_ptr);
    ++it_ptr;
    return old;
}

/*!
 *	@brief Sobrecarga do operador --it.
 *  @param x inutilizado
 *
 *  @return O ponteiro no estado antes de ser decrementado
 */
template < class T >
typename Forward_list<T>::Iterator Forward_list<T>::Iterator::operator--(char x)
{
    Iterator old(it_ptr);
    --it_ptr;
    return old;
}


/*!
 *	@brief Sobrecarga do operador =.
 *  @param it2 um outro iterador do mesmo tipo
 *
 *  iguala os ponteiros de ambos iteradores
 */
template < class T >
void Forward_list<T>::Iterator::operator=( const Iterator & it2)
{
    it_ptr = it2.it_ptr;
}

/*!
 *	@brief Sobrecarga do operador ==.
 *  @param it2 um outro iterador do mesmo tipo
 *
 *  @return True se os ponteiros apontam o mesmo objeto, False caso contrário
 */
template < class T >
bool Forward_list<T>::Iterator::operator==( const Iterator & it2) const
{
    return (it_ptr == it2.it_ptr);
}

/*!
 *	@brief Sobrecarga do operador !=.
 *  @param it2 um outro iterador do mesmo tipo
 *
 *  @return True se os ponteiros não apontam o mesmo objeto, False caso contrário
 */
template < class T >
bool Forward_list<T>::Iterator::operator!=( const Iterator & it2) const
{
    return (it_ptr != it2.it_ptr);
}

/*!
 *	@brief Construtor da classe.
 *  @param flis um ponteiro para um objeto do tipo da lista
 *
 *  atribui o ponteiro à variável  it_ptr
 */
template < class T >
Forward_list<T>::Const_Iterator::Const_Iterator(T * flis) : const_it_ptr(flis)
        {}

/*!
 *	@brief Sobrecarga do operador =.
 *  @param it2 um outro iterador do mesmo tipo
 *
 *  iguala os ponteiros de ambos iteradores
 */
template < class T >
void Forward_list<T>::Const_Iterator::operator=( const Const_Iterator & it2)
{
    const_it_ptr = it2.const_it_ptr;
}

/*!
 *	@brief Sobrecarga do operador ==.
 *  @param it2 um outro iterador do mesmo tipo
 *
 *  @return True se os ponteiros apontam o mesmo objeto, False caso contrário
 */
template < class T >
bool Forward_list<T>::Const_Iterator::operator==( const Const_Iterator & it2) const
{
    return (const_it_ptr == it2.const_it_ptr);
}

/*!
 *	@brief Sobrecarga do operador !=.
 *  @param it2 um outro iterador do mesmo tipo
 *
 *  @return True se os ponteiros não apontam o mesmo objeto, False caso contrário
 */
template < class T >
bool Forward_list<T>::Const_Iterator::operator!=( const Const_Iterator & it2) const
{
    return (const_it_ptr != it2.const_it_ptr);
}
