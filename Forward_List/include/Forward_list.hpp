/*!
 *	@file Forward_list.hpp
 *
 *  Arquivo que contém as assinaturas da classe Forward_list, assim como os
 *  headers necessários para o funcionamento do código
 */
#ifndef _FORWARD_LIST_HPP_
#define _FORWARD_LIST_HPP_

#include <iostream>
#include <memory>
#include <stdexcept>



using size_type = long long unsigned;

/*!
 *  @brief Classe Forward_list
 *
 *  Classe que simula a implementação de uma Forward_list, utiliza da TAD
 *  lista encadeada para manutenção dos dados.
 */


template <class T>
class Forward_list {
    private:
    //----------------------------Definição de tipo-----------------------------

    //Struct que guarda a definição de nó, usa-se template para maior flexibilidade
        struct Node {
          T data;
          Node * next;

          Node ( const T & d = T( ), Node * n = nullptr ) : data ( d ), next ( n )
          { /* Empty */ }
        };

    public:
    //-----------Construtores, Destrutor e operadores sobrecarregados-----------

    //Construtor básico
        Forward_list();

    //Construtor cópia
        Forward_list(const Forward_list<T> &);

    //Destrutor
        ~Forward_list();

    //Sobrecarga do operador = para receber elementos de uma outra lista
        Forward_list & operator= ( const Forward_list<T> & );

    //Sobrecarga do operador = para receber elementos de um ponteiro para uma lista
        Forward_list & operator= ( Forward_list<T> && );

    //-------------------------Classes de iteradores----------------------------

    /*!
     *  @brief Classe aninhada Iterator
     *
     *  Classe que se comporta similar de um iterador, suporta as operações comuns
     *  desse iterador
     */
        class Iterator
        {
            friend class Forward_list;

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
            friend class Forward_list;
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

        //------------------------Métodos públicos------------------------------
        // Para uma descrição detalhada, consultar o arquivo "Forward_list.inl"

        // Retorna a quantidade atual de elementos da lista
        size_type size() const;

        // Percorre a lista desalocando a memória de cada elemento, limpando-a
        void clear();

        // Confere se a lista está vazia ou não
        bool empty();

        // Anexa o objeto recebido ao último nó da lista
        void push_back( const T & x );

        // Remove o ultimo elemento da lista, liberando sua memória
        void pop_back();

        // Retorna o dado do último elemento da lista
        const T & back() const;

        // Retorna o  dado do primeiro elemento da lista
        const T & front() const;

        // Substitui todos os objetos da lista pelo objeto recebido
        void assign(const T & x);

        // Métodos específicos das listas encadeadas

        // Adiciona o objeto recebido na primeira posição da lista
        void push_front( const T & x );

        // Remove o primeiro elemento da lista
        void pop_front();

        // Imprime na tela a lista completa
        void print();



    private:
        //------------------------Variáveis de classe---------------------------

        // Guarda o tamanho atual da lista
        size_type m_size;

        // Aponta para o primeiro elemento da lista
        Node *m_head;

        // Aponta para o último elemento da lista
        Node *m_tail;

};


// Inclui as implementações contidas em "Forward_list.inl" ao final do arquivo
#include "Forward_list.inl"
#endif
