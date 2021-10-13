#ifndef __LOWPASS_FILTER_H__
#define __LOWPASS_FILTER_H__

#include <filter.h>

class LowPassFilter : public Filter {

public:
    
    LowPassFilter(float cutFrq, uint32_t sampleFrq); // 低通滤波器截止频率
    LowPassFilter(float cof); // 低通滤波器系数
    ~LowPassFilter();

    void run(int16_t *Vi, int16_t *Vo);
    

private:

    uint32_t _sampleFrq;
    float _cutFrq;
    float _cof;
    int16_t _Vo_p;
    bool _direct;

};


#endif /* __LOWPASS_FILTER_H__ */
