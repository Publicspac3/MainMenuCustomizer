#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"
#include "version.h"

//Cvar Macros
#define CVAR_COMPONENT_5     "FovSlider"

constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);

class MainMenuCustomizer : public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginWindow
{
	//Boilerplate
	virtual void onLoad();
	virtual void onUnload();
	
	//imgui
	std::shared_ptr<bool> enabled;
	bool isWindowOpen_ = false;
	bool isMinimized_ = false;
	std::string menuTitle_ = "MainMenuCustomizer";
	virtual void Render() override;
	virtual std::string GetMenuName() override;
	virtual std::string GetMenuTitle() override;
	virtual void SetImGuiContext(uintptr_t ctx) override;
	virtual bool ShouldBlockInput() override;
	virtual bool IsActiveOverlay() override;
	virtual void OnOpen() override;
	virtual void OnClose() override;

	
public:
	//menu toggle 
	void Menu_Toggle();
	//Background
	void setBackground_Stadium();
	void setBackground_SaltyShores();
	void setBackground_Throwback();
	void setBackground_SnowyUtopia();
	void setBackground_BeckwithPark();
	void setBackground_NeonFields();
	void setBackground_UrbanCentralSpooky();
	void setBackground_ForbiddenTemple();
	void setBackground_Circuit();
	void setBackground_DeadeyeCanyon();
	void setBackground_StarbaseArcAftermath();
	void setBackground_BeckwithParkSnowy();
	void setBackground_CurrentDefault();
	void ReloadMenu();
	
	//FOV
	void fov_small();
	void fov_large();
	void fov_random();
	void fov_normal();
	void fov_slider();
private:
	//Slider
	std::shared_ptr<int>         FOV_Slider;
};

