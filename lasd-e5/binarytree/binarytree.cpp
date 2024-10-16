
namespace lasd {

/* ****************************************************************************************************************** */
                                                //*** Node ***//
/* ****************************************************************************************************************** */

//Specific member function IsLeaf of Node
template <typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept{
    if(HasLeftChild() == true || HasRightChild() == true){
        return false;
    }
    return true;
}

/* ************************************************************************ */

//Comparison operator == of Node
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& nod) const noexcept {
    bool ret1 = true;
    bool ret2 = true;
    if(Element() != nod.Element()){
        return false;
    }
    if(IsLeaf() != nod.IsLeaf()){
        return false;
    }
    if(HasLeftChild() != nod.HasLeftChild()){
        return false;
    }
    if(HasRightChild() != nod.HasRightChild()){
        return false;
    }
    if(IsLeaf() == false){
        if(HasLeftChild() == true){
            ret1 = (LeftChild() == nod.LeftChild()); //Call to comparison == of Node
            if(ret1 == false){
                return false;
            }
        }
        if(HasRightChild()){
            ret2 = (RightChild() == nod.RightChild()); //Call to comparison == of Node
            if(ret2 == false){
                return false;
            }
        }
    }
    return (Element() == nod.Element());
}

//Comparison operator != of Node
template <typename Data>
inline bool BinaryTree<Data>::Node::operator!=(const Node& nod) const noexcept {
    return !(*this == nod);
}

/* ****************************************************************************************************************** */
                                            //*** BinaryTree ***//
/* ****************************************************************************************************************** */

//Comparison operator == of BinaryTree
template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& tree) const noexcept {
    if(size != tree.size){
        return false;
    }
    if(size > 0){
        return (Root() == tree.Root()); //Call to comparison == of Node
    }
    return true;
}

//Comparison operator != of BinaryTree
template <typename Data>
inline bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& tree) const noexcept {
    return !(*this == tree);
}

/* ****************************************************************************************************************** */

//Specific member functions (inherited from MappableContainer) MapPreOrder
template<typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* par){
    if(size > 0) {
        MapPreOrder(fun, par, &Root());
    }
}

//Specific member functions (inherited from MappableContainer) MapPostOrder
template<typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* par){
    if(size > 0) {
        MapPostOrder(fun, par, &Root());
    }
}

/* ****************************************************************************************************************** */

//Specific member functions (inherited from FoldableContainer) FoldPreOrder
template<typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const{
    if(size > 0) {
        FoldPreOrder(fun, par, acc, &Root());
    }
}

//Specific member functions (inherited from FoldableContainer) FoldPostOrder
template<typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const{
    if(size > 0) {
        FoldPostOrder(fun, par, acc, &Root());
    }
}

/* ****************************************************************************************************************** */

//Specific member functions (inherited from InOrderMappableContainer) MapInOrder
template<typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* par){
    if(size > 0) {
        MapInOrder(fun, par, &Root());
    }
}

//Specific member functions (inherited from InOrderFoldableContainer) FoldInOrder
template<typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* par, void* acc) const{
    if(size > 0) {
        FoldInOrder(fun, par, acc, &Root());
    }
}

/* ****************************************************************************************************************** */

//Specific member functions (inherited from BreadthMappableContainer) MapBreadth
template<typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* par){
    if(size > 0) {
        MapBreadth(fun, par, &Root());
    }
}

//Specific member functions (inherited from BreadthFoldableContainer) FoldBreadth
template<typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* par, void* acc) const{
    if(size > 0){
        FoldBreadth(fun, par, acc, &Root());
    }
}

/* ****************************************************************************************************************** */

//Auxiliary member functions MapPreOrder Accessory
template<typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* par, Node* curr){
    fun(curr->Element(), par);
    if(curr->HasLeftChild())
        MapPreOrder(fun, par, &curr->LeftChild());
    if(curr->HasRightChild())
        MapPreOrder(fun, par, &curr->RightChild());
}


//Auxiliary member functions MapPostOrder Accessory
template<typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* par, Node* curr){
    if(curr->HasLeftChild())
        MapPostOrder(fun, par, &curr->LeftChild());
    if(curr->HasRightChild())
        MapPostOrder(fun, par, &curr->RightChild());
    fun(curr->Element(), par);
}

/* ****************************************************************************************************************** */

//Auxiliary member functions FoldPreOrder Accessory
template<typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc, Node* curr) const{
    fun(curr->Element(), par, acc);
    if(curr->HasLeftChild())
        FoldPreOrder(fun, par, acc, &curr->LeftChild());
    if(curr->HasRightChild())
        FoldPreOrder(fun, par, acc, &curr->RightChild());
}


//Auxiliary member functions FoldPostOrder Accessory
template<typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc, Node* curr) const{
    if(curr->HasLeftChild())
        FoldPostOrder(fun, par, acc, &curr->LeftChild());
    if(curr->HasRightChild())
        FoldPostOrder(fun, par, acc, &curr->RightChild());
    fun(curr->Element(), par, acc);
}

/* ****************************************************************************************************************** */

//Auxiliary member functions MapInOrder Accessory
template<typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* par, Node* curr){
    if(curr->HasLeftChild())
        MapInOrder(fun, par, &curr->LeftChild());
    fun(curr->Element(), par);
    if(curr->HasRightChild())
        MapInOrder(fun, par, &curr->RightChild());
}

//Auxiliary member functions FoldInOrder Accessory
template<typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* par, void* acc, Node* curr) const{
    if(curr->HasLeftChild())
        FoldInOrder(fun, par, acc, &curr->LeftChild());
    fun(curr->Element(), par, acc);
    if(curr->HasRightChild())
        FoldInOrder(fun, par, acc, &curr->RightChild());
}

/* ****************************************************************************************************************** */

//Auxiliary member functions MapBreadth Accessory
template<typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* par, Node* curr){
    lasd::QueueLst<Node*> queue;
    queue.Enqueue(curr);
    while(!queue.Empty()){
        Node* n = queue.HeadNDequeue();
        if (n->HasLeftChild())
            queue.Enqueue(&n->LeftChild());
        if(n->HasRightChild())
            queue.Enqueue(&n->RightChild());
        fun(n->Element(), par);
    }
}

//Auxiliary member functions FoldBreadth Accessory
template<typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* par, void* acc, Node* curr) const{
    lasd::QueueLst<Node*> queue;
    queue.Enqueue(curr);
    while(!queue.Empty()){
        Node* n = queue.HeadNDequeue();
        if (n->HasLeftChild())
            queue.Enqueue(&n->LeftChild());
        if(n->HasRightChild())
            queue.Enqueue(&n->RightChild());
        fun(n->Element(), par, acc);
        }
}

/* ****************************************************************************************************************** */
                                        //*** BTPreOrderIterator ***//
/* ****************************************************************************************************************** */

// Specific constructors of BTPreOrderIterator
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree) {
    if(tree.Size() > 0){
        curr = &tree.Root();
    }else{
        curr = nullptr;
    }
}

/* ************************************************************************ */

// Copy constructor of BTPreOrderIterator
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& iter){
    curr = iter.curr;
    stack = iter.stack; //Call to copy assigment of Stack
}

// Move constructor of BTPreOrderIterator
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& iter)noexcept{
    std::swap(curr,iter.curr);
    std::swap(stack,iter.stack);
}

/* ************************************************************************ */

// Copy assignment of BTPreOrderIterator
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& iter){
    BTPreOrderIterator<Data>* new_iter = new BTPreOrderIterator<Data>(iter);
    std::swap(*new_iter, *this);
    delete new_iter;
    return *this;
}

// Move assignment of BTPreOrderIterator
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& iter)noexcept{
    std::swap(curr,iter.curr);
    std::swap(stack,iter.stack);
    return *this;
}

/* ************************************************************************ */

// Comparison operator == of BTPreOrderIterator
template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& iter) const noexcept {
    if(curr != iter.curr){
        return false;
    }
    return true;
}

// Comparison operator == of BTPreOrderIterator
template <typename Data>
inline bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& iter)const noexcept{
    return !(*this == iter);
}

/* ************************************************************************ */

// Operator *() of BTPreOrderIterator
template <typename Data>
Data& BTPreOrderIterator<Data>::operator*()const{
  if(curr != nullptr){
    return curr->Element();
  }else{
      throw std::out_of_range("Accesso ad un iteratore terminato.");
  }
}

/* ************************************************************************ */

// Terminated of BTPreOrderIterator
template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    if(curr == nullptr && stack.Empty()){
        return true;
    }
    return false;
}

/* ************************************************************************ */

// Operator++() of BTPreOrderIterator
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if(Terminated() == true){
        throw std::out_of_range("Accesso ad un iteratore terminato.");
    }
    if(curr->HasLeftChild()){
        if(curr->HasRightChild()){
            stack.Push(&(curr->RightChild()));
        }
    curr = &(curr->LeftChild());
    }else{
        if(curr->HasRightChild()){
            curr = &(curr->RightChild());
        }else{
            try{
                curr = stack.TopNPop();
            }catch (std::length_error e){
                curr = nullptr;
            }
        }
    }
    return *this;
}

/* ****************************************************************************************************************** */
                                        //*** BTPostOrderIterator ***//
/* ****************************************************************************************************************** */

// Auxiliary member functions mostLeafSx
template <typename Data>
typename BinaryTree<Data>::Node& BTPostOrderIterator<Data>::mostLeafSx(typename BinaryTree<Data>::Node& root){
    if (root.HasLeftChild()) {
        stack.Push(&root);
        return mostLeafSx(root.LeftChild());
        }

    if (root.HasRightChild()) {
        stack.Push(&root);
        return mostLeafSx(root.RightChild());
        }
    return root;
}

/* ************************************************************************ */

// Specific constructors of BTPostOrderIterator
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree){
    if(tree.Size() > 0){
        curr = &(mostLeafSx(tree.Root()));
    }else{
        curr = nullptr;
    }
}

/* ************************************************************************ */

// Copy constructor of BTPostOrderIterator
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& iter){
    curr = iter.curr;
    stack = iter.stack; //Call to copy assigment form stack
}

// Move constructor of BTPostOrderIterator
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& iter)noexcept{
    std::swap(curr,iter.curr);
    std::swap(stack,iter.stack);
}

/* ************************************************************************ */

// Copy assignment of BTPostOrderIterator
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& iter) {
    BTPostOrderIterator<Data>* new_iter = new BTPostOrderIterator<Data>(iter);
    std::swap(*new_iter, *this);
    delete new_iter;
    return *this;
}
// Move assignment of BTPostOrderIterator
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& iter)noexcept{
    std::swap(curr,iter.curr);
    std::swap(stack,iter.stack);
    return *this;
}

/* ************************************************************************ */

// Comparison operator == of BTPostOrderIterator
template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& iter) const noexcept {
    if(curr != iter.curr){
       return false;
    }
    return true;
}

// Comparison operator != of BTPostOrderIterator
template <typename Data>
inline bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& iter) const noexcept {
    return !(*this == iter);
}

/* ************************************************************************ */

//Operator*() of BTPostOrderIterator
template <typename Data>
Data& BTPostOrderIterator<Data>::operator*()const{
    if(curr != nullptr){
        return curr->Element();
    }else{
        throw std::out_of_range("Accesso ad un iteratore terminato.");
    }
}

/* ************************************************************************ */

//Terminated() of BTPostOrderIterator
template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    if(curr == nullptr && stack.Empty()){
        return true;
    }
    return false;
}

/* ************************************************************************ */

//Operator++() of BTPostOrderIterator
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if(Terminated() == true){
        throw std::out_of_range("Accesso ad un iteratore terminato.");
    }
    try {
        typename BinaryTree<Data>::Node *node = stack.Top();
        if(node->HasRightChild()){
            if(&(node->RightChild()) == curr){
                curr = stack.TopNPop();
            }else{
                curr = &(mostLeafSx(node->RightChild()));
            }
        }else{
            curr = stack.TopNPop();
        }
    }catch (std::length_error &e){
        curr = nullptr;
    }
    return *this;
}

/* ****************************************************************************************************************** */
                                        //*** BTInOrderIterator ***//
/* ****************************************************************************************************************** */

// Auxiliary member functions mostLeaftNode
template <typename Data>
typename BinaryTree<Data>::Node& BTInOrderIterator<Data>::mostLeftNode(typename BinaryTree<Data>::Node& root){
    if(root.HasLeftChild()){
        stack.Push(&root);
        return mostLeftNode(root.LeftChild());
    }
    return root;
}

/* ************************************************************************ */

// Specific constructors of BTInOrderIterator
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree){
    if(tree.Size() > 0){
        curr = &(mostLeftNode(tree.Root()));
    }else{
        curr = nullptr;
    }
}
/* ************************************************************************ */

// Copy constructor of BTInOrderIterator
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& iter){
    curr = iter.curr;
    stack = iter.stack;
}

// Move constructor of BTInOrderIterator
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& iter)noexcept{
    std::swap(curr,iter.curr);
    std::swap(stack,iter.stack);
}
/* ************************************************************************ */

// Copy assignment of BTInOrderIterator
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>& iter) {
    BTInOrderIterator<Data>* new_iter = new BTInOrderIterator<Data>(iter);
    std::swap(*new_iter, *this);
    delete new_iter;
    return *this;
}

// Move assignment of BTInOrderIterator
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& iter)noexcept{
    std::swap(curr,iter.curr);
    std::swap(stack,iter.stack);
    return *this;
}

/* ************************************************************************ */

// Comparison operator == of BTInOrderIterator
template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& iter) const noexcept {
    if(curr != iter.curr){
        return false;
    }
    return true;
}
// Comparison operator != of BTInOrderIterator
template <typename Data>
inline bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& iter) const noexcept {
    return !(*this == iter);
}

/* ************************************************************************ */

//Operator*() of BTInOrderIterator
template <typename Data>
Data& BTInOrderIterator<Data>::operator*()const{
    if(curr != nullptr){
        return curr->Element();
    }else{
        throw std::out_of_range("Accesso ad un iteratore terminato.");
    }
}

/* ************************************************************************ */

//Terminated() of BTInOrderIterator
template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    if(curr == nullptr && stack.Empty()){
        return true;
    }
    return false;
}

/* ************************************************************************ */

//Operator++() of BTInOrderIterator
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if(Terminated() == true){
        throw std::out_of_range("Accesso ad un iteratore terminato.");
        }
    if(curr->HasRightChild()){
        curr = &(mostLeftNode(curr->RightChild()));
    }else{
        try{
            curr = stack.TopNPop();
        }catch(std::length_error &e){
            curr = nullptr;
        }
    }
    return *this;
}

/* ****************************************************************************************************************** */
                                        //*** BTBreadthIterator ***//
/* ****************************************************************************************************************** */

//Specific constructors of BTBreadthIterator
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree){
    try{
        curr = &tree.Root();
    } catch (std::length_error) {
        curr = nullptr;
    }
}

/* ************************************************************************ */

//Copy constructor of BTBreadthIterator
template<typename Data>BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& iter){
    queue = iter.queue;
    curr = iter.curr;
}

//Move constructor of BTBreadthIterator
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& iter) noexcept{
    std::swap(queue, iter.queue);
    std::swap(curr, iter.curr);
}

/* ************************************************************************ */

//Copy assignment of BTBreadthIterator
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& iter){
     BTBreadthIterator<Data>* new_iter = new BTBreadthIterator<Data>(iter);
     std::swap(*new_iter, *this);
     delete new_iter;
     return *this;
}

//Move assignment of BTBreadthIterator
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& iter) noexcept{
    std::swap(queue, iter.queue);
    std::swap(curr, iter.curr);
    return *this;
}

/* ************************************************************************ */

//Comparison operator == of BTBreadthIterator
template<typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& iter) const noexcept{
    if(curr != iter.curr ){
        return false;
    }
    return true;
}

//Comparison operator != of BTBreadthIterator
template<typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& iter) const noexcept{
    return !(*this == iter);
}

/* ************************************************************************ */

//Operator *() of BTBreadthIterator
template<typename Data>
Data& BTBreadthIterator<Data>::operator*()const{
    if(curr == nullptr){
        throw std::out_of_range("Accesso ad un iteratore terminato.");
    } else {
        return curr->Element();
    }
}

/* ************************************************************************ */

//Terminated() of BTBreadthIterator
template<typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
    if(curr == nullptr){
        return true;
    }
    return false;
}

/* ************************************************************************ */

//Operator++() of BTBreadthIterator
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++(){
    if(Terminated() == true){
        throw std::out_of_range("Accesso ad un iteratore terminato.");
    }
    if(curr->HasLeftChild()){
        queue.Enqueue(&(curr->LeftChild()));
    }
    if(curr->HasRightChild()){
        queue.Enqueue(&(curr->RightChild()));
    }
    try{
        curr = queue.HeadNDequeue();
    }catch(std::length_error &e){
        curr = nullptr;
    }
    return *this;
}

/* ****************************************************************************************************************** */

}
