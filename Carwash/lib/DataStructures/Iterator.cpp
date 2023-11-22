#include "Iterator.h"

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