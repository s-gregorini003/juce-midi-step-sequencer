/*
  ==============================================================================

    StepControls.cpp
    Created: 29 Apr 2019 5:14:46pm
    Author:  Silvio

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "StepControls.h"

//==============================================================================
StepControls::StepControls()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
	setSize(1000, 200);


	for (int i = 0; i < 16; ++i) {


		//velocity[i].setColour(Slider::thumbColourId, Colours::transparentBlack);
		//velocity[i].setColour(Slider::rotarySliderFillColourId, Colours::orange);
		//velocity[i].setColour(Slider::rotarySliderOutlineColourId, Colours::black);
		velocity[i].setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
		velocity[i].setLookAndFeel(&customLookAndFeel);
		velocity[i].setRange(0.0f, 127.0f, 1.0f);
		velocity[i].setValue(64.0f);
		velocity[i].setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
		velocity[i].addListener(this);
		addAndMakeVisible(velocity[i]);

	
	}
}

StepControls::~StepControls()
{
}

void StepControls::paint (Graphics& g)
{
 
	//juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);

	//g.fillAll(Colours::black);
	//g.setColour(Colours::white);
	//g.drawText("Filter", titleArea, Justification::centredTop);

	juce::Rectangle <float> area(0, 20, 830, 80);
	
	g.setColour(Colour(12, 20, 31));
	g.fillRoundedRectangle(area, 5.0f);
	
}

void StepControls::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
	juce::Rectangle<int> area = getLocalBounds().reduced(20);

	int x = 20;

	for (int i = 0; i < 16; ++i) {
		
		
		velocity[i].setBounds(x, area.getY() + 20, 40, 40);
	
		x += 50;
	}

}

void StepControls::sliderValueChanged(Slider * slider)
{
	for (int i = 0; i < 16; ++i) {

		if (slider == &velocity[i]) {

			velValue[i] = velocity[i].getValue();


		
		}
	}


}


float StepControls::getVelValue(int valuePlace)
{
	return velValue[valuePlace];
}

