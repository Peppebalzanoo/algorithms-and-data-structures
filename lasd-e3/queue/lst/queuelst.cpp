
namespace lasd {

/* ************************************************************************** */
// Default constructor
template <typename Data>
QueueLst<Data>::QueueLst(){ }

// Specific constructor
template <typename Data>
QueueLst<Data>::QueueLst(const LinearContainer<Data>& con) : List<Data>(con){}

// Copy constructor
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst& quelis) : List<Data>(quelis){}

// Move constructor
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst&& quelis)noexcept: List<Data>(std::move(quelis)){}

// Destructor
template <typename Data>
QueueLst<Data>::~QueueLst(){
    List<Data>::Clear();
}

/* ************************************************************************** */

// Copy assigment
template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& quelis) {
    List<Data>::operator=(quelis); //Call to Copy Assignment of List
    return *this;
}

// Copy assigment
template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& quelis)noexcept {
    List<Data>::operator=(std::move(quelis)); //Force Call to Copy Assignment of List
    return *this;
}

/* ************************************************************************** */

// Comparison operators ==
template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst<Data>& queueLst) const noexcept {
    return List<Data>::operator==(queueLst);
}

// Comparison operators !=
template <typename Data>
bool inline QueueLst<Data>::operator!=(const QueueLst<Data>& queueLst) const noexcept {
    return List<Data>::operator!=(queueLst);
}

/* ************************************************************************** */

//Enqueue Copy
template<typename Data>
void QueueLst<Data>::Enqueue(const Data& dat) {
    List<Data>::InsertAtBack(dat);
}

//Enqueue Move
template<typename Data>
void QueueLst<Data>::Enqueue(Data&& dat)noexcept {
    List<Data>::InsertAtBack(std::move(dat));
}

/* ************************************************************************** */

//Head
template <typename Data>
Data& QueueLst<Data>::Head() const {
    return List<Data>::Front();
}

/* ************************************************************************** */

//Dequeue
template <typename Data>
void QueueLst<Data>::Dequeue() {
    List<Data>::RemoveFromFront();
}

//HeadNDequeue
template <typename Data>
Data QueueLst<Data>::HeadNDequeue() {
    return List<Data>::FrontNRemove();
}

/* ************************************************************************** */

//Clear
template <typename Data>
void QueueLst<Data>::Clear() {
    List<Data>::Clear();
}

/* ************************************************************************** */

}
