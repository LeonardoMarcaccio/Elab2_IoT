#ifndef _LOADINGBAR_
#define _LOADINGBAR_

class LoadingBar {
    private:
        unsigned long start;
        unsigned long currentValue;
        unsigned long end;
        unsigned long currentPercentage;
        unsigned long blockPercentage;
        unsigned long barSize;
        bool changed = true;
        String cache;
        unsigned long calculatePercentage(unsigned long start, unsigned long value, unsigned long end);
    public:
        LoadingBar(unsigned long start, unsigned long currentValue, unsigned long end,
            unsigned long barSize);
        void setCurrentValue(unsigned long currentValue);
        void forcePercentage(unsigned long percentage);
        unsigned long getPercentage();
        String getLoadingBar();
};
#endif
