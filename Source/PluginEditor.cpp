/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.1

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MoogFilterAudioProcessorEditor::MoogFilterAudioProcessorEditor (MoogFilterAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (freqCtrl = new Slider ("Frequency"));
    freqCtrl->setTooltip (TRANS("Frequency"));
    freqCtrl->setRange (0, 12000, 0.01);
    freqCtrl->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    freqCtrl->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    freqCtrl->setColour (Slider::thumbColourId, Colour (0x00eee4bd));
    freqCtrl->setColour (Slider::trackColourId, Colour (0xffeee4bd));
    freqCtrl->setColour (Slider::rotarySliderFillColourId, Colour (0xffeee4bd));
    freqCtrl->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffeee4bd));
    freqCtrl->setColour (Slider::textBoxTextColourId, Colour (0xffeee4bd));
    freqCtrl->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    freqCtrl->setColour (Slider::textBoxHighlightColourId, Colour (0x40a2cfda));
    freqCtrl->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    freqCtrl->addListener (this);

    addAndMakeVisible (resoCtrl = new Slider ("Resonance"));
    resoCtrl->setTooltip (TRANS("Resonance"));
    resoCtrl->setRange (0, 5, 0.01);
    resoCtrl->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    resoCtrl->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    resoCtrl->setColour (Slider::thumbColourId, Colour (0x00eee4bd));
    resoCtrl->setColour (Slider::trackColourId, Colour (0xffeee4bd));
    resoCtrl->setColour (Slider::rotarySliderFillColourId, Colour (0xffeee4bd));
    resoCtrl->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffeee4bd));
    resoCtrl->setColour (Slider::textBoxTextColourId, Colour (0xffeee4bd));
    resoCtrl->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    resoCtrl->setColour (Slider::textBoxHighlightColourId, Colour (0x40a2cfda));
    resoCtrl->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    resoCtrl->addListener (this);

    addAndMakeVisible (label = new Label ("Frequency",
                                          TRANS("frequency")));
    label->setFont (Font ("Avenir", 25.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colour (0xffeee4bd));
    label->setColour (TextEditor::textColourId, Colour (0x00000000));
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    label->setColour (TextEditor::highlightColourId, Colour (0x001111ee));

    addAndMakeVisible (label2 = new Label ("Resonance",
                                           TRANS("resonance")));
    label2->setFont (Font ("Avenir", 25.00f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colour (0xffeee4bd));
    label2->setColour (TextEditor::textColourId, Colour (0x00000000));
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    label2->setColour (TextEditor::highlightColourId, Colour (0x001111ee));

    addAndMakeVisible (driveCtrl = new Slider ("Drive"));
    driveCtrl->setTooltip (TRANS("Drive"));
    driveCtrl->setRange (0.1, 10, 0.01);
    driveCtrl->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    driveCtrl->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    driveCtrl->setColour (Slider::thumbColourId, Colour (0xffeee4bd));
    driveCtrl->setColour (Slider::trackColourId, Colour (0xffeee4bd));
    driveCtrl->setColour (Slider::rotarySliderFillColourId, Colour (0xffeee4bd));
    driveCtrl->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffeee4bd));
    driveCtrl->setColour (Slider::textBoxTextColourId, Colour (0xffeee4bd));
    driveCtrl->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    driveCtrl->setColour (Slider::textBoxHighlightColourId, Colour (0x40a2cfda));
    driveCtrl->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    driveCtrl->addListener (this);

    addAndMakeVisible (label3 = new Label ("Drive",
                                           TRANS("drive")));
    label3->setFont (Font ("Avenir", 25.00f, Font::plain));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colour (0xffeee4bd));
    label3->setColour (TextEditor::textColourId, Colour (0x00000000));
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    label3->setColour (TextEditor::highlightColourId, Colour (0x001111ee));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (510, 230);


    //[Constructor] You can add your own custom stuff here..
	getProcessor()->RequestUIUpdate();
	startTimer(200);
    //[/Constructor]
}

MoogFilterAudioProcessorEditor::~MoogFilterAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    freqCtrl = nullptr;
    resoCtrl = nullptr;
    label = nullptr;
    label2 = nullptr;
    driveCtrl = nullptr;
    label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MoogFilterAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff1b2226));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MoogFilterAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    freqCtrl->setBounds (10, 15, 200, 200);
    resoCtrl->setBounds (300, 15, 200, 200);
    label->setBounds (10, 165, 200, 24);
    label2->setBounds (300, 165, 200, 24);
    driveCtrl->setBounds (205, 123, 100, 100);
    label3->setBounds (205, 95, 100, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MoogFilterAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	MoogFilterAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == freqCtrl)
    {
        //[UserSliderCode_freqCtrl] -- add your slider handling code here..
		ourProcessor->setParameter(MoogFilterAudioProcessor::frequency, (float)freqCtrl->getValue());
        //[/UserSliderCode_freqCtrl]
    }
    else if (sliderThatWasMoved == resoCtrl)
    {
        //[UserSliderCode_resoCtrl] -- add your slider handling code here..
		ourProcessor->setParameter(MoogFilterAudioProcessor::resonance, (float)resoCtrl->getValue());
        //[/UserSliderCode_resoCtrl]
    }
    else if (sliderThatWasMoved == driveCtrl)
    {
        //[UserSliderCode_driveCtrl] -- add your slider handling code here..
		ourProcessor->setParameter(MoogFilterAudioProcessor::drive, (float)driveCtrl->getValue());
        //[/UserSliderCode_driveCtrl]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MoogFilterAudioProcessorEditor::timerCallback()
{
	MoogFilterAudioProcessor* ourProcessor = getProcessor();
	if (ourProcessor->NeedsUIUpdate())
	{
		freqCtrl->setValue(ourProcessor->getParameter(MoogFilterAudioProcessor::frequency), dontSendNotification);
		resoCtrl->setValue(ourProcessor->getParameter(MoogFilterAudioProcessor::resonance), dontSendNotification);
		driveCtrl->setValue(ourProcessor->getParameter(MoogFilterAudioProcessor::drive), dontSendNotification);
		ourProcessor->ClearUIUpdateFlag();
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MoogFilterAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="MoogFilterAudioProcessor&amp; ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="510" initialHeight="400">
  <BACKGROUND backgroundColour="ff1b2226">
    <RECT pos="0 0 510 220" fill="solid: 0" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="Frequency" id="6b0ed33aabc97f3b" memberName="freqCtrl"
          virtualName="" explicitFocusOrder="0" pos="10 10 200 200" tooltip="Frequency"
          thumbcol="eee4bd" trackcol="ffeee4bd" rotarysliderfill="ffeee4bd"
          rotaryslideroutline="ffeee4bd" textboxtext="ffeee4bd" textboxbkgd="ffffff"
          textboxhighlight="40a2cfda" textboxoutline="808080" min="0" max="20000"
          int="0.10000000000000000555" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Resonance" id="fd27c6e8349e50e3" memberName="resoCtrl"
          virtualName="" explicitFocusOrder="0" pos="300 10 200 200" tooltip="Resonance"
          thumbcol="eee4bd" trackcol="ffeee4bd" rotarysliderfill="ffeee4bd"
          rotaryslideroutline="ffeee4bd" textboxtext="ffeee4bd" textboxbkgd="ffffff"
          textboxhighlight="40a2cfda" textboxoutline="808080" min="0" max="5"
          int="0.10000000000000000555" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Frequency" id="8550ff1cff1d1e9b" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="10 160 200 24" textCol="ffeee4bd"
         edTextCol="0" edBkgCol="0" hiliteCol="1111ee" labelText="frequency"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Avenir" fontsize="25" bold="0" italic="0" justification="36"/>
  <LABEL name="Resonance" id="e6e20c48409a6a0a" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="300 160 200 24" textCol="ffeee4bd"
         edTextCol="0" edBkgCol="0" hiliteCol="1111ee" labelText="resonance"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Avenir" fontsize="25" bold="0" italic="0" justification="36"/>
  <SLIDER name="Drive" id="6f59a7cec17010ad" memberName="driveCtrl" virtualName=""
          explicitFocusOrder="0" pos="205 118 100 100" tooltip="Drive"
          thumbcol="ffeee4bd" trackcol="ffeee4bd" rotarysliderfill="ffeee4bd"
          rotaryslideroutline="ffeee4bd" textboxtext="ffeee4bd" textboxbkgd="ffffff"
          textboxhighlight="40a2cfda" textboxoutline="808080" min="0.10000000000000000555"
          max="10" int="0.10000000000000000555" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Drive" id="f3dbaa98bb13f39c" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="205 90 100 24" textCol="ffeee4bd"
         edTextCol="0" edBkgCol="0" hiliteCol="1111ee" labelText="drive"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Avenir" fontsize="25" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
