/*!
 *	@file Forward_list.hpp
 *
 *  Arquivo que contém as implementações dos métodos da classe Forward_list
 */

/*!
 *	@brief Construtor da classe.
 *
 *	Construtor básico que inicializa as várias e a lista vazia
 */
template <class T>
Forward_list<T>::Forward_list() :
        m_size (0),
        m_head (nullptr),
        m_tail (nullptr)
{ /* Empty */ }

/*!
 *	@brief Construtor cópia
 *  @param lista Uma lista do mesmo tipo passada por referência
 *
 *	Nesse construtor é criada uma duplicata da lista que foi recebida como parâmetro
 */
template <class T>
Forward_list<T>::Forward_list(const Forward_list<T> &lista)
{
    if(lista.size() != 0)
    {
        Node * tocopy = lista.m_head;
        Node * newNode;

        // Teste de erro para ver se é possível alocar o novo objeto
        try {
            newNode = new Node;
        }
        catch(const std::bad_alloc & e) {
            throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
        }

        newNode->data = tocopy->data;
        newNode->next = nullptr;
        tocopy = tocopy->next;

        while(tocopy != nullptr){

            try {
                newNode->next = new Node;
            }
            catch(const std::bad_alloc & e) {
                throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
            }
            newNode = newNode->next;

            newNode->data = tocopy->data;
            newNode->next = nullptr;

            tocopy = tocopy->next;
        }
    }

    //Os valores da lista a ser copiada são atribuidos à nova lista
    m_size = lista.size();
    m_head = lista.m_head;
    m_tail = lista.m_tail;

}

/*!
 *	@brief Destrutor
 *
 *	Convoca a função clear, eliminando todos os elementos da lista
 */
template <class T>
Forward_list<T>::~Forward_list()
{
    clear();
}

/*!
 *	@brief Sobrecarga do operador =
 *  @param lista Uma lista do mesmo tipo passada por referência
 *
 *	Tem comportamento análogo ao construtor cópia, fazendo a cópia profunda no
 *  primeiro argumento da lista passada no segundo argumento
 *  @return A lista já copiada
 */
template <class T>
Forward_list<T> & Forward_list<T>::operator= ( const Forward_list<T> & lista){
    clear();
    if(lista.size() != 0)
    {
        Node * tocopy = lista.m_head;
        Node * newNode;

        // Teste de erro para ver se é possível alocar o novo objeto
        try {
            newNode = new Node;
        }
        catch(const std::bad_alloc & e) {
            throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
        }

        newNode->data = tocopy->data;
        newNode->next = nullptr;
        tocopy = tocopy->next;

        while(tocopy != nullptr){

            try {
                newNode->next = new Node;
            }
            catch(const std::bad_alloc & e) {
                throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
            }
            newNode = newNode->next;

            newNode->data = tocopy->data;
            newNode->next = nullptr;

            tocopy = tocopy->next;
        }
    }

    //Os valores da lista a ser copiada são atribuidos à nova lista
    m_size = lista.size();
    m_head = lista.m_head;
    m_tail = lista.m_tail;
    return *this;
}

/*!
 *	@brief Sobrecarga do operador = para recebimento de ponteiros
 *  @param lista Um ponteiro para uma lista
 *
 *  Realiza uma cópia rasa da lista passada por ponteiro
 */
template <class T>
Forward_list<T> & Forward_list<T>::operator= ( Forward_list<T> && lista)
{
    clear();
    Node* work = lista.m_head;
    while(work != nullptr)
    {
        this->pushBack(work->data);
        work = work->next;
    }
    m_head = lista.front();
    m_tail = lista.back();
}

/*!
 *	@brief Retorna o tamanho da lista
 *
 *  @return Um inteiro longo longo e sem sinal dizendo a quantidade de elementos
 */
template <class T>
size_type Forward_list<T>::size() const {

    return m_size;
}


/*!
 *	@brief Deleta todos os elementos da lista
 *
 *  Percorre todos os elementos da lista chamando a função delete para eles
 *  no final zera o tamanho total da lista assim como reseta os ponteiros de
 *  início e fim
 */
template <class T>
void Forward_list<T>::clear(){
    if(m_head != nullptr){
        Node* work = m_head;
         while(m_head != nullptr) {
            work = work->next;
            delete[] m_head;
            m_head = work;
        }
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }
}

/*!
 *	@brief Consulta se a lista está vazia
 *
 *	Retorna true se o ponteiro de inicio aponta para nada, falso caso contrário
 */
template <class T>
bool Forward_list<T>::empty() {
    return (m_head == nullptr);
}

/*!
 *	@brief Insere um elemento ao final da lista
 *  @param x Um objeto a ser inserido na lista
 *
 *	Primeiramente testa se é possível alocar um novo objeto, se sim, o novo objeto
 *  é inserido na posição após o ponteiro de fim. Os ponteiros de inicio e fim são
 *  então atualizados de acordo.
 */
template <class T>
void Forward_list<T>::push_back( const T & x ){
    Node* newNode;
    try {
        newNode = new Node;
    }
      catch(const std::bad_alloc & e) {
        throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
    }

    newNode->data = x;
    newNode->next = nullptr;

    if(!empty())
    {
        m_tail->next = newNode;
        m_tail = newNode;
    }
    else
    {
        m_head = newNode;
        m_tail = newNode;
    }
    m_size++;
}

/*!
 *	@brief Remove o node no final da lista
 *
 *	Primeiramente testa se há algum elemento na lista, se sim, a lista é percorrida
 *  até o ultimo elemento, que é removido. Então, os ponteiros de inicio e fim são
 *  atualizados de acordo
 */
template <class T>
void Forward_list<T>::pop_back() {
    if(empty() ) {
        throw std::underflow_error ("Nao ha elemento a ser removido");
    }
    Node* work = m_head;
    Node* work2 = nullptr;
    while(work->next != nullptr) {
        work2 = work;
        work = work->next;
    }
    delete[] work;
    if (work2 == nullptr)
    {
        m_head = nullptr;
        m_tail = nullptr;
    }
    else
    {
        m_tail = work2;
        work2->next = nullptr;
    }
    m_size--;
}

/*!
 *	@brief Retorna o valor do último node
 *
 *	@return Objeto de dados contido node ultimo no da lista
 */
template <class T>
const T & Forward_list<T>::back() const {
    if(m_head == nullptr) {
      throw std::length_error ("Nao ha valor a ser consultado");
    }
    return m_tail->data;
}

/*!
 *	@brief Retorna o valor do primeiro node
 *
 *	@return Objeto de dados contido no primeiro node da lista
 */
template <class T>
const T & Forward_list<T>::front() const {
    if(m_head == nullptr) {
        throw std::length_error ("Nao ha valor a ser consultado");
    }
    return m_head->data;
}


/*!
 *	@brief Substitui os valores da lista
 *  @param x Valor que substituirá cada elemento da lista
 */
template <class T>
void Forward_list<T>::assign(const T & x){
    Node * work = m_head;
    while (work != nullptr){
        work-> data = x;
        work = work->next;
    }
}

/*!
 *	@brief Insere um elemento no inicio da lista
 *  @param x Um objeto a ser inserido na lista
 *
 *	Primeiramente testa se é possível alocar um novo objeto, se sim, o novo objeto
 *  é inserido na posição anterior o ponteiro de inicio. Os ponteiros de inicio e fim são
 *  então atualizados de acordo.
 */
template <class T>
void Forward_list<T>::push_front( const T & x ) {
    Node* newNode = nullptr;

    try {
        newNode = new Node;
    }
    catch(const std::bad_alloc & e) {
        throw std::overflow_error ( "Erro durante alocação na memoria do novo valor da lista.\n");
    }

    newNode->data = x;
    newNode->next = m_head;
    m_head = newNode;
    m_size++;
    if(m_size == 1)
        m_tail = m_head;
}


/*!
 *	@brief Remove o node no inicio da lista
 *
 *	Primeiramente testa se ha algum elemento na lista, se sim, o elemento apontado
 *  pelo ponteiro de inicio e deletado. Entao, os ponteiros de inicio e fim sao
 *  atualizados de acordo
 */
template <class T>
void Forward_list<T>::pop_front() {
    if(empty() ) {
        throw std::underflow_error ("Nao ha elemento a ser removido");
    }
    Node* work = m_head;
    work = work->next;
    delete[] m_head;
    m_head = work;
    m_size--;
    if(m_size == 0)
        m_tail = nullptr;
}

/*!
 *	@brief Imprime a lista na tela
 */
template <class T>
void Forward_list<T>::print() {
    int i = 0;
    Node* work = m_head;
    if(empty() ) {
      std::cerr << ">>> Lista vazia.\n"; // erro de lista vazia
    }
    std::cout << "[ ";
    while(work != nullptr) {
      std::cout << work->data << " ";
      i++;
      work = work->next;
    }
    std::cout << "]\n";
}
