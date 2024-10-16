
namespace lasd {

/* ************************************************************************** */

// Default constructor
template <typename Data>
StackVec<Data>::StackVec() : Vector<Data>(4){
   currentTop = -1;
}

// Specific constructor
template <typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& con) : Vector<Data>(con){
    currentTop = (con.Size() - 1);
}

// Copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec& stkvec) : Vector<Data>(stkvec){
    currentTop = stkvec.currentTop;
}

// Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec&& stkvec) noexcept : Vector<Data>(std::move(stkvec)){
   std::swap(currentTop, stkvec.currentTop);
}

// Destructor
template <typename Data>
StackVec<Data>::~StackVec(){
    Vector<Data>::Clear();
}
/* ************************************************************************** */

// Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stkvec) {
    Vector<Data>::operator=(stkvec); //Call to Copy Assignment of Vector
    currentTop = stkvec.currentTop;
    return *this;
}

// Move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stkvec)noexcept{
    Vector<Data>::operator=(std::move(stkvec)); //Call to Move Assignment of Vector
    std::swap(currentTop, stkvec.currentTop);
    return *this;
}

/* ************************************************************************** */

// Comparison operators ==
template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stkvec) const noexcept {
    if (currentTop == stkvec.currentTop){
        for(long i = 0; i <= currentTop; ++i){
            if(Elements[i] != stkvec.Elements[i]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

// Comparison operators !=
template <typename Data>
bool inline StackVec<Data>::operator!=(const StackVec<Data>& stkvec)const noexcept{
    return !(*this == stkvec);
}

/* ************************************************************************** */

//Push Copy
template <typename Data>
void StackVec<Data>::Push(const Data& dat) {
    if (currentTop == (size - 1)){ //Check for Expand (Check if the currentTop reaches the size and therefore there is no more space available)
        Expand();
    }
    currentTop = currentTop + 1;
    Elements[currentTop] = dat;
}

//Push Copy
template <typename Data>
void StackVec<Data>::Push(Data&& dat)noexcept {
    if (currentTop == (size - 1)){ //Check for Expand (Check if the currentTop reaches the size and therefore there is no more space available)
        Expand();
    }
    currentTop = currentTop + 1;
    Elements[currentTop] = dat;
}

/* ************************************************************************** */

//Top
template <typename Data>
Data& StackVec<Data>::Top()const{
    if (currentTop == -1){
        throw std::length_error("Accesso ad un StackVec vuoto.");
    }else{
        return Elements[currentTop];
    }
}

/* ************************************************************************** */

//Pop
template <typename Data>
void StackVec<Data>::Pop(){
    if(currentTop == -1 ){
        throw std::length_error("Accesso ad un StackVec vuoto.");
    }else{
        currentTop = currentTop - 1;
        if( (currentTop + 1) == (size * 0.25) && (size > 4) ){  //Check for Reduce (Check if the real size of the structure is 1/4 (0.25) of the vector size and that it does not go below the minimum size)
            Reduce();
        }
    }
}

//TopNPop
template <typename Data>
Data StackVec<Data>::TopNPop(){
    if(currentTop == -1 ){
        throw std::length_error("Accesso ad un StackVec vuoto.");
    }else{
        Data dat = Elements[currentTop];
        currentTop = currentTop - 1;
        if( (currentTop + 1) == (size * 0.25) && (size > 4) ){ //Check for Reduce (Check if the real size of the structure is 1/4 (0.25) of the vector size and that it does not go below the minimum size)
            Reduce();
        }
        return dat;
    }
}
/* ************************************************************************** */

//Empty
template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
    if (currentTop == -1){
        return true;
    }
    return false;
}

//Size
template <typename Data>
ulong StackVec<Data>::Size() const noexcept{
    return (currentTop + 1);
}

//Clear
template <typename Data>
void StackVec<Data>::Clear(){
    Vector<Data>::Clear();
    Vector<Data>::Resize((4));
    size = 4;
    currentTop = -1;
}


/* ************************************************************************** */

//Expand
template <typename Data>
void StackVec<Data>::Expand() {
    Vector<Data>::Resize((2*size));
}

//Reduce
template <typename Data>
void StackVec<Data>::Reduce(){
    Vector<Data>::Resize((size/2));
}

/* ************************************************************************** */

}
