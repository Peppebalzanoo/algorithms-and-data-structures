#include "test.hpp"

/* ****************************************************************************************************************** */
template <typename Type>
void colResize(lasd::Matrix<Type>& matr){
    ulong col;
    std::cout<<"@INSERISCI LA NUOVA DIMENSIONE DELLE COLONNE: "<<std::endl;
    std::cout<<"@"; std::cin>>col;
    if (std::cin.fail()) {
        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
    }else{
        matr.ColumnResize(col);
    }
}

template <typename Type>
void rowResize(lasd::Matrix<Type>& matr){
    ulong row;
    std::cout<<"@INSERISCI LA NUOVA DIMENSIONE DELLE RIGHE: "<<std::endl;
    std::cout<<"@"; std::cin>>row;
    if (std::cin.fail()) {
        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
    }else{
        matr.RowResize(row);
    }
}
/* ****************************************************************************************************************** */

template <typename Type>
void checkCell(lasd::Matrix<Type>& matr){
    ulong row, col;
    std::cout<<"@INSERISCI INDICE DI RIGA: "<<std::endl;
    std::cout<<"@"; std::cin>>row;
    if (std::cin.fail()) {
        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
    }

    std::cout<<"@INSERISCI INDICE DI COLONNA: "<<std::endl;
    std::cout<<"@"; std::cin>>col;
    if (std::cin.fail()) {
        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
    }
    if(matr.ExistsCell(row,col) == true){
        std::cout<<">>> LA CELLA ESISTE <<<"<<std::endl;
    }else{
        std::cout<<">>> LA CELLA NON ESISTE <<<"<<std::endl;
    }
}

template <typename Type>
void accessNotConstCell(lasd::Matrix<Type>& matr){
    ulong row, col;
    Type val;

    std::cout<<"@INSERISCI INDICE DI RIGA: "<<std::endl;
    std::cout<<"@"; std::cin>>row;
    if (std::cin.fail()) {
        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
    }
    std::cout<<"@INSERISCI INDICE DI COLONNA: "<<std::endl;
    std::cout<<"@"; std::cin>>col;
    if (std::cin.fail()) {
        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
    }

    std::cout<<"@INSERISCI IL DATO DA INSERIRE A ("<<row<<" ,"<<col<<") :"<<std::endl;
    std::cout<<"@"; std::cin>>val;
    if (std::cin.fail()) {
        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
    }
    try {
        matr.operator()(row, col) = val;
        std::cout << ">>> INSERIMENTO EFFETTUATO CORRETTAMENTE <<<" << std::endl;
    }catch (std::out_of_range e){
        std::cout<<">>> NON E' POSSIBILE ACCEDERE ALLA CELLA <<<"<<std::endl;
    }
}


template <typename Type>
void accessConstCell(const lasd::Matrix<Type>& matr){
    ulong row, col;

    std::cout<<"@INSERISCI INDICE DI RIGA: "<<std::endl;
    std::cout<<"@"; std::cin>>row;
    if (std::cin.fail()) {
        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
    }

    std::cout<<"@INSERISCI INDICE DI COLONNA: "<<std::endl;
    std::cout<<"@"; std::cin>>col;
    if (std::cin.fail()) {
        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
    }
    try {
        std::cout<<">>> IL DATO DELLA CELLA E': "<<matr.operator()(row,col)<<" <<<"<<std::endl;
    }catch (std::length_error e){
        std::cout<<">>> NON E' POSSIBILE ACCEDERE AL DATO <<<"<<std::endl;
    }catch (std::out_of_range e){
        std::cout<<">>> NON E' POSSIBILE ACCEDERE ALLA CELLA <<<"<<std::endl;
    }
}

/* ****************************************************************************************************************** */

//*** Select the library functions ***//
template <typename Type>
void selectFunctionLibrary(lasd::Matrix<Type>&matr){
    Type data;
    int enne = -1;
    int type = -1;

    do {
        std::cout<<"\n*******************************************************************************"<<std::endl;
        std::cout<<"*** SELEZIONA UNA DELLE SEGUENTI FUNZIONI DI LIBRERIA ***"<<std::endl;
        std::cout<<"    [1] ACCESSO IN LETTURA AD UNA SPECIFICA CELLA"<<std::endl;
        std::cout<<"    [2] ACCESSO IN SCRITTURA AD UNA SPECIFICA CELLA"<<std::endl;
        std::cout<<"    [3] CONTROLLO ESISTENZA DI UNA SPECIFICA CELLA"<<std::endl;
        std::cout<<"    [4] RIDIMENSIONAMENTO DELLE RIGHE"<<std::endl;
        std::cout<<"    [5] RIDIMENSIONAMENTO DELLE COLONNE"<<std::endl;
        std::cout<<"    [6] STAMPA LA MATRICE"<<std::endl;
        std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE"<<std::endl;
        std::cout<<"@"; std::cin>>enne;

        if(!std::cin.fail()){

            switch (enne) {
                case 1:
                    accessConstCell(matr);
                    break;

                case 2:
                    accessNotConstCell(matr);
                    break;

                case 3:
                    checkCell(matr);
                    break;

                case 4:
                    rowResize(matr);
                    break;

                case 5:
                    colResize(matr);
                    break;
                case 6:
                    viewInPreOrdineMap(matr);
                    break;
                case 0:
                    enne = 0;
                    break;
                default :
                    std::cout<<"*** SELEZIONE NON VALIDA ***"<<std::endl;
                    break;
            }
        }else{
            std::cout<<"*** SELEZIONE NON VALIDA ***"<<std::endl;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }while(std::cin.fail() || enne != 0);
}

/* ****************************************************************************************************************** */

template <typename Type>
void dueEnneElements(Type& elem, void* par){
    elem = 2*elem;
}

template <typename Type>
void minusEnneCubeElements(Type& elem, void* par){
    if(elem != Type{}){
        elem = -(elem * elem * elem);
    }
}

template <typename Type>
void frontString(Type& elem, void* par){
    if(elem != Type {}) {
        std::string front = *(std::string *) par;
        elem.insert(0, front);
    }
}

//*** 2*n of elements of structure (MappableContainer<int>) using MapPreOrder function ***//
void operationForStructureTypeMapInteger(lasd::MappableContainer<int>& obj){
    std::cout<<"*** TUTTI GLI ELEMENTI DELLA STRUTTURA DOPPIATI ***"<<std::endl;
    obj.MapPreOrder(&dueEnneElements<int>, nullptr);
    std::cout<<">>> VISUALIZZAZIONE IN PRE-ORDINE <<<"<<std::endl;
    obj.MapPreOrder(&printForMap<int>, nullptr);
}

//*** -Cube elements of structure (MappableContainer<float>) using MapPreOrder function ***//
void operationForStructureTypeMapFloat(lasd::MappableContainer<float>& obj){
    std::cout<<"*** TUTTI GLI ELEMENTI DELLA STRUTTURA AL -(CUBO) ***"<<std::endl;
    obj.MapPreOrder(&minusEnneCubeElements<float>, nullptr);
    std::cout<<">>> VISUALIZZAZIONE IN PRE-ORDINE <<<"<<std::endl;
    obj.MapPreOrder(&printForMap<float>, nullptr);
}

//*** Concatenation at front elements of structure (MappableContainer<string>) using MapPreOrder function ***//
void operationForStructureTypeMapString(lasd::MappableContainer<std::string>& obj){
    std::cout<<"*** TUTTI GLI ELEMENTI DELLA STRUTTURA CON UNA STRINGA CONCATENATA IN TESTA ***"<<std::endl;
    std::string str = "";
    std::cout << "@INSERISCI LA STRINGA DA CONCATENARE IN TESTA" << std::endl;
    std::cout << "@";
    std::cin >> str;
    obj.MapPreOrder(&frontString<std::string>, &str);
    std::cout<<">>> VISUALIZZAZIONE IN PRE-ORDINE <<<"<<std::endl;
    obj.MapPreOrder(&printForMap<std::string>, nullptr);
}
/* ****************************************************************************************************************** */

template <typename Type>
void productIntegers(const Type& elem, const void* dim, void* acc){
    if(elem < (*(int*)dim) && elem != Type{}){
        (*(int*)acc) = (*(int*)acc)*elem;
    }
}

template <typename Type>
void sumFloats(const Type& elem, const void* dim, void* acc){
    if(elem > (*(int*)dim)){
        (*(float*)acc) = (*(float*)acc)+elem;
    }
}

template <typename Type>
void concatenationStrings(const Type& elem, const void* dim, void* acc){
    if( elem.size() <= (*(int*)dim)){
        (*(std::string*)acc) = ( (*(std::string*)acc)+elem );
    }
}

//*** Sum of elements less than n of structure (FoldableContainer<int>) using FoldPreOrder function ***//
void operationForStructureTypeFoldInteger(lasd::FoldableContainer<int>& obj, int& n) {
    std::cout << "*** IL PRODOTTO DEGLI INTERI < N ***" << std::endl;
    std::cout << "@INSERISCI N PER LA FUNZIONE FOLD PREVISTA PER LA STRUTTURA" << std::endl;
    std::cout << "@";
    std::cin >> n;
    do {
        const void *dim = &n;
        void *acc = nullptr;
        if (!std::cin.fail() && n > 0) {
            int ac = 1;
            acc = &ac;
            obj.FoldPreOrder(&productIntegers<int>, dim, acc);
            std::cout << ">>> IL PRODOTTO VALE: " << ac << " <<<" << std::endl;

        } else {
            std::cout << "*** VALORE NON VALIDO ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    } while (std::cin.fail() || n < 0);
}

//*** Sum of elements greater than n of structure (FoldableContainer<float>) using FoldPreOrder function ***//
void operationForStructureTypeFoldFloat(lasd::FoldableContainer<float>& obj, int& n) {
    std::cout << "*** SOMMA PER I FLOAT > N ***" << std::endl;
    std::cout << "@INSERISCI N PER LA FUNZIONE FOLD PREVISTA PER LA STRUTTURA" << std::endl;
    std::cout << "@";
    std::cin >> n;
    do {
        const void *dim = &n;
        void *acc = nullptr;
        if (!std::cin.fail() && n > 0) {
            float ac = 0;
            acc = &ac;
            obj.FoldPreOrder(&sumFloats<float>, dim, acc);
            std::cout<<">>> LA SOMMA VALE: "<<std::fixed<<ac<<std::endl;
        }else{
            std::cout << "*** VALORE NON VALIDO ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }while(std::cin.fail() || n < 0);
}

//*** Concatenation of elements less-equals than n of structure (FoldableContainer<string>) ***//
void operationForStructureTypeFoldString(lasd::FoldableContainer<std::string>& obj, int& n) {
    std::cout << "*** CONCETENAZIONE DELLE STRINGHE CON LUNGHEZZA <= N ***" << std::endl;
    std::cout << "@INSERISCI N PER LA FUNZIONE FOLD PREVISTA PER LA STRUTTURA" << std::endl;
    std::cout << "@";
    std::cin >> n;
    do {
        const void *dim = &n;
        void *acc = nullptr;
        if (!std::cin.fail() && n > 0) {
            std::string ac = "";
            acc = &ac;
            obj.FoldPreOrder(concatenationStrings<std::string>, dim, acc);
            std::cout<<">>> LA CONCATENAZIONE E': "<<ac<<" <<<"<<std::endl;
        }else{
            std::cout<< "*** VALORE NON VALIDO ***" <<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }while(std::cin.fail() || n < 0);
}

/* ****************************************************************************************************************** */

void checkTheExistenceInteger(lasd::TestableContainer<int>& obj){
    int elem;
    do {
        std::cout << "\n@INSERISCI L'ELEMENTO CHE VUOI CERCARE" << std::endl;
        std::cout<<"@"; std::cin>>elem;
        if (!std::cin.fail() && elem > 0) {
            if (obj.Exists(elem)== true) {
                std::cout<<">>> L'ELEMENTO E' PRESENTE <<<"<<std::endl;
            } else {
                std::cout<<">>> L'ELEMENTO NON E' PRESENTE <<<"<<std::endl;
            }
        }else{
            std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }while(std::cin.fail() || elem < 0);
}

void checkTheExistenceFloat(lasd::TestableContainer<float>& obj){
    float elem;
    do {
        std::cout << "\n@INSERISCI L'ELEMENTO CHE VUOI CERCARE" << std::endl;
        std::cout<<"@"; std::cin>>elem;
        if (!std::cin.fail() && elem > 0) {
            if (obj.Exists(elem)== true) {
                std::cout<<">>> L'ELEMENTO E' PRESENTE <<<"<<std::endl;
            } else {
                std::cout<<">>> L'ELEMENTO NON E' PRESENTE <<<"<<std::endl;
            }
        }else{
            std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }while(std::cin.fail() || elem < 0);
}

void checkTheExistanceString(lasd::TestableContainer<std::string>& obj){
    std::string str ="";
    do {
        std::cout << "\n@INSERISCI L'ELEMENTO CHE VUOI CERCARE" << std::endl;
        std::cout<<"@"; std::cin>>str;
        if (!std::cin.fail() && str != ""){
            if (obj.Exists(str)) {
                std::cout<<">>> L'ELEMENTO E' PRESENTE <<<"<< std::endl;
            } else {
                std::cout<<">>> L'ELEMENTO NON E' PRESENTE <<<"<<std::endl;
            }
        }
    }while(str =="");
}

/* ****************************************************************************************************************** */
template <typename Type>
void viewInPreOrdineMap(lasd::Matrix<Type>& obj){
    obj.MapPreOrder(&printForMap<Type>, nullptr);
}

template <typename Type>
void viewInPostOrdineMap(lasd::Matrix<Type>& obj){
    obj.MapPostOrder(&printForMap<Type>, nullptr);
}
/* ****************************************************************************************************************** */

//*** Select the operation for the structure ***//
int& selectActionStructure(int& todo){

    std::cout<<"\n*******************************************************************************"<<std::endl;
    std::cout<<"@SELEZIONA L'OPERAZIONE DIGITANDO IL NUMERO DI RIFERIMENTO"<<std::endl;
    std::cout<<"    [1] VISUALIZZAZIONE IN PRE-ORDINE (FUNZIONE MAP)"<<std::endl;
    std::cout<<"    [2] VISUALIZZAZIONE IN POST-ORDINE (FUNZIONE MAP)"<<std::endl;
    std::cout<<"    [3] CONTROLLO DI ESISTENZA DI UN VALORE"<<std::endl;
    std::cout<<"    [4] FUNZIONALITA' PREVISTA PER IL TIPO DELLA STRUTTURA (FUNZIONE FOLD)"<<std::endl;
    std::cout<<"    [5] APPLICAZIONE DI FUNZIONALITA'"<<std::endl;
    std::cout<<"    [6] FUNZIONALITA' DI LIBRERIA PREVISTE PER LA STRUTTURA"<<std::endl;
    std::cout<<"    [7] STAMPA LA STRUTTURA"<<std::endl;
    std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRINCIPALE"<<std::endl;
    std::cout<<"@"; std::cin>>todo;
    return todo;
}

/* ****************************************************************************************************************** */

template <typename Type>
void printForMap(Type& elem, void* par){
    std::cout<<std::fixed<<elem<<" ";
}

template <typename Type>
void viewAllElementsMap(lasd::Matrix<Type>& obj){
    obj.MapPreOrder(&printForMap<Type>, nullptr);
}

/* ****************************************************************************************************************** */

//*** Generator for integers ***//
void generatorMatrString(const ulong& rownum, const ulong& colnum, lasd::Matrix<std::string>& matr){
    ulong num_elem;
    ulong index_row, index_col;
    std::string val;
    static auto& chrs = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

    std::default_random_engine gen(std::random_device{}());
    do {
        std::cout << "@INSERISCI IL NUMERO DI ELEMENTI DA GENERARE N > 0" << std::endl;
        std::cout << "@";
        std::cin >> num_elem;
        if (num_elem > 0 && (num_elem <= rownum*colnum) ) {
            std::cout<<"[1]"<<std::endl;
            for (ulong i = 0; i < num_elem; i++) {
                std::uniform_int_distribution<int> dist_index_row(0, (rownum - 1));
                index_row = dist_index_row(gen);

                std::uniform_int_distribution<int> dist_index_col(0, (colnum - 1));
                index_col = dist_index_col(gen);

                std::uniform_int_distribution <int> distribution(3,10);
                ulong range = rownum*colnum;
                std::string s[range];

                int tmp = distribution(rg);
                for(ulong j =0; j < range; j++){
                    while(tmp--){
                        s[j] += chrs[pick(rg)];
                    }
                    tmp = distribution(rg);

                   val = s[j];
                }
                if (matr.operator()(index_row, index_col) == std::string{}) {
                    matr.operator()(index_row, index_col) = val;
                } else {
                    i--;
                }
            }
        }else {
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
        }
    }while(num_elem <= 0 || (num_elem > rownum*colnum));
}

//*** Generator for integers ***//
void generatorMatrFloat(const ulong& rownum, const ulong& colnum, lasd::Matrix<float>& matr){
    ulong num_elem;
    ulong index_row, index_col;
    float val;

    std::default_random_engine gen(std::random_device{}());

    do {
        std::cout << "@INSERISCI IL NUMERO DI ELEMENTI DA GENERARE N > 0" << std::endl;
        std::cout << "@";
        std::cin >> num_elem;
        if (num_elem > 0 && (num_elem <= rownum*colnum) ) {
            for (ulong i = 0; i < num_elem; i++) {
                std::uniform_int_distribution<int> dist_index_row(0, (rownum - 1));
                index_row = dist_index_row(gen);

                std::uniform_int_distribution<int> dist_index_col(0, (colnum - 1));
                index_col = dist_index_col(gen);

                std::uniform_real_distribution<float> dist_val(10, 99);
                val = dist_val(gen);

                if ((matr.operator()(index_row, index_col)) == float{}) {
                    matr.operator()(index_row, index_col) = val;
                } else {
                    i--;
                }
            }
        }else {
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
        }
    }while(num_elem <= 0 || (num_elem > rownum*colnum));
}

//*** Generator for integers ***//
void generatorMatrInteger(const ulong& rownum, const ulong& colnum, lasd::Matrix<int>& matr){
    ulong num_elem;
    ulong index_row, index_col;
    int val;

    std::default_random_engine gen(std::random_device{}());

    do {
        std::cout << "@INSERISCI IL NUMERO DI ELEMENTI DA GENERARE N > 0" << std::endl;
        std::cout << "@";
        std::cin >> num_elem;
        if (num_elem > 0 && (num_elem <= (rownum*colnum))) {

            for (ulong i = 0; i < num_elem; i++) {
                std::uniform_int_distribution<int> dist_index_row(0, (rownum-1) );
                index_row = dist_index_row(gen);

                std::uniform_int_distribution<int> dist_index_col(0, (colnum-1) );
                index_col = dist_index_col(gen);

                std::uniform_int_distribution<int> dist_val(10, 99);
                val = dist_val(gen);

                if ((matr.operator()(index_row, index_col)) == int{}) {
                    matr.operator()(index_row, index_col) = val;
                } else {
                    i--;
                }
            }
        }else {
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
        }
    }while(num_elem <= 0 || (num_elem >(rownum*colnum)));
}

/* ****************************************************************************************************************** */

//*** Select the dimension of structure (integer, float, string) ***//
ulong& selectSizeStructureCol(ulong& colnum){
    std::cout<<"\n*******************************************************************************"<<std::endl;
    do {
        std::cout<<"@INSERISCI IL NUMERO DI COLONNE N > 0"<<std::endl;
        std::cout<<"@"; std::cin>>colnum;

        if(std::cin.fail()){
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }else if(colnum <= 0){
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
        }

    }while(std::cin.fail() || colnum <= 0);
    return colnum;
}

//*** Select the dimension of structure (integer, float, string) ***//
ulong& selectSizeStructureRow(ulong& rownum){
    std::cout<<"\n*******************************************************************************"<<std::endl;
    do {
        std::cout<<"@INSERISCI IL NUMERO DI RIGHE N > 0"<<std::endl;
        std::cout<<"@"; std::cin>>rownum;

        if(std::cin.fail()){
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }else if(rownum <= 0){
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
        }

    }while(std::cin.fail() || rownum <= 0);
    return rownum;
}

/* ****************************************************************************************************************** */

//*** Select the type of structure (integer, float, string) ***//
int selectTypeStructure(){
    int select_typestructure = -1;
    do {
        std::cout<<"\n*******************************************************************************"<<std::endl;
        std::cout<<"@SELEZIONA IL TIPO DELLA STRUTTURA DIGITANDO IL NUMERO DI RIFERIMENTO"<<std::endl;
        std::cout<<"    [1] INTERO"<<std::endl;
        std::cout<<"    [2] FLOAT"<<std::endl;
        std::cout<<"    [3] STRINGA"<<std::endl;
        std::cout<<"    [0] PER USCIRE"<<std::endl;
        std::cout<<"@"; std::cin>>select_typestructure;

        switch (select_typestructure) {
            case 1 : //Integer
                std::cout<<">>> HAI SELEZIONATO IL TIPO INTERO <<<"<<std::endl;
                return 1;
            case 2 : //Float
                std::cout<<">>> HAI SELEZIONATO IL TIPO FLOAT <<<"<<std::endl;
                return 2;
            case 3 : //String
                std::cout<<">>> HAI SELEZIONATO IL TIPO STRINGA <<<"<<std::endl;
                return 3;
            case 0 : //Exit
                select_typestructure = 0;
                return 0;
            default:
                std::cout<<"*** SELEZIONE NON VALIDA DEL TIPO ***"<<std::endl;
                break;
        }
    }while(select_typestructure != 0);
    return select_typestructure;
}

/* ****************************************************************************************************************** */
void start() {
    int select_structure = -1;
    int type_structure = -1;
    ulong rownum = 0;
    ulong colnum = 0;
    int num = -1;
    int todo = -1;
    do {
        std::cout << "\n***************************** BENVENUTO NEL MENU' *****************************" << std::endl;
        std::cout << "@SELEZIONA LA STRUTTURA DIGITANDO IL NUMERO DI RIFERIMENTO" << std::endl;
        std::cout << "    [1] MATRIX VEC" << std::endl;
        std::cout << "    [2] MATRIX CSR" << std::endl;
        std::cout << "    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE" << std::endl;
        std::cout << "@";
        std::cin >> select_structure;
        switch (select_structure) {
            case 1:
                std::cout << ">>> HAI SELEZIONATO MATRIX VEC <<<" << std::endl;
                type_structure = selectTypeStructure();
                if (type_structure != 0) {
                    selectSizeStructureRow(rownum);
                    selectSizeStructureCol(colnum);
                    std::cout << ">>> LA DIMENSIONE DELLA STRUTTURA E': " << rownum << " x " << colnum << std::endl;
                    if (type_structure == 1) { //*** MATRIX VEC INTEGER ***//
                        lasd::MatrixVec<int> matvec_int(rownum, colnum);
                        generatorMatrInteger(rownum, colnum, matvec_int);
                        do {
                            switch(todo = selectActionStructure(todo)){
                                case 1: //VIEW MAP PRE-ORDER
                                    viewInPreOrdineMap(matvec_int);
                                    break;

                                case 2: //VIWA MAP POST-ORDER
                                    viewInPostOrdineMap(matvec_int);
                                    break;

                                case 3: //EXISTS
                                    checkTheExistenceInteger(matvec_int);
                                    break;

                                case 4: //FUNZIONE FOLD
                                    operationForStructureTypeFoldInteger(matvec_int, num);
                                    break;

                                case 5: //MAP SPECIFIC FOR TYPE
                                    operationForStructureTypeMapInteger(matvec_int);
                                    break;

                                case 6: //FUNZIONALITA' DI LIBRERIA
                                    selectFunctionLibrary(matvec_int);
                                    break;
                                case 7:
                                    viewAllElementsMap(matvec_int);
                                    break;
                                case 0:
                                    return;
                            }
                        } while (todo != 0);

                    } else if (type_structure == 2) { //*** MATRIX VEC FLOAT ***//
                        lasd::MatrixVec<float> matvec_float(rownum, colnum);
                        generatorMatrFloat(rownum, colnum, matvec_float);
                        do {
                            switch(todo = selectActionStructure(todo)){
                                case 1: //VIEW MAP PRE-ORDER
                                    viewInPreOrdineMap(matvec_float);
                                    break;

                                case 2: //VIWA MAP POST-ORDER
                                    viewInPostOrdineMap(matvec_float);
                                    break;

                                case 3: //EXISTS
                                    checkTheExistenceFloat(matvec_float);
                                    break;

                                case 4: //FUNZIONE FOLD
                                    operationForStructureTypeFoldFloat(matvec_float, num);
                                    break;

                                case 5: //MAP SPECIFIC FOR TYPE
                                    operationForStructureTypeMapFloat(matvec_float);
                                    break;

                                case 6: //FUNZIONALITA' DI LIBRERIA
                                    selectFunctionLibrary(matvec_float);
                                    break;

                                case 7:
                                    viewAllElementsMap(matvec_float);
                                    break;

                                case 0:
                                    return;
                            }
                        } while (todo != 0);

                    } else if (type_structure == 3) { //*** MATRIX VEC STRING ***//
                        lasd::MatrixVec<std::string> matvec_string(rownum, colnum);
                        generatorMatrString(rownum, colnum, matvec_string);
                        do {
                            switch(todo = selectActionStructure(todo)){
                                case 1: //VIEW MAP PRE-ORDER
                                    viewInPreOrdineMap(matvec_string);
                                    break;

                                case 2: //VIWA MAP POST-ORDER
                                    viewInPostOrdineMap(matvec_string);
                                    break;

                                case 3: //EXISTS
                                    checkTheExistanceString(matvec_string);
                                    break;

                                case 4: //FUNZIONE FOLD
                                    operationForStructureTypeFoldString(matvec_string, num);
                                    break;

                                case 5: //MAP SPECIFIC FOR TYPE
                                    operationForStructureTypeMapString(matvec_string);
                                    break;

                                case 6: //FUNZIONALITA' DI LIBRERIA
                                    selectFunctionLibrary(matvec_string);
                                    break;

                                case 7:
                                    viewAllElementsMap(matvec_string);
                                    break;

                                case 0:
                                    return;
                            }
                        } while (todo != 0);
                    }
                    break;

            case 2 :
                std::cout << ">>> HAI SELEZIONATO MATRIX CSR <<<" << std::endl;
                type_structure = selectTypeStructure();
                selectSizeStructureRow(rownum);
                selectSizeStructureCol(colnum);
                std::cout << ">>> LA DIMENSIONE DELLA STRUTTURA E': " << rownum << " x " << colnum << std::endl;

                if (type_structure == 1) { //*** MATRIX CSR INTEGER ***//
                    lasd::MatrixCSR<int> matcsr_int(rownum, colnum);
                    generatorMatrInteger(rownum, colnum, matcsr_int);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //VIEW MAP PRE-ORDER
                                viewInPreOrdineMap(matcsr_int);
                                break;

                            case 2: //VIWA MAP POST-ORDER
                                viewInPostOrdineMap(matcsr_int);
                                break;

                            case 3: //EXISTS
                                checkTheExistenceInteger(matcsr_int);
                                break;

                            case 4: //FUNZIONE FOLD
                                operationForStructureTypeFoldInteger(matcsr_int, num);
                                break;

                            case 5: //MAP SPECIFIC FOR TYPE
                                operationForStructureTypeMapInteger(matcsr_int);
                                break;

                            case 6: //FUNZIONALITA' DI LIBRERIA
                                selectFunctionLibrary(matcsr_int);
                                break;

                            case 7:
                                viewAllElementsMap(matcsr_int);
                                break;

                            case 0:
                                return;
                        }
                    } while (todo != 0);

                } else if (type_structure == 2) { //*** MATRIX CSR FLOAT ***//
                    lasd::MatrixCSR<float> matcsr_float(rownum, colnum);
                    generatorMatrFloat(rownum, colnum, matcsr_float);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //VIEW MAP PRE-ORDER
                                viewInPreOrdineMap(matcsr_float);
                                break;

                            case 2: //VIWA MAP POST-ORDER
                                viewInPostOrdineMap(matcsr_float);
                                break;

                            case 3: //EXISTS
                                checkTheExistenceFloat(matcsr_float);
                                break;

                            case 4: //FUNZIONE FOLD
                                operationForStructureTypeFoldFloat(matcsr_float, num);
                                break;

                            case 5: //MAP SPECIFIC FOR TYPE
                                operationForStructureTypeMapFloat(matcsr_float);
                                break;

                            case 6: //FUNZIONALITA' DI LIBRERIA
                                selectFunctionLibrary(matcsr_float);
                                break;

                            case 7:
                                viewAllElementsMap(matcsr_float);
                                break;

                            case 0:
                                return;
                        }
                    } while (todo != 0);


                } else if (type_structure == 3) { //*** MATRIX CSR STRING ***//
                    lasd::MatrixCSR<std::string> matcsr_string(rownum, colnum);
                    generatorMatrString(rownum, colnum, matcsr_string);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //VIEW MAP PRE-ORDER
                                viewInPreOrdineMap(matcsr_string);
                                break;

                            case 2: //VIWA MAP POST-ORDER
                                viewInPostOrdineMap(matcsr_string);
                                break;

                            case 3: //EXISTS
                                checkTheExistanceString(matcsr_string);
                                break;

                            case 4: //FUNZIONE FOLD
                                operationForStructureTypeFoldString(matcsr_string, num);
                                break;

                            case 5: //MAP SPECIFIC FOR TYPE
                                operationForStructureTypeMapString(matcsr_string);
                                break;

                            case 6: //FUNZIONALITA' DI LIBRERIA
                                selectFunctionLibrary(matcsr_string);
                                break;

                            case 7:
                                viewAllElementsMap(matcsr_string);
                                break;

                            case 0:
                                return;
                        }
                    } while (todo != 0);
                }
                break;
                }
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }while (std::cin.fail() || select_structure != 0);
}