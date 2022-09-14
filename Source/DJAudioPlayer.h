/*
  ==============================================================================

    DJAudioPlayer.h
    Created: 20 Jan 2021 10:04:24pm
    Author:  Goh Sin Hau

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

using namespace juce;

class DJAudioPlayer: public AudioSource {
	public:
		DJAudioPlayer();
		~DJAudioPlayer();

		//==============================================================================
		void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
		void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
		void releaseResources() override;

		void loadURL(URL audioURL);
		void setGain(double gain);
		void setSpeed(double ratio);
		void setPosition(double posInSecs);
		void setPositionRelative(double pos);

		void start();
		void stop();

	private:
		AudioFormatManager formatManager;
		std::unique_ptr<AudioFormatReaderSource> readerSource;
		AudioTransportSource transportSource;
		ResamplingAudioSource resampleSource{&transportSource, false, 2};

};