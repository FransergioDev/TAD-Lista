/*!
 *	@file Vector.hpp
 *
 *  Arquivo que contém as assinaturas da classe Vector, assim como os
 *  headers necessários para o funcionamento do código
 */
#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
#include <memory>
#include <stdexcept>


using size_type = unsigned long long;

/*!
*   @brief  Classe Vector
*
*   Classe que simula a implementação de um vector, utiliza da
*  estrutura de dado array para manutenção dos dados.
*/
template < class T >
class Vector
{

    public:

    // -------------Class of iterator--------------

        /*!
        *  @brief Classe aninhada Iterator
        *
        *  Classe que se comporta similar de um iterador, suporta as operações comuns
        *  desse iterador
        */
        class Iterator
        {
            friend class Vector;
            public:
                // Métodos públicos que são abordados no arquivo "iterator.inl"
                Iterator(T * vec = nullptr);
                Iterator & operator++(int k);
                Iterator & operator--(int x);
                Iterator operator++(char);
                Iterator operator--(char);
                void operator= ( const Iterator & it2);
                bool operator==( const Iterator & it2) const;
                bool operator!=( const Iterator & it2) const;

            protected:
                /* A única variável é um ponteiro para um objeto cujo o tipo é
                 * o mesmo da Forward_list
                 */
                T * it_ptr;
        };

        /*!
         *  @brief Classe aninhada Const_Iterator
         *
         *  Classe que se comporta similar de um iterador constante, suporta as
         *  operações comuns desse iterador, porém não possui os operadores ++ e
         *  -- por não permitir ter seu valor alterado.
         */
        class Const_Iterator
        {
            friend class Vector;
            public:
                // Métodos públicos que são abordados no arquivo "iterator.inl"
                Const_Iterator(T * vec = nullptr);
                void operator=( const Const_Iterator & it2);
                bool operator==( const Const_Iterator & it2) const;
                bool operator!=( const Const_Iterator & it2) const;

            protected:
                /* A única variável é um ponteiro para um objeto cujo o tipo é
                 * o mesmo da Forward_list
                 */
                T * const_it_ptr;
        };

    // --------Constructor and destructor-----------
        Vector(size_type = 1);
        Vector(Vector & arr);
        ~Vector();

    // -------------Public Methods------------------

        // Para uma descrição detalhada, consultar o arquivo "Vector.inl"

        //  Esse é o prototipo da sobrecarga do operador []
        T & operator[] (size_type idx) const;
        //  Esse é o prototipo da função que retorna o elemento da posição passad como parametro.
        T & at(size_type idx);
        //  Esse é o prototipo da função que retorna a capacidade do array interno.
        size_type capacity() const;
        //  Esse prototipo é da função que aumenta a capacidade do array, se a nova capacidade for maior do que a atual.
        void reserve(size_type new_capacity);

        // prototipo da função que retorna o tamanho do array (a quantidade de elementos armazenados no array interno).
        size_type size() const;
        // prototipo da função que deleta todos os elementos do array.
        void clear();
        // prototipo do metodo que retorna se o array interno esta ou não vazio.
        bool empty();
        // prototipo do metodo que adiciona no final do array um elemento passado como parametro.
        void push_back( const T & x );
        // prototipo do metodo que remove do final do array o ultimo elemento e o retorna.
        void pop_back();
        // prototipo do metodo que retorna o ultimo elemento do array sem remove-lo.
        const T & back() const;
        // prototipo do metodo que que retorna o primeiro elemento do array sem remove-lo
        const T & front() const;
        // prototipo do metodo que substitui os valores das posições do array que estão armazenando algo pelo valor que foi passado como argumento.
        void assign(const T & x);

        Iterator begin();
        Iterator end();

        // Métodos comuns que utilizam o iterator


    private:
    // -------------Class Variables-----------------

        // variavel que indica o tamanho do array interno, ou seja, quantos elemento que o array esta armazenando.
        size_type arrSz;
        // variavel que armazena a capacidade do array interno, ou seja, a quantidade maxima de elementos que esse array pode armazenar sem ser aumentar a capacidade com alocação dinamica
        size_type arrCapacity;
        // arr é a variavel ponteiro que aponta para o array interno.
        std::unique_ptr<T[]> arr;
};

#include "vector.inl"
#include "iterator.inl"


#endif
