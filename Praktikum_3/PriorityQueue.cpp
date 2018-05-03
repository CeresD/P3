//
// Created by ceres on 01.05.18.
//

#include <iostream>
#include <iomanip>
#include "PriorityQueue.h"
#include "Exception.h"
#include "Node.h"

template<typename T>
PriorityQueue<T>::PriorityQueue() {
    // I don't need that, tho.
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {

    entries.clear();
}

template<typename T>
void PriorityQueue<T>::swap(int indexA, int indexB) {

    pqentry_t entry;

    entry = entries[indexA];
    entries[indexA] = entries[indexB];
    entries[indexB] = entry;
}

template<typename T>
void PriorityQueue<T>::heapifyUp(int index) {

    while (hasParent(index) && entries[getParent(index)].priority > entries[index].priority) {
        swap(index, getParent(index));
        index = getParent(index);
    }
}

template<typename T>
void PriorityQueue<T>::heapifyDown(int index) {

    while (hasLeftChild(index)) {

        int smallerChildIndex = getLeftChild(index);

        if (hasRightChild(index) && entries[getRightChild(index)].priority < entries[getLeftChild(index)].priority) {
            smallerChildIndex = getRightChild(index);
        }

        if (entries[index].priority < entries[smallerChildIndex].priority) {
            break;
        } else {
            swap(index, smallerChildIndex);
        }

        index = smallerChildIndex;
    }
}

template<typename T>
void PriorityQueue<T>::insert(T value, float priority) {

    pqentry_t entry;

    entry.priority = priority;
    entry.value = value;

    entries.push_back(entry);

    heapifyUp(entries.size() - 1);
}

template<typename T>
T PriorityQueue<T>::extractMin() {

    try {
        if (isEmpty()) {
            throw Exception("Queue is empty! - extractMin()");
        }
    } catch (Exception e) {
        std::cout << e.toString() << std::endl;
    }

    T extractedValue;

    extractedValue = entries[0].value;
    entries.pop_back();

    heapifyDown(0);

    return extractedValue;
}

template<typename T>
void PriorityQueue<T>::decreaseKey(T value, float priority) {


    try {
        if (isEmpty()) {
            throw Exception("Can't decrease a key if queue is empty! - decreaseKey()/empty queue");
        }

        int index;

        for (index = 0; index < entries.size(); index++) {
            if (entries[index].value == value) {
                if (entries[index].priority > priority) {
                    entries[index].priority = priority;
                    heapifyUp(index);

                    return;
                } else
                    throw Exception("Key is already smaller - decreaseKey()");
            }
        }
        throw Exception("No value found! - decreaseKey()");
    } catch (Exception e) {
        std::cout << e.toString() << std::endl;
    }

}

template<typename T>
void PriorityQueue<T>::remove(T value) {

    try {
        if (isEmpty()) {
            throw Exception("Queue is empty! - remove()");
        }
    } catch (Exception e) {
        std::cout << e.toString() << std::endl;
    }

    int index;

    try {
        for (index = 0; index < entries.size(); index++) {
            if (entries[index].value == value) {

                entries[index].value = entries[entries.size() - 1].value;
                entries.pop_back();
                heapifyUp(index);

                return;
            }
        }

        throw Exception("No value found! - remove()");
    } catch (Exception e) {
        std::cout << e.toString() << std::endl;
    }

}

template<typename T>
bool PriorityQueue<T>::isEmpty() {

    return (entries.empty());
}

template<typename T>
void PriorityQueue<T>::printQueue() {

    for (pqentry_t &pq : entries) {

        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << std::setw(6) << pq.priority << " - " << pq.value << std::endl;
    }
}

// Template definitions
template class PriorityQueue<std::string>;
template class PriorityQueue<Node*>;
template class PriorityQueue<int>;
template class PriorityQueue<float>;
template class PriorityQueue<long>;
template class PriorityQueue<char>;
