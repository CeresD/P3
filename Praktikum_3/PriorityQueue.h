//
// Created by ceres on 01.05.18.
//

#ifndef PRAKTIKUM_2_PRIORITYQUEUE_H
#define PRAKTIKUM_2_PRIORITYQUEUE_H


#include <string>
#include <vector>

template<typename T>
class PriorityQueue {

    typedef struct Entry {

        T value;
        float priority;
    } pqentry_t;

    // Dynamic Array from the STL
    std::vector<pqentry_t> entries;

    // Helper methods
    int getLeftChild(int i) { return 2*i + 1; }
    int getRightChild(int i) { return 2*i + 2; }
    int getParent(int i) { return (i-1) / 2; }

    bool hasLeftChild(int i) { return getLeftChild(i) < entries.size(); }
    bool hasRightChild(int i) { return getRightChild(i) < entries.size(); }
    bool hasParent(int i) { return getParent(i) >= 0; }

    void swap(int indexA, int indexB);

    void heapifyUp(int index);
    void heapifyDown(int index);

public:

    PriorityQueue<T>();
    ~PriorityQueue();

    void insert(T value, float priority);
    T extractMin(void);
    void decreaseKey(T, float priority);
    void remove(T);
    bool isEmpty();

    // Debug
    void printQueue();
};


#endif //PRAKTIKUM_2_PRIORITYQUEUE_H
