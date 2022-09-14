/*
  ==============================================================================

    DeckGUI.h
    Created: 23 Jan 2021 9:36:49pm
    Author:  Goh Sin Hau

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DJAudioPlayer.h"

using namespace juce;

//==============================================================================
/*
*/
class DeckGUI  : public juce::Component,
				 public Button::Listener,
				 public Slider::Listener
{
public:
    DeckGUI(DJAudioPlayer* _player);
    ~DeckGUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;

	/** implement Button::Listener*/
	void buttonClicked(Button *) override;
	/** implement Slider::Listener*/
	void sliderValueChanged(Slider *slider) override;

private:

	TextButton playButton{ "PLAY" };
	TextButton stopButton{ "STOP" };
	TextButton loadButton{ "LOAD" };
	Slider volSlider;
	Slider speedSlider;
	Slider posSlider;

	DJAudioPlayer* player;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DeckGUI)
};
