//------------------------------------------------------------------------
// Copyright(c) 2025 Jeff.
//------------------------------------------------------------------------

#include "at_processor.h"
#include "at_cids.h"

#include "base/source/fstreamer.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"

using namespace Steinberg;

namespace MyCompanyName {
//------------------------------------------------------------------------
// AbletonTimerProcessor
//------------------------------------------------------------------------

int srate;

AbletonTimerProcessor::AbletonTimerProcessor ()
{
	//--- set the wanted controller for our processor
	setControllerClass (kAbletonTimerControllerUID);
	srate = this->processSetup.sampleRate;
}

//------------------------------------------------------------------------
AbletonTimerProcessor::~AbletonTimerProcessor ()
{}

//------------------------------------------------------------------------
tresult PLUGIN_API AbletonTimerProcessor::initialize (FUnknown* context)
{
	// Here the Plug-in will be instantiated
	
	//---always initialize the parent-------
	tresult result = AudioEffect::initialize (context);
	// if everything Ok, continue
	if (result != kResultOk)
	{
		return result;
	}

	//--- create Audio IO ------
	addAudioInput (STR16 ("Stereo In"), Steinberg::Vst::SpeakerArr::kStereo);
	addAudioOutput (STR16 ("Stereo Out"), Steinberg::Vst::SpeakerArr::kStereo);

	/* If you don't need an event bus, you can remove the next line */
	addEventInput (STR16 ("Event In"), 1);

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AbletonTimerProcessor::terminate ()
{
	// Here the Plug-in will be de-instantiated, last possibility to remove some memory!
	
	//---do not forget to call parent ------
	return AudioEffect::terminate ();
}

//------------------------------------------------------------------------
tresult PLUGIN_API AbletonTimerProcessor::setActive (TBool state)
{
	//--- called when the Plug-in is enable/disable (On/Off) -----
	return AudioEffect::setActive (state);
}

//------------------------------------------------------------------------
tresult PLUGIN_API AbletonTimerProcessor::process (Vst::ProcessData& data)
{
	// read file:

	// add data.numSamples/sampleRate to fracSeconds:

	// modulos/remainders:

	// write file:
	/*for (int s = 0; s < data.numSamples; s++) {
		
	}*/

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AbletonTimerProcessor::setupProcessing (Vst::ProcessSetup& newSetup)
{
	//--- called before any processing ----
	return AudioEffect::setupProcessing (newSetup);
}

//------------------------------------------------------------------------
tresult PLUGIN_API AbletonTimerProcessor::canProcessSampleSize (int32 symbolicSampleSize)
{
	// by default kSample32 is supported
	if (symbolicSampleSize == Vst::kSample32)
		return kResultTrue;

	// disable the following comment if your processing support kSample64
	/* if (symbolicSampleSize == Vst::kSample64)
		return kResultTrue; */

	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AbletonTimerProcessor::setState (IBStream* state)
{
	// called when we load a preset, the model has to be reloaded
	IBStreamer streamer (state, kLittleEndian);
	
	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AbletonTimerProcessor::getState (IBStream* state)
{
	// here we need to save the model
	IBStreamer streamer (state, kLittleEndian);

	return kResultOk;
}

//------------------------------------------------------------------------
} // namespace MyCompanyName
