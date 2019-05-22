/*
  ==============================================================================

    NoteControls.cpp
    Created: 1 May 2019 2:25:49pm
    Author:  Silvio

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "NoteControls.h"

//==============================================================================
NoteControls::NoteControls()
{
	setSize(200, 240);

	noteMenu1.setLookAndFeel(&customLookAndFeel2);
	noteMenu2.setLookAndFeel(&customLookAndFeel2);
	noteMenu3.setLookAndFeel(&customLookAndFeel2);
	noteMenu4.setLookAndFeel(&customLookAndFeel2);
	noteMenu1.addListener(this);
	noteMenu2.addListener(this);
	noteMenu3.addListener(this);
	noteMenu4.addListener(this);

	{
	noteMenu1.addItem("C0", 24);
	noteMenu1.addItem("C#0", 25);
	noteMenu1.addItem("D0", 26);
	noteMenu1.addItem("D#0", 27);
	noteMenu1.addItem("E0", 28);
	noteMenu1.addItem("F0", 29);
	noteMenu1.addItem("F#0", 30);
	noteMenu1.addItem("G0", 31);
	noteMenu1.addItem("G#0", 32);
	noteMenu1.addItem("A0", 33);
	noteMenu1.addItem("A#0", 34);
	noteMenu1.addItem("B0", 35);

	noteMenu1.addItem("C1", 36);
	noteMenu1.addItem("C#1", 37);
	noteMenu1.addItem("D1", 38);
	noteMenu1.addItem("D#1", 39);
	noteMenu1.addItem("E1", 40);
	noteMenu1.addItem("F1", 41);
	noteMenu1.addItem("F#1", 42);
	noteMenu1.addItem("G1", 43);
	noteMenu1.addItem("G#1", 44);
	noteMenu1.addItem("A1", 45);
	noteMenu1.addItem("A#1", 46);
	noteMenu1.addItem("B1", 47);

	noteMenu1.addItem("C2", 48);
	noteMenu1.addItem("C#2", 49);
	noteMenu1.addItem("D2", 50);
	noteMenu1.addItem("D#2", 51);
	noteMenu1.addItem("E2", 52);
	noteMenu1.addItem("F2", 53);
	noteMenu1.addItem("F#2", 54);
	noteMenu1.addItem("G2", 55);
	noteMenu1.addItem("G#2", 56);
	noteMenu1.addItem("A2", 57);
	noteMenu1.addItem("A#2", 58);
	noteMenu1.addItem("B2", 59);

	noteMenu1.addItem("C3", 60);
	noteMenu1.addItem("C#3", 61);
	noteMenu1.addItem("D3", 62);
	noteMenu1.addItem("D#3", 63);
	noteMenu1.addItem("E3", 64);
	noteMenu1.addItem("F3", 65);
	noteMenu1.addItem("F#3", 66);
	noteMenu1.addItem("G3", 67);
	noteMenu1.addItem("G#3", 68);
	noteMenu1.addItem("A3", 69);
	noteMenu1.addItem("A#3", 70);
	noteMenu1.addItem("B3", 71);

	noteMenu1.addItem("C4", 72);
	noteMenu1.addItem("C#4", 73);
	noteMenu1.addItem("D4", 74);
	noteMenu1.addItem("D#4", 75);
	noteMenu1.addItem("E4", 76);
	noteMenu1.addItem("F4", 77);
	noteMenu1.addItem("F#4", 78);
	noteMenu1.addItem("G4", 79);
	noteMenu1.addItem("G#4", 80);
	noteMenu1.addItem("A4", 81);
	noteMenu1.addItem("A#4", 82);
	noteMenu1.addItem("B4", 83);

	noteMenu1.addItem("C5", 84);
	noteMenu1.addItem("C#5", 85);
	noteMenu1.addItem("D5", 86);
	noteMenu1.addItem("D#5", 87);
	noteMenu1.addItem("E5", 88);
	noteMenu1.addItem("F5", 89);
	noteMenu1.addItem("F#5", 90);
	noteMenu1.addItem("G5", 91);
	noteMenu1.addItem("G#5", 92);
	noteMenu1.addItem("A5", 93);
	noteMenu1.addItem("A#5", 94);
	noteMenu1.addItem("B5", 95);

	noteMenu1.addItem("C6", 96);
	noteMenu1.addItem("C#6", 97);
	noteMenu1.addItem("D6", 98);
	noteMenu1.addItem("D#6", 99);
	noteMenu1.addItem("E6", 100);
	noteMenu1.addItem("F6", 101);
	noteMenu1.addItem("F#6", 102);
	noteMenu1.addItem("G6", 103);
	noteMenu1.addItem("G#6", 104);
	noteMenu1.addItem("A6", 105);
	noteMenu1.addItem("A#6", 106);
	noteMenu1.addItem("B6", 107);


	addAndMakeVisible(noteMenu1);

	//==============================================================================
	//==============================================================================

	noteMenu2.addItem("C0", 24);
	noteMenu2.addItem("C#0", 25);
	noteMenu2.addItem("D0", 26);
	noteMenu2.addItem("D#0", 27);
	noteMenu2.addItem("E0", 28);
	noteMenu2.addItem("F0", 29);
	noteMenu2.addItem("F#0", 30);
	noteMenu2.addItem("G0", 31);
	noteMenu2.addItem("G#0", 32);
	noteMenu2.addItem("A0", 33);
	noteMenu2.addItem("A#0", 34);
	noteMenu2.addItem("B0", 35);

	noteMenu2.addItem("C1", 36);
	noteMenu2.addItem("C#1", 37);
	noteMenu2.addItem("D1", 38);
	noteMenu2.addItem("D#1", 39);
	noteMenu2.addItem("E1", 40);
	noteMenu2.addItem("F1", 41);
	noteMenu2.addItem("F#1", 42);
	noteMenu2.addItem("G1", 43);
	noteMenu2.addItem("G#1", 44);
	noteMenu2.addItem("A1", 45);
	noteMenu2.addItem("A#1", 46);
	noteMenu2.addItem("B1", 47);

	noteMenu2.addItem("C2", 48);
	noteMenu2.addItem("C#2", 49);
	noteMenu2.addItem("D2", 50);
	noteMenu2.addItem("D#2", 51);
	noteMenu2.addItem("E2", 52);
	noteMenu2.addItem("F2", 53);
	noteMenu2.addItem("F#2", 54);
	noteMenu2.addItem("G2", 55);
	noteMenu2.addItem("G#2", 56);
	noteMenu2.addItem("A2", 57);
	noteMenu2.addItem("A#2", 58);
	noteMenu2.addItem("B2", 59);

	noteMenu2.addItem("C3", 60);
	noteMenu2.addItem("C#3", 61);
	noteMenu2.addItem("D3", 62);
	noteMenu2.addItem("D#3", 63);
	noteMenu2.addItem("E3", 64);
	noteMenu2.addItem("F3", 65);
	noteMenu2.addItem("F#3", 66);
	noteMenu2.addItem("G3", 67);
	noteMenu2.addItem("G#3", 68);
	noteMenu2.addItem("A3", 69);
	noteMenu2.addItem("A#3", 70);
	noteMenu2.addItem("B3", 71);

	noteMenu2.addItem("C4", 72);
	noteMenu2.addItem("C#4", 73);
	noteMenu2.addItem("D4", 74);
	noteMenu2.addItem("D#4", 75);
	noteMenu2.addItem("E4", 76);
	noteMenu2.addItem("F4", 77);
	noteMenu2.addItem("F#4", 78);
	noteMenu2.addItem("G4", 79);
	noteMenu2.addItem("G#4", 80);
	noteMenu2.addItem("A4", 81);
	noteMenu2.addItem("A#4", 82);
	noteMenu2.addItem("B4", 83);

	noteMenu2.addItem("C5", 84);
	noteMenu2.addItem("C#5", 85);
	noteMenu2.addItem("D5", 86);
	noteMenu2.addItem("D#5", 87);
	noteMenu2.addItem("E5", 88);
	noteMenu2.addItem("F5", 89);
	noteMenu2.addItem("F#5", 90);
	noteMenu2.addItem("G5", 91);
	noteMenu2.addItem("G#5", 92);
	noteMenu2.addItem("A5", 93);
	noteMenu2.addItem("A#5", 94);
	noteMenu2.addItem("B5", 95);

	noteMenu2.addItem("C6", 96);
	noteMenu2.addItem("C#6", 97);
	noteMenu2.addItem("D6", 98);
	noteMenu2.addItem("D#6", 99);
	noteMenu2.addItem("E6", 100);
	noteMenu2.addItem("F6", 101);
	noteMenu2.addItem("F#6", 102);
	noteMenu2.addItem("G6", 103);
	noteMenu2.addItem("G#6", 104);
	noteMenu2.addItem("A6", 105);
	noteMenu2.addItem("A#6", 106);
	noteMenu2.addItem("B6", 107);

	addAndMakeVisible(noteMenu2);

	//==============================================================================
	//==============================================================================

	noteMenu3.addItem("C0", 24);
	noteMenu3.addItem("C#0", 25);
	noteMenu3.addItem("D0", 26);
	noteMenu3.addItem("D#0", 27);
	noteMenu3.addItem("E0", 28);
	noteMenu3.addItem("F0", 29);
	noteMenu3.addItem("F#0", 30);
	noteMenu3.addItem("G0", 31);
	noteMenu3.addItem("G#0", 32);
	noteMenu3.addItem("A0", 33);
	noteMenu3.addItem("A#0", 34);
	noteMenu3.addItem("B0", 35);

	noteMenu3.addItem("C1", 36);
	noteMenu3.addItem("C#1", 37);
	noteMenu3.addItem("D1", 38);
	noteMenu3.addItem("D#1", 39);
	noteMenu3.addItem("E1", 40);
	noteMenu3.addItem("F1", 41);
	noteMenu3.addItem("F#1", 42);
	noteMenu3.addItem("G1", 43);
	noteMenu3.addItem("G#1", 44);
	noteMenu3.addItem("A1", 45);
	noteMenu3.addItem("A#1", 46);
	noteMenu3.addItem("B1", 47);

	noteMenu3.addItem("C2", 48);
	noteMenu3.addItem("C#2", 49);
	noteMenu3.addItem("D2", 50);
	noteMenu3.addItem("D#2", 51);
	noteMenu3.addItem("E2", 52);
	noteMenu3.addItem("F2", 53);
	noteMenu3.addItem("F#2", 54);
	noteMenu3.addItem("G2", 55);
	noteMenu3.addItem("G#2", 56);
	noteMenu3.addItem("A2", 57);
	noteMenu3.addItem("A#2", 58);
	noteMenu3.addItem("B2", 59);

	noteMenu3.addItem("C3", 60);
	noteMenu3.addItem("C#3", 61);
	noteMenu3.addItem("D3", 62);
	noteMenu3.addItem("D#3", 63);
	noteMenu3.addItem("E3", 64);
	noteMenu3.addItem("F3", 65);
	noteMenu3.addItem("F#3", 66);
	noteMenu3.addItem("G3", 67);
	noteMenu3.addItem("G#3", 68);
	noteMenu3.addItem("A3", 69);
	noteMenu3.addItem("A#3", 70);
	noteMenu3.addItem("B3", 71);

	noteMenu3.addItem("C4", 72);
	noteMenu3.addItem("C#4", 73);
	noteMenu3.addItem("D4", 74);
	noteMenu3.addItem("D#4", 75);
	noteMenu3.addItem("E4", 76);
	noteMenu3.addItem("F4", 77);
	noteMenu3.addItem("F#4", 78);
	noteMenu3.addItem("G4", 79);
	noteMenu3.addItem("G#4", 80);
	noteMenu3.addItem("A4", 81);
	noteMenu3.addItem("A#4", 82);
	noteMenu3.addItem("B4", 83);

	noteMenu3.addItem("C5", 84);
	noteMenu3.addItem("C#5", 85);
	noteMenu3.addItem("D5", 86);
	noteMenu3.addItem("D#5", 87);
	noteMenu3.addItem("E5", 88);
	noteMenu3.addItem("F5", 89);
	noteMenu3.addItem("F#5", 90);
	noteMenu3.addItem("G5", 91);
	noteMenu3.addItem("G#5", 92);
	noteMenu3.addItem("A5", 93);
	noteMenu3.addItem("A#5", 94);
	noteMenu3.addItem("B5", 95);

	noteMenu3.addItem("C6", 96);
	noteMenu3.addItem("C#6", 97);
	noteMenu3.addItem("D6", 98);
	noteMenu3.addItem("D#6", 99);
	noteMenu3.addItem("E6", 100);
	noteMenu3.addItem("F6", 101);
	noteMenu3.addItem("F#6", 102);
	noteMenu3.addItem("G6", 103);
	noteMenu3.addItem("G#6", 104);
	noteMenu3.addItem("A6", 105);
	noteMenu3.addItem("A#6", 106);
	noteMenu3.addItem("B6", 107);

	addAndMakeVisible(noteMenu3);

	//==============================================================================
	//==============================================================================

	noteMenu4.addItem("C0", 24);
	noteMenu4.addItem("C#0", 25);
	noteMenu4.addItem("D0", 26);
	noteMenu4.addItem("D#0", 27);
	noteMenu4.addItem("E0", 28);
	noteMenu4.addItem("F0", 29);
	noteMenu4.addItem("F#0", 30);
	noteMenu4.addItem("G0", 31);
	noteMenu4.addItem("G#0", 32);
	noteMenu4.addItem("A0", 33);
	noteMenu4.addItem("A#0", 34);
	noteMenu4.addItem("B0", 35);

	noteMenu4.addItem("C1", 36);
	noteMenu4.addItem("C#1", 37);
	noteMenu4.addItem("D1", 38);
	noteMenu4.addItem("D#1", 39);
	noteMenu4.addItem("E1", 40);
	noteMenu4.addItem("F1", 41);
	noteMenu4.addItem("F#1", 42);
	noteMenu4.addItem("G1", 43);
	noteMenu4.addItem("G#1", 44);
	noteMenu4.addItem("A1", 45);
	noteMenu4.addItem("A#1", 46);
	noteMenu4.addItem("B1", 47);

	noteMenu4.addItem("C2", 48);
	noteMenu4.addItem("C#2", 49);
	noteMenu4.addItem("D2", 50);
	noteMenu4.addItem("D#2", 51);
	noteMenu4.addItem("E2", 52);
	noteMenu4.addItem("F2", 53);
	noteMenu4.addItem("F#2", 54);
	noteMenu4.addItem("G2", 55);
	noteMenu4.addItem("G#2", 56);
	noteMenu4.addItem("A2", 57);
	noteMenu4.addItem("A#2", 58);
	noteMenu4.addItem("B2", 59);

	noteMenu4.addItem("C3", 60);
	noteMenu4.addItem("C#3", 61);
	noteMenu4.addItem("D3", 62);
	noteMenu4.addItem("D#3", 63);
	noteMenu4.addItem("E3", 64);
	noteMenu4.addItem("F3", 65);
	noteMenu4.addItem("F#3", 66);
	noteMenu4.addItem("G3", 67);
	noteMenu4.addItem("G#3", 68);
	noteMenu4.addItem("A3", 69);
	noteMenu4.addItem("A#3", 70);
	noteMenu4.addItem("B3", 71);

	noteMenu4.addItem("C4", 72);
	noteMenu4.addItem("C#4", 73);
	noteMenu4.addItem("D4", 74);
	noteMenu4.addItem("D#4", 75);
	noteMenu4.addItem("E4", 76);
	noteMenu4.addItem("F4", 77);
	noteMenu4.addItem("F#4", 78);
	noteMenu4.addItem("G4", 79);
	noteMenu4.addItem("G#4", 80);
	noteMenu4.addItem("A4", 81);
	noteMenu4.addItem("A#4", 82);
	noteMenu4.addItem("B4", 83);

	noteMenu4.addItem("C5", 84);
	noteMenu4.addItem("C#5", 85);
	noteMenu4.addItem("D5", 86);
	noteMenu4.addItem("D#5", 87);
	noteMenu4.addItem("E5", 88);
	noteMenu4.addItem("F5", 89);
	noteMenu4.addItem("F#5", 90);
	noteMenu4.addItem("G5", 91);
	noteMenu4.addItem("G#5", 92);
	noteMenu4.addItem("A5", 93);
	noteMenu4.addItem("A#5", 94);
	noteMenu4.addItem("B5", 95);

	noteMenu4.addItem("C6", 96);
	noteMenu4.addItem("C#6", 97);
	noteMenu4.addItem("D6", 98);
	noteMenu4.addItem("D#6", 99);
	noteMenu4.addItem("E6", 100);
	noteMenu4.addItem("F6", 101);
	noteMenu4.addItem("F#6", 102);
	noteMenu4.addItem("G6", 103);
	noteMenu4.addItem("G#6", 104);
	noteMenu4.addItem("A6", 105);
	noteMenu4.addItem("A#6", 106);
	noteMenu4.addItem("B6", 107);

	addAndMakeVisible(noteMenu4);

}
	//==============================================================================
	//==============================================================================
	
	noteMenu1.setSelectedId(60, dontSendNotification);
	noteMenu2.setSelectedId(60, dontSendNotification);
	noteMenu3.setSelectedId(60, dontSendNotification);
	noteMenu4.setSelectedId(60, dontSendNotification);
}

NoteControls::~NoteControls()
{
}

void NoteControls::paint (Graphics& g)
{
   	juce::Rectangle <float> area(0, 30, 100, 210);

	g.setColour(Colour(12, 20, 31));
	g.fillRoundedRectangle(area, 5.0f);
}

void NoteControls::resized()
{
	juce::Rectangle<int> area = getLocalBounds();

	noteMenu1.setBounds(20, 50, 60, 20);
	noteMenu2.setBounds(20, 100, 60, 20);
	noteMenu3.setBounds(20, 150, 60, 20);
	noteMenu4.setBounds(20, 200, 60, 20);
}

void NoteControls::comboBoxChanged(ComboBox * comboBoxThatHasChanged)
{
	if (comboBoxThatHasChanged == &noteMenu1) {

		trackNote[0] = noteMenu1.getSelectedId();
	}

	if (comboBoxThatHasChanged == &noteMenu2) {

		trackNote[1] = noteMenu2.getSelectedId();
	}

	if (comboBoxThatHasChanged == &noteMenu3) {

		trackNote[2] = noteMenu3.getSelectedId();
	}

	if (comboBoxThatHasChanged == &noteMenu4) {

		trackNote[3] = noteMenu4.getSelectedId();
	}
}

int NoteControls::getTrackNote(int _track)
{
	return trackNote[_track];
}
