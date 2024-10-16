
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
#include "../matrix/vec/matrixvec.hpp"
#include "../matrix/csr/matrixcsr.hpp"

/* ************************************************************************** */

template <typename Type>
void colResize(lasd::Matrix<Type>& matr);

template <typename Type>
void rowResize(lasd::Matrix<Type>& matr);

/* ************************************************************************** */

template <typename Type>
void checkCell(lasd::Matrix<Type>& matr);

template <typename Type>
void accessNotConstCell(lasd::Matrix<Type>& matr);

template <typename Type>
void accessConstCell(const lasd::Matrix<Type>& matr);

template <typename Type>
void selectFunctionLibrary(lasd::Matrix<Type>&matr);

/* ************************************************************************** */

template <typename Type>
void dueEnneElements(Type& elem, void* par);

template <typename Type>
void minusEnneCubeElements(Type& elem, void* par);

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
void viewInPreOrdineMap(lasd::Matrix<Type>& obj);

template <typename Type>
void viewInPostOrdineMap(lasd::Matrix<Type>& obj);

/* ************************************************************************** */

template <typename Type>
void printForMap(Type& elem, void* par);

template<typename Type>
void viewAllElementsMap(lasd::MappableContainer<Type>& obj);

/* ************************************************************************** */

void generatorMatrInteger(const ulong& rownum, const ulong& colnum, lasd::Matrix<int>& matr);
void generatorMatrFloat(const ulong& rownum, const ulong& colnum, lasd::Matrix<float>& matr);
void generatorMatrString(const ulong& rownum, const ulong& colnum, lasd::Matrix<std::string>& matr);

/* ************************************************************************** */

int& selectActionStructure(int& todo);

ulong& selectSizeStructureCol(ulong& colnum);

ulong& selectSizeStructureRow(ulong& rownum);

int selectTypeStructure();

void start();
/* ************************************************************************** */

#endif
