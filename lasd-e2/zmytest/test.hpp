
#ifndef MYTEST_HPP
#define MYTEST_HPP
#include <iostream>
#include <random>
#include <algorithm>
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"

/* ************************************************************************** */
void emptiness(lasd::Container& con);
/* ************************************************************************** */

template <typename Type>
void elementImmediatly(lasd::Queue<Type>& que);

template <typename Type>
void elementImmediatly(lasd::Stack<Type>& stk);

/* ************************************************************************** */

template <typename Type>
void removeFromQueueWithoutRead(lasd::Queue<Type>& que);

template <typename Type>
void removeFromQueueRead(lasd::Queue<Type>& que);

/* ************************************************************************** */

template <typename Type>
void removeFromStackWithoutRead(lasd::Stack<Type>& stk);

template <typename Type>
void removeFromStackRead(lasd::Stack<Type>& stk);

/* ************************************************************************** */

template <typename Type>
void insertInQueue(lasd::Queue<Type>& que);

template<typename Type>
void insertInStack(lasd::Stack<Type>& stk);

/* ************************************************************************** */

void generatorQueueInteger(const ulong& dimension, lasd::Queue<int>& que);
void generatorQueueFloat(const ulong& dimension, lasd::Queue<float>& que);
void generatorQueueString(const ulong& dimension, lasd::Queue<std::string>& que);

void generatorStackInteger(const ulong& dimension, lasd::Stack<int>& stk);
void generatorStackFloat(const ulong& dimension, lasd::Stack<float>& stk);
void generatorStackString(const ulong& dimension, lasd::Stack<std::string>& stk);

/* ************************************************************************** */

int& selectActionStructure(int& todo);

int selectTypeStructure();

void start();

/* ************************************************************************** */

#endif
