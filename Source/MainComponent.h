/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "TogglePad.h"
#include "StepControls.h"
#include "NoteControls.h"
#include "CustomLookAndFeel.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component,
						public ComboBox::Listener,
						public Slider::Listener,
						public Button::Listener,
						private Timer

{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void comboBoxChanged(ComboBox * comboBoxThatHasChanged) override;
	void sliderValueChanged(Slider * slider) override;
	void buttonClicked(Button *button) override;
	void timerCallback() override;
	void saveMidiPattern();


private:
    //==============================================================================
	CustomLookAndFeel customLookAndFeel;
	CustomLookAndFeel2 customLookAndFeel2;

	TogglePad pad[16] [4];
	 
	TextButton   saveButton;
	ShapeButton pauseButton, stopButton, playButton;
	Slider bpmSlider;
	StepControls stepControls;
	NoteControls noteControls;
	std::unique_ptr<MidiOutput> midiOutput;
	ComboBox deviceList;
	MidiMessage midiMessage;
	MidiMessageSequence midiEventList;
	MidiFile midiFile;

	unsigned int bpm;
	unsigned long int timeCount;
	int beatCount, track;
	

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
