# DataStructures_Toolkit.h
A comprehensive, header-only, generic C++ library of fundamental data structures and algorithms. This toolkit is designed to be a reusable and easy-to-integrate solution for various programming needs.

**Author:** Rishikesh Venkat Shinde  
**Version:** 1.0.0  
**License:** MIT

---

## 🌟 Overview

`DataStructures_Toolkit.h` provides a collection of the most commonly used data structures and algorithms, all implemented in a generic, template-based fashion. This means they can be used with any data type (`int`, `float`, `char`, `double`, or custom objects) without modification. The entire library is contained within a single header file for maximum portability and ease of use.

## ✨ Features

The toolkit is organized into several key components:

### 1. Core Data Structures

A robust implementation of various linear and non-linear data structures.

| Structure                   | Description                                          | Key Operations                                           |
| --------------------------- | ---------------------------------------------------- | -------------------------------------------------------- |
| **SinglyLL** | Singly Linear Linked List                            | `InsertFirst`, `InsertLast`, `InsertAtPos`, `Delete...`  |
| **DoublyLL** | Doubly Linear Linked List                            | `InsertFirst`, `InsertLast`, `InsertAtPos`, `Delete...`  |
| **SinglyCLL** | Singly Circular Linked List                          | `InsertFirst`, `InsertLast`, `InsertAtPos`, `Delete...`  |
| **DoublyCLL** | Doubly Circular Linked List                          | `InsertFirst`, `InsertLast`, `InsertAtPos`, `Delete...`  |
| **StackX** | LIFO Stack (implemented using a linked list)         | `Push`, `Pop`                                            |
| **QueueX** | FIFO Queue (implemented using a linked list)         | `Enqueue`, `Dequeue`                                     |
| **BST** | Binary Search Tree                                   | `Insert`, `Search`, `CountLeaf`, `CountParent`           |

### 2. Algorithms

Implementations of fundamental sorting and searching algorithms operating on arrays.

| Class       | Algorithm             | Description                                          |
| ----------- | --------------------- | ---------------------------------------------------- |
| **ArrayX** | **Bubble Sort** | Simple comparison-based sorting algorithm.           |
|             | **Selection Sort** | In-place comparison sort.                            |
|             | **Insertion Sort** | Builds the final sorted array one item at a time.    |
| **ArrayXX** | **Linear Search** | Sequential search for an element.                    |
|             | **Binary Search** | Efficiently finds an item in a **sorted** array.     |

### 3. Specialized Utility Classes

These classes are built upon the linked list structure to perform specific data analysis tasks.

| Class                 | Description                                                  | Key Operations                                                   |
| --------------------- | ------------------------------------------------------------ | ---------------------------------------------------------------- |
| **DataSequence** | Performs basic statistical analysis on a list of elements.   | `FindFirst`, `FindLast`, `Aggregate (Sum)`, `FindMax`, `FindMin` |
| **NumericCollection** | Performs number-theoretic analysis on a list of integers.    | `DisplayPerfect`, `DisplayPrime`, `SumEven`, `SecondLargest`     |
| **DigitAnalyzer** | Performs digit-level manipulation and analysis of integers.  | `DisplayReverse`, `DisplayPalindrome`, `DisplaySmallestDigits`   |

## 🚀 How to Use

Since this is a header-only library, there is no need for separate compilation or linking. Simply include the `DataStructures_Toolkit.h` file in your C++ project.

### Example: Using the SinglyLL Class

Here is a simple example of how to use the Singly Linear Linked List class to store and manipulate integers.

```cpp
#include <iostream>
#include "DataStructures_Toolkit.h" // Make sure the header is in the same directory

int main()
{
    // Create an instance of SinglyLL for integers
    SinglyLL<int> list;

    // Insert elements
    list.InsertFirst(50);
    list.InsertFirst(40);
    list.InsertLast(60);
    list.InsertAtPos(45, 2); // Insert 45 at position 2

    // Display the list
    std::cout << "Elements in the list: ";
    list.Display(); // Expected output: | 40 |->| 45 |->| 50 |->| 60 |->NULL

    // Display the count
    std::cout << "Number of nodes: " << list.Count() << std::endl; // Expected output: 4

    // Delete an element
    list.DeleteAtPos(2);
    std::cout << "After deleting element at position 2: ";
    list.Display(); // Expected output: | 40 |->| 50 |->| 60 |->NULL

    return 0;
}
