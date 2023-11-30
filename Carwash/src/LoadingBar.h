#ifndef _LOADINGBAR_
#define _LOADINGBAR_

class LoadingBar {
    private:
        uint8_t start;
        uint8_t currentValue;
        uint8_t end;
        uint8_t currentPercentage;
        uint8_t blockPercentage;
        uint8_t barSize;
        bool changed = true;
        String cache;
        uint8_t calculatePercentage(uint8_t start, uint8_t value, uint8_t end);
    public:
        LoadingBar(uint8_t start, uint8_t currentValue, uint8_t end,
            uint8_t barSize);
        void setCurrentValue(uint8_t currentValue);
        void forcePercentage(uint8_t percentage);
        uint8_t getPercentage();
        String getLoadingBar();
};
#endif
