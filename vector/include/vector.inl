#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "vector.hpp"

/**
*   Esse contrutor cria o vector com valores zerados
*/
template < class T >
Vector<T>::Vector() :
        arrCapacity(0),
        arrSz(0),
        arr (new T [0])
        {}

/**
*   Esse contrutor cria o vector
*   @params _size   Esse parametro é o tamanho do vector.
*/
template < class T >
Vector<T>::Vector(size_type _size) :
        arrCapacity(_size),
        arrSz(0),
        arr (new T [arrCapacity])
        {}

/**
*   Esse contrutor cria o vector
*   @params toCopy  o objeto vector que deverá ser copiado para o que esta sendo construído.
*/
template <class T>
Vector<T>::Vector(Vector & toCopy)
{
    for(int i=0; i < toCopy.size(); i++) {
        arr[i] = toCopy[i];
    }
    this->capacity = toCopy.capacity();
    this->arrSz = toCopy.size();
}

template <class T>
Vector<T>::~Vector()
{
    clear();
}

/**
*   Implementa o operador []
*   @params recebe como parametro o index do elemento a ser acessado.
*   @return retorna uma referência do elemento que foi pedido.
*/
template <class T>
T & Vector<T>::operator[] (size_type idx) const
{
    return arr[idx];
}

template <class T>
T & Vector<T>::at(size_type idx)
{
    if(arrCapacity < idx) {
        std::cerr << ">>> O indice que voce pediu é maior doque o tamanho do array.\n";
    }
    else {
        return arr[idx];
    }
}

template <class T>
size_type Vector<T>::capacity() const {
    return arrCapacity;
}

template <class T>
void Vector<T>::reserve(size_type new_capacity) {
    if(arrCapacity < new_capacity) {
        T *auxArr = new T[capacity * 2];
        for(int i=0; i < capacity; i++) {
            auxArr[i] = arr[i];
        }
        arrCapacity *= 2;
        clear();
        arr(nullptr);
        arr(auxArr);
    }
    else {
        std::cerr << ">>> O novo tamanho não é maior do que o tamanho atual.\n";
    }
}

/**
*   Implementa o operador []
*   @params recebe como parametro o index do elemento a ser acessado.
*   @return retorna uma referência do elemento que foi pedido.
*/
template < class T >
size_type Vector<T>::size() const
{
    return arrCapacity;
}

template < class T >
void Vector<T>::clear()
{
    for(auto i=0; i < arrSz; i++)
    {
        arr[i].~T();
        arrSz--;
    }
}

/**
*   A função empty() informa se o vetor está vazio.
*   @return caso o vetor esteja vazio o retorno é true, caso contrario é false.
*/
template < class T >
bool Vector<T>::empty()
{
    return arrSz == 0;
}

/**
*   A função push_back() adiciona um elemento na (ultima posição ocupada do array) + 1.
*   @param  x   Esse argumento recebe a referencia do elemento que deve ser adicionado no array.
*   @return esta função não possui retorno.
*/
template < class T >
void Vector<T>::push_back( const T & x )
{
    arr[arrSz] = x;
    arrSz++;
}

/**
*   A função pop_back() deleta o ultimo elemento existente no array. Se o array estiver vazio lança uma exeção de array vazio.
*   @see empty()
*   @return esta função não possui retorno.
*/
template < class T >
void Vector<T>::pop_back()
{
    if(empty())
    {
        std::cerr << ">>> Não é posivel retirar elementos pois vetor esta vazio.\n";
    }
    arr[arrSz]->~T();
    arrSz--;
}

/**
*   A função back() retorna o valor armazenado na ultima posição do array.
*   @return esta função tem como retorno uma referencia ao elemento armazenado na ultima posição do array.
*/
template < class T >
const T & Vector<T>::back() const
{
    return arr[arrSz];
}

/**
*   A função front() retorna o valor armazenado na primeira posição do array.
*   @return esta função tem como retorno uma referencia ao elemento armazenado na primeira posição do array.
*/
template < class T >
const T & Vector<T>::front() const
{
    return arr[0];
}

/**
*   A função assign substitui os valores das posições do array que estão armazenado algo pelo valor que foi passado como argumento.
*   @param  x   recebe o valor que irá substituir os valores das posições que estão armazenando algo.
*   @return esta função não possue retorno
*/
template < class T >
void Vector<T>::assign(const T & x)
{
    for(auto i=0; i <= arrSz; i++) {
        arr[i] = x;
    }
}

#endif
