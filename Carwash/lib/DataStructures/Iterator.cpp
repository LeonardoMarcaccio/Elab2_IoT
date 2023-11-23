#include "Iterator.h"

template <typename E>
Iterator<E>::Iterator(E* vector, int length) {
    this->vector = vector;
    this->length = length;
}

template <typename E>
bool Iterator<E>::hasNext() {
    return this->position < this->length;
}

template <typename E>
E* Iterator<E>::getNext() {
    if (this.hasNext()) {
        E* element = this->vector[this->position];
        this->position = this->position + 1;
        return element;
    } else {
        return nullptr;
    }
}