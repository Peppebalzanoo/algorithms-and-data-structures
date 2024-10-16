
#ifndef MYTEST_HPP
#define MYTEST_HPP
#include <iostream>
#include <random>
#include <algorithm>
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"



/* ************************************************************************** */
template <typename Type>
void startPredecessSuccess(lasd::BST<Type>& tree);

template <typename Type>
void startMinimumMaximum(lasd::BST<Type>& tree);

template <typename Type>
void selectFunctionLibrary(lasd::BST<Type>&tree);

/* ************************************************************************** */

template <typename Type>
void productIntegers(const Type& elem, const void* dim, void* acc);

template <typename Type>
void sumFloats(const Type& elem, const void* dim, void* acc);

template <typename Type>
void concatenationStrings(const Type& elem, const void* dim, void* acc);

/* ************************************************************************** */
void checkTheExistenceInteger(lasd::TestableContainer<int>& obj);
void checkTheExistenceFloat(lasd::TestableContainer<float>& obj);
void checkTheExistanceString(lasd::TestableContainer<std::string>& obj);
/* ************************************************************************** */

template <typename Type>
void startPredecessSuccess(lasd::BST<Type>&);

template <typename Type>
void startMinimumMaximum(lasd::BST<Type>&);

template <typename Type>
void selectFunctionLibrary(lasd::BST<Type>&tree);

/* ************************************************************************** */

template <typename Type>
void viewInAmpiezzaMap(lasd::BinaryTree<Type>& obj);

template <typename Type>
void viewInPreOrdineMap(lasd::BinaryTree<Type>& obj);

template <typename Type>
void viewInInOrdineMap(lasd::BinaryTree<Type>& obj);

template <typename Type>
void viewInPostOrdineMap(lasd::BinaryTree<Type>& obj);

/* ************************************************************************** */

template <typename Type>
void printForMap(Type& elem, void* par);

template<typename Type>
void viewAllElementsMap(lasd::MappableContainer<Type>& obj);

/* ************************************************************************** */
void generatorBTString(const ulong& dimension, lasd::Vector<std::string>& vec_string);
void generatorBTFloat(const ulong& dimension, lasd::Vector<float>& vector_float);
void generatorBTInteger(const ulong& dimension, lasd::Vector<int>& vec_int);
/* ************************************************************************** */

int& selectActionStructure(int& todo);

ulong& selectSizeStructure(ulong& dimension);

int selectTypeStructure();

void start();

/* ************************************************************************** */

#endif
