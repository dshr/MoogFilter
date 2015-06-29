//
//  MoogFilter.h
//  MoogFilter
//
//  Created by Desislav Hristov on 26/03/2015.
//
//

#ifndef __MoogFilter__MoogFilter__
#define __MoogFilter__MoogFilter__

#include <stdio.h>
#include <math.h>

class MoogFilter {
	float frequency;
	float g;
	float resonance;
	float drive;
	int sampleRate;
	
	float y_a;
	float y_b;
	float y_c;
	float y_d;
	float y_d_1;
	
public:
	MoogFilter();
	~MoogFilter();
	void processSamples(float *samples, int numSamples);
	
	float getFrequency();
	float getResonance();
	float getDrive();
	
	void setFrequency(float f);
	void setResonance(float r);
	void setSampleRate(int s);
	void setDrive(float d);
};

#endif /* defined(__MoogFilter__MoogFilter__) */
