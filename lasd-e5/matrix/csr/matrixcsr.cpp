
namespace lasd {

/* ****************************************************************************************************************** */

//Default constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR() {
    vectorRows[0] = &head;
}

/* ****************************************************************************************************************** */

//Specific constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(ulong r, ulong c) {
    rownum = r;
    colnum = c;
    vectorRows.Resize(rownum + 1);
    for (ulong i = 0; i<= rownum; i++){
        vectorRows[i] = &head;
    }
}

/* ****************************************************************************************************************** */

//Copy constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR<Data>& matr) : MatrixCSR(matr.rownum, matr.colnum){
    for(ulong r = 0; r < rownum; r++){
        for(Node** ptr = matr.vectorRows[r]; ptr != matr.vectorRows[r + 1]; ptr = &((*ptr)->next)){
            Node& nod = **ptr;
            this->operator()(r, nod.info.second) = nod.info.first;
        }
    }
}

//Move constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR<Data>&& matr)noexcept{
    std::swap(rownum, matr.rownum);
    std::swap(colnum, matr.colnum);
    std::swap(vectorRows, matr.vectorRows);
    std::swap(head,matr.head);
    std::swap(tail, matr.tail);
    std::swap(size, matr.size);

    for(ulong i = 0; i < size && vectorRows[i] == &matr.head; i++){
        vectorRows[i] = &head;
    }
    for(ulong i = 0; i < matr.size && matr.vectorRows[i] == &head; i++){
        matr.vectorRows[i] = &matr.head;
    }
}
/* ****************************************************************************************************************** */

template<typename Data>
MatrixCSR<Data>::~MatrixCSR(){
   List<std::pair<Data,ulong>>::Clear();
   vectorRows.Clear();
   rownum = 0;
   colnum = 0;
   size = 0;
}

/* ****************************************************************************************************************** */

//Copy assignment
template<typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR& matr){
    MatrixCSR<Data>* temp = new MatrixCSR<Data>(matr);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

//Move assignement
template<typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR&& matr) noexcept {
    std::swap(rownum, matr.rownum);
    std::swap(colnum, matr.colnum);
    std::swap(vectorRows, matr.vectorRows);
    std::swap(head,matr.head);
    std::swap(tail, matr.tail);
    std::swap(size, matr.size);

    for(ulong i = 0; i < size && vectorRows[i] == &matr.head; i++){
        vectorRows[i] = &head;
    }
    for(ulong i = 0; i < matr.size && matr.vectorRows[i] == &head; i++){
        matr.vectorRows[i] = &matr.head;
    }
    return *this;
}

/* ****************************************************************************************************************** */

//Comparison operator ==
template<typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR& matr) const noexcept {

    if (rownum == matr.rownum && colnum == matr.colnum) {
        if(rownum == 0 || colnum == 0){
            return true;
        }
        ulong r = 0;
        ulong ro = 0;

        Node **ptr = vectorRows[0];
        Node** limit = nullptr;

        Node **ptrMatr = matr.vectorRows[0];
        Node **limitMatr = nullptr;


        while(r < rownum && ptr == vectorRows[r+1]){
            ptr = vectorRows[r+1];
            r++;
        }

        while(ro < matr.rownum && ptrMatr == matr.vectorRows[ro+1]){
            ptrMatr = matr.vectorRows[ro+1];
            ro++;
        }

        if(r != ro){
            return false;
        }

        Node& nod1 = **ptr;
        Node& nod2 = **ptrMatr;

        if(*ptr != nullptr && *ptrMatr != nullptr){
            if(nod1.info != nod2.info){
                return false;
            }
            ptr = &(nod1.next);
            ptrMatr = &(nod2.next);
            while(r < rownum && ro < matr.rownum) {
                limit = vectorRows[r+1];
                limitMatr = matr.vectorRows[ro+1];
                while (ptr != limit && ptrMatr != limitMatr) {
                    Node &nod1 = **ptr;
                    Node &nod2 = **ptrMatr;
                    if (nod1.info != nod2.info) {
                        return false;
                    }
                    ptr = &(nod1.next);
                    ptrMatr = &(nod2.next);
                }
                if(ptr == limit && ptrMatr != limitMatr || ptr != limit && ptrMatr == limitMatr ){
                    return false;
                }
                r++;
                ro++;
            }
            return true;

        }else if(*ptr == nullptr && *ptrMatr == nullptr){
            return true;

        }else{
            return false;
        }
    }else {
        return false;
    }
}


//Comparison operator !=
template<typename Data>
inline bool MatrixCSR<Data>::operator!=(const MatrixCSR& matr) const noexcept{
    return !(*this == matr);
}

/* ****************************************************************************************************************** */

//RowResize
template<typename Data>
void MatrixCSR<Data>::RowResize(ulong r){
    if(r == 0){
        List<std::pair<Data, ulong>>::Clear();
        vectorRows.Clear();
        vectorRows.Resize(1);
        vectorRows[0] = &head;

    } else if(r < rownum){ //Reduce
        Node* curr = *(vectorRows[r]);
        Node *temp = nullptr;
        while(curr != nullptr){
            temp = curr;
            curr = curr->next;
            delete temp;
            size--;
        }
        *(vectorRows[r]) = nullptr;
        vectorRows.Resize(r+1);

    } else { //Expande
        vectorRows.Resize(r+1);
        ulong i = rownum;
        while(i < r){
            vectorRows[i+1] = vectorRows[i];
            i++;
        }
    }

    rownum = r;
}

/* ****************************************************************************************************************** */

//ColumnResize
template<typename Data>
void MatrixCSR<Data>::ColumnResize(ulong c){
    if(c == 0){
        List<std::pair<Data, ulong>>::Clear();
        for (ulong i = 0; i<= rownum; i++){
            vectorRows[i] = &head;
        }

    }else if(c < colnum) {
        ulong i = 1;
        Node **ptr = &head;
        while(i <= rownum) {
            Node *nod;
            Node **ext = vectorRows[i];
            while(ptr != ext && (*ptr)->info.second < c) {
                nod = *ptr;
                ptr = &(nod->next);
            }
            if(ptr != ext) {
                if(ext == vectorRows[rownum]) {
                    tail = nod;
                }
                Node *tmp = *ptr;
                *ptr = *ext;
                *ext = nullptr;
                for(Node *ptr = tmp; ptr != nullptr; ptr = ptr->next) {
                    size--;
                }
                Node* temp = nullptr;
                while(tmp != *ptr && tmp != nullptr){
                  temp = tmp;
                  tmp = tmp->next;
                  delete temp;
                }
            }
            for(; i <= rownum && vectorRows[i] == ext; ++i) {
                vectorRows[i] = ptr;
            }
        }
    }
    colnum = c;
}

/* ****************************************************************************************************************** */

//ExistsCell
template<typename Data>
bool MatrixCSR<Data>::ExistsCell(ulong r, ulong c) const noexcept{
    if((r < rownum) && (c < colnum)){
        Node** ptr = vectorRows[r];
        while(ptr != vectorRows[r + 1]){
            Node& nod = **ptr;
            if(nod.info.second == c){
                return true;
            }
            ptr = &(nod.next);
        }
    }
    return false;
}

/* ****************************************************************************************************************** */

//Operator() NOT CONST
template<typename Data>
Data& MatrixCSR<Data>::operator()(ulong r, ulong c){

    if((r < rownum) && (c < colnum)){
        Node** ptr = vectorRows[r];
        Node** limit = vectorRows[r + 1];
        while(ptr != limit && (*ptr)->info.second <= c){
            Node& nod = **ptr;
            if(nod.info.second == c){
               return nod.info.first;
            }
            ptr = &(nod.next);
        }
        Node *newnode = new Node();
        newnode->info.first = Data {};
        newnode->info.second = c;

        if(*ptr == nullptr){ //Insert the Last node of List
            newnode->next = nullptr;
            *ptr = newnode;
            tail = newnode;
            for(ulong i = r+1; i <= rownum; i++){
                Node &nod = **ptr;
                vectorRows[i] = &(nod.next);
            }
        }else{

            newnode->next = &(**ptr);
            *ptr = newnode;

            if(ptr == vectorRows[r+1]){ //If the row is Empty OR Insert the Last OR First node
                ulong i = r+1;
                while(vectorRows[i] == vectorRows[i+1]){
                    vectorRows[i] = &(*newnode).next;
                    i++;
                }
                vectorRows[i] = &(*newnode).next;
            }
        }
        size++;
        return (**ptr).info.first;
    }else{
        throw std::out_of_range("Accesso alla matrice non valido.");
    }
}

/* ****************************************************************************************************************** */

//Operator() CONST
template<typename Data>
const Data& MatrixCSR<Data>::operator()(ulong r, ulong c) const{
    if((r < rownum) && (c < colnum)){
        Node** ptr = vectorRows[r];
        Node** ext = vectorRows[r+1];

        while(ptr != ext && (*ptr)->info.second <= c){
            Node& nod = **ptr;
            if(nod.info.second == c){
                return nod.info.first;
            }
            ptr = &(nod.next);
        }
        throw std::length_error("Accesso ad un dato non esistente.");

    }else{
        throw std::out_of_range("Accesso alla matrice non valido.");
    }
}

/* ****************************************************************************************************************** */

//Clear
template<typename Data>
void MatrixCSR<Data>::Clear(){
   List<std::pair<Data,ulong>>::Clear();
   vectorRows.Clear();
   vectorRows.Resize(1);
   vectorRows[0] = &head;
   rownum = 0;
   colnum = 0;
   size = 0;
}

/* ****************************************************************************************************************** */

template <typename Data>
void MatrixCSR<Data>::MapPreOrder(MapFunctor fun, void *par) {
    List<std::pair<Data,ulong>>::MapPreOrder([&fun](std::pair<Data,ulong>& datx, void* parx){ fun (datx.first, parx); } , par);
}

template <typename Data>
void MatrixCSR<Data>::MapPostOrder(MapFunctor fun, void *par) {
    List<std::pair<Data,ulong>>::MapPostOrder([&fun](std::pair<Data,ulong>& datx, void* parx){ fun (datx.first, parx); } , par);
}

template <typename Data>
void MatrixCSR<Data>::FoldPreOrder(FoldFunctor fun, const void *par, void *acc)const{
    List<std::pair<Data,ulong>>::FoldPreOrder([&fun](const std::pair<Data,ulong>& datx, const void *parx, void *accx){ fun (datx.first, parx, accx); } , par, acc);
}

template <typename Data>
void MatrixCSR<Data>::FoldPostOrder(FoldFunctor fun, const void *par, void *acc)const{
    List<std::pair<Data,ulong>>::FoldPostOrder([&fun](const std::pair<Data,ulong>& datx, const void *parx, void *accx){ fun (datx.first, parx, accx); } , par, acc);
}
/* ****************************************************************************************************************** */


}
