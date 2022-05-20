#pragma once

#include <cstddef>
#include <iostream>
#include "DynamicArray.hpp"
#include "Sequence.hpp"

template <class T> class ArraySequence : Sequence<T> 
{
private:

    DynamicArray<T>* buffer;

public:
    ArraySequence(T* items, size_t count) {
        buffer = new DynamicArray<T>(items, count);
    };

    ArraySequence () {
        buffer = new DynamicArray<T>();
    };

    ArraySequence (ArraySequence<T> &list) {
        this->buffer = new DynamicArray<T>(list.GetLength());
		for (int i = 0; i < list.GetLength(); i++)
			this->buffer->Set(list.Get(i), i);
    };

    ~ArraySequence () {
        delete buffer;
    };

    T GetFirst() override {
        return this->buffer->GetItem(0);
    };

    T GetLast() override {
        return this->buffer->GetItem(this->GetLength() - 1);
    };

    T Get(int index) override {
        return this->buffer->GetItem(index);
    };

    int GetLength() override {
        return this->buffer->GetSize();
    };

    void Print() override {
        this->buffer->PrintArray();
    }

    void Append(T item) override {
        this->buffer->Resize(this->GetLength() + 1);
        this->buffer->Set(this->GetLength() - 1, item);
    };

    void Prepend(T item) override {
        this->buffer->Resize(this->GetLength() + 1);
        for (int i = this->GetLength() - 1; i > 0; i--) {
            T tmp = this->Get(i);
            this->buffer->Set(i, this->Get(i-1));
            this->buffer->Set(i-1, tmp);            
        }
        this->buffer->Set(0, item);
    };

    void InsertAt(T item, int index) override {
        this->buffer->Set(index, item);
    };
};
