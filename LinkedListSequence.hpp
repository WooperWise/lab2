#pragma once

#include <iostream>
#include "LinkedList.hpp"
#include "Sequence.hpp"

template <class T> class LinkedListSequence : Sequence<T> 
{
private:

    LinkedList<T> *buffer;

public:

    LinkedListSequence (T* items, int count) {buffer = new LinkedList<T>(items, count);};

    LinkedListSequence () {buffer = new LinkedList<T>();};

    LinkedListSequence (LinkedListSequence<T> & list){
        buffer = new LinkedList<T>();
        for (int i = 0; i < list.GetLength(); i++)
			this->buffer->Append(list.Get(i));
    };

    ~LinkedListSequence () {
        delete buffer;
    }

    T GetFirst() override {
        return this->buffer->GetFirst();
    };

    T GetLast() override {
        return this->buffer->GetLast();
    };

    T Get(int index) override {
        return this->buffer->GetItem(index);
    };

    int GetLength() override {
        return this->buffer->GetLength();
    };

    void Print() override {
        this->buffer->PrintList();
    };

    void Append(T item) override {
        this->buffer->Append(item);
    };

    void Prepend(T item) override {
        this->buffer->Prepend(item);
    };

    void InsertAt(T item, int index) override {
        this->buffer->InsertAt(item, index);
    };

    T &operator[](size_t index) {
		return Get(index);
	};

    LinkedListSequence<T>* GetSubList (int startIndex, int endIndex) {
		LinkedList<T> *subList = this->buffer->GetSubList(startIndex, endIndex);
		size_t count = endIndex - startIndex + 1;
        T items[count];
        for (int i = 0; i < subList->GetLength(); i++)
			items[i] = subList->GetItem(i);
        delete subList;
		LinkedListSequence<T>* tmpList = new LinkedListSequence<T>(items, count);
        return tmpList;
	};

    void Concat(LinkedListSequence<T> *list) {
        for (int i = 0; i < list->GetLength(); i++) {
            this->buffer->Append(list->Get(i));
        }        
    };

};