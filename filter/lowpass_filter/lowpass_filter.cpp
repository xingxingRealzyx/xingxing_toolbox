#include <math.h>
#include <lowpass_filter.h>


LowPassFilter::LowPassFilter(float cutFrq, uint32_t sampleFrq)
{
    _cutFrq = cutFrq;
    _sampleFrq = sampleFrq;
    _cof = 0.0f;
    _Vo_p = 0.0f;
    _direct = false;
}

LowPassFilter::LowPassFilter(float cof)
{
    _cof = cof;
    _Vo_p = 0.0f;
    _direct = true;
}

LowPassFilter::~LowPassFilter()
{

}

void LowPassFilter::run(int16_t *Vi, int16_t *Vo)
{
    if (_direct)
    {
        *Vo = _cof*(*Vi) + (1-_cof)*_Vo_p; 
    } else {
        float RC, Cof1, Cof2;
	
        RC = (float)1.0/2.0/PI/_cutFrq;
        Cof1 = 1/(1+RC*_sampleFrq);
        Cof2 = RC*_sampleFrq/(1+RC*_sampleFrq);
        *Vo = Cof1 * (*Vi) + Cof2 * (_Vo_p);	
    }
    // update
    _Vo_p = *Vo;
}
