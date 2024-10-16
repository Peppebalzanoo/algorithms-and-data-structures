#include "test.hpp"

/* ****************************************************************************************************************** */

//*** Start functions for Iterators ***//
template <typename Type>
void startIteratorFunction(lasd::ForwardIterator<Type>&iterator){
    int select = -1;
    do{
        std::cout<<"\n*******************************************************************************"<<std::endl;
        std::cout<<"*** SELEZIONE IL TIPO DI OPERAZIONE DA EFFETTUARE ATTRAVERSO L'ITERATORE ***"<<std::endl;
        std::cout<<"    [1] STAMPA IL DATO DEL NODO CORRENTE"<<std::endl;
        std::cout<<"    [2] VAI AL NODO SUCCESSIVO"<<std::endl;
        std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE"<<std::endl;
        std::cout<<"@"; std::cin>>select;
        if(!std::cin.fail()){
            switch (select) {
                case 1:
                    try {
                        std::cout << ">>> IL DATO NEL NODO CORRENTE E': " << iterator.operator*() << " <<<"<< std::endl;
                    }catch (std::out_of_range e){
                        std::cout << "\n*** IMPOSSIBILE ACCEDERE AL NODO, ITERATORE TERMINATO ***" << std::endl;
                        std::cout << "*** PREMI UN TASTO PER CONTINUARE ***" << std::endl;
                        select = 0;
                        break;
                    }
                     break;
                case 2:
                    try {
                        iterator.operator++();
                        std::cout << ">>> INCREMENTO EFFETTUATO CORRETTAMENTE <<<" << std::endl;
                    }catch(std::out_of_range e){
                        std::cout << "\n*** ITERATORE TERMINATO ***" << std::endl;
                        std::cout << "*** PREMI UN TASTO PER CONTINUARE ***" << std::endl;
                        select = 0;
                        break;
                    }
                    break;
                case 0:
                    select = 0;
                    return;
            }
        }else{
            std::cout<<"*** SELEZIONE NON VALIDA ***"<<std::endl;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }while(std::cin.fail() || select != 0);
}

//*** Select the type of Iterator ***//
int selectTypeIteratorBT(int& type_iter){
    do{
        std::cout<<"\n*******************************************************************************"<<std::endl;
        std::cout<<">>>*** SELEZIONE IL TIPO DI ITERATORE DA UTILIZZARE SULLA STRUTTURA ***<<<"<<std::endl;
        std::cout<<"    [1] AMPIEZZA"<<std::endl;
        std::cout<<"    [2] PRE-ORDINE"<<std::endl;
        std::cout<<"    [3] IN-ORDINE"<<std::endl;
        std::cout<<"    [4] POST-ORDINE"<<std::endl;
        std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE"<<std::endl;
        std::cout<<"@"; std::cin>>type_iter;
        if(!std::cin.fail()){
            std::cout<<">>> HAI HAI SELEZIONATO CORRETTAMENTO L'ITERATORE <<<"<<std::endl;
            break;
        }else{
            std::cout<<"*** SELEZIONE NON VALIDA ***"<<std::endl;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }while(std::cin.fail() || type_iter != 0);
    return type_iter;
}


//*** Select the library functions ***//
template <typename Type>
void selectFunctionLibrary(lasd::BinaryTree<Type>&tree){
    Type data;
    int enne = -1;
    int type = -1;

    typename lasd::BinaryTree<Type>::Node* root = &tree.Root(); //CHECK EXCEPTION

    do {
        std::cout<<"\n*******************************************************************************"<<std::endl;
        std::cout<<"*** SELEZIONA UNA DELLE SEGUENTI FUNZIONI DI LIBRERIA ***"<<std::endl;
        std::cout<<"    [1] ACCESSO IN LETTURA AL DATO CONTENUTO NEL NODO CORRENTE"<<std::endl;
        std::cout<<"    [2] ACCESSO IN SCRITTURA AL DATO CONTENUTO NEL NODO CORRENTE"<<std::endl;
        std::cout<<"    [3] CONTROLLO ESISTENZA FIGLIO SINISTRO"<<std::endl;
        std::cout<<"    [4] ACCESSO AL FIGLIO SINISTRO"<<std::endl;
        std::cout<<"    [5] CONTROLLO ESISTENZA FIGLIO DESTRO"<<std::endl;
        std::cout<<"    [6] ACCESSO AL FIGLIO DESTRO"<<std::endl;
        std::cout<<"    [7] NAVIGAZIONE CON GLI ITERATORI"<<std::endl;
        std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE"<<std::endl;
        std::cout<<"@"; std::cin>>enne;

        if(!std::cin.fail()){

            switch (enne) {
                case 1:
                    std::cout<<">>> IL DATO DELL'ELEMENTO DEL NODO CORRENTE E': "<<root->Element()<<" <<<"<<std::endl;
                    break;
                case 2:
                    std::cout<<"@INSERISCI IL DATO DA INSERIRE AL NODO CORRENTE: "<<std::endl;
                    std::cout<<"@"; std::cin>>data;
                    if (!std::cin.fail()) {
                        root->Element() = data;
                    }else{
                        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
                    }
                    break;
                case 3:
                    if(root->HasLeftChild()){
                        std::cout<<">>> IL NODO CORRENTE HA FIGLIO SINISTRO <<<"<<std::endl;
                    }else{
                        std::cout<<">>> IL NODO CORRENTE NON HA FIGLIO SINISTRO <<<"<<std::endl;
                    }
                    break;
                case 4:
                    try{
                        root = &root->LeftChild();
                        std::cout<<">>> ACCESSO EFFETTUATO CORRETTAMENTE AL FIGLIO SINISTRO <<<"<<std::endl;
                        std::cout<<">>> IL DATO DELL'ELEMENTO DEL NODO CORRENTE E': "<<root->Element()<<" <<<"<<std::endl;
                    }catch(std::out_of_range e){
                        std::cout<<"*** IL NODO CORRENTE NON PRESENTA FIGLIO SINISTRO! PERTANTO NON E' POSSIBILE ACCEDERVI! ***"<<std::endl;
                    }
                    break;
                case 5:
                    if(root->HasRightChild()){
                        std::cout<<">>> IL NODO CORRENTE HA FIGLIO DESTRO <<<"<<std::endl;

                    }else{
                        std::cout<<">>> IL NODO CORRENTE NON HA FIGLIO DESTRO <<<"<<std::endl;
                    }
                    break;
                case 6:
                    try{
                        root = &root->RightChild();
                        std::cout<<">>> ACCESSO EFFETTUATO CORRETTAMENTE AL FIGLIO DESTRO <<<"<<std::endl;
                        std::cout<<">>> IL DATO DELL'ELEMENTO DEL NODO CORRENTE E': "<<root->Element()<<" <<<"<<std::endl;
                    }catch(std::out_of_range e){
                        std::cout<<"*** IL NODO CORRENTE NON PRESENTA FIGLIO DESTRO! PERTANTO NON E' POSSIBILE ACCEDERVI! ***"<<std::endl;
                    }
                    break;
                case 7: {
                        selectTypeIteratorBT(type);
                        if(type == 1){
                            lasd::BTBreadthIterator<Type>iterator_ampiezza(tree);
                            startIteratorFunction(iterator_ampiezza);
                        }else if(type == 2){
                            lasd::BTPreOrderIterator<Type>iterator_preorder(tree);
                            startIteratorFunction(iterator_preorder);
                        }else if(type == 3){
                            lasd::BTInOrderIterator<Type>iterator_inorder(tree);
                            startIteratorFunction(iterator_inorder);
                        }else if(type == 4){
                            lasd::BTPostOrderIterator<Type>iterator_postorder(tree);
                            startIteratorFunction(iterator_postorder);
                        }
                    }
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
void triplicationElements(Type& elem, void* par){
    elem = 3*elem;
}

template <typename Type>
void cubeElements(Type& elem, void* par){
    elem = elem * elem * elem;
}

template <typename Type>
void frontString(Type& elem, void* par){
    std::string front = *(std::string*)par;
    elem.insert(0,front);
}

//*** 3*n of elements of structure (MappableContainer<int>) using MapPreOrder function ***//
void operationForStructureTypeMapInteger(lasd::MappableContainer<int>& obj){
    std::cout<<"*** TUTTI GLI ELEMENTI DELLA STRUTTURA TRIPLICATI ***"<<std::endl;
    obj.MapPreOrder(&triplicationElements<int>, nullptr);
    std::cout<<">>> VISUALIZZAZIONE IN PRE-ORDINE <<<"<<std::endl;
    obj.MapPreOrder(&printForMap<int>, nullptr);
}

//*** Cube elements of structure (MappableContainer<float>) using MapPreOrder function ***//
void operationForStructureTypeMapFloat(lasd::MappableContainer<float>& obj){
    std::cout<<"*** TUTTI GLI ELEMENTI DELLA STRUTTURA AL CUBO ***"<<std::endl;
    obj.MapPreOrder(&cubeElements<float>, nullptr);
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
    if(elem < (*(int*)dim)){
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
void printForMap(Type& elem, void* par){
    std::cout<<std::fixed<<elem<<" ";
}

template <typename Type>
void viewAllElementsMap(lasd::MappableContainer<Type>& obj){
    obj.MapPreOrder(&printForMap<Type>, nullptr);
}

/* ****************************************************************************************************************** */

template <typename Type>
void viewInAmpiezzaMap(lasd::BinaryTree<Type>& obj){
    obj.MapBreadth(&printForMap<Type>, nullptr);
}

template <typename Type>
void viewInPreOrdineMap(lasd::BinaryTree<Type>& obj){
    obj.MapPreOrder(&printForMap<Type>, nullptr);
}

template <typename Type>
void viewInInOrdineMap(lasd::BinaryTree<Type>& obj){
    obj.MapInOrder(&printForMap<Type>, nullptr);
}

template <typename Type>
void viewInPostOrdineMap(lasd::BinaryTree<Type>& obj){
    obj.MapPostOrder(&printForMap<Type>, nullptr);
}

/* ****************************************************************************************************************** */


//*** Select the operation for the structure ***//
int& selectActionStructure(int& todo){

    std::cout<<"\n*******************************************************************************"<<std::endl;
    std::cout<<"@SELEZIONA L'OPERAZIONE DIGITANDO IL NUMERO DI RIFERIMENTO"<<std::endl;
    std::cout<<"    [1] VISUALIZZAZIONE IN AMPIEZZA (FUNZIONE MAP)"<<std::endl;
    std::cout<<"    [2] VISUALIZZAZIONE IN PRE-ORDINE (FUNZIONE MAP)"<<std::endl;
    std::cout<<"    [3] VISUALIZZAZIONE IN IN-ORDINE (FUNZIONE MAP)"<<std::endl;
    std::cout<<"    [4] VISUALIZZAZIONE IN POST-ORDINE (FUNZIONE MAP)"<<std::endl;
    std::cout<<"    [5] CONTROLLO DI ESISTENZA DI UN VALORE"<<std::endl;
    std::cout<<"    [6] FUNZIONALITA' PREVISTA PER IL TIPO DELLA STRUTTURA (FUNZIONE FOLD)"<<std::endl;
    std::cout<<"    [7] APPLICAZIONE DI FUNZIONALITA'"<<std::endl;
    std::cout<<"    [8] FUNZIONALITA' DI LIBRERIA PREVISTE PER LA STRUTTURA"<<std::endl;
    std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRINCIPALE"<<std::endl;
    std::cout<<"@"; std::cin>>todo;
    return todo;
}

/* ****************************************************************************************************************** */

//*** Generator for integers ***//
void generatorBTInteger(const ulong& dimension, lasd::Vector<int>& vector_int){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        vector_int[i] = dist(gen);
    }
}

//*** Generator for floats ***//
void generatorBTFloat(const ulong& dimension, lasd::Vector<float>& vector_float){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        vector_float[i] = dist(gen);
    }
}

//*** Generator for strings ***//
void generatorBTString(const ulong& dimension, lasd::Vector<std::string>& vector_string){
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
        vector_string[i] = s[i];
    }
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
                return 0;
            default:
                std::cout<<"*** SELEZIONE NON VALIDA DEL TIPO ***"<<std::endl;
                break;
        }
    }while(select_typestructure != 0);
    return select_typestructure;
}

/* ****************************************************************************************************************** */

template <typename Type>
void printSubtree(typename lasd::BinaryTree<Type>::Node* root, const std::string& prefix)
{
    if (root == nullptr)
    {
        return;
    }
    if (!root->HasLeftChild() && !root->HasRightChild())
    {
        return;
    }
    std::cout << prefix;
    std::cout << ((root->HasLeftChild()  && root->HasRightChild()) ? "├── " : "");
    std::cout << ((!root->HasLeftChild() && root->HasRightChild()) ? "└── " : "");

    if (root->HasRightChild())
    {
        bool printStrand = (root->HasLeftChild() && root->HasRightChild() && (root->RightChild().HasRightChild() || root->RightChild().HasLeftChild()));
        std::string newPrefix = prefix + (printStrand ? "│   " : "    ");
        std::cout << root->RightChild().Element() << std::endl;
        printSubtree<Type>(&root->RightChild(), newPrefix);
    }

    if (root->HasLeftChild())
    {
        std::cout << (root->HasRightChild() ? prefix : "") << "└── " << root->LeftChild().Element() << std::endl;
        printSubtree<Type>(&root->LeftChild(), prefix + "    ");
    }
}

template <typename Type>
void printTree(typename lasd::BinaryTree<Type>::Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->Element() << std::endl;
    printSubtree<Type>(root, "");
    std::cout << std::endl;
}

/* ****************************************************************************************************************** */

void start() {
    int select_structure = -1;
    int type_structure = -1;
    ulong dimension = 0;
    int num = -1;
    int todo = -1;
    do {
        std::cout << "\n***************************** BENVENUTO NEL MENU' *****************************" << std::endl;
        std::cout << "@SELEZIONA LA STRUTTURA DIGITANDO IL NUMERO DI RIFERIMENTO" << std::endl;
        std::cout << "    [1] BINARYTREE VECTOR" << std::endl;
        std::cout << "    [2] BINARYTREE LINKEDLIST" << std::endl;
        std::cout << "    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE" << std::endl;
        std::cout << "@";
        std::cin >> select_structure;
        switch (select_structure) {
            case 1:
                std::cout << ">>> HAI SELEZIONATO BINARYTREE VECTOR <<<" << std::endl;
                type_structure = selectTypeStructure();
                if (type_structure != 0) {
                    selectSizeStructure(dimension);
                    if (type_structure == 1) { //********************************BTVEC INTEGER
                        lasd::Vector<int> vector_int(dimension);
                        generatorBTInteger(dimension, vector_int);
                        lasd::BinaryTreeVec<int> btvec_int(vector_int);
                        std::cout<<std::endl;
                        printTree<int>(&btvec_int.Root());

                        do {
                            switch (todo = selectActionStructure(todo)) {
                                case 1: //MapBreadth
                                    viewInAmpiezzaMap(btvec_int);
                                    break;

                                case 2: //MaPreOrder
                                    viewInPreOrdineMap(btvec_int);
                                    break;

                                case 3: //MapInOrder
                                    viewInInOrdineMap(btvec_int);
                                    break;

                                case 4: //MapPostOrder
                                    viewInPostOrdineMap(btvec_int);
                                    break;

                                case 5: //Exists
                                    checkTheExistenceInteger(btvec_int);
                                    break;

                                case 6: //Funzionalità FOLD
                                    operationForStructureTypeFoldInteger(btvec_int, num);
                                    break;

                                case 7: //Applicazione di una funzionalità
                                    operationForStructureTypeMapInteger(btvec_int);
                                    break;

                                case 8: //Funzionalità di libreria punto 3
                                    selectFunctionLibrary(btvec_int);
                                    break;
                                case 0:
                                    return;
                            }
                        } while (todo != 0);
                    } else if (type_structure == 2) { //************************BTVEC FLOAT
                        lasd::Vector<float> vector_float(dimension);
                        generatorBTFloat(dimension, vector_float);
                        lasd::BinaryTreeVec<float> btvec_float(vector_float);
                        std::cout<<std::endl;
                        printTree<float>(&btvec_float.Root());
                        do {
                            switch (todo = selectActionStructure(todo)) {
                                case 1: //MapBreadth
                                    viewInAmpiezzaMap(btvec_float);
                                    break;

                                case 2: //MaPreOrder
                                    viewInPreOrdineMap(btvec_float);
                                    break;

                                case 3: //MapInOrder
                                    viewInInOrdineMap(btvec_float);
                                    break;

                                case 4: //MapPostOrder
                                    viewInPostOrdineMap(btvec_float);
                                    break;

                                case 5: //Exists
                                    checkTheExistenceFloat(btvec_float);
                                    break;

                                case 6: //Funzionalità FOLD
                                    operationForStructureTypeFoldFloat(btvec_float, num);
                                    break;

                                case 7: //Applicazione di una funzionalità
                                    operationForStructureTypeMapFloat(btvec_float);
                                    break;

                                case 8: //Funzionalità di libreria punto 3
                                    selectFunctionLibrary(btvec_float);
                                    break;
                                case 0:
                                    return;
                            }
                        } while (todo != 0);

                    } else if (type_structure == 3) { //*************************BTVEC STRING
                        lasd::Vector<std::string> vector_string(dimension);
                        generatorBTString(dimension, vector_string);
                        lasd::BinaryTreeVec<std::string> btvec_string(vector_string);
                        std::cout<<std::endl;
                        printTree<std::string>(&btvec_string.Root());
                        do {
                            switch (todo = selectActionStructure(todo)) {
                                case 1: //MapBreadth
                                    viewInAmpiezzaMap(btvec_string);
                                    break;

                                case 2: //MaPreOrder
                                    viewInPreOrdineMap(btvec_string);
                                    break;

                                case 3: //MapInOrder
                                    viewInInOrdineMap(btvec_string);
                                    break;

                                case 4: //MapPostOrder
                                    viewInPostOrdineMap(btvec_string);
                                    break;

                                case 5: //Exists
                                    checkTheExistanceString(btvec_string);
                                    break;

                                case 6: //Funzionalità FOLD
                                    operationForStructureTypeFoldString(btvec_string, num);
                                    break;

                                case 7: //Applicazione di una funzionalità
                                    operationForStructureTypeMapString(btvec_string);
                                    break;

                                case 8: //Funzionalità di libreria punto 3
                                    selectFunctionLibrary(btvec_string);
                                    break;
                                case 0:
                                    return;
                            }
                        } while (todo != 0);
                    }
            case 2:
                std::cout << ">>> HAI SELEZIONATO BINARYTREE LINK <<<" << std::endl;
                type_structure = selectTypeStructure();
                selectSizeStructure(dimension);
                if (type_structure == 1) { //**********************************BTLNK INTEGER
                    lasd::Vector<int> vector_int(dimension);
                    generatorBTInteger(dimension, vector_int);
                    lasd::BinaryTreeLnk<int> btlnk_int(vector_int);
                    std::cout<<std::endl;
                    printTree<int>(&btlnk_int.Root());
                    do {
                        switch (todo = selectActionStructure(todo)) {
                            case 1: //MapBreadth
                                viewInAmpiezzaMap(btlnk_int);
                                break;

                            case 2: //MaPreOrder
                                viewInPreOrdineMap(btlnk_int);
                                break;

                            case 3: //MapInOrder
                                viewInInOrdineMap(btlnk_int);
                                break;

                            case 4: //MapPostOrder
                                viewInPostOrdineMap(btlnk_int);
                                break;

                            case 5: //Exists
                                checkTheExistenceInteger(btlnk_int);
                                break;

                            case 6: //Funzionalità FOLD
                                operationForStructureTypeFoldInteger(btlnk_int, num);
                                break;

                            case 7: //Applicazione di una funzionalità
                                operationForStructureTypeMapInteger(btlnk_int);
                                break;

                            case 8: //Funzionalità di libreria punto 3
                                selectFunctionLibrary(btlnk_int);
                                break;

                            case 0:
                                return;
                             }
                            } while (todo != 0);
                } else if (type_structure == 2) { //***********************************BTLNK FLOAT
                    lasd::Vector<float> vector_float(dimension);
                    generatorBTFloat(dimension, vector_float);
                    lasd::BinaryTreeLnk<float> btlnk_float(vector_float);
                    std::cout<<std::endl;
                    printTree<float>(&btlnk_float.Root());
                    do {
                        switch (todo = selectActionStructure(todo)) {
                            case 1: //MapBreadth
                                viewInAmpiezzaMap(btlnk_float);
                                break;

                            case 2: //MaPreOrder
                                viewInPreOrdineMap(btlnk_float);
                                break;

                            case 3: //MapInOrder
                                viewInInOrdineMap(btlnk_float);
                                break;

                            case 4: //MapPostOrder
                                viewInPostOrdineMap(btlnk_float);
                                break;

                            case 5: //Exists
                                checkTheExistenceFloat(btlnk_float);
                                break;

                            case 6: //Funzionalità FOLD
                                operationForStructureTypeFoldFloat(btlnk_float, num);
                                break;

                            case 7: //Applicazione di una funzionalità
                                operationForStructureTypeMapFloat(btlnk_float);
                                break;

                            case 8: //Funzionalità di libreria punto 3
                                selectFunctionLibrary(btlnk_float);
                                break;
                            case 0:
                                return;
                            }
                        } while (todo != 0);

                } else if (type_structure == 3) { //BTLNK STRING****************************************************
                    lasd::Vector<std::string> vector_string(dimension);
                    generatorBTString(dimension, vector_string);
                    lasd::BinaryTreeLnk<std::string> btlnk_string(vector_string);
                    std::cout<<std::endl;
                    printTree<std::string>(&btlnk_string.Root());
                    do {
                        switch (todo = selectActionStructure(todo)) {
                            case 1: //MapBreadth
                                viewInAmpiezzaMap(btlnk_string);
                                break;

                            case 2: //MaPreOrder
                                viewInPreOrdineMap(btlnk_string);
                                break;

                            case 3: //MapInOrder
                                viewInInOrdineMap(btlnk_string);
                                break;

                            case 4: //MapPostOrder
                                viewInPostOrdineMap(btlnk_string);
                                break;

                            case 5: //Exists
                                checkTheExistanceString(btlnk_string);
                                break;

                            case 6: //Funzionalità FOLD
                                operationForStructureTypeFoldString(btlnk_string, num);
                                break;

                            case 7: //Applicazione di una funzionalità
                                operationForStructureTypeMapString(btlnk_string);
                                break;

                            case 8: //Funzionalità di libreria punto 3
                                selectFunctionLibrary(btlnk_string);
                                break;

                            case 0:
                                return;
                            }
                        } while (todo != 0);
                    }
                }
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    } while (std::cin.fail() || select_structure != 0);
}

