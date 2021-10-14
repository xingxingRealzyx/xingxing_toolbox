#include <highpass_filter.h>


HighPassFilter::HighPassFilter(float cutFrq, float sampleFrq)
{
    _cutFrq = cutFrq;
    _sampleFrq = sampleFrq;
    _Vi_p = 0.0f;
    _Vo_p = 0.0f;
    _direct = false;
}

HighPassFilter::HighPassFilter(float cof)
{
    _cof = cof;
    _Vi_p = 0.0f;
    _Vo_p = 0.0f;
    _direct = true;
}

HighPassFilter::~HighPassFilter()
{

}

void HighPassFilter::run(float *Vi, float *Vo)
{
    if (_direct)
    {
        *Vo = ((*Vi) - _Vi_p + _Vo_p) * _cof;

    } else {
        float RC, cof;
        RC = (float)1.0/2.0/PI/_cutFrq;
        cof = RC/(RC + 1/_sampleFrq);
        *Vo = ((*Vi) - _Vi_p + _Vo_p) * cof;
    }
    // update
    _Vo_p = *Vo;
    _Vi_p = *Vi;
    
}