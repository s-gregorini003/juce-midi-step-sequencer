/*
  ==============================================================================

    TogglePad.h
    Created: 29 Apr 2019 3:13:24pm
    Author:  Silvio

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class TogglePad : public ToggleButton

{
public:

	void paint(Graphics &g)
	{
		Colour fillColour = (getToggleState() == true ? Colour(223, 116, 12) : Colour(20, 31, 51));
		g.fillAll(fillColour);

		if (getState() == highlight) {

			g.setOpacity(0.5);
			g.fillAll();
		}


	}

	void lightUpStep()
	{
		setState(highlight);

	}
	
	void resetStep()
	{
		setState(ButtonState::buttonNormal);
	}

private:
	ButtonState highlight;

};