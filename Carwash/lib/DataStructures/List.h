#ifndef _LIST_
#define _LIST_

#include <Iterator.h>

template <typename T>
class List {
    virtual Iterator<T> iterator() = 0;
};
#endif
