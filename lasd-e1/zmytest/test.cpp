#include "test.hpp"


/* ****************************************************************************************************************** */

//*** Resize dimension of structure (Vector<Type>) using Resize function ***//
template <typename Type>
void resizeVector(lasd::Vector<Type>& vec){
    ulong n;
    do {
        std::cout << "@INSERISCI LA NUOVA DIMENSIONE PER IL VETTORE" << std::endl;
        std::cout << "@";
        std::cin >> n;
        if(!std::cin.fail()){
            vec.Resize(n);
        }else{
            std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

    }while(std::cin.fail());
}

/* ****************************************************************************************************************** */

//*** Select the library functions for Lists ***//
template <typename Type>
void selectLibraryFunctionList(lasd::List<Type>& lis){
    int enne = -1;
    Type val;
    do {
        std::cout<<"\n*******************************************************************************"<<std::endl;
        std::cout<<">>>*** SELEZIONA UNA DELLE SEGUENTI FUNZIONI DI LIBRERIA ***<<<"<<std::endl;
        std::cout<<"    [1] INSERIMENTO IN TESTA"<<std::endl;
        std::cout<<"    [2] INSERIMENTO IN CODA"<<std::endl;
        std::cout<<"    [3] RIMOZIONE SENZA LETTURA"<<std::endl;
        std::cout<<"    [4] RIMOZIONE CON LETTURA"<<std::endl;
        std::cout<<"    [5] STAMPA GLI ELEMENTI DELLA STRUTTURA"<<std::endl;
        std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE"<<std::endl;
        std::cout<<"@"; std::cin>>enne;

        if(!std::cin.fail()){
            switch (enne) {
                case 1:
                    std::cout<<"@INSERISCI IL VALORE DA INSERIRE IN TESTA"<<std::endl;
                    std::cout<<"@"; std::cin>>val;
                    if(!std::cin.fail()){
                        lis.InsertAtFront(val);
                    }else{
                        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
                    }
                    break;
                case 2:
                    std::cout<<"@INSERISCI IL VALORE DA INSERIRE IN CODA"<<std::endl;
                    std::cout<<"@"; std::cin>>val;
                    if (!std::cin.fail()) {
                        lis.InsertAtBack(val);
                    }else{
                        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
                    }
                    break;
                case 3:
                    try{
                        lis.RemoveFromFront();
                        std::cout<<">>> RIMOZIONE SENZA LETTURA EFFETTUATA <<<"<<std::endl;
                        break;
                    }catch(std::length_error &exc){
                        std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
                    }
                case 4:
                    try{
                        std::cout<<">>> L'ELEMENTO CHE HAI RIMOSSO E': "<<std::fixed<<lis.FrontNRemove()<<" <<<"<<std::endl;
                        break;
                    }catch(std::length_error &exc){
                        std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
                    }
                case 5:
                    lis.MapPreOrder(&printForMap<Type>, nullptr);
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
void doublingElements(Type& elem, void* par){
    elem = 2*elem;
}

template <typename Type>
void squareElements(Type& elem, void* par){
    elem *= elem;
}

template <typename Type>
void uppercaseString(Type& elem, void* par){
    std::transform(elem.begin(), elem.end(),elem.begin(), ::toupper);
}

//*** Doubling of elements of structure (MappableContainer<int>) using MapPreOrder function ***//
void operationForStructureTypeMapInteger(lasd::MappableContainer<int>& obj){
    obj.MapPreOrder(&doublingElements<int>, nullptr);
    obj.MapPreOrder(&printForMap<int>, nullptr);
}

//*** Squared elements of structure (MappableContainer<float>) using MapPreOrder function ***//
void operationForStructureTypeMapFloat(lasd::MappableContainer<float>& obj){
    obj.MapPreOrder(&squareElements<float>, nullptr);
    obj.MapPreOrder(&printForMap<float>, nullptr);
}

//*** Uppercase elements of structure (MappableContainer<string>) using MapPreOrder function ***//
void operationForStructureTypeMapString(lasd::MappableContainer<std::string>& obj){
    obj.MapPreOrder(&uppercaseString<std::string>, nullptr);
    obj.MapPreOrder(&printForMap<std::string>, nullptr);
}

/*template <typename Type>
void operationForStructureTypeMap(lasd::MappableContainer<Type>& obj){
    if constexpr(std::is_same<Type,int>::value){ //Doubling of elements of structure (MappableContainer<int>) using MapPreOrder function
        std::cout<<">>> RADDOPPIA GLI INTERI <<<"<<std::endl;
        obj.MapPreOrder(&doublingElements<Type>, nullptr);
        obj.MapPreOrder(&printForMap<Type>, nullptr);
    }else if constexpr(std::is_same<Type,float>::value){ //Squared elements of structure (MappableContainer<float>) using MapPreOrder function
        std::cout<<">>> I FLOAT AL QUADRATO <<<"<<std::endl;
        obj.MapPreOrder(&squareElements<Type>, nullptr);
        obj.MapPreOrder(&printForMap<Type>, nullptr);
    }else if constexpr(std::is_same<Type,std::string>::value){
        std::cout<<">>> UPPERCASE LE STRINGHE <<<"<<std::endl; //Uppercase elements of structure (MappableContainer<string>) using MapPreOrder function
        obj.MapPreOrder(&uppercaseString<Type>, nullptr);
        obj.MapPreOrder(&printForMap<Type>, nullptr);
    }
}*/

/* ****************************************************************************************************************** */

template <typename Type>
void sumIntegers(const Type& elem, const void* dim, void* acc){
    if(elem < (*(int*)dim)){
        (*(int*)acc) = (*(int*)acc)+elem;
    }
}

template <typename Type>
void productFloats(const Type& elem, const void* dim, void* acc){
    if(elem > (*(int*)dim)){
        (*(float*)acc) = (*(float*)acc)*elem;
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
    std::cout << "@INSERISCI N PER LA FUNZIONE FOLD PREVISTA PER LA STRUTTURA" << std::endl;
    std::cout << "@";
    std::cin >> n;
    do {
        const void *dim = &n;
        void *acc = nullptr;
        if (!std::cin.fail() && n > 0) {
                int ac = 0;
                acc = &ac;
                obj.FoldPreOrder(&sumIntegers<int>, dim, acc);
                std::cout << ">>> LA SOMMA VALE: " << ac << " <<<" << std::endl;

        } else {
            std::cout << "*** VALORE NON VALIDO ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    } while (std::cin.fail() || n < 0);
}

//*** Product of elements greater than n of structure (FoldableContainer<float>) using FoldPreOrder function ***//
void operationForStructureTypeFoldFloat(lasd::FoldableContainer<float>& obj, int& n) {
    std::cout << "@INSERISCI N PER LA FUNZIONE FOLD PREVISTA PER LA STRUTTURA" << std::endl;
    std::cout << "@";
    std::cin >> n;
    do {
        const void *dim = &n;
        void *acc = nullptr;
        if (!std::cin.fail() && n > 0) {
            float ac = 1;
            acc = &ac;
            obj.FoldPreOrder(&productFloats<float>, dim, acc);
            std::cout<<">>> IL PRODOTTO VALE: "<<std::fixed<<ac<<std::endl;
        }else{
            std::cout << "*** VALORE NON VALIDO ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }while(std::cin.fail() || n < 0);
}

//*** Concatenation of elements less-equals than n of structure (FoldableContainer<string>) ***//
void operationForStructureTypeFoldString(lasd::FoldableContainer<std::string>& obj, int& n) {
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
void printForMap(Type& elem, void* par){
    std::cout<<std::fixed<<elem<<" ";
}

template <typename Type>
void viewAllElementsMap(lasd::MappableContainer<Type>& obj){
    obj.MapPreOrder(&printForMap<Type>, nullptr);
}

/* ****************************************************************************************************************** */

template <typename Type>
void displayElementVecLis(int& todo, lasd::LinearContainer<Type>& object, int& index){
    switch (todo) {
        case 1: //*** Displays the first element of the structure (LinearContainer<Type>) ***//
            try {
                std::cout<< ">>> IL PRIMO ELEMENTO DELLA STRUTTURA E': " <<std::fixed<<object.Front()<<" <<<"<<std::endl;
                break;
            }catch(std::length_error &exc){
                std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
            }
        case 2: //*** Displays the last element of the structure (LinearContainer<Type>) ***//
            try {
                std::cout<< ">>> L'ULTIMO ELEMENTO DELLA STRUTTURA E': "<<std::fixed<<object.Back()<<" <<<" <<std::endl;
                break;
            }catch(std::length_error &exc){
                std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
            }
        case 3: //*** Displays the item at a specific index of the structure (LinearContainer<Type>) ***//
            try {
                std::cout<<">>> L' ELEMENTO DELLA STRUTTURA ALL'INDICE DA TE SCELTO E': "<<std::fixed<<object[index]<< " <<<"<<std::endl;
                break;
            }catch(std::out_of_range &exc){
                std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
            }
    }
}

template <typename Type>
void displayElementAtIndex(int& todo, lasd::LinearContainer<Type>& obj, int& index){
    do {
        switch (todo) {
            case 1: //*** Displays the first element of the structure (LinearContainer<Type>) ***//
                index = 0;
                displayElementVecLis(todo, obj, index);
                break;
            case 2: //*** Displays the last element of the structure (LinearContainer<Type>) ***//
                index = obj.Size() - 1;
                displayElementVecLis(todo, obj, index);
                break;
            case 3: //*** Displays the item at a specific index of the structure (LinearContainer<Type>) ***//
                std::cout << "\n@INSERISCI L'INDICE DELL'ELEMENTO CHE VUOI VISUALIZZARE" << std::endl;
                std::cout << "@";
                std::cin >> index;
                if (!std::cin.fail()) {
                    displayElementVecLis(todo, obj, index);
                } else {
                    std::cout << "*** INSERIMENTO NON VALIDO ***" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
        }
    }while(std::cin.fail());
}

/* ****************************************************************************************************************** */

//*** Generator for Vector of integers ***//
void generatorVectorInteger(const ulong& dimension, lasd::Vector<int>& vec){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        vec[i] = dist(gen);
    }
}

//*** Generator for Vector of floats ***//
void generatorVectorFloat(const ulong& dimension, lasd::Vector<float>& vec){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        vec[i] = dist(gen);
    }
}

//*** Generator for Vector of strings ***//
void generatorVectorString(const ulong& dimension, lasd::Vector<std::string>& vec) {
    static auto& chrs = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);
    std::uniform_int_distribution <int> distribution(3,10);
    std::string s[dimension];
    int tmp = distribution(rg);
    for(ulong i =0; i < dimension; i++){
        while(tmp--){
            s[i] += chrs[pick(rg)];
        }
        tmp = distribution(rg);
        vec[i] = s[i];
    }
}

/* ****************************************************************************************************************** */

//*** Generator for List of integers ***//
void generatorListInteger(const ulong& dimension, lasd::List<int>& lis){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        lis.InsertAtBack(dist(gen));
    }
}

//*** Generator for List of floats ***//
void generatorListFloat(const ulong& dimension, lasd::List<float>& lis){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        lis.InsertAtBack(dist(gen));
    }
}

//*** Generator for List of strings ***//
void generatorListString(const ulong& dimension, lasd::List<std::string>& lis){
    static auto& chrs = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);
    std::uniform_int_distribution <int> distribution(3,10);
    std::string s[dimension];
    int tmp = distribution(rg);
    for(ulong i =0; i < dimension; i++){
        while(tmp--){
            s[i] += chrs[pick(rg)];
        }
        tmp = distribution(rg);
        lis.InsertAtBack(s[i]);
    }
}

/* ****************************************************************************************************************** */

//*** Select the operation for the structure ***//
int& selectActionStructure(int& todo){

    std::cout<<"\n*******************************************************************************"<<std::endl;
    std::cout<<"@SELEZIONA L'OPERAZIONE DIGITANDO IL NUMERO DI RIFERIMENTO"<<std::endl;
    std::cout<<"    [1] VISUALIZZA IL PRIMO ELEMENTO DELLA STRUTTURA"<<std::endl;
    std::cout<<"    [2] VISUALIZZA L'ULTIMO ELEMENTO DELLA STRUTTURA"<<std::endl;
    std::cout<<"    [3] VISUALIZZA UN ELEMENTO AD UN CERTO INDICE DELLA STRUTTURA"<<std::endl;
    std::cout<<"    [4] STAMPA TUTTI GLI ELEMENTI DELLA STRUTTURA (MAP)"<<std::endl;
    std::cout<<"    [5] CONTROLLA L'ESISTENZA DI UN ELEMENTO NELLA STRUTTURA"<<std::endl;
    std::cout<<"    [6] FUNZIONALITA' FOLD IN BASE AL TIPO (INT,FLOAT,STRING) CONTENUTO NELLA STRUTTURA"<<std::endl;
    std::cout<<"    [7] FUNZIONALITA' MAP IN BASE AL TIPO (INT,FLOAT,STRING) CONTENUTO NELLA STRUTTURA"<<std::endl;
    std::cout<<"    [8] FUNZIONALITA' DI LIBRERIA"<<std::endl;
    std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE"<<std::endl;
    std::cout<<"@"; std::cin>>todo;
    return todo;
}

/* ****************************************************************************************************************** */

//*** Select the dimension of structure (integer, float, string) ***//
ulong& selectSizeStructure(ulong& dimension){
    std::cout<<"\n*******************************************************************************"<<std::endl;
    do {
        std::cout<<"@INSERISCI LA DIMENSIONE DELLA STRUTTURA N > 0"<<std::endl;
        std::cout<<"@"; std::cin>>dimension;

        if(std::cin.fail()){
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }else if(dimension <= 0){
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
        }
    }while(std::cin.fail() || dimension <= 0);
    std::cout<<">>> LA DIMENSIONE DELLA STRUTTURA E': "<<dimension<<" <<<"<<std::endl;
    return dimension;
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
                break;
            default:
                std::cout<<"*** SELEZIONE NON VALIDA DEL TIPO ***"<<std::endl;
                break;
        }
    }while(select_typestructure != 0);
    return select_typestructure;
}

/* ****************************************************************************************************************** */

void start(){
    int select_structure = -1;
    int type_structure = -1;
    ulong dimension = -1;
    int todo = -1;
    int index = -1;
    int num = -1;

    do {
        std::cout<<"\n***************************** BENVENUTO NEL MENU' *****************************"<<std::endl;
        std::cout<<"@SELEZIONA LA STRUTTURA DIGITANDO IL NUMERO DI RIFERIMENTO"<<std::endl;
        std::cout<<"    [1] VETTORI"<<std::endl;
        std::cout<<"    [2] LISTE"<<std::endl;
        std::cout<<"    [0] PER USCIRE"<<std::endl;
        std::cout<<"@"; std::cin>>select_structure;

        switch (select_structure) {
            case 1 : //Vector
                std::cout<<">>> HAI SELEZIONATO I VETTORI <<<"<<std::endl;
                type_structure = selectTypeStructure();
                if(type_structure == 1){ //Vector of integers
                    selectSizeStructure(dimension);
                    lasd::Vector<int>vec_int(dimension);
                    //generatorVector(dimension, vec_int);
                    generatorVectorInteger(dimension, vec_int);
                    do {
                        switch (todo = selectActionStructure(todo)) {
                            case 1: //Displays the first element of the structure (Vector of integers)
                                displayElementAtIndex(todo, vec_int, index);
                                break;
                            case 2: //Displays the last element of the structure (Vector of integers)
                                displayElementAtIndex(todo, vec_int, index);
                                break;
                            case 3: //Displays the item at a specific index of the structure (Vector of integers)
                                displayElementAtIndex(todo, vec_int, index);
                                break;
                            case 4: //View all elements of the structure (Vector of integers) using MapPreOrder function
                                viewAllElementsMap(vec_int);
                                break;
                            case 5: //Check the existence of an item of structure (Vector of integers) using Exists function
                                checkTheExistenceInteger(vec_int);
                                break;
                            case 6: //Sum of elements less than n of structure (Vector of integers) using FoldPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout << ">>>*** SOMMA DEGLI INTERI < N ***<<<" << std::endl;
                                operationForStructureTypeFoldInteger(vec_int, num);
                                break;
                            case 7: //Doubling of elements of structure (Vector of integers) using MapPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout<<">>>*** RADDOPPIA GLI INTERI ***<<<"<<std::endl;
                                operationForStructureTypeMapInteger(vec_int);
                                break;
                            case 8: //Resize dimension of structure (Vector of integers) using Resize function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout << ">>>*** RIDIMENSIONAMENTO VETTORE ***<<<" << std::endl;
                                resizeVector(vec_int);
                                break;
                        }

                    }while(todo != 0);
                }
              else if(type_structure == 2){ //Vector of floats
                    selectSizeStructure(dimension);
                    lasd::Vector<float>vec_float(dimension);
                    //generatorVector(dimension, vec_float);
                    generatorVectorFloat(dimension, vec_float);
                    do {
                        switch (todo = selectActionStructure(todo)) {
                            case 1: //Displays the first element of the structure (Vector of floats)
                                displayElementAtIndex(todo, vec_float, index);
                                break;
                            case 2: //Displays the last element of the structure (Vector of floats)
                                displayElementAtIndex(todo, vec_float, index);
                                break;
                            case 3: //Displays the item at a specific index of the structure(Vector of floats)
                                displayElementAtIndex(todo, vec_float, index);
                                break;
                            case 4: //View all elements of the structure (Vector of floats) using MapPreOrder function
                                viewAllElementsMap(vec_float);
                                break;
                            case 5: //Check the existence of an item of structure (Vector of floats) using Exists function
                                checkTheExistenceFloat(vec_float);
                                break;
                            case 6: //Product of elements greater than n of structure (Vector of floats) using FoldPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout<<">>>*** PRODOTTO DEI FLOAT > N ***<<<"<<std::endl;
                                operationForStructureTypeFoldFloat(vec_float, num);
                                break;
                            case 7: //Squared elements of structure (Vector of floats) using MapPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout<<">>>*** I FLOAT AL QUADRATO ***<<<"<<std::endl;
                                operationForStructureTypeMapFloat(vec_float);
                                break;
                            case 8: //Resize dimension of structure (Vector of floats) using Resize function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout << ">>>*** RIDIMENSIONAMENTO VETTORE ***<<<" << std::endl;
                                resizeVector(vec_float);
                                break;
                        }

                    }while(todo != 0);
              }else if(type_structure == 3){ //Vector of string
                    selectSizeStructure(dimension);
                    lasd::Vector<std::string>vec_string(dimension);
                    //generatorVector(dimension, vec_string);
                    generatorVectorString(dimension, vec_string);
                    do {
                        switch (todo = selectActionStructure(todo)) {
                            case 1: //Displays the first element of the structure (Vector of strings)
                                displayElementAtIndex(todo, vec_string, index);
                                break;
                            case 2: //Displays the last element of the structure (Vector of strings)
                                displayElementAtIndex(todo, vec_string, index);
                                break;
                            case 3: //Displays the item at a specific index of the structure(Vector of strings)
                                displayElementAtIndex(todo, vec_string, index);
                                break;
                            case 4: //View all elements of the structure (Vector of strings) using MapPreOrder function
                                viewAllElementsMap(vec_string);
                                break;
                            case 5: //Check the existence of an item of structure (Vector of strings) using Exists function
                                checkTheExistanceString(vec_string);
                                break;
                            case 6: //Concatenation of elements less-equals than n of structure (Vector of strings) using FoldPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout<<">>>*** CONCATENAZIONE STRINGHE CON LUNGHEZZA <= N ***<<<"<<std::endl;
                                operationForStructureTypeFoldString(vec_string, num);
                                break;
                            case 7: //Uppercase elements of structure (Vector of strings) using MapPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout<<">>>*** UPPERCASE LE STRINGHE ***<<<"<<std::endl;
                                operationForStructureTypeMapString(vec_string);
                                break;
                            case 8: //Resize dimension of structure (Vector of string) using Resize function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout << ">>>*** RIDIMENSIONAMENTO VETTORE ***<<<" << std::endl;
                                resizeVector(vec_string);
                                break;
                        }

                    }while(todo != 0);
              }
                select_structure = 0;
                break;

            case 2 : //List
                std::cout<<">>> HAI SELEZIONATO LE LISTE <<<"<<std::endl;
                type_structure = selectTypeStructure();
                if(type_structure == 1) { //List of integers
                    selectSizeStructure(dimension);
                    lasd::List<int>list_int;
                    //generatorList(dimension, list_int);
                    generatorListInteger(dimension, list_int);
                    do {
                        switch (todo = selectActionStructure(todo)) {
                            case 1: //Displays the first element of the structure (List of integers)
                                displayElementAtIndex(todo, list_int, index);
                                break;
                            case 2: //Displays the last element of the structure (List of integers)
                                displayElementAtIndex(todo, list_int, index);
                                break;
                            case 3: //Displays the item at a specific index of the structure(List of integers)
                                displayElementAtIndex(todo, list_int, index);
                                break;
                            case 4: //View all elements of the structure (List of integers) using MapPreOrder function
                                viewAllElementsMap(list_int);
                                break;
                            case 5: //Check the existence of an item of structure (List of integers) using Exists function
                                checkTheExistenceInteger(list_int);
                                break;
                            case 6: //Sum of elements less than n of structure (List of integers) using FoldPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout << ">>>*** SOMMA DEGLI INTERI < N ***<<<" << std::endl;
                                operationForStructureTypeFoldInteger(list_int, num);
                                break;
                            case 7: //Doubling of elements of structure (List of integers) using MapPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout<<">>>*** RADDOPPIA GLI INTERI ***<<<"<<std::endl;
                                operationForStructureTypeMapInteger(list_int);
                                break;
                            case 8: //Select the library functions for Lists
                                selectLibraryFunctionList(list_int);
                                break;
                        }
                    }while(todo != 0);
                }
                else if(type_structure == 2) { //List of floats
                    selectSizeStructure(dimension);
                    lasd::List<float>list_float;
                    //generatorList(dimension, list_float);
                    generatorListFloat(dimension, list_float);
                    do {
                        switch (todo = selectActionStructure(todo)) {
                            case 1: //Displays the first element of the structure (List of floats)
                                displayElementAtIndex(todo, list_float, index);
                                break;
                            case 2: //Displays the last element of the structure (List of floats)
                                displayElementAtIndex(todo, list_float, index);
                                break;
                            case 3: //Displays the item at a specific index of the structure(List of floats)
                                displayElementAtIndex(todo, list_float, index);
                                break;
                            case 4: //View all elements of the structure (List of floats) using MapPreOrder function
                                viewAllElementsMap(list_float);
                                break;
                            case 5: //Check the existence of an item of structure (List of floats) using Exists function
                                checkTheExistenceFloat(list_float);
                                break;
                            case 6: //Product of elements greater than n of structure (List of floats) using FoldPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout<<">>>*** PRODOTTO DEI FLOAT > N ***<<<"<<std::endl;
                                operationForStructureTypeFoldFloat(list_float, num);
                                break;
                            case 7: //Squared elements of structure (List of floats) using MapPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout<<">>>*** I FLOAT AL QUADRATO ***<<<"<<std::endl;
                                operationForStructureTypeMapFloat(list_float);
                                break;
                            case 8: //Select the library functions for Lists
                                selectLibraryFunctionList(list_float);
                                break;
                        }

                    }while(todo != 0);

                }else if(type_structure == 3){ //List of strings
                    selectSizeStructure(dimension);
                    lasd::List<std::string>list_string;
                    //generatorList(dimension, list_string);
                    generatorListString(dimension, list_string);
                    do {
                        switch (todo = selectActionStructure(todo)) {
                            case 1: //Displays the first element of the structure (List of strings)
                                displayElementAtIndex(todo, list_string, index);
                                break;
                            case 2: //Displays the last element of the structure (List of strings)
                                displayElementAtIndex(todo, list_string, index);
                                break;
                            case 3: //Displays the item at a specific index of the structure(List of strings)
                                displayElementAtIndex(todo, list_string, index);
                                break;
                            case 4: //View all elements of the structure (List of strings) using MapPreOrder function
                                viewAllElementsMap(list_string);
                                break;
                            case 5: //Check the existence of an item of structure (List of strings) using Exists function
                                checkTheExistanceString(list_string);
                                break;
                            case 6: //Concatenation of elements less-equals than n of structure (List of strings) using FoldPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout<<">>>*** CONCATENAZIONE STRINGHE CON LUNGHEZZA <= N ***<<<"<<std::endl;
                                operationForStructureTypeFoldString(list_string, num);
                                break;
                            case 7: //Uppercase elements of structure (List of strings) using MapPreOrder function
                                std::cout << "\n*******************************************************************************" << std::endl;
                                std::cout<<">>>*** UPPERCASE LE STRINGHE ***<<<"<<std::endl;
                                operationForStructureTypeMapString(list_string);
                                break;
                            case 8: //Select the library functions for Lists
                                selectLibraryFunctionList(list_string);
                                break;
                        }
                    }while(todo != 0);
                }
                select_structure = 0;
                break;
            case 0 : //Exit
                select_structure = 0;
                break;
            default:
                std::cout<<"*** SELEZIONE NON VALIDA DELLA STRUTTURA ***"<<std::endl;
                break;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }while(std::cin.fail() || select_structure != 0);
}

/* ****************************************************************************************************************** */