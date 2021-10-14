#ifndef __LOWPASS_FILTER_H__
#define __LOWPASS_FILTER_H__

#include <filter.h>

class LowPassFilter : public Filter {

public:
    
    LowPassFilter(float cutFrq, float sampleFrq);
    LowPassFilter(float cof);
    ~LowPassFilter();

    void run(float *Vi, float *Vo);
    

private:

    float _sampleFrq;
    float _cutFrq;
    float _cof;
    float _Vo_p;
    bool _direct;

};


#endif /* __LOWPASS_FILTER_H__ */
