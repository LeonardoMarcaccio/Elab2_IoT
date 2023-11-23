#ifndef _ARRAYLIST_
#define _ARRAYLIST_

template <typename T>
class List {
    virtual Iterator<T> iterator() = 0;
};
#endif
