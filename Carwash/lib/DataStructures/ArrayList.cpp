#include "ArrayList.h"
#include "Iterator.h"
#include "List.h"
#include <stdlib.h>

template <typename T>
ArrayList<T>::ArrayList() {}
template <typename T>
ArrayList<T>::ArrayList(int initialSize) {
    this->vectPtr = (T**) malloc(sizeof(T*)*initialSize);
    this->allocated = initialSize;
}
template <typename T>
ArrayList<T>::ArrayList(T* elementArray, int size) {
    this->vectPtr = (T**) malloc(sizeof(T*)*size);
    for (int index = 0; index < size; index++) {
        vectPtr[index] = &elementArray[index];
    }
    this->allocated = size;
}

template <typename T>
void ArrayList<T>::add(T* element) {
    if (this->needsRealloc()) {
        this->size++;
        T* tempVect = (T**) realloc(this->vectPtr, sizeof(T*)*(this->size));
        if (tempVect == nullptr) {
            throw 1;
        } else {
            this->vectPtr = tempVect;
        }
    }
}

template<typename T>
T* ArrayList<T>::get(int index) {
    if (this->isInVectorRange(index)) {
        return this->vectPtr[index];
    }
}

template <typename T>
void ArrayList<T>::set(T* element, int index) {
    if (this->isInVectorRange(index)) {
        this->vectPtr[index] = element;
    }
}

template <typename T>
void ArrayList<T>::remove(int index) {
    if (this->isInVectorRange(index)) {
        int idxb = 0;
        this->size--;
        T* tempVect = (T**) malloc(sizeof(T*)*size);
        for (int idxa = 0; idxa < size; idxa++) {
            if (idxb == index) {
                idxb++;
            }
            tempVect[idxa] = this->vectPtr[idxb];
            idxb++;
        }
    }
}

template <typename T>
int ArrayList<T>::listSize() {
    return this->size;
}

template <typename T>
void ArrayList<T>::clear() {
    if (this->allocated != 0) {
        // TODO: check if this can be recursive for arrays of arrays
        free(this->vectPtr);
    }
}

template <typename T>
Iterator<T> ArrayList<T>::iterator() {
    return new Iterator<T>(this->dynamicVect, this->size);
}

template <typename T>
ArrayList<T>::~ArrayList() {
    free(this->vectPtr);
}

template <typename T>
bool ArrayList<T>::needsRealloc() {
    return this->size >= this->allocated;
}

template <typename T>
bool ArrayList<T>::isInVectorRange(int index) {
    return index < this->size && index >= 0;
}
