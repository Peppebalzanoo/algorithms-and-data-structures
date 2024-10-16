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

/* ************************************************************************** */

template <typename Type>
void startIteratorFunction(lasd::ForwardIterator<Type>&iterator);

int selectTypeIteratorBT(int& type_iter);

template <typename Type>
void selectFunctionLibrary(lasd::BinaryTree<Type>&tree);

/* ************************************************************************** */

template <typename Type>
void triplicationElements(Type& elem, void* par);

template <typename Type>
void cubeElements(Type& elem, void* par);

template <typename Type>
void frontString(Type& elem, void* par);


void operationForStructureTypeMapInteger(lasd::MappableContainer<int>& obj);
void operationForStructureTypeMapFloat(lasd::MappableContainer<float>& obj);
void operationForStructureTypeMapString(lasd::MappableContainer<std::string>& obj);

/* ************************************************************************** */

template <typename Type>
void productIntegers(const Type& elem, const void* dim, void* acc);

template <typename Type>
void sumFloats(const Type& elem, const void* dim, void* acc);

template <typename Type>
void concatenationStrings(const Type& elem, const void* dim, void* acc);



void operationForStructureTypeFoldInteger(lasd::FoldableContainer<int>& obj, int& n);
void operationForStructureTypeFoldFloat(lasd::FoldableContainer<float>& obj, int& n);
void operationForStructureTypeFoldString(lasd::FoldableContainer<std::string>& obj, int& n);

/* ************************************************************************** */

void checkTheExistenceInteger(lasd::TestableContainer<int>& obj);

void checkTheExistenceFloat(lasd::TestableContainer<float>& obj);

void checkTheExistanceString(lasd::TestableContainer<std::string>& obj);

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

template <typename Type>
void printSubtree(typename lasd::BinaryTree<Type>::Node* root, const std::string& prefix);

template <typename Type>
void printTree(typename lasd::BinaryTree<Type>::Node* root);

/* ************************************************************************** */

int& selectActionStructure(int& todo);

ulong& selectSizeStructure(ulong& dimension);

int selectTypeStructure();

void start();

/* ************************************************************************** */

#endif
