
namespace lasd {

/* ****************************************************************************************************************** */

// Specific constructors
template<typename Data>
BST<Data>::BST(const LinearContainer <Data> &lin) {
    for (ulong i = 0; i < lin.Size(); i++) {
        Insert(lin[i]);
    }
}
/* ****************************************************************************************************************** */

// Copy constructor
template<typename Data>
BST<Data>::BST(const BST &bstree) : BinaryTreeLnk<Data>(bstree) {}

// Move constructor
template<typename Data>
BST<Data>::BST(BST &&bstree) noexcept : BinaryTreeLnk<Data>(std::move(bstree)) {}

/* ****************************************************************************************************************** */

// Copy assigment
template<typename Data>
BST <Data> &BST<Data>::operator=(const BST &bstree) {
    BinaryTreeLnk<Data>::operator=(bstree);
    return *this;
}

// Move assigment
template<typename Data>
BST <Data> &BST<Data>::operator=(BST &&bstree) noexcept {
    BinaryTreeLnk<Data>::operator=(std::move(bstree));
    return *this;
}

/* ****************************************************************************************************************** */

// Comparison operator ==
template<typename Data>
bool BST<Data>::operator==(const BST &bstree) const noexcept {
    if (size != bstree.size) {
        return false;
    }
    BTInOrderIterator <Data> iter1(*this);
    BTInOrderIterator <Data> iter2(bstree);
    while (!iter1.Terminated()) {
        if (*iter1 != *iter2) {
            return false;
        }
        ++iter1;
        ++iter2;
    }
    return true;
}

// Comparison operator !=
template<typename Data>
inline bool BST<Data>::operator!=(const BST &bstree) const noexcept {
    return !(*this == bstree);
}

/* ****************************************************************************************************************** */

//FindPointerTo version CONST
template<typename Data>
typename BST<Data>::NodeLnk *const &BST<Data>::FindPointerTo(typename BST<Data>::NodeLnk *const &root, const Data &dat) const noexcept {
    typename BST<Data>::NodeLnk *const *punt = &root;
    if(root == nullptr) {
        return root;
    }
    if(root->info == dat) {
        return *punt;
    }else if(root->info < dat) { //I go down to the right
        if(root->right != nullptr) {
            return FindPointerTo(root->right, dat); //Recursive call on the Right Child
        }else {
            return (*punt)->right; //Return the right pointer of the node
        }
    }else{ //I go down to the left
        if(root->left != nullptr){
            return FindPointerTo(root->left, dat); //Recursive call on the Left Child
        }else{
            return (*punt)->left; //Return the left pointer of the node
        }
    }
}


//FindPointerTo version NOT CONST
template<typename Data>
typename BST<Data>::NodeLnk *&BST<Data>::FindPointerTo(typename BST<Data>::NodeLnk *&root, const Data &dat) noexcept {
    return const_cast<typename BST<Data>::NodeLnk *&>(static_cast<const BST <Data> *>(this)->FindPointerTo(root,dat));
}

/* ****************************************************************************************************************** */

//FindPointerToMIN version CONST
template<typename Data>
typename BST<Data>::NodeLnk *const &BST<Data>::FindPointerToMin(typename BST<Data>::NodeLnk *const &root) const noexcept {
    typename BST<Data>::NodeLnk *const *punt = &root;
    typename BST<Data>::NodeLnk *curr = root;

    if(curr != nullptr){
        for (; curr->left != nullptr; curr = curr->left) {
            punt = &curr->left;
        }
    }

    return *punt; //Return the pointer of the node
}

//FindPointerToMIN version NOT CONST
template<typename Data>
typename BST<Data>::NodeLnk *&BST<Data>::FindPointerToMin(typename BST<Data>::NodeLnk *&root) noexcept {
    return const_cast<typename BST<Data>::NodeLnk *&>(static_cast<const BST <Data> *>(this)->FindPointerToMin(root));
}

/* ****************************************************************************************************************** */

//FindPointerToMAX version CONST
template<typename Data>
typename BST<Data>::NodeLnk *const &
BST<Data>::FindPointerToMax(typename BST<Data>::NodeLnk *const &root) const noexcept {
    typename BST<Data>::NodeLnk *const *punt = &root;
    typename BST<Data>::NodeLnk *curr = root;

    if(curr != nullptr) {
        for (; curr->right != nullptr; curr = curr->right) {
            punt = &curr->right;
        }
    }

    return *punt;  //Return the pointer of the node
}

//FindPointerToMAX version NOT CONST
template<typename Data>
typename BST<Data>::NodeLnk *&BST<Data>::FindPointerToMax(typename BST<Data>::NodeLnk *&root) noexcept {
    return const_cast<typename BST<Data>::NodeLnk *&>(static_cast<const BST <Data> *>(this)->FindPointerToMax(root));
}

/* ****************************************************************************************************************** */

//FindPointerToPredecessor version CONST
template<typename Data>
typename BST<Data>::NodeLnk* const* BST<Data>::FindPointerToPredecessor(const Data &dat) const noexcept {
    typename BST<Data>::NodeLnk *const *curr = &root;
    typename BST<Data>::NodeLnk *const *predecessor = nullptr;

    while ((*curr) != nullptr) {
        if ((*curr)->info == dat) {
            if ((*curr)->left != nullptr){ //If Left SubTree exists
               return &FindPointerToMax((*curr)->left);
            }else{
                return predecessor;
            }
        } else if ((*curr)->info < dat) {  //I go down to the right and update the predecessor
            predecessor = curr;
            curr = &(*curr)->right;
        } else { //I go down to the left
            curr = &(*curr)->left;
        }
    }

    return predecessor;
}

//FindPointerToPredecessor version NOT CONST
template<typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(const Data &dat) noexcept {
    return const_cast<typename BST<Data>::NodeLnk **>(static_cast<const BST <Data> *>(this)->FindPointerToPredecessor(dat));
}

/* ****************************************************************************************************************** */

//FindPointerToSuccessor version CONST
template<typename Data>
typename BST<Data>::NodeLnk* const* BST<Data>::FindPointerToSuccessor(const Data &dat) const noexcept {
    typename BST<Data>::NodeLnk * const* curr = &root;
    typename BST<Data>::NodeLnk * const *successor = nullptr;

    while ((*curr) != nullptr) {
        if ((*curr)->info == dat) {
            if ((*curr)->right != nullptr){ //If Right SubTree exists
                return &FindPointerToMin((*curr)->right);
            }
            else{
                return successor;
            }

        } else if ((*curr)->info < dat) {  //I go down to the right
            curr = &(*curr)->right;

        } else { //I go down to the left and update the successor
            successor = curr;
            curr = &(*curr)->left;
        }
    }

    return successor;
}

template<typename Data>
typename BST<Data>::NodeLnk **BST<Data>::FindPointerToSuccessor(const Data &dat) noexcept {
    return const_cast<typename BST<Data>::NodeLnk **>(static_cast<const BST <Data> *>(this)->FindPointerToSuccessor(dat));
}

/* ****************************************************************************************************************** */

//Detach
template<typename Data>
typename BST<Data>::NodeLnk *BST<Data>::Detach(typename BST<Data>::NodeLnk *&nod) noexcept {
    typename BST<Data>::NodeLnk *temp = nullptr;

    if (nod->left != nullptr && nod->right == nullptr) { //If the node has only Left Child
        temp = SkipOnLeft(nod);

    } else if (nod->right != nullptr && nod->left == nullptr) { //If the node has only Right Child
        temp = SkipOnRight(nod);

    } else if(nod->left != nullptr && nod->right != nullptr){ //If the node has Left Child and Right Child
        temp = DetachMin(nod->right);
        //temp = DetachMax(nod->left);
        std::swap(nod->info, temp->info);

    }else{ //If the node is Leaf
        temp = SkipOnLeft(nod);
    }

    return temp;
}


//DetachMin
template<typename Data>
typename BST<Data>::NodeLnk *BST<Data>::DetachMin(typename BST<Data>::NodeLnk *&nod) noexcept {
    typename BST<Data>::NodeLnk *& min = FindPointerToMin(nod);
    return SkipOnRight(min);
}

//DetachMax
template<typename Data>
typename BST<Data>::NodeLnk *BST<Data>::DetachMax(typename BST<Data>::NodeLnk *&nod) noexcept {
    typename BST<Data>::NodeLnk *& max = FindPointerToMax(nod);
    return SkipOnRight(max);
}

/* ****************************************************************************************************************** */

//SkipOnLeft
template<typename Data>
typename BST<Data>::NodeLnk *BST<Data>::SkipOnLeft(typename BST<Data>::NodeLnk *&nod) noexcept {
    typename BST<Data>::NodeLnk *lef = nullptr;
    if (nod != nullptr) {
        std::swap(lef, nod->left);
        std::swap(lef, nod);
        size--;
    }
    return lef;
}

//SkipOnLeft
template<typename Data>
typename BST<Data>::NodeLnk *BST<Data>::SkipOnRight(typename BST<Data>::NodeLnk *&nod) noexcept {
    typename BST<Data>::NodeLnk *right = nullptr;
    if (nod != nullptr) {
        std::swap(right, nod->right);
        std::swap(right, nod);
        size--;
    }
    return right;
}

/* ****************************************************************************************************************** */

//DataNDalate
template<typename Data>
Data BST<Data>::DataNDelete(typename BST<Data>::NodeLnk *nod) {
   Data dat {};
   std::swap(dat, nod->info);
   delete nod;
   return dat;
}

/* ****************************************************************************************************************** */

//Insert Copy
template<typename Data>
void BST<Data>::Insert(const Data &dat) noexcept {
    typename BST<Data>::NodeLnk *& ptr = FindPointerTo(root, dat);
    if(ptr == nullptr){
        ptr = new typename BST<Data>::NodeLnk(dat);
        size++;
    }
}

//Insert Move
template<typename Data>
void BST<Data>::Insert(Data &&dat) noexcept {
    typename BST<Data>::NodeLnk *& ptr = FindPointerTo(root, dat);
    if(ptr == nullptr){
        ptr = new typename BST<Data>::NodeLnk(std::move(dat));
        size++;
    }
}

/* ****************************************************************************************************************** */

//Remove
template<typename Data>
void BST<Data>::Remove(const Data &dat) noexcept {
    typename BST<Data>::NodeLnk*& ptr = FindPointerTo(root, dat);
    if (ptr != nullptr) {
        typename BST<Data>::NodeLnk *temp = Detach(ptr);
        delete temp;
    }
}

/* ************************************************************************* */

//Min
template<typename Data>
const Data &BST<Data>::Min() const {
    if(root != nullptr){
        return FindPointerToMin(root)->info;
    }else{
        throw std::length_error("Accesso a min non valido, albero vuoto");
    }
}

//MinNRemove
template<typename Data>
Data BST<Data>::MinNRemove(){
    if(root != nullptr){
        typename BST<Data>::NodeLnk * min = DetachMin(root);
        return DataNDelete(min);
    }else{
        throw std::length_error("Accesso a min non valido, albero vuoto");
    }
}

//RemoveMin
template<typename Data>
void BST<Data>::RemoveMin(){
    if(root != nullptr){
        delete DetachMin(root);
    }else{
        throw std::length_error("Accesso a min non valido, albero vuoto");
    }
}

/* ************************************************************************* */

//Max
template<typename Data>
const Data &BST<Data>::Max() const {
        if (root != nullptr) {
            return FindPointerToMax(root)->info;
        } else {
            throw std::length_error("Accesso a min non valido, albero vuoto");
        }
    }

//MaxNRemove
template<typename Data>
Data BST<Data>::MaxNRemove(){
    if(root != nullptr){
        typename BST<Data>::NodeLnk * max = DetachMax(root);
        return DataNDelete(max);
    }else{
        throw std::length_error("Accesso a min non valido, albero vuoto");
    }
}

//RemoveMax
template<typename Data>
void BST<Data>::RemoveMax(){
    if(root != nullptr){
        delete DetachMax(root);
    }else{
        throw std::length_error("Accesso a min non valido, albero vuoto");
    }
}

/* ************************************************************************* */

//Predecessor
template<typename Data>
const Data& BST<Data>::Predecessor(const Data& dat)const{
    typename BST<Data>::NodeLnk* const* ptr2 = FindPointerToPredecessor(dat);
    if(ptr2 != nullptr){
        return (*ptr2)->info;
    }else{
        throw std::length_error("Accesso a predecessor non valido, albero vuoto");
    }
}

//PredecessorNRemove
template<typename Data>
Data BST<Data>::PredecessorNRemove(const Data& dat){
    typename BST<Data>::NodeLnk **ptr = FindPointerToPredecessor(dat);
    if(ptr != nullptr){
        return DataNDelete(Detach(*ptr));
    }else{
        throw std::length_error("Accesso a predecessor non valido, albero vuoto");
    }
}

//PredecessorNRemove
template<typename Data>
void BST<Data>::RemovePredecessor(const Data& dat) {
    typename BST<Data>::NodeLnk **ptr = FindPointerToPredecessor(dat);
    if(ptr != nullptr){
        delete Detach(*ptr);
    }else{
        throw std::length_error("Accesso a predecessor non valido, albero vuoto");
    }
}

/* ************************************************************************* */

//Successor
template<typename Data>
const Data& BST<Data>::Successor(const Data& dat)const {
        typename BST<Data>::NodeLnk* const* ptr2 = FindPointerToSuccessor(dat);
        if (ptr2 != nullptr) {
            return (*ptr2)->info;
        } else {
            throw std::length_error("Accesso a successor non valido, albero vuoto");
        }
    }

//SuccessorNRemove
template<typename Data>
Data BST<Data>::SuccessorNRemove(const Data& dat){
    typename BST<Data>::NodeLnk **ptr = FindPointerToSuccessor(dat);
    if(ptr != nullptr)
        return DataNDelete(Detach(*ptr));
    else{
        throw std::length_error("Accesso a successor non valido, albero vuoto");
    }
}

//SuccessorNRemove
template<typename Data>
void BST<Data>::RemoveSuccessor(const Data& dat) {
    typename BST<Data>::NodeLnk **ptr = FindPointerToSuccessor(dat);
    if(ptr != nullptr){
        delete Detach(*ptr);
    }else{
        throw std::length_error("Accesso a successor non valido, albero vuoto");
    }
}

/* ************************************************************************* */

//Exists
template <typename Data>
bool BST<Data>::Exists(const Data& dat ) const noexcept {
    return (FindPointerTo(root,dat) != nullptr);
}


}