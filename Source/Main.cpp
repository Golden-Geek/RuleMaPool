//==============================================================================

#include "MainIncludes.h"
#include "Engine/RMPEngine.h"

RuleMaPoolApplication::RuleMaPoolApplication() :
	OrganicApplication("RuleMaPool", true, ImageCache::getFromMemory(BinaryData::icon_png, BinaryData::icon_pngSize))
{
}


void RuleMaPoolApplication::initialiseInternal(const String &)
{
	engine.reset(new RMPEngine());
	if(useWindow) mainComponent.reset(new MainContentComponent());

	//Call after engine init
	AppUpdater::getInstance()->setURLs("http://RuleMaPool.lighting/update.json", "http://RuleMaPool.lighting/installs/", "RuleMaPool");
	// HelpBox::getInstance()->helpURL = URL("http://benjamin.kuperberg.fr/chataigne/help/");

	//CrashDumpUploader::getInstance()->init("http://hazlab.fr/RuleMaPool/crash_report.php",ImageCache::getFromMemory(BinaryData::crash_png, BinaryData::crash_pngSize));

	// DashboardManager::getInstance()->setupDownloadURL("http://benjamin.kuperberg.fr/download/dashboard/dashboard.php?folder=dashboard");
	
	ShapeShifterManager::getInstance()->setDefaultFileData(BinaryData::default_rmplayout  );
	ShapeShifterManager::getInstance()->setLayoutInformations("rmplayout", "RuleMaPool/layouts");
}


void RuleMaPoolApplication::afterInit()
{
	//ANALYTICS
	if (mainWindow != nullptr)
	{
		
		// MainContentComponent* comp = (MainContentComponent*)mainComponent.get();
		// RMPEngine* eng = (RMPEngine*)engine.get();
		//RMPMenuBarComponent* menu = new RMPMenuBarComponent(comp, eng);
		// mainWindow->setMenuBarComponent(menu);
	}
	

}

void RuleMaPoolApplication::shutdown()
{   
	OrganicApplication::shutdown();
	AppUpdater::deleteInstance();
}

void RuleMaPoolApplication::handleCrashed()
{
	/*
	for (auto& m : ModuleManager::getInstance()->getItemsWithType<OSModule>())
	{
		m->crashedTrigger->trigger();
	}

	if (enableSendAnalytics->boolValue())
	{
		MatomoAnalytics::getInstance()->log(MatomoAnalytics::CRASH);
		while (MatomoAnalytics::getInstance()->isThreadRunning())
		{
			//wait until thread is done
		}
	}
	*/
	OrganicApplication::handleCrashed();
}
