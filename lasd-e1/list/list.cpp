
namespace lasd {

/* ****************************************************************************************************************** */

// Specific constructors of Node
template <typename Data>
List<Data>::Node::Node(const Data& dat){
    info = dat;
    next = nullptr;
}

// Copy constructor of Node
template <typename Data>
List<Data>::Node::Node(const Node& nod){
    info = nod.info;
    next = nullptr;
}

// Move constructor of Node
template <typename Data>
List<Data>::Node::Node(Node&& nod) noexcept{
    std::swap(info, nod.info);
    next = nullptr;
    }

// Comparisono operator == of Node
template <typename Data>
bool List<Data>::Node::operator==(const Node& nod) const noexcept {
    if(info != nod.info){
        return false;
    }
    return true;
}

// Comparisono operator != of Node
template <typename  Data>
inline bool List<Data>::Node::operator!=(const Node& nod) const noexcept {
    return !(*this == nod);
}

/* ************************************************************************** */

// Specific constructor of List
template <typename Data>
List<Data>::List(const LinearContainer<Data>& lis){
    if(lis.Size() != 0) {
        size = lis.Size();
        head = new Node(lis[0]);
        tail = head;
        Node *curr = head;
        for (ulong i = 1; i < size; ++i) {
            curr->next = new Node(lis[i]);
            curr = curr->next;
            tail = curr;
        }
    }else{
        head = nullptr;
        tail = nullptr;
        size = lis.Size();
    }
}

// Copy constructor of List
template<typename Data>
List<Data>::List(const List<Data>& lis){
    if(lis.size != 0){
        Node* curr_lis = lis.head;

        head = new Node(curr_lis->info);
        tail = head;
        Node* prev = head;

        curr_lis = curr_lis->next;

        while(curr_lis != nullptr){
            prev->next= new Node(curr_lis->info);
            prev = prev->next;
            tail = prev;
            curr_lis = curr_lis->next;
        }
        size = lis.size;
    }else{
        head = lis.head;
        tail = lis.tail;
        size = lis.size;
    }
}

// Move constructor of List
template <typename Data>
List<Data>::List(List<Data>&& lis)noexcept{
    std::swap(size, lis.size);
    std::swap(head, lis.head);
    std::swap(tail, lis.tail);
}

// Destructor of List
template <typename Data>
List<Data>::~List(){
    Node *temp = nullptr;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

/* ****************************************************************************************************************** */

// Copy assignment
template <typename Data>
List<Data>& List<Data>::operator=(const List<Data> &lis) {
    List<Data>* templist = new List<Data>(lis);
    std::swap(*templist, *this);
    delete templist;
    return *this;
}

//Move assignment
template <typename Data>
List<Data>& List<Data>::operator=(List&& lis)noexcept{
    std::swap(size, lis.size);
    std::swap(head, lis.head);
    std::swap(tail, lis.tail);
    return *this;
}

/* ****************************************************************************************************************** */

// Comparison operators ==
template <typename Data>
bool List<Data>::operator==(const List<Data>& lis) const noexcept{
    if(size != lis.size){
        return false;
    }
    Node* curr = head;
    Node* temp = lis.head;

    while(curr != nullptr){
        if (curr->info != temp->info){
            return false;
        }
        curr = curr->next;
        temp = temp->next;
    }
    return true;
}

// Comparison operators !=
template <typename Data>
inline bool List<Data>::operator!=(const List<Data> &lis) const noexcept {
    return !(*this == lis);
}

/* ****************************************************************************************************************** */

// InsertAtFront Copy
template <typename Data>
void List<Data>::InsertAtFront(const Data& dat){
    Node* node = new Node(dat);
    if(head == nullptr){
        head = node;
        tail = node;
    }
    else{
        node->next = head;
        head = node;
    }
    size = size + 1;
}

//InsertAtFront Move
template <typename Data>
void List<Data>::InsertAtFront(Data&& dat)noexcept{
    Node* node = new Node(dat);
    if(head == nullptr){
        head = node;
        tail = node;
    }
    else{
        node->next = head;
        head = node;
    }
    size = size + 1;
}

/* ****************************************************************************************************************** */

//RemoveFromFront
template <typename Data>
void List<Data>::RemoveFromFront() {
    if(head != nullptr){
        Node* curr = head;
        head = head->next;
        delete curr;
        size = size - 1;
    }else{
        throw std::length_error("Accesso ad una lista vuota.");
    }
}

//FrontNRemove
template <typename Data>
Data List<Data>::FrontNRemove(){
    if(head != nullptr){
        Node* curr = head;
        Data info = curr->info;
        head = head->next;
        delete curr;
        size = size - 1;
        return info;
    }else{
        throw std::length_error("Accesso ad una lista vuota.");
    }
}

/* ****************************************************************************************************************** */

//InsertAtBack Copy
template <typename Data>
void List<Data>::InsertAtBack(const Data& dat) {
    Node* node = new Node(dat);
    if(head == nullptr){
        head = node;
        tail = node;
    }else{
        tail->next = node;
        tail = node;
    }
    size = size + 1;
}

//InsertAtBack Move
template <typename Data>
void List<Data>::InsertAtBack(Data&& dat) noexcept {
    Node* node = new Node(dat);
    if(head == nullptr){
        head = node;
        tail = node;
    }else{
        tail->next = node;
        tail = node;
    }
    size = size + 1;
}

/* ****************************************************************************************************************** */

// Specific member function (inherited from Container) Clear()
template <typename Data>
void List<Data>::Clear(){
    Node *temp = nullptr;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/* ****************************************************************************************************************** */

// Specific member function (inherited from LinearContainer) Front()
template <typename Data>
Data& List<Data>::Front() const {
    if(size != 0){
        return head->info;
    }else{
        throw std::length_error("Accesso ad una lista vuota.");
    }
}

// Specific member function (inherited from LinearContainer) Back()
template <typename Data>
Data& List<Data>::Back() const {
    if(size != 0){
        return tail->info;
    }else{
        throw std::length_error("Accesso ad una lista vuota.");
    }
}

// Specific member function (inherited from LinearContainer) operator[]
template <typename Data>
Data& List<Data>::operator[](const ulong index) const {
    if(index <= (size-1)){
        if(index == 0){
            return Front();
        }else if(index == (size-1)){
            return Back();
        }else{
            Node* curr = head;
            ulong k = 0;
            while(k < index){
                k++;
                curr = curr->next;
            }
            return curr->info;
        }
    }else{
        throw std::length_error("Accesso non valido alla lista.");
    }
}

/* ****************************************************************************************************************** */

// Specific member function (inherited from MappableContainer) MapPreOrder
template<typename Data>
void List<Data>::MapPreOrder(const MapFunctor fun, void *par) {
    MapPreOrder(fun, par, head);  //Call to accessory function
}

// Specific member function (inherited from MappableContainer) MapPostOrder
template<typename Data>
void List<Data>::MapPostOrder(const MapFunctor fun, void *par) {
    MapPostOrder(fun, par, head); //Call to accessory function
}

/* ****************************************************************************************************************** */

// Specific member functions (inherited from FoldableContainer) FoldPreOrder
template<typename Data>
void List<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const {
    FoldPreOrder(fun, par, acc, head); //Call to accessory function
}

// Specific member functions (inherited from FoldableContainer) FoldPostOrder
template<typename Data>
void List<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const {
    FoldPostOrder(fun, par, acc, head); //Call to accessory function
}

/* ****************************************************************************************************************** */

// Auxiliary member function (for MappableContainer) MapPreOrder Accessory
template<typename Data>
void List<Data>::MapPreOrder(const MapFunctor fun, void* par, Node* cur) {
    for (; cur != nullptr; cur = cur->next) {
        fun(cur->info, par);
    }
}

// Auxiliary member function (for MappableContainer) MapPostOrder Accessory
template<typename Data>
void List<Data>::MapPostOrder(const MapFunctor fun, void* par, Node* cur) {
    if (cur != nullptr) {
        MapPostOrder(fun, par, cur->next);
        fun(cur->info, par);
    }
}

/* ****************************************************************************************************************** */

// Auxiliary member functions (for FoldableContainer) FoldPreOrder Accessory
template<typename Data>
void List<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc, Node *cur) const {
    for (; cur != nullptr; cur = cur->next) {
        fun(cur->info, par, acc);
    }
}
// Auxiliary member functions (for FoldableContainer) FoldPostOrder Accessory
template<typename Data>
void List<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc, Node *cur) const {
    if (cur != nullptr) {
        FoldPostOrder(fun, par, acc, cur->next);
        fun(cur->info, par, acc);
    }
}

/* ****************************************************************************************************************** */

}
