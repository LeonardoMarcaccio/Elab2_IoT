#ifndef _ARRAYLIST_
#define _ARRAYLIST_
template <typename T>
class ArrayList {
    private:
        T** dynamicVect;
    public:
        ArrayList(T* elementArray, int size);
        void add(T* element);
        T* get(int index);
        void set(int index);
        void clear();
        void remove(T* element);
        bool isPresent(T  * element);
        ~ArrayList()
};
#endif
