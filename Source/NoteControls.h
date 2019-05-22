/*
  ==============================================================================

    NoteControls.h
    Created: 1 May 2019 2:25:49pm
    Author:  Silvio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "CustomLookAndFeel.h"
//==============================================================================
/*
*/
class NoteControls    : public Component,
						public ComboBox::Listener
{
public:
    NoteControls();
    ~NoteControls();

    void paint (Graphics&) override;
    void resized() override;
	void comboBoxChanged(ComboBox * comboBoxThatHasChanged) override;
	int getTrackNote(int _track);

private:

	CustomLookAndFeel2 customLookAndFeel2;
	ComboBox noteMenu1, noteMenu2, noteMenu3, noteMenu4;
	int trackNote[4] = { 60, 60, 60, 60 };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NoteControls)
};
