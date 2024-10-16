
namespace lasd {

/* ****************************************************************************************************************** */
                                            //*** NodeVec ***//
/* ****************************************************************************************************************** */

// Specific constructor of Nodes
template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data &dat, long ind, Vector<NodeVec*>* vec) {
    info = dat;
    index = ind;
    puntvec = vec;
}

/* ********************************************************************** */

// Copy constructor of Nodes
template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const NodeVec &nod) {
    info = nod.info;
    index = -1;
    puntvec = nullptr;
}

/* ********************************************************************** */

// Move constructor of Nodes
template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(NodeVec &&nod) noexcept {
    std::swap(info, nod.info);
    index = -1;
    puntvec = nullptr;
}

/* ********************************************************************** */

//Copy assignment of Nodes
template<typename Data>
typename BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec &nod) {
    NodeVec *temp = new NodeVec(nod.info);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

/* ********************************************************************** */

//Move assignment of Nodes
template<typename Data>
typename BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::operator=(NodeVec &&nod) noexcept {
    std::swap(info, nod.info);
    index = -1;
    puntvec = nullptr;
    return *this;
}

/* ********************************************************************** */

//Element() of NodeVec mutable
template<typename Data>
Data &BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return info;
}

/* ********************************************************************** */

//Element() of NodeVec immutable
template<typename Data>
const Data &BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return info;
}

/* ********************************************************************** */

// HasLeftChild of NodeVec
template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    if(puntvec->Size() > ((index*2)+1)){
        return true;
    }
    return false;
}

/* ********************************************************************** */

// HasRightChild of NodeVec
template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    if(puntvec->Size() > ((index*2)+2)){
        return true;
    }
    return false;
}

/* ********************************************************************** */

//LeftChild of NodeVec
template<typename Data>
typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild()const{
    if(HasLeftChild() == true) {
        return *(puntvec->operator[]((index*2)+1));
    }
    else{
        throw std::out_of_range("Accesso a LeftChild non valido");
    }
}

/* ********************************************************************** */

//RightChild of NodeVec
template<typename Data>
typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild()const{
    if(HasRightChild() == true){
        return *(puntvec->operator[]((index*2)+2));
    }else{
        throw std::out_of_range("Accesso a RightChild non valido");
    }
}

/* ****************************************************************************************************************** */
                                        //*** BinaryTreeVec ***//
/* ****************************************************************************************************************** */

//Specific constructors of BinaryTreeVec
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& lin){
    if(lin.Size() > 0){
        size = lin.Size();
        vec = new Vector<NodeVec*>(size);
        for(ulong i = 0; i < size; i++){
            vec->operator[](i) = new NodeVec(lin[i], i, vec);
        }
    }else{
        size = lin.Size();
        vec = new Vector<NodeVec*>();
    }
}

/* ****************************************************************************************************************** */

//Copy constructor of BinaryTreeVec
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& tree){
    size = tree.size;
    if(size > 0){
        vec = new Vector<NodeVec*>(tree.size);
        for(ulong i = 0; i < size; i++){
            vec->operator[](i) = new NodeVec(tree.vec->operator[](i)->Element(), i, vec);
        }
    }else{
        vec = new Vector<NodeVec*>();
    }
}

/* ****************************************************************************************************************** */

//Move constructor of BinaryTreeVec
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& tree)noexcept{
    vec = new Vector<NodeVec*>();
    std::swap(size,tree.size);
    std::swap(vec, tree.vec);
}

/* ****************************************************************************************************************** */

//Destructor of BinaryTreeVec
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec<Data>() {
    for(ulong i = 0; i < size; i++) {
        delete vec->operator[](i);
    }
    delete vec;
    vec = nullptr;
    size = 0;
}

/* ****************************************************************************************************************** */

//Copy assignment of BinaryTreeVec
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec& tree){
    BinaryTreeVec<Data>* temp = new BinaryTreeVec<Data>(tree);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

/* ****************************************************************************************************************** */

//Move assignment of BinaryTreeVec
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& tree)noexcept{
    std::swap(size,tree.size);
    std::swap(vec,tree.vec);
    return *this;
}

/* ****************************************************************************************************************** */

//Comparison operator == of BinaryTreeVec
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data>& tree) const noexcept {
    if(size != tree.size){
        return false;
    }
    for (ulong i = 0; i < size; i++){
        if( vec->operator[](i)->Element() != tree.vec->operator[](i)->Element()){
            return false;
        }
    }
    return true;
}

//Comparison operator != of BinaryTreeVec
template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data>& tree) const noexcept {
    return!(*this == tree);
}

/* ****************************************************************************************************************** */

// Specific member functions (inherited from BinaryTree) Root
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const {
    if(size > 0) {
        return *(vec->operator[](0));
    }else{
      throw std::length_error("Accesso a Root non valido");
    }
}

/* ****************************************************************************************************************** */

// Specific member functions (inherited from Container) Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear() {
    for(ulong i = 0; i < size; i++) {
        delete vec->operator[](i);
    }
    if(vec != nullptr){
        vec->Clear();
    }
    size = 0;
}

/* ****************************************************************************************************************** */

// Specific member functions (inherited from BreadthMappableContainer) MapBreadth
template <typename Data>
void BinaryTreeVec<Data>::MapBreadth(const MapFunctor fun, void *par) {
    for(ulong i = 0; i < size; i++)
        fun(vec->operator[](i)->Element(), par);
}

/* ****************************************************************************************************************** */

// Specific member functions (inherited from BreadthFoldableContainer) FoldBreadth
template <typename Data>
void BinaryTreeVec<Data>::FoldBreadth(const FoldFunctor fun, const void* par, void *acc) const {
    for(ulong i = 0; i < size; i++)
        fun(vec->operator[](i)->Element(), par, acc);
}

/* ************************************************************************** */
}
