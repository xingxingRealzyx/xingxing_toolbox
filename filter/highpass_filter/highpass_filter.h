#ifndef __HIGHPASS_FILTER_H__
#define __HIGHPASS_FILTER_H__

#include <filter.h>

class HighPassFilter : public Filter {

public:
    HighPassFilter(float cutFrq, float sampleFrq);
    HighPassFilter(float cof);
    ~HighPassFilter();

    void run(float *Vi, float *Vo);
private:
    float _cutFrq;
    float _sampleFrq;
    float _cof;
    float _Vi_p;
    float _Vo_p;
    bool _direct;
};

#endif /* __HIGHPASS_FILTER_H__ */