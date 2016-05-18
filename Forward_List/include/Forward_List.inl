template <class T>
Forward_list<T>::Forward_list() :
        m_size (0),
        m_head (nullptr),
        m_tail (nullptr)
{ /* Empty */ }

template <class T>
size_type Forward_list<T>::size() const {

    return m_size;
}


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
        m_size = 0;
    }
}

template <class T>
bool Forward_list<T>::empty() {
    return (m_head == nullptr);
}

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

template <class T>
const T & Forward_list<T>::back() const {
    if(m_head == nullptr) {
      throw std::length_error ("Nao ha valor a ser consultado");
    }
    return m_tail->data;
}

template <class T>
const T & Forward_list<T>::front() const {
    if(m_head == nullptr) {
        throw std::length_error ("Nao ha valor a ser consultado");
    }
    return m_head->data;
}

template <class T>
void Forward_list<T>::assign(const T & x){
    Node * work = m_head;
    while (work != nullptr){
        work-> data = x;
        work = work->next;
    }
}

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

template <class T>
size_type Forward_list<T>::length() {
    return m_size;
}

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


/**
*   Retorna o node anterior ao do node procurado.
*/
// template <class T>
// Node* Forward_list<T>::find(int _targetVal)
// {
//     Node* work = m_head;
//     if(work == nullptr) {
//       std::cout << ">>> A lista esta vazia.\n";
//       return nullptr;
//     }
//     if(work->data == _targetVal) {
//       return nullptr;
//     }
//     if(tail->dataa == _targetVal) {
//         return tail;
//     }
//     while(work->next != nullptr) {
//       if( (work->next->data) == _targetVal){
//         return work;
//       }
//       work = work->next;
//     }
//     std::cout << ">>> O elemento não foi encontrado.\n";
//     return nullptr;
// }

// template <class T>
// bool Forward_list<T>::insert(Node* _pAnte, int _newVal ) //antes tinha 3 entradas            bool insert( SNPtr & _pAIL, SNPtr _pAnte, int _newVal )
// {
//     Node* work = m_head;
//     Node* newNode;
//     if(_pAnte == nullptr) { // o novo Node deve ser
//       Node* work = m_head;
//       m_head = new Node;
//       m_head->data = _newVal;
//       m_head->next = work;
//       return true;
//     }
//     else if(m_head == nullptr) { // a lista é vazia, um node é craiado
//       try {
//         newNode = new Node;
//       }
//       catch(const std::bad_alloc & e) {
//         std::cout << ">>> Erro durante alocação na memoria do novo valor da lista.\n";
//         return false;
//       }
//       newNode->data = _newVal;
//       newNode->next = nullptr;
//       m_head = newNode;
//     }
//     else if(m_head == _pAnte) {

//       try {
//         SNPtr newNode = new Node;
//       }
//       catch(const std::bad_alloc & e) {
//         std::cout << ">>> Erro durante alocação na memoria do novo valor da lista.\n";
//         return false;
//       }

//       newNode->data = _newVal;
//       newNode->next = work;
//       m_head = newNode;
//     }
//     while(work->next != _pAnte) {
//       if(work->next == nullptr) {
//         std::cout << ">>> A posição que deve ser colocado o volor " << _newVal << " não foi encontrado.\n";
//         return false;
//       }
//       work = work->next;
//     }

//     try {
//       SNPtr newNode = new Node;
//     }
//     catch(std::bad_alloc & e) {
//       std::cout << ">>> Erro durante alocação na memoria do novo valor da lista.\n";
//       return false;
//     }

//     newNode->data = _newVal;
//     newNode->next = _pAnte;
//     work->next = newNode;
//     m_size += 1;
//     return true;
// }

// template <class T>
// bool Forward_list<T>::remove(Node* _pAnte, int & _retrievedVal ) // antes tinha 3 entradas     bool remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal )
// {
//     int x;
//     Node* work = m_head;
//     if(work == nullptr) {
//       std::cout << ">>> A lista esta vazia. Não existe oque remover.\n";
//       return false;
//     }
//     if(_pAnte == nullptr) {
//       work = work->next;
//       _retrievedVal = work->data;
//       delete work;
//       return true;
//     }
//     work = _pAnte->next;
//     _pAnte->next = work->next;
//     _retrievedVal = work->data;
//     delete work;
//     return true;
// }
