#ifndef _ITERATOR_
#define _ITERATOR_

template <typename E>
class Iterator {
    private:
        const int length;
        int position;
        E* vector;
    public:
        bool hasNext();
        E* getNext();
};
#endif
