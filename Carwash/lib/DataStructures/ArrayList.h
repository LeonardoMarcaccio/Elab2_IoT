#ifndef _ARRAYLIST_
#define _ARRAYLIST_

#include <List.h>
#include <Iterator.h>

template <typename T>
class ArrayList : public List<T> {
    private:
        T** vectPtr = nullptr;
        int size = 0;
        int allocated = 0;
        bool needsRealloc();
        bool isInVectorRange(int index);
    public:
        ArrayList();
        ArrayList(int initialSize);
        ArrayList(T* elementArray, int size);
        void add(T* element);
        T* get(int index);
        void set(T* element, int index);
        void clear();
        void remove(int index);
        int listSize();
        Iterator<T> iterator() override;
        ~ArrayList();
};
#endif
