#pragma once

#include <cstring>
#include <cstdlib>
#include <iostream>

template <class T> class LinkedList 
{
private:

    struct node { 
        T data;
        node* next;
    };

    struct linkedList {
        node* head;
        node* tail;
        size_t count;
    };

    linkedList list = {nullptr, nullptr, 0};

public:

    // Создание

    LinkedList () {};

    LinkedList (T* items, int count) {
        if (count < 0) throw std::runtime_error("Invalid list of size.");
        if (count == 0) return;
        if (list.head == nullptr && count != 0) {
            list.count = count;
            list.head = new node;
            list.head->data = items[0];
            list.head->next = nullptr;
            list.tail = list.head;
            for (int i = 1; i < count; i++) {
                list.tail->next = new node;
                list.tail = list.tail->next;
                list.tail->data = items[i];
                list.tail->next = nullptr;            
            }
        } else {
            for (int i = 0; i < count; i++) {
                list.tail->next = new node;
                list.tail = list.tail->next;
                list.tail->data = items[i];
                list.tail->next = nullptr;            
            }
            list.count += count;
        }
    };

    LinkedList (LinkedList<T>& l) {
        list.head = l.list.head;
        list.tail = l.list.tail;
        list.count = l.list.count;
    };

    ~LinkedList () {
        while (list.head != nullptr) {
            node* timeList = list.head->next;
            delete list.head;
            list.head = timeList;
        }
        list.count = 0;
    };

    // Декомпозиция

    T GetItem (int index) {
        if ((index < 0) || (index >= list.count)) throw std::runtime_error("Index out of range.");

        node* timeList = list.head;
        for (int i = 0; i < index; i++) {
            timeList = timeList->next;
        }
        return timeList->data;
    }

    T GetFirst() {
        if (list.head == nullptr) throw std::runtime_error("Index out of range.");
        return list.head->data;
    };

    T GetLast() {
        if (list.tail == nullptr) throw std::runtime_error("Index out of range.");
        return list.tail->data;    
    };

    T &operator[](int index) {
        if ((index < 0) || (index >= list.count)) throw std::runtime_error("Index out of range.");
        node* timeList = list.head;
        for (int i = 0; i < index; i++) {
            timeList = timeList->next;
        }
        return timeList->data;
    };

    LinkedList<T>* GetSubList(int startIndex, int endIndex) {
        if ((startIndex < 0) || (startIndex >= list.count) || (endIndex < 0) || (endIndex >= list.count) || (startIndex > endIndex)) 
            throw std::runtime_error("Index out of range.");
        size_t count = endIndex - startIndex + 1;
        T items[count];
        node* timeList = list.head;
        for (int i = 0, j = 0; i < list.count; i++) {
            if ((i >= startIndex) && (i <= endIndex)) {
                items[j++] = timeList->data;
            }
            timeList = timeList->next;
        }
        LinkedList<T>* newList = new LinkedList<T>(items, count);
        return newList;
    };

    int GetLength() {return list.count;};

    // Операции

    void Append(T item) {
        list.tail->next = new node;
        list.tail = list.tail->next;
        list.tail->data = item;
        list.tail->next = nullptr;
        list.count++;
    };

    void Prepend(T item) {
        node* timeList = new node;
        timeList->data = item;
        timeList->next = list.head;
        list.head = timeList;
        list.count++;
    };

    void InsertAt(T item, int index) {
        if ((index < 0) || (index >= list.count)) throw std::runtime_error("Index out of range.");

        node* timeList = list.head;
        for (int i = 0; i < index; i++) {
            timeList = timeList->next;
        }
        timeList->data = item;
    };

    LinkedList<T>* Concat(LinkedList<T> *l) {
        l->list.tail->next = list.head;
        l->list.tail = list.tail;
        return l;
    };

    void PrintList () {
        node* timeList = list.head;
        for (int i = 0; i < list.count; i++) {
            std::cout << timeList->data << ' ';
            timeList = timeList->next;
        }
        std::cout << "\n";
    };
};