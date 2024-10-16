
namespace lasd {

/* ****************************************************************************************************************** */
                                            //*** NodeLnk ***//
/* ****************************************************************************************************************** */

// Specific constructor of Node
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& dat) {
    info = dat;
    left = nullptr;
    right = nullptr;
}

/* ********************************************************************** */

// Copy constructor of Node
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& nod) {
    info = nod.info;
    left = nullptr;
    right = nullptr;
}

// Move constructor of Node
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& nod)noexcept{
    std::swap(info, nod.info);
    left = nullptr;
    right = nullptr;
}

/* ********************************************************************** */

// Destructor of Node
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    delete left;
    delete right;
}

/* ********************************************************************** */

// Copy Assigment of Node
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& nod) {
    typename BinaryTreeLnk<Data>::NodeLnk::NodeLnk *temp = new NodeLnk(nod);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

// Move Assigment of Node
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& nod)noexcept{
    std::swap(info, nod.info);
    left = nullptr;
    right = nullptr;
    return *this;
}

/* ********************************************************************** */

// Element of Node mutable
template<typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element()noexcept{
    return info;
}

// Element of Node immutable
template<typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element()const noexcept{
    return info;
}

/* ********************************************************************** */

// HasLeftChild of Node
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    if(left != nullptr){
        return true;
    }
    return false;
}

// HasRightChild of Node
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    if(right != nullptr){
        return true;
    }
    return false;
}

/* ********************************************************************** */

// LeftChild of Node
template<typename Data>
typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild()const{
    if(left != nullptr){
        return *left;
    }else{
        throw std::out_of_range("Accesso a LeftChild non valido");
    }
}

// RightChild of Node
template<typename Data>
typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild()const{
    if(right != nullptr){
        return *right;
    }else{
        throw std::out_of_range("Accesso a RightChild non valido");
    }
}

/* ****************************************************************************************************************** */
                                            //*** BinaryTreeLnk ***//
/* ****************************************************************************************************************** */

// Auxiliary functions for Specific constructor of BinaryTreeLnk
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::recursiveCopyContainer(const LinearContainer<Data>& con, ulong i){
    if(i < con.Size()){
        NodeLnk* new_node = new NodeLnk(con[i]);
        new_node->left = recursiveCopyContainer(con,(2*i)+1);
        new_node->right = recursiveCopyContainer(con,(2*i)+2);
        return new_node;
    }else{
        return nullptr;
    }
}

/* ****************************************************************************************************************** */

// Specific constructors of BinaryTreeLnk
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& con) {
    size = con.Size();
    if(size > 0){
        ulong i = 0;
        root = recursiveCopyContainer(con, i);
    }
    else{
        root = nullptr;
    }
}

/* ****************************************************************************************************************** */

// Auxiliary functions for Copy constructor of BinaryTreeLnk
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::recursiveCopyConstructor(const NodeLnk* node_tocopy){
    if(node_tocopy != nullptr){
        NodeLnk* new_node = new NodeLnk(node_tocopy->Element());
        new_node->left = recursiveCopyConstructor(node_tocopy->left);
        new_node->right = recursiveCopyConstructor(node_tocopy->right);
        return new_node;
    }else{
        return nullptr;
    }
}

/* ****************************************************************************************************************** */

// Copy constructors of BinaryTreeLnk
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& tree) {
    size = tree.size;
    if(size > 0){
        root = recursiveCopyConstructor(tree.root);
    }else{
        root = nullptr;
    }
}

// Move constructors of BinaryTreeLnk
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& tree)noexcept{
    std::swap(size, tree.size);
    std::swap(root, tree.root);
}

/* ****************************************************************************************************************** */

// Copy assigment of BinaryTreeLnk
template <typename Data>
BinaryTreeLnk<Data> & BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& tree) {
    BinaryTreeLnk<Data>* temp = new BinaryTreeLnk<Data>(tree);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

// Move assigment of BinaryTreeLnk
template <typename Data>
BinaryTreeLnk<Data> & BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& tree)noexcept{
    std::swap(size, tree.size);
    std::swap(root, tree.root);
    return *this;
}

/* ****************************************************************************************************************** */

// Destructor of BinaryTreeLnk
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk<Data>() {
    if(root != nullptr) {
        delete root;
    }
    root = nullptr;
    size = 0;
}

/* ****************************************************************************************************************** */

// Comparison == of BinaryTreeLnk
template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& tree)const noexcept{
    if(size != tree.size){
        return false;
    }
    return lasd::BinaryTree<Data>::operator==(tree);
}

// Comparison != of BinaryTreeLnk
template <typename Data>
inline bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& tree)const noexcept{
    return !(*this == tree);
}

/* ****************************************************************************************************************** */

// Specific member functions (inherited from BinaryTree) Root
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root()const {
    if(root != nullptr){
        return *root;
    }else{
        throw std::length_error("Accesso a Root non valido");
    }
}

/* ****************************************************************************************************************** */

// Specific member functions (inherited from Container) Clear
template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    if(root != nullptr) {
        delete root;
    }
    size = 0;
    root = nullptr;
}

/* ****************************************************************************************************************** */
}
