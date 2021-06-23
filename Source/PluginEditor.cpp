/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LightsPluginAudioProcessorEditor::LightsPluginAudioProcessorEditor (LightsPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Constructor
    mLightsSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mLightsSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 20);
    mLightsSlider.setRange(-60.0f, 0.0f, 0.01);
    mLightsSlider.setValue(-20.0f);
    mLightsSlider.addListener(this);
    addAndMakeVisible(mLightsSlider);
    
    setSize (200, 300);
}

LightsPluginAudioProcessorEditor::~LightsPluginAudioProcessorEditor()
{
}

//==============================================================================
void LightsPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
}

void LightsPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mLightsSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}

void LightsPluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &mLightsSlider)
    {
        audioProcessor.mLight = mLightsSlider.getValue();
    }
}
