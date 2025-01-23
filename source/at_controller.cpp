//------------------------------------------------------------------------
// Copyright(c) 2025 Jeff.
//------------------------------------------------------------------------

#include "at_controller.h"
#include "at_cids.h"
#include "vstgui/plugin-bindings/vst3editor.h"
#include "pluginterfaces/base/ibstream.h"
#include "base/source/fstreamer.h"
#include <pluginterfaces/base/ustring.h>
//#include "base/source/fstring.h"
//#include "pluginterfaces/base/futils.h"
//#include "pluginterfaces/base/ustring.h"
//#include <public.sdk/source/vst/vstnoteexpressiontypes.h>
//#include <public.sdk/source/vst/utility/sampleaccurate.h>
//#include <processthreadsapi.h>
#include "vst"

using namespace Steinberg;

namespace MyCompanyName {

	//------------------------------------------------------------------------
	// AbletonTimerController Implementation
	//------------------------------------------------------------------------
	tresult PLUGIN_API AbletonTimerController::initialize(FUnknown* context)
	{
		// Here the Plug-in will be instantiated

		//---do not forget to call parent ------
		tresult result = EditControllerEx1::initialize(context);
		if (result != kResultOk)
		{
			return result;
		}

		Vst::Parameter* param;

		param = new Vst::StringListParameter(USTRING("Timer"), kTimerId, nullptr, Vst::ParameterInfo::kIsReadOnly, 0, nullptr);

			//parameters.addParameter(param);

		// -> Vst::EditController::parameters.addParameter(param);
		return result;
	}

	//------------------------------------------------------------------------
	tresult PLUGIN_API AbletonTimerController::terminate()
	{
		// Here the Plug-in will be de-instantiated, last possibility to remove some memory!

		//---do not forget to call parent ------
		return EditControllerEx1::terminate();
	}

	//------------------------------------------------------------------------
	tresult PLUGIN_API AbletonTimerController::setComponentState(IBStream* state)
	{
		// Here you get the state of the component (Processor part)
		if (!state)
			return kResultFalse;

		return kResultOk;
	}

	//------------------------------------------------------------------------
	tresult PLUGIN_API AbletonTimerController::setState(IBStream* state)
	{
		// Here you get the state of the controller

		return kResultTrue;
	}

	//------------------------------------------------------------------------
	tresult PLUGIN_API AbletonTimerController::getState(IBStream* state)
	{
		// Here you are asked to deliver the state of the controller (if needed)
		// Note: the real state of your plug-in is saved in the processor

		return kResultTrue;
	}

	//------------------------------------------------------------------------
	IPlugView* PLUGIN_API AbletonTimerController::createView(FIDString name)
	{
		// Here the Host wants to open your editor (if you have one)
		if (FIDStringsEqual(name, Vst::ViewType::kEditor))
		{
			// create your editor here and return a IPlugView ptr of it
			auto* view = new VSTGUI::VST3Editor(this, "view", "at_editor.uidesc");
			return view;
		}
		return nullptr;
	}

	//------------------------------------------------------------------------
} // namespace MyCompanyName