namespace lasd {

/* ****************************************************************************************************************** */

// Specific constructors
template <typename Data>
Vector<Data>::Vector(const ulong newsize){
    Elements = new Data[newsize] {};
    size = newsize;
}

// A vector obtained from a LinearContainer
template <typename Data>
Vector<Data>::Vector(const LinearContainer<Data>& con) {
    size = con.Size();
    Elements = new Data[size];
    for (ulong i = 0; i < size; ++i) {
        Elements[i] = con[i];
    }
}

/* ****************************************************************************************************************** */

// Copy constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& vec){
    Elements = new Data[vec.size];
    std::copy(vec.Elements, vec.Elements + vec.size, Elements);
    size = vec.size;
}

// Move constructor
template <typename Data>
Vector<Data>::Vector(Vector<Data>&& vec) noexcept{
    std::swap(Elements, vec.Elements);
    std::swap(size, vec.size);
 }

//Destructor
template <typename Data>
Vector<Data>::~Vector<Data>() {
    delete[] Elements;
}

/* ****************************************************************************************************************** */

// Copy assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec){
    Vector<Data>* tempvec = new Vector<Data>(vec);
    std::swap(*tempvec, *this);
    delete tempvec;
    return *this;
}
// Move assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec) noexcept{
    std::swap(Elements, vec.Elements);
    std::swap(size, vec.size);
    return *this;
}

/* ****************************************************************************************************************** */

// Comparison operators ==
template <typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept{
    if(size != vec.size){
        return false;
    }
    else {
        for (ulong i = 0; i < size; ++i){
            if (Elements[i] != vec.Elements[i]){
                return false;
            }
        }
        return true;
    }
}

// Comparison operators !=
template <typename Data>
inline bool Vector<Data>::operator!=(const Vector<Data> &vec) const noexcept {
    return !(*this == vec);
}

/* ****************************************************************************************************************** */

// Specific member function Resize()
template <typename Data>
void Vector<Data>::Resize(const ulong newsize) {
    if (newsize == 0){
        Clear();
    }else if (size != newsize){
        //IF condition is true: size ELSE newsize
        ulong limit = (size < newsize) ? size : newsize;
        Data* TmpElements = new Data[newsize] {};
        for (ulong i = 0; i < limit ; ++i) {
            std::swap(Elements[i], TmpElements[i]);
        }
        std::swap(Elements, TmpElements);
        size = newsize;
        delete[] TmpElements;
    }
}

/* ****************************************************************************************************************** */

// Specific member function (inherited from Container) Clear()
template <typename Data>
void Vector<Data>::Clear(){
    delete[] Elements;
    Elements = nullptr;
    size = 0;
}

/* ****************************************************************************************************************** */

// Specific member function (inherited from LinearContainer) Front()
template <typename Data>
Data& Vector<Data>::Front() const {
    if(size != 0){
        return Elements[0];
    }else {
        throw std::length_error("Accesso ad un vettore vuoto.");
    }
}

// Specific member function (inherited from LinearContainer) Back()
template <typename Data>
Data& Vector<Data>::Back() const {
    if(size != 0){
        return Elements[size-1];
    }else{
        throw std::length_error("Accesso ad un vettore vuoto.");
    }
}

// Specific member function (inherited from LinearContainer) operator[]
template <typename Data>
Data& Vector<Data>::operator[](const ulong i) const {
    if(i < size){
        return Elements[i];
    }else{
        throw std::out_of_range("Accesso ad indice " + std::to_string(i) + "; Dimensione vettore " + std::to_string(size) + ".");
    }
}

/* ****************************************************************************************************************** */

// Specific member functions (inherited from FoldableContainer) MapPreOrder
template <typename Data>
void Vector<Data>::MapPreOrder(const MapFunctor fun, void* par) {
    for (ulong i = 0; i < size; ++i){
        fun(Elements[i], par);
    }
}

// Specific member functions (inherited from FoldableContainer) MapPostOrder
template <typename Data>
void Vector<Data>::MapPostOrder(const MapFunctor fun, void* par) {
    ulong i = size;
    while(i > 0){
        fun(Elements[--i], par);
    }
}

/* ****************************************************************************************************************** */

// Specific member function (inherited from FoldableContainer) FoldPreOrder
template <typename Data>
void Vector<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const{
    for (ulong i = 0; i < size; ++i){
            fun(Elements[i], par, acc);
    }
}

// Specific member function (inherited from FoldableContainer) FoldPostOrder
template <typename Data>
void Vector<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const {
    ulong i = size;
    while(i > 0){
        fun(Elements[--i], par, acc);
    }
}

/* ****************************************************************************************************************** */

}
