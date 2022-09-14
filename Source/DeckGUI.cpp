/*
  ==============================================================================

    DeckGUI.cpp
    Created: 23 Jan 2021 9:36:49pm
    Author:  Goh Sin Hau

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DeckGUI.h"

//==============================================================================
DeckGUI::DeckGUI(DJAudioPlayer* _player) : player(_player)
{
	addAndMakeVisible(playButton);
	addAndMakeVisible(stopButton);
	addAndMakeVisible(volSlider);
	addAndMakeVisible(speedSlider);
	addAndMakeVisible(loadButton);
	addAndMakeVisible(posSlider);

	playButton.addListener(this);
	stopButton.addListener(this);
	loadButton.addListener(this);

	volSlider.addListener(this);
	speedSlider.addListener(this);
	posSlider.addListener(this);

	volSlider.setRange(0.0, 1.0);
	posSlider.setRange(0.0, 1.0);
	speedSlider.setRange(0.0, 100.0);
}

DeckGUI::~DeckGUI()
{
}

void DeckGUI::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("DeckGUI", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void DeckGUI::resized()
{
	double rowH = getHeight() / 6;
	playButton.setBounds(0, 0, getWidth(), rowH);
	stopButton.setBounds(0, rowH, getWidth(), rowH);
	volSlider.setBounds(0, rowH * 2, getWidth(), rowH);
	speedSlider.setBounds(0, rowH * 3, getWidth(), rowH);
	posSlider.setBounds(0, rowH * 4, getWidth(), rowH);
	loadButton.setBounds(0, rowH * 5, getWidth(), rowH);
}

void DeckGUI::buttonClicked(Button * button)
{
	if (button == &playButton)
	{
		DBG("start button was clicked");
		player->start();
	}

	if (button == &stopButton)
	{
		DBG("stop button was clicked");
		player->stop();
	}

	if (button == &loadButton)
	{
		FileChooser chooser{ "Select a file..." };
		if (chooser.browseForFileToOpen())
		{
			player->loadURL(URL{ chooser.getResult() });
		}
	}
}

void DeckGUI::sliderValueChanged(Slider * slider)
{
	if (slider == &volSlider)
	{
		//DBG("vol slider moved" << slider->getValue());
		player->setGain(slider->getValue());
	}

	if (slider == &speedSlider)
	{
		player->setSpeed(slider->getValue());
	}

	if (slider == &posSlider)
	{
		player->setPositionRelative(slider->getValue());
	}
}
