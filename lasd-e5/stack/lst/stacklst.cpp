
namespace lasd {

/* ************************************************************************** */

// Default constructor
template <typename Data>
StackLst<Data>::StackLst(){ }


// Specific constructor
template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& con) : List<Data>(con){}

// Copy constructor
template <typename Data>
StackLst<Data>::StackLst(const StackLst& stklis) : List<Data>(stklis){}

// Move constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst&& stklis)noexcept : List<Data>(std::move(stklis)){}

// Destructor
template <typename Data>
StackLst<Data>::~StackLst(){
    List<Data>::Clear(); //From book
}

/* ************************************************************************** */

// Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& stklis){
    List<Data>::operator=(stklis); //Call to Copy Assignment of List
    return *this;
}

// Move assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& stklis)noexcept{
    List<Data>::operator=(std::move(stklis)); //Force Call to Move Assignment of List
    return *this;
}

/* ************************************************************************** */

// Comparison operators ==
template <typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& stklis) const noexcept {
    return List<Data>::operator==(stklis);
}

// Comparison operators !=
template <typename Data>
bool inline StackLst<Data>::operator!=(const StackLst<Data>& stklis) const noexcept {
    return List<Data>::operator!=(stklis);
}

/* ************************************************************************** */

// Push Copy
template <typename Data>
void StackLst<Data>::Push(const Data& dat) {
    List<Data>::InsertAtFront(dat);
}

// Push Move
template <typename Data>
void StackLst<Data>::Push(Data&& dat)noexcept{
    List<Data>::InsertAtFront(std::move(dat)); //Force Call to InsertAtBack of List
}

/* ************************************************************************** */

// Top
template <typename Data>
Data& StackLst<Data>::Top() const {
    return List<Data>::Front();
}

// Pop
template <typename Data>
void StackLst<Data>::Pop(){
    List<Data>::RemoveFromFront();
}

// TopNPop
template <typename Data>
Data StackLst<Data>::TopNPop(){
    return List<Data>::FrontNRemove();
}

/* ************************************************************************** */

// Clear
template <typename Data>
void StackLst<Data>::Clear() {
    List<Data>::Clear();
}

/* ************************************************************************** */

}
