/*
 ==============================================================================
 
	This file was auto-generated by the Introjucer!
 
	It contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
MoogFilterAudioProcessor::MoogFilterAudioProcessor()
{
	UserParams[frequency] = 10000.0f;
	UserParams[resonance] = 1.0f;
	UserParams[drive] = 1.0f;
	
	UIUpdateFlag=true;
}

MoogFilterAudioProcessor::~MoogFilterAudioProcessor()
{
}

//==============================================================================
const String MoogFilterAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

int MoogFilterAudioProcessor::getNumParameters()
{
	return totalNumParam;
}

float MoogFilterAudioProcessor::getParameter (int index)
{
	switch(index)
	{
		case frequency:
			UserParams[frequency] = filter[0].getFrequency();
			return UserParams[frequency];
		case resonance:
			UserParams[resonance] = filter[0].getResonance();
			return UserParams[resonance];
		case drive:
			UserParams[drive] = filter[0].getDrive();
			return UserParams[drive];
		default: return 0.0f;
 }
}

void MoogFilterAudioProcessor::setParameter (int index, float newValue)
{
	switch(index)
	{
		case frequency:
			UserParams[frequency] = newValue;
			filter[0].setFrequency(newValue);
			filter[1].setFrequency(newValue);
			break;
		case resonance:
			UserParams[resonance] = newValue;
			filter[0].setResonance(newValue);
			filter[1].setResonance(newValue);
			break;
		case drive:
			UserParams[drive] = newValue;
			filter[0].setDrive(newValue);
			filter[1].setDrive(newValue);
			break;
		default: return;
	}
	UIUpdateFlag = true;
}

const String MoogFilterAudioProcessor::getParameterName (int index)
{
	switch (index) {
		case frequency:	return "frequency";
		case resonance:	return "resonance";
		case drive:	return "drive";
		default: return String::empty;
	}
}

const String MoogFilterAudioProcessor::getParameterText (int index)
{
	if(index >= 0 && index < totalNumParam) return String(UserParams[index]);
	else return String::empty;
}

const String MoogFilterAudioProcessor::getInputChannelName (int channelIndex) const
{
	return String (channelIndex + 1);
}

const String MoogFilterAudioProcessor::getOutputChannelName (int channelIndex) const
{
	return String (channelIndex + 1);
}

bool MoogFilterAudioProcessor::isInputChannelStereoPair (int index) const
{
	return true;
}

bool MoogFilterAudioProcessor::isOutputChannelStereoPair (int index) const
{
	return true;
}

bool MoogFilterAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

bool MoogFilterAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

bool MoogFilterAudioProcessor::silenceInProducesSilenceOut() const
{
	return false;
}

double MoogFilterAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

int MoogFilterAudioProcessor::getNumPrograms()
{
	return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
	// so this should be at least 1, even if you're not really implementing programs.
}

int MoogFilterAudioProcessor::getCurrentProgram()
{
	return 0;
}

void MoogFilterAudioProcessor::setCurrentProgram (int index)
{
}

const String MoogFilterAudioProcessor::getProgramName (int index)
{
	return String();
}

void MoogFilterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MoogFilterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	for (int i = 0; i < 2; i++) {
		filter[i].setSampleRate((int)sampleRate);
		filter[i].setFrequency(UserParams[frequency]);
		filter[i].setResonance(UserParams[resonance]);
		filter[i].setDrive(UserParams[drive]);
	}
}

void MoogFilterAudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
}

void MoogFilterAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
		buffer.clear (i, 0, buffer.getNumSamples());
	
	for (int channel = 0; channel < getNumInputChannels(); ++channel)
	{
		float* channelData = buffer.getWritePointer (channel);
		filter[channel].processSamples(channelData, buffer.getNumSamples());
	}
}

//==============================================================================
bool MoogFilterAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MoogFilterAudioProcessor::createEditor()
{
	return new MoogFilterAudioProcessorEditor (*this);
}

//==============================================================================
void MoogFilterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	// code courtesy of Redwood Audio
	// http://www.redwoodaudio.net/Tutorials/juce_for_vst_development__intro6.html
	for(int i = 0; i < totalNumParam; i++)
		UserParams[i] = getParameter(i);
	XmlElement root("Root");
	XmlElement *el = root.createNewChildElement("AllUserParam");
	el->addTextElement(String(floatArrayToString(UserParams, totalNumParam)));
	copyXmlToBinary(root, destData);
}

void MoogFilterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	// code courtesy of Redwood Audio
	// http://www.redwoodaudio.net/Tutorials/juce_for_vst_development__intro6.html
	XmlElement* pRoot = getXmlFromBinary(data, sizeInBytes);
	float TmpUserParam[totalNumParam];
	if (pRoot != NULL)
	{
		forEachXmlChildElement((*pRoot), pChild)
		{
			if (pChild->hasTagName("AllUserParam"))
			{
				String sFloatCSV = pChild->getAllSubText();
				if(stringToFloatArray(sFloatCSV, TmpUserParam, totalNumParam) == totalNumParam)
				{
					for (int i = 0; i < totalNumParam; i++)
						setParameter(i, TmpUserParam[i]);
				}
			}
		}
		delete pRoot;
		UIUpdateFlag = true;
	}
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new MoogFilterAudioProcessor();
}
