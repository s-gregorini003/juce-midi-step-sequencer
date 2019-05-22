/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

/*
TO DO:

-change play stop pause appearance
-change duration slider colour

*/
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : playButton("playButton", Colour(20, 31, 51), Colour(20, 31, 51), Colour(20, 31, 51)),
									stopButton("stopButton", Colour(20, 31, 51), Colour(20, 31, 51), Colour(20, 31, 51)),
									pauseButton("pauseButton", Colour(20, 31, 51), Colour(20, 31, 51), Colour(20, 31, 51))
{
    setSize (960, 400);
	timeCount = 0;
	beatCount = 0;
	bpm = 100;
	addAndMakeVisible(stepControls);
	addAndMakeVisible(noteControls);

	
	bpmSlider.setSliderStyle(Slider::LinearBar);
	//bpmSlider.setLookAndFeel(&customLookAndFeel);
	bpmSlider.setRange(0, 400, 1);
	bpmSlider.setValue(100);
	bpmSlider.addListener(this);
	addAndMakeVisible(bpmSlider);

	
	Rectangle<float> buttonArea(40., 40.);

	Path playPath;
	playPath.addTriangle(0, 0, 0, buttonArea.getHeight(), buttonArea.getWidth() * sqrt(3) / 2, buttonArea.getHeight() / 2);
	playButton.setShape(playPath, false, true, true);
	playButton.setOnColours(Colours::darkred, Colours::darkred, Colours::darkred);
	playButton.shouldUseOnColours(true);
	playButton.setClickingTogglesState(true);
	playButton.addListener(this);
	addAndMakeVisible(playButton);

	Path pausePath;
	pausePath.addRectangle(0., 0., 13., buttonArea.getHeight());
	pausePath.addRectangle(20., 0., 13., buttonArea.getHeight());
	pauseButton.setShape(pausePath, false, true, true);
	pauseButton.setOnColours(Colour(8, 12, 20), Colour(8, 12, 20), Colour(8, 12, 20));
	pauseButton.shouldUseOnColours(true);
	pauseButton.setClickingTogglesState(true);
	pauseButton.addListener(this);
	addAndMakeVisible(pauseButton);

	Path stopPath;
	stopPath.addRectangle(0., 0., buttonArea.getWidth(), buttonArea.getHeight());
	stopButton.setShape(stopPath, false, true, true);
	stopButton.setOnColours(Colour(8, 12, 20), Colour(8, 12, 20), Colour(8, 12, 20));
	stopButton.shouldUseOnColours(true);
	stopButton.setClickingTogglesState(true);
	stopButton.addListener(this);
	addAndMakeVisible(stopButton);

	saveButton.setButtonText("save");
	saveButton.setLookAndFeel(&customLookAndFeel2);
	saveButton.setClickingTogglesState(true);
	saveButton.addListener(this);
	addAndMakeVisible(saveButton);

	for (int i = 0; i < 16; ++i) {


		for (int j = 0; j < 4; ++j) {

			pad[i][j].Button::setToggleState(false, dontSendNotification);
			pad[i][j].addListener(this);
			addAndMakeVisible(pad[i][j]);

		}
	}

	
	midiOutput->getDevices();

	for (int i = 0; i < midiOutput->getDevices().size(); ++i) {
		deviceList.addItem(midiOutput->getDevices()[i], i+1);
	}

	deviceList.setLookAndFeel(&customLookAndFeel2);
	deviceList.addListener(this);
	addAndMakeVisible(deviceList);
}

MainComponent::~MainComponent()
{
	
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(Colour(8, 12, 20));
	
	g.setColour(Colour(12, 20, 31));
	Rectangle<float> toggleRect(120, 90, 830, 210);
	g.fillRoundedRectangle(toggleRect, 5.0f);
	g.fillRoundedRectangle(10.0f, 10.0f, 500.0f, 70.0f, 5.0f);
	g.fillRoundedRectangle(520.0f, 10.0f, 210.0f, 70.0f, 5.0f);
	g.fillRoundedRectangle(740.0f, 10.0f, 210.0f, 70.0f, 5.0f);

	g.setColour(Colour(223, 116, 12));
	g.setFont(Font(14, 1));
	g.drawText("Select MIDI device:", 50, 10, 200, 30.0f, Justification::centredLeft);
	g.drawText("B P M", 800, 10, 100, 30.0f, Justification::horizontallyCentred);
	g.drawText("Export pattern", 550, 10, 160, 30.0f, Justification::horizontallyCentred);

}


void MainComponent::resized()
{   
	juce::Rectangle<int> area = getLocalBounds().reduced(10);

	stepControls.setBounds(120, 290, 1000, 100);
	noteControls.setBounds(10, 60, 200, 240);


	bpmSlider.setBounds(800, 40, 100, 20); //change bpm slider position

	int xx = 260;
	playButton.setBounds(xx, 25, 40, 40);
	pauseButton.setBounds(xx + 60, 25, 40, 40);
	stopButton.setBounds(xx + 130, 25, 40, 40);
	saveButton.setBounds(600, 40, 60, 20);

	deviceList.setBounds(50, 40, 100, 20);

	int x = 140;
	
	for (int i = 0; i < 16; ++i) {


		int y = 100;

		for (int j = 0; j < 4; ++j) {

			pad[i][j].setBounds(x, y, 40, 40);

			y += 50;
		}
		
		x += 50;
	}



    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainComponent::comboBoxChanged(ComboBox * comboBoxThatHasChanged)
{
	if (comboBoxThatHasChanged = &deviceList) {

		if (midiOutput == nullptr && MidiOutput::getDevices().size() > 0)
		{
			midiOutput.reset(MidiOutput::openDevice(deviceList.getSelectedId()));
		}
	}

}

void MainComponent::sliderValueChanged(Slider * slider)
{
	if (slider == &bpmSlider) {

		bpm = bpmSlider.getValue();
	}

}

void MainComponent::buttonClicked(Button * button)
{
	if (playButton.getToggleState() == true) {

		Timer::startTimer(60000 / (bpm * 4));
		playButton.setRadioGroupId(1, dontSendNotification);
		midiEventList.begin();
	}

	if (pauseButton.getToggleState() == true) {

		Timer::stopTimer();
		pauseButton.setRadioGroupId(1, dontSendNotification);
		midiOutput->clearAllPendingMessages();
		
	}

	if (stopButton.getToggleState() == true) {

		Timer::stopTimer();
		stopButton.setRadioGroupId(1, dontSendNotification);
		
		for (int i = 0; i < 16; ++i) {
			for (int j = 0 ; j < 4; ++j)
				pad[i][j].resetStep();
		}
		midiOutput->clearAllPendingMessages();
		timeCount = 0;
		beatCount = 0;
	}

	if (saveButton.getToggleState() == true) {

		saveMidiPattern();
		saveButton.setToggleState(false, dontSendNotification);
	}

}

void MainComponent::timerCallback()
{

		if (beatCount > 15) {
			beatCount = 0;
			
			midiEventList.clear();
		}


		for (track = 0; track < 4; ++track) {

			pad[beatCount][track].lightUpStep();

			if (pad[beatCount][track].getToggleState() == true) {

				midiMessage = MidiMessage::noteOn(track + 1, noteControls.getTrackNote(track), stepControls.getVelValue(beatCount) / 127.0f);

				DBG(midiMessage.getDescription());
				

			}

			else if (pad[beatCount][track].getToggleState() == false) {

				midiMessage = MidiMessage::noteOff(track + 1, noteControls.getTrackNote(track), stepControls.getVelValue(beatCount) / 127.0f);

				DBG(midiMessage.getDescription());

				
			}

		midiOutput->sendMessageNow(midiMessage);
		}
		
		
		

		//GUI Grid
		if (beatCount == 0) {

			for (int i = 0; i < 4; ++i)
				pad[15][i].resetStep();
		}

		else {

			for (int i = 0; i < 4; ++i)
				pad[beatCount - 1][i].resetStep();
		}


		++beatCount;
		++timeCount;

}

void MainComponent::saveMidiPattern()
{FileChooser chooser("Select file to save",
		File::getCurrentWorkingDirectory(), "*.mid");

	if (chooser.browseForFileToSave(true))
	{

	double 	timerInterval = 60000 / (bpm * 4);

	for (beatCount = 0; beatCount < 16; ++beatCount) {

		for (track = 0; track < 4; ++track) {

			if (pad[beatCount][track].getToggleState() == true) {

				midiMessage = MidiMessage::noteOn(track + 1, noteControls.getTrackNote(track), stepControls.getVelValue(beatCount) / 127.0f);

				midiMessage.setTimeStamp(timerInterval * (beatCount + 1));
				midiEventList.addEvent(midiMessage);
				midiEventList.updateMatchedPairs();
				DBG(midiMessage.getDescription());
				DBG(midiMessage.getTimeStamp());

			}

			else if (pad[beatCount][track].getToggleState() == false) {

				midiMessage = MidiMessage::noteOff(track + 1, noteControls.getTrackNote(track), stepControls.getVelValue(beatCount) / 127.0f);

				midiMessage.setTimeStamp(timerInterval * (beatCount + 1));
				midiEventList.addEvent(midiMessage);
				midiEventList.updateMatchedPairs();
				DBG(midiMessage.getDescription());
				DBG(midiMessage.getTimeStamp());
			}

		}
	}

	DBG(midiEventList.getNumEvents());


	MidiFile midiFile;
	midiFile.setTicksPerQuarterNote(96);
	
	FileOutputStream outputStream(chooser.getResult());

	midiFile.addTrack(midiEventList);
	midiFile.writeTo(outputStream, 0);
	outputStream.flush();

	}
}

