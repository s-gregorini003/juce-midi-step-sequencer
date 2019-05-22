/*
  ==============================================================================

    StepControls.h
    Created: 29 Apr 2019 5:14:46pm
    Author:  Silvio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "CustomLookAndFeel.h"

//==============================================================================
/*
*/
class StepControls    : public Component,
						public Slider::Listener
{
public:
    StepControls();
    ~StepControls();

    void paint (Graphics&) override;
    void resized() override;
	void sliderValueChanged(Slider * slider) override;
	float getVelValue(int valuePlace);
	//float getDurValue(int valuePlace);



private:
	
	CustomLookAndFeel customLookAndFeel;
	Slider velocity[16], duration[16];
	float velValue[16] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
	//float durValue[16] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
	

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepControls)
};
