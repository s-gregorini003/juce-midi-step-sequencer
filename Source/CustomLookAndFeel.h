/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 3 May 2019 8:30:02pm
    Author:  Silvio

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class CustomLookAndFeel : public LookAndFeel_V4


{
public:

	void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider &) override
	{
		float diameter = jmin(width, height);
		float radius = diameter / 2;
		float centreX = x + width / 2;
		float centreY = y + height / 2;
		float rx = centreX - radius;
		float ry = centreY - radius;
		float angle = rotaryStartAngle + (sliderPosProportional * (rotaryEndAngle - rotaryStartAngle));

		juce::Rectangle<float> dialArea(rx, ry, diameter, diameter);

		Path dialTick, backgndTick;

		dialTick.addPieSegment(dialArea, rotaryStartAngle, angle, 0.6);
		backgndTick.addPieSegment(dialArea, rotaryStartAngle, rotaryEndAngle, 0.6);

		g.setColour(Colour(20, 31, 51));
		g.fillPath(backgndTick);

		g.setColour(Colour(223, 116, 12));
		g.fillPath(dialTick);
		//PathStrokeType::JointStyle::beveled

	}

	void drawLinearSlider(Graphics &g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider &) override
	{

		juce::Rectangle<float> sliderArea(x, y, width, height);

		
		g.setColour(Colour(20, 31, 51));
		g.fillRect(x, y, width, height);

		g.setColour(Colour(223, 116, 12));
		g.fillRect((float)x, sliderPos, (float)width, y + (height - sliderPos));
		
	}

	void drawLabel(Graphics &g, Label &label) override
	{

		if (!label.isBeingEdited())
		{
			auto alpha = label.isEnabled() ? 1.0f : 0.5f;
			const Font font(12, 1); 

			g.setColour(Colour(223, 116, 12));
			g.setFont(font);

			auto textArea = getLabelBorderSize(label).subtractedFrom(label.getLocalBounds());

			g.drawFittedText(label.getText(), textArea, label.getJustificationType(),
				jmax(1, (int)(textArea.getHeight() / font.getHeight())),
				label.getMinimumHorizontalScale());

		}

	}

	void drawToggleButton(Graphics& g, ToggleButton& button,
		bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
	{
		auto fontSize = jmin(15.0f, button.getHeight() * 0.75f);
		auto tickWidth = fontSize * 1.1f;

		Colour fillColour = (button.getToggleState() == true ? Colour(223, 116, 12) : Colour(20, 31, 51));
		g.fillAll(fillColour);

		/*drawTickBox(g, button, 4.0f, (button.getHeight() - tickWidth) * 0.5f,
			tickWidth, tickWidth,
			button.getToggleState(),
			button.isEnabled(),
			shouldDrawButtonAsHighlighted,
			shouldDrawButtonAsDown);*/

		g.setColour(button.findColour(ToggleButton::textColourId));
		g.setFont(fontSize);

		if (!button.isEnabled())
			g.setOpacity(0.5f);

		g.drawFittedText(button.getButtonText(),
			button.getLocalBounds().withTrimmedLeft(roundToInt(tickWidth) + 10)
			.withTrimmedRight(2),
			Justification::centredLeft, 10);
	}

};


class CustomLookAndFeel2 : public LookAndFeel_V4

{
	public:

	void drawLabel(Graphics &g, Label &label) override
	{

		if (!label.isBeingEdited())
		{
			const Font font(14, 0);

			g.setColour(Colour(250, 250, 250));
			g.setFont(font);

			BorderSize<int> borderSize(0, 0, 0, 0);
			label.setBorderSize(borderSize);
			
			juce::Rectangle<int> rect(label.getX(), label.getY(), label.getWidth(), label.getHeight());

			auto textArea = getLabelBorderSize(label).subtractedFrom(rect);

			g.drawFittedText(label.getText(), textArea, Justification::horizontallyCentred,
				jmax(1, (int)(textArea.getHeight() / font.getHeight())),
				label.getMinimumHorizontalScale());

			
		}

	}



	void drawComboBox(Graphics& g, int width, int height, const bool isMouseButtonDown, int buttonX, int buttonY, int buttonW, int buttonH, ComboBox& box) override
	{

		juce::Rectangle<int> boxBounds(0, 0, width, height);


		g.setColour(Colour(20, 31, 51));
		g.fillRect(boxBounds.toFloat());


	}

	void drawPopupMenuBackground(Graphics& g, int width, int height) override
	{
		auto background = Colour(20, 31, 51);

		g.fillAll(background);
	}

	Font getComboBoxFont(ComboBox& box) override
	{
		Font font(12, 0);

		return font;
	}

	void positionComboBoxText(ComboBox& box, Label& label) override
	{
		label.setBounds(0, 0,
			box.getWidth(),
			box.getHeight() - 2);

		label.setFont(getComboBoxFont(box));

		label.setJustificationType(Justification::centred);
	}

	void drawPopupMenuItem(Graphics& g, const juce::Rectangle<int>& area,
		const bool isSeparator, const bool isActive,
		const bool isHighlighted, const bool isTicked,
		const bool hasSubMenu, const String& text,
		const String& shortcutKeyText,
		const Drawable* icon, const Colour* const textColourToUse) override
	{
		if (isSeparator)
		{
			auto r = area.reduced(5, 0);
			r.removeFromTop(roundToInt((r.getHeight() * 0.5f) - 0.5f));

			g.setColour(findColour(PopupMenu::textColourId).withAlpha(0.3f));
			g.fillRect(r.removeFromTop(1));
		}
		else
		{
			auto textColour = (textColourToUse == nullptr ? findColour(PopupMenu::textColourId)
				: *textColourToUse);

			auto r = area.reduced(1);

			if (isHighlighted && isActive)
			{
				g.setColour(Colour(8, 12, 20));
				g.fillRect(r);

				g.setColour(findColour(PopupMenu::highlightedTextColourId));
			}
			else
			{
				g.setColour(textColour.withMultipliedAlpha(isActive ? 1.0f : 0.5f));
			}

			r.reduce(jmin(5, area.getWidth() / 20), 0);

			auto font = getPopupMenuFont();

			auto maxFontHeight = r.getHeight() / 1.3f;

			if (font.getHeight() > maxFontHeight)
				font.setHeight(maxFontHeight);

			g.setFont(font);

			auto iconArea = r.removeFromLeft(roundToInt(maxFontHeight)).toFloat();

			if (icon != nullptr)
			{
				icon->drawWithin(g, iconArea, RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize, 1.0f);
				r.removeFromLeft(roundToInt(maxFontHeight * 0.5f));
			}
			else if (isTicked)
			{
				auto tick = getTickShape(1.0f);
				g.fillPath(tick, tick.getTransformToScaleToFit(iconArea.reduced(iconArea.getWidth() / 5, 0).toFloat(), true));
			}

			if (hasSubMenu)
			{
				auto arrowH = 0.6f * getPopupMenuFont().getAscent();

				auto x = static_cast<float> (r.removeFromRight((int)arrowH).getX());
				auto halfH = static_cast<float> (r.getCentreY());

				Path path;
				path.startNewSubPath(x, halfH - arrowH * 0.5f);
				path.lineTo(x + arrowH * 0.6f, halfH);
				path.lineTo(x, halfH + arrowH * 0.5f);

				g.strokePath(path, PathStrokeType(2.0f));
			}

			r.removeFromRight(3);
			g.drawFittedText(text, r, Justification::centredLeft, 1);

			if (shortcutKeyText.isNotEmpty())
			{
				auto f2 = font;
				f2.setHeight(f2.getHeight() * 0.75f);
				f2.setHorizontalScale(0.95f);
				g.setFont(f2);

				g.drawText(shortcutKeyText, r, Justification::centredRight, true);
			}
		}
	}

	Label* createSliderTextBox(Slider& slider) override
	{
		auto* l = LookAndFeel_V2::createSliderTextBox(slider);

		if (getCurrentColourScheme() == LookAndFeel_V4::getGreyColourScheme() && (slider.getSliderStyle() == Slider::LinearBar
			|| slider.getSliderStyle() == Slider::LinearBarVertical))
		{
			l->setColour(Label::textColourId, Colours::black.withAlpha(0.7f));
		}

		return l;
	}
};