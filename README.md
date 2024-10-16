# 📚 Fundamental Data Structures and Algorithms in C++
This project involves the implementation "from scratch" of fundamental algorithms and data structures studied in our Algorithms and Data Structures course. The project is implemented in C++ and utilizes templates for managing generic data types. The project consists of five exercises, each focusing on different data structures and their functionalities.

## ✨ Exercises Overview

### 🥇 Exercise 1: Dynamic Arrays and Lists
- **Objective**: Implement two libraries for managing dynamic data structures: vectors and lists for generic data types (integers, floats, strings, structs, etc.).
- **Key Functionalities**:
  1. Construction and destruction of data structures.
  2. Assignment and comparison operations between instances.
  3. Common operations (non-destructive access to first, last, or specific index elements; checking the existence of a value; applying functions to all elements; fold operations; checking emptiness; reading size; clearing the structure).
  4. Specific vector functions (resizing).
  5. Specific list functions (inserting at head or tail; removing with reading and non-reading of the head element).

### 🥈 Exercise 2: Stacks and Queues
- **Objective**: Implement two libraries for managing dynamic data structures: stacks and queues using previously developed data structures (vectors and lists).
- **Key Functionalities**:
  1. Construction and destruction of data structures.
  2. Assignment and comparison operations.
  3. Common operations (inserting an element; removing, reading, and non-destructive reading of the accessible element; checking emptiness; reading size; clearing the structure).

### 🥉 Exercise 3: Binary Trees
- **Objective**: Implement a library for managing a dynamic binary tree containing generic data types using two concrete representations (node array and node pointers).
- **Key Functionalities**:
  1. Construction and destruction of the data structure.
  2. Assignment and comparison operations between instances.
  3. Specific operations (reading/writing access to node data; checking existence and accessing left/right children; navigation through iterators).
  4. Generic operations (checking the existence of a value; applying functions (breadth-first, pre-order, in-order, post-order) to all elements; fold operations; checking emptiness; reading size; clearing the structure).

### 🏅 Exercise 4: Binary Search Trees
- **Objective**: Implement a library for managing a dynamic binary search tree containing generic data types using explicit pointer representation.
- **Key Functionalities**:
  1. Construction and destruction of the data structure.
  2. Assignment and comparison operations.
  3. Specific operations (inserting/removing elements; reading minimum/maximum or predecessor/successor without destruction).
  4. Generic operations (checking the existence of a value; applying functions (breadth-first, pre-order, in-order, post-order) to all elements; fold operations; checking emptiness; reading size; clearing the structure).

### 🏆 Exercise 5: Dynamic Matrices
- **Objective**: Implement a library for managing a dynamic matrix containing generic data types using two representations (vector serialization and Yale format - compressed sparse row).
- **Key Functionalities**:
  1. Construction and destruction of the data structure.
  2. Assignment and comparison operations.
  3. Specific operations (accessing a cell: checking existence, reading, writing/inserting; resizing).
  4. Generic operations (checking the existence of a value; applying functions (pre-order/post-order) to all elements; fold operations; checking emptiness; reading size; clearing the structure).

## 🛠️ Object-Oriented Programming Concepts in C++

This project is based on several key concepts of Object-Oriented Programming (OOP) in C++:

1. **Encapsulation**: Bundling the data (attributes) and methods (functions) that operate on the data into a single unit or class, restricting access to some of the object's components. This helps to protect the integrity of the data and provides a clear interface for interacting with the objects.

2. **Inheritance**: Allowing one class (derived class) to inherit the properties and methods of another class (base class), promoting code reusability. However, it can lead to complexity if not managed properly and may cause issues with deep inheritance hierarchies.

3. **Polymorphism**: Enabling objects to be treated as instances of their parent class. The two types of polymorphism in C++ are compile-time (function overloading and operator overloading) and run-time (using virtual functions). Polymorphism can introduce difficulties in debugging and maintenance if the code becomes too dynamic.

4. **Abstraction**: Hiding the complex implementation details and exposing only the necessary parts of an object. This simplifies interactions with the objects but may lead to challenges in understanding the underlying system if not documented properly.
