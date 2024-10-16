
namespace lasd {

/* ****************************************************************************************************************** */

//Specific constructor
template <typename Data>
MatrixVec<Data>::MatrixVec(ulong r,  ulong c) : Vector<Data>(r*c){
    rownum = r;
    colnum = c;
}

/* ****************************************************************************************************************** */

//Copy constructor
template <typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec& matr) : Vector<Data>(matr){
    rownum = matr.rownum;
    colnum = matr.colnum;
}

//Move constructor
template <typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec&& matr) noexcept : Vector<Data>(std::move(matr)){
    std::swap(matr.rownum, rownum);
    std::swap(matr.colnum, colnum);
}

/* ****************************************************************************************************************** */

//Destructor
template <typename Data>
MatrixVec<Data>::~MatrixVec() {
    Vector<Data>::Clear();
    rownum = 0;
    colnum = 0;
}

/* ****************************************************************************************************************** */

//Copy assignment
template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(const MatrixVec<Data>& matr) {
    MatrixVec<Data>* tempmatr = new MatrixVec<Data>(matr);
    std::swap(*tempmatr, *this);
    delete tempmatr;
    return *this;
}

//Move assignment
template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(MatrixVec<Data>&& matr) noexcept{
    Vector<Data>::operator=(std::move(matr));
    std::swap(matr.rownum, rownum);
    std::swap(matr.colnum, colnum);
    return *this;
}

/* ************************************************************************** */

// Comparison operator ==
template <typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec <Data>& matr) const noexcept {
    if(rownum != matr.rownum || colnum != matr.colnum){
        return false;
    }
    return Vector<Data>::operator==(matr);
}

// Comparison operator !=
template <typename Data>
inline bool MatrixVec<Data>::operator!=(const MatrixVec <Data>& matr) const noexcept{
    return !(*this == matr);
}

/* ****************************************************************************************************************** */

//RowResize
template <typename Data>
void MatrixVec<Data>::RowResize(ulong r) {
    if(r != 0) {
        Vector<Data>::Resize(r * colnum);
        rownum = r;
    }else{
        ulong oldcol = colnum;
        Clear();
        colnum = oldcol;
    }
}

/* ****************************************************************************************************************** */

//ColumnResize
template <typename Data>
void MatrixVec<Data>::ColumnResize(ulong new_c){

    if(new_c != 0) {
        ulong i = 0;
        ulong j = 0;

        ulong count = 0;
        long zero = 0;
        long diff = (new_c - colnum);

        Data *temp = new Data[rownum*new_c]{};

        if (diff > 0) { //Expand
            while (i < Vector<Data>::size) {
                if (count < colnum || colnum == 0) {
                    std::swap(temp[j], Vector<Data>::operator[](i));
                    count++;
                    i++;
                    j++;
                } else if (zero < diff) {
                    temp[j] = Data {};
                    zero++;
                    j++;
                } else {
                    count = 0;
                    zero = 0;
                }
            }
        } else if(diff < 0){ //Reduce
            while (i < Vector<Data>::size) {
                if (count < (colnum + diff)) {
                    std::swap(temp[j], Vector<Data>::operator[](i));
                    count++;
                    i++;
                    j++;
                } else if (zero > diff) {
                    i++;
                    zero--;
                } else {
                    count = 0;
                    zero = 0;
                }
            }
        }
        std::swap(Vector<Data>::Elements, temp);
        delete [] temp;
        colnum = new_c;
        Vector<Data>::size = (rownum*colnum);
    }else{
        ulong oldrow = rownum;
        Clear();
        rownum = oldrow;
    }
}

/* ****************************************************************************************************************** */

//ExistsCell
template <typename Data>
bool MatrixVec<Data>::ExistsCell(ulong r, ulong c) const noexcept {
    if(Vector<Data>::size > 0){
        if(r <= rownum && c <= colnum){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

/* ************************************************************************** */

//Operator() CONST
template <typename Data>
const Data& MatrixVec<Data>::operator()(ulong r, ulong c) const {
    if(ExistsCell(r,c) == true){
        return Vector<Data>::operator[]((r*colnum)+c);
    }else{
        throw std::out_of_range("Accesso alla matrice non valido.");
    }
}

//Operator() NOT-CONST
template <typename Data>
Data& MatrixVec<Data>::operator()(ulong r, ulong c){
        return const_cast<Data &>(static_cast<const MatrixVec<Data> *>(this)->operator()(r, c));
}

/* ************************************************************************** */

//Clear
template <typename Data>
void MatrixVec<Data>::Clear(){
    Vector<Data>::Clear();
    rownum = 0;
    colnum = 0;
}


}
