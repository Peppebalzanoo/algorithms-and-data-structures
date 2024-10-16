#ifndef MYTEST_HPP
#define MYTEST_HPP
#include <iostream>
#include <random>
#include <algorithm>
#include "../list/list.hpp"
#include "../vector/vector.hpp"

/* ****************************************************************************************************************** */

template <typename Type>
void resizeVector(lasd::Vector<Type>& vec);

/* ****************************************************************************************************************** */

template <typename Type>
void selectLibraryFunctionList(lasd::List<Type>& lis);

/* ****************************************************************************************************************** */

template <typename Type>
void doublingElements(Type& elem, void* par);

template <typename Type>
void squareElements(Type& elem, void* par);

template <typename Type>
void uppercaseString(Type& elem, void* par);

void operationForStructureTypeMapInteger(lasd::MappableContainer<int>& obj);
void operationForStructureTypeMapFloat(lasd::MappableContainer<float>& obj);
void operationForStructureTypeMapString(lasd::MappableContainer<std::string>& obj);

/* ****************************************************************************************************************** */

template <typename Type>
void sumIntegers(const Type& elem, const void* dim, void* acc);

template <typename Type>
void productFloats(const Type& elem, const void* dim, void* acc);

template <typename Type>
void concatenationStrings(const Type& elem, const void* dim, void* acc);

void operationForStructureTypeFoldInteger(lasd::FoldableContainer<int>& obj, int& n);
void operationForStructureTypeFoldFloat(lasd::FoldableContainer<float>& obj, int& n);
void operationForStructureTypeFoldString(lasd::FoldableContainer<std::string>& obj, int& n);

/* ****************************************************************************************************************** */

void checkTheExistenceInteger(lasd::TestableContainer<int>& obj);
void checkTheExistenceFloat(lasd::TestableContainer<float>& obj);
void checkTheExistanceString(lasd::TestableContainer<std::string>& obj);

/* ****************************************************************************************************************** */

template <typename Type>
void printForMap(Type &elem, void* par);

template <typename  Type>
void viewAllElementsMap(lasd::MappableContainer<Type>& obj);

/* ****************************************************************************************************************** */

template <typename Type>
void displayElementVecLis(int& todo, lasd::LinearContainer<Type>& obj, int& index);

template <typename Type>
void displayElementAtIndex(int& todo, lasd::LinearContainer<Type>& obj, int& index);

/* ****************************************************************************************************************** */

void generatorVectorInteger(const ulong& dimension, lasd::Vector<int>& vec);
void generatorVectorFloat(const ulong& dimension, lasd::Vector<float>& vec);
void generatorVectorString(const ulong& dimension, lasd::Vector<std::string>& vec);

void generatorListInteger(const ulong& dimension, lasd::List<int>& lis);
void generatorListFloat(const ulong& dimension, lasd::List<float>& lis);
void generatorListString(const ulong& dimension, lasd::List<std::string>& lis);

/* ****************************************************************************************************************** */

int& selectActionStructure(int& todo);

ulong& selectSizeStructure(ulong &dimension);

int selectTypeStructure();

void start();

/* ****************************************************************************************************************** */
#endif