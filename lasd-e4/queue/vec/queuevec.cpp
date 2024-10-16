
namespace lasd {

/* ************************************************************************** */

// Default constructor
template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>(4){
    front = -1;
    rear = -1;
}

// Specific constructor
template <typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& con) : Vector<Data>(con){
    front = 0;
    rear = (con.Size() - 1);
}

// Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& quevec) : Vector<Data>(quevec){
    front = quevec.front;
    rear = quevec.rear;
}

// Move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& quevec)noexcept: Vector<Data>(std::move(quevec)){
  std::swap(front, quevec.front);
  std::swap(rear, quevec.rear);
}

// Destructor
template <typename Data>
QueueVec<Data>::~QueueVec(){
    Vector<Data>::Clear();
}

/* ************************************************************************** */

// Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& quevec) {
    Vector<Data>::operator=(quevec);
    front = quevec.front;
    rear = quevec.rear;
    return *this;
}

// Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& quevec)noexcept{
    Vector<Data>::operator=(std::move(quevec));
    std::swap(front, quevec.front);
    std::swap(rear, quevec.rear);
    return *this;
}


/* ************************************************************************** */

// Comparison operator ==
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& quevec) const noexcept {
        if(Size() != quevec.Size()) {  //Check the Size() of the two structures
            return false;
        }else if(Empty() == true && quevec.Empty() == true){ //If the two structures are Empty
            return true;
        }
        ulong index = quevec.front;
        if(rear == front){  //Check the one element of the structure
            if(Elements[front] != quevec.Elements[index]){
                return false;
            }
        }else {  //Structures have more than one element
            for (long i = front; i != rear; i = (i + 1) % size) {
                if (Elements[i] != quevec.Elements[index]) {
                    return false;
                }
                index = (index + 1) % quevec.size;
            }
            if (Elements[rear] != quevec.Elements[index]) { //Check the last element of the structure
                return false;
            }
        }
        return true;
}

// Comparison operator !=
template <typename Data>
bool inline QueueVec<Data>::operator!=(const QueueVec<Data>& quevec) const noexcept {
    return !(*this == quevec);
}

/* ************************************************************************** */

// Enqueue Copy
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& dat){
    if(front == -1 && rear == -1){
        front = (front + 1) % size;
        rear = (rear + 1) % size;
    }else{
        if((rear + 1) % size == front){ //Check for Expand (Check if the rear reaches the front and therefore there is no more space available)
            Expand();
        }
        rear = (rear + 1) % size;
    }
    Elements[rear] = dat;
}

// Enqueue Move
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& dat)noexcept{
    if(front == -1 && rear == -1){
        front = (front + 1) % size;
        rear = (rear + 1) % size;
    }else{
        if((rear + 1) % size == front){ //Check for Expand (Check if the rear reaches the front and therefore there is no more space available)
            Expand();
        }
        rear = (rear + 1) % size;
    }
    Elements[rear] = dat;
}

/* ************************************************************************** */

// Head
template <typename Data>
Data& QueueVec<Data>::Head() const {
    if(front == -1){
        throw std::length_error("Accesso ad una QueueVec vuota.");
    }else{
        return Elements[front];
    }
}

/* ************************************************************************** */

//Dequeue
template <typename Data>
void QueueVec<Data>::Dequeue() {
    if(front == -1){
        throw std::length_error("Accesso ad una QueueVec vuota.");
    }else{
        if(front == rear){  //Dequeue the one element of the structure
            front = -1;
            rear = -1;
        }else{
            front = ((front + 1) % size);
            if(Size() == (size * 0.25) && size > 4){ //Check for Reduce (Check if the real size of the structure is 1/4 of the vector size and that it does not go below the minimum size)
                Reduce();
            }
        }
    }
}

//HeadNDequeue
template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if(front == -1){
        throw std::length_error("Accesso ad una QueueVec vuota.");
    }else{
        Data dat = Elements[front];
        if (front == rear) { //Dequeue the one element of the structure
            front =  -1;
            rear = -1;
        }else {
            front = ((front + 1) % size);
            if (Size() == (size * 0.25) && size > 4) { //Check for Reduce (Check if the real size of the structure is 1/4 of the vector size and that it does not go below the minimum size)
                Reduce();
            }
        }
        return  dat;
    }
}

/* ************************************************************************** */

//Empty
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    if (front == -1 && rear == -1){
        return true;
    }
    return false;
}

/* ************************************************************************** */

//Size
template <typename Data>
ulong QueueVec<Data>::Size() const noexcept {
    if(Empty() == true){
        return 0;
    }else if(front == rear){
        return 1;
    }else{
        return (((rear-front)%size)+1);
    }
}

/* ************************************************************************** */

//Clear
template <typename Data>
void QueueVec<Data>::Clear() {
    Vector<Data>::Clear();
    Elements = new Data[4]{};
    size = 4;
    front =  -1;
    rear = -1;
}

/* ************************************************************************** */
//Expand()
template <typename Data>
void QueueVec<Data>::Expand() {
        ulong newsize = (2*size);
        ulong index = 0;
        Data* TmpElements = new Data[newsize]{};
        while(front != rear){
            std::swap(Elements[front], TmpElements[index]);
            front = ((front + 1) % size);
            index = index + 1;
        }
        if(front == rear){ //For the last element
            std::swap(Elements[front], TmpElements[index]);
        }
        std::swap(Elements, TmpElements);
        front = 0;
        rear = index;
        size = newsize;
        delete[] TmpElements;
    }



//Reduce()
template <typename Data>
void QueueVec<Data>::Reduce() {
        ulong newsize = (size/2);
        ulong index = 0;
        Data* TmpElements = new Data[newsize]{};
        while(front != rear){
            std::swap(Elements[front], TmpElements[index]);
            front = ((front + 1) % size);
            index = index + 1;
        }
        if(front == rear){ //For the last element
            std::swap(Elements[front], TmpElements[index]);
        }
        std::swap(Elements, TmpElements);
        front = 0;
        rear = index;
        size = newsize;
        delete[] TmpElements;
}

/* ************************************************************************** */
}
