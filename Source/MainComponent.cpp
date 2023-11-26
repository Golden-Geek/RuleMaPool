#include "MainIncludes.h"
#include "Screen/ScreenIncludes.h"
#include "Media/MediaIncludes.h"
#include "Common/CommonIncludes.h"
#include "MainComponent.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
	// Make sure you set the size of the component after
	// you add any child components.
	// setSize (800, 600);

	getCommandManager().registerAllCommandsForTarget(this);
	ScreenOutputWatcher::getInstance(); // triggers the creation of the singleton
}

MainContentComponent::~MainContentComponent()
{
	// This shuts down the audio Fixture and clears the audio source.
	//shutdownAudio();

	//GlContextHolder::getInstance()->unregisterOpenGlRenderer(this);

	ScreenOutputWatcher::deleteInstance();
	GlContextHolder::deleteInstance();
}


void MainContentComponent::init()
{
	ShapeShifterFactory::getInstance()->defs.add(new ShapeShifterDefinition("Screens", &ScreenManagerUI::create));
	ShapeShifterFactory::getInstance()->defs.add(new ShapeShifterDefinition("Screen Editor", &ScreenEditorPanel::create));
	ShapeShifterFactory::getInstance()->defs.add(new ShapeShifterDefinition("Medias", &MediaManagerUI::create));
	ShapeShifterFactory::getInstance()->defs.add(new ShapeShifterDefinition("Online Explorer", &OnlineContentExplorer::create));

	OrganicMainContentComponent::init();

	//getLookAndFeel().setColour(juce::TextButton::textColourOffId, Colour(127,127,127));
	getLookAndFeel().setColour(juce::TextButton::buttonColourId, Colour(64, 64, 64));
}

void MainContentComponent::setupOpenGL()
{
	//do not use organic one
	GlContextHolder::getInstance()->setup(this);
}

void MainContentComponent::paint(Graphics& g)
{
	//nothing
	//OrganicMainContentComponent::paint(g);
}