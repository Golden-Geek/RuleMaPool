/*
  ==============================================================================

    ObjectManager.cpp
    Created: 26 Sep 2020 10:02:28am
    Author:  bkupe

  ==============================================================================
*/

#include "Media/MediaIncludes.h"

juce_ImplementSingleton(MediaManager);

MediaManager::MediaManager() :
    BaseManager("Media")
{
    managerFactory = &factory;

    factory.defs.add(Factory<Media>::Definition::createDef<ColorMedia>(""));
    factory.defs.add(Factory<Media>::Definition::createDef<PictureMedia>(""));
    factory.defs.add(Factory<Media>::Definition::createDef<VideoMedia>(""));
    factory.defs.add(Factory<Media>::Definition::createDef<NDIMedia>(""));
    factory.defs.add(Factory<Media>::Definition::createDef<CompositionMedia>(""));

    itemDataType = "Media";
    selectItemWhenCreated = true;
}

MediaManager::~MediaManager()
{
    // stopThread(1000);
}


void MediaManager::addItemInternal(Media* o, var data)
{
    reorderItems();
}

void MediaManager::removeItemInternal(Media* o)
{
}

void MediaManager::onContainerParameterChanged(Parameter* p)
{
}

