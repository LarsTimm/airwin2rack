/* ========================================
 *  PunchyDeluxe - PunchyDeluxe.h
 *  Created 8/12/11 by SPIAdmin 
 *  Copyright (c) Airwindows, Airwindows uses the MIT license
 * ======================================== */

#ifndef __PunchyDeluxe_PunchyDeluxe_H
#define __PunchyDeluxe_PunchyDeluxe_H

#ifndef __audioeffect__
#include "../airwin_consolidated_base.h"
#endif

#include <set>
#include <string>
#include <math.h>

namespace airwinconsolidated::PunchyDeluxe {
enum {
	kParamA =0,
	kParamB =1,
	kParamC =2,
	kParamD =3,
	kParamE =4,
	kParamF =5,
	kParamG =6,
	kParamH =7,
	kParamI =8,
	kParamJ =9,
  kNumParameters = 10
}; //

const int kNumPrograms = 0;
const int kNumInputs = 2;
const int kNumOutputs = 2;
const unsigned long kUniqueId = 'pudx';    //Change this to what the AU identity is!

class PunchyDeluxe : 
    public AudioEffectX 
{
public:
    PunchyDeluxe(audioMasterCallback audioMaster);
    ~PunchyDeluxe();
    virtual bool getEffectName(char* name);                       // The plug-in name
    virtual VstPlugCategory getPlugCategory();                    // The general category for the plug-in
    virtual bool getProductString(char* text);                    // This is a unique plug-in string provided by Steinberg
    virtual bool getVendorString(char* text);                     // Vendor info
    virtual VstInt32 getVendorVersion();                          // Version number
    virtual void processReplacing (float** inputs, float** outputs, VstInt32 sampleFrames);
    virtual void processDoubleReplacing (double** inputs, double** outputs, VstInt32 sampleFrames);
    virtual void getProgramName(char *name);                      // read the name from the host
    virtual void setProgramName(char *name);                      // changes the name of the preset displayed in the host
    virtual float getParameter(VstInt32 index);                   // get the parameter value at the specified index
    virtual void setParameter(VstInt32 index, float value);       // set the parameter at index to value
    virtual void getParameterLabel(VstInt32 index, char *text);  // label for the parameter (eg dB)
    virtual void getParameterName(VstInt32 index, char *text);    // name of the parameter
    virtual void getParameterDisplay(VstInt32 index, char *text); // text description of the current value    
    // Added by the perl as inverses
    virtual bool parameterTextToValue(VstInt32 index, const char *text, float &value);
    virtual bool canConvertParameterTextToValue(VstInt32 index);
    virtual VstInt32 canDo(char *text);
private:
    char _programName[kVstMaxProgNameLen + 1];
    std::set< std::string > _canDo;
    
    float A;
    float B;
    float C;
    float D;
    float E;
    float F;
    float G;
    float H;
    float I;
    float J;

	double angSL[18][16];
	double angAL[18][16];
	double angSR[18][16];
	double angAR[18][16];
	double angG[16];
	
	uint32_t fpdL;
	uint32_t fpdR;
	//default stuff
};

#endif
} // end namespace
