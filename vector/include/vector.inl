/*!
 *	@file Vector.inl
 *
 *  Arquivo que contém as implementações dos métodos da classe Vector
 */

/*!
 *   @brief     Esse contrutor cria o vector
 *   @param    _size   Esse parametro é o tamanho do vector.
 */
template < class T >
Vector<T>::Vector(size_type _size) :
        arrSz(0),
        arrCapacity(_size),
        arr (new T [arrCapacity])
        {}

/*!
 *   @brief     Esse contrutor cria o vector
 *   @param    toCopy  o objeto vector que deverá ser copiado para o que esta sendo construído.
 */
template <class T>
Vector<T>::Vector(Vector & toCopy) :
        arrCapacity (toCopy.capacity()),
        arrSz (toCopy.size())
{
    for(int i=0; i < toCopy.size(); i++) {
        arr[i] = toCopy[i];
    }
}

/*!
*    @brief     Esse é o destrutor
*/
template <class T>
Vector<T>::~Vector()
{
    clear();
}

/*!
 *   @brief Implementa o operador []
 *   @param recebe como parametro o index do elemento a ser acessado.
 *   @return retorna uma referência do elemento que foi pedido.
 */
template <class T>
T & Vector<T>::operator[] (size_type idx) const
{
    if (idx >= arrSz)
        throw std::length_error ("Indice fora do escopo");
    return arr[idx];
}

/*!
*    @brief     Essa funcao retorna o elemento no indice que foi passado no parametro idx.
*    @param    idx     esse parametro é o índice do elemento que deverá ser retornado
*    @return    O retorno é uma copia do elemento na posição especificada
*/
template <class T>
T & Vector<T>::at(size_type idx)
{
    if(arrCapacity < idx) {
        std::cerr << ">>> O indice que voce pediu é maior do que o tamanho do array.\n";
    }
    else {
        return arr[idx];
    }
}

/*!
*    @brief     Essa funcao retorna a capacidade que o vector possui
*    @return    O retorno é a capacidade que o array interno do vector possui
*/
template <class T>
size_type Vector<T>::capacity() const {
    return arrCapacity;
}

/*!
*    @brief     Essa funcao aumenta a capacidade do array interno do vector se essa nova capacidade for maior do que a atual.
*    @param    new_capacity   esse parametro é a nova capacidade do array interno do vector
*    @return    Essa função não possui retorno
*/
template <class T>
void Vector<T>::reserve(size_type new_capacity) {
    if(new_capacity == 0) {
        new_capacity = 2;
    }

    if(arrCapacity < new_capacity) {
        std::unique_ptr<T[]> auxArr (new T[new_capacity]);
        for(int i=0; i < arrCapacity; i++) {
            auxArr[i] = arr[i];
        }
        arr = std::move(auxArr);
        arrCapacity = new_capacity;
    }
    else {
        std::cerr << ">>> O novo tamanho nao e maior do que o tamanho atual.\n";
    }
}

/*!
 *   @Brief     Essa função retorna o size (quantidade de elementos dentro do array interno do vector).
 *   @return    O retorno é o size do array interno do vector.
 */
template < class T >
size_type Vector<T>::size() const
{
    return arrSz;
}

/*!
*    @brief     A funcao clear() deleta todos os elementos dentro do array interno do vector usando seus destrutores.
*    @return    Essa função não possui retorno.
*/
template < class T >
void Vector<T>::clear()
{
    for(auto i=0; i < arrSz; i++)
    {
        arr[i].~T();
    }
    arrSz = 0;
}

/*!
*   @brief      A função empty() informa se o vetor está vazio.
*   @return     O retorno desse função é true caso esteja vazio, caso contrario é false.
*/
template < class T >
bool Vector<T>::empty()
{
    return arrSz == 0;
}

/*!
*   @brief      A função push_back() adiciona um elemento na (ultima posição ocupada do array) + 1.
*   @param      x   Esse argumento recebe a referencia do elemento que deve ser adicionado no array.
*   @return     esta função não possui retorno.
*/
template < class T >
void Vector<T>::push_back( const T & x )
{
    if(arrSz == arrCapacity)
        reserve(arrCapacity * 2);
    arr[arrSz] = x;
    arrSz++;
}

/*!
*   @brief       A função pop_back() deleta o ultimo elemento existente no array. Se o array estiver vazio lança uma exeção de array vazio.
*   @return     esta função não possui retorno.
*/
template < class T >
void Vector<T>::pop_back()
{
    if(arrSz == 0)
    {
        throw std::length_error ("Nao ha elemento no vetor");
    }
    arr[arrSz - 1].~T();
    arrSz--;
}

/*!
*   @brief      A função back() retorna o valor armazenado na ultima posição do array.
*   @return     O retorno dessa função é uma referencia ao elemento armazenado na ultima posição do array.
*/
template < class T >
const T & Vector<T>::back() const
{
    if (arrSz == 0)
    {
        throw std::length_error ("Nao ha elemento no vetor");
    }

    return arr[arrSz - 1];
}

/*!
*   @brief      A função front() retorna o valor armazenado na primeira posição do array.
*   @return     O retorno dessa função é uma referencia ao elemento armazenado na primeira posição do array.
*/
template < class T >
const T & Vector<T>::front() const
{
    if(arrSz == 0 )
    {
        throw std::length_error ("Nao ha elemento no vetor");
    }
    return arr[0];
}

/*!
*   @brief      A função assign substitui os valores das posições do array que estão armazenando algo pelo valor que foi passado como argumento.
*   @param      x   esse parametro recebe o valor que irá substituir os valores das posições que estão armazenando algo.
*   @return     esta função não possue retorno
*/
template < class T >
void Vector<T>::assign(const T & x)
{
    for(auto i=0; i < arrSz; i++) {
        arr[i] = x;
    }
}
