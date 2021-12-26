#include "pch.h"
#include "MainMenuCustomizer.h"

BAKKESMOD_PLUGIN(MainMenuCustomizer, "Allows you to customize the main menu", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void MainMenuCustomizer::onLoad()
{

    //Something to take note: a lot of this code is old and just reused from the og plugin i based this off of and my own work; didnt want to throw it all away and im lazy

    //enables the functionality we need
    cvarManager->executeCommand("load_freeplay MENU_Main_P");
    cvarManager->executeCommand("cl_notifications_enabled_beta 1");

    //Notifier for menu
    cvarManager->registerNotifier("MainMenuCustomizerMenu", [&](std::vector<std::string> args) {Menu_Toggle(); }, "lol", 0);

    //all the notifiers for the backgrounds
    cvarManager->registerNotifier("setBackground_SaltyShores", [&](std::vector<std::string> args) {setBackground_SaltyShores(); }, "Sets the Menu to be Salty Shores", 0);
    cvarManager->registerNotifier("setBackground_Throwback", [&](std::vector<std::string> args) {setBackground_Throwback(); }, "Sets the Menu to be Throwback Stadium Snowy", 0);
    cvarManager->registerNotifier("setBackground_SnowyUtopia", [&](std::vector<std::string> args) {setBackground_SnowyUtopia(); }, "Sets the Menu to be Snowy Utopia", 0);
    cvarManager->registerNotifier("setBackground_BeckwithPark", [&](std::vector<std::string> args) {setBackground_BeckwithPark(); }, "Sets the Menu to be Beckwith Park", 0);
    cvarManager->registerNotifier("setBackground_NeonFields", [&](std::vector<std::string> args) {setBackground_NeonFields(); }, "Sets the Menu to be Neon Fields", 0);
    cvarManager->registerNotifier("setBackground_UrbanCentralSpooky", [&](std::vector<std::string> args) {setBackground_UrbanCentralSpooky(); }, "Sets the Menu to be Urban Central Spooky", 0);
    cvarManager->registerNotifier("setBackground_Stadium", [&](std::vector<std::string> args) {setBackground_Stadium(); }, "Sets the Menu to be DFH Stadium", 0);
    cvarManager->registerNotifier("setBackground_ForbiddenTemple", [&](std::vector<std::string> args) {setBackground_ForbiddenTemple(); }, "Sets the Menu to be Forbidden Temple", 0);
    cvarManager->registerNotifier("setBackground_Circuit", [&](std::vector<std::string> args) {setBackground_Circuit(); }, "Sets the Menu to be DFH Stadium Circuit", 0);
    cvarManager->registerNotifier("setBackground_DeadeyeCanyon", [&](std::vector<std::string> args) {setBackground_DeadeyeCanyon(); }, "Sets the Menu to be Deadeye Canyon", 0);
    cvarManager->registerNotifier("setBackground_StarbaseArcAftermath", [&](std::vector<std::string> args) {setBackground_StarbaseArcAftermath(); }, "Sets the Menu to be Starbase Arc Aftermath", 0);
    cvarManager->registerNotifier("setBackground_BeckwithParkSnowy", [&](std::vector<std::string> args) {setBackground_BeckwithParkSnowy(); }, "Sets the Menu to be Beckwith Park Snowy", 0);
    cvarManager->registerNotifier("setBackground_CurrentDefault", [&](std::vector<std::string> args) {setBackground_CurrentDefault(); }, "Resets the menu to the current default", 0);

    //All the notifiers for the FOV's
    cvarManager->registerNotifier("fov_small", [&](std::vector<std::string> params) {fov_small(); }, "Sets the FOV small", 0);
    cvarManager->registerNotifier("fov_large", [&](std::vector<std::string> params) {fov_large(); }, "Sets the FOV large", 0);
    cvarManager->registerNotifier("fov_random", [&](std::vector<std::string> args) {fov_random(); }, "Sets a random FOV", 0);
    cvarManager->registerNotifier("fov_normal", [&](std::vector<std::string> args) {fov_normal(); }, "Sets the FOV back to normal", 0);
    
    //Popup
    cvarManager->registerNotifier("MainMenuBackgroundChanger_Toast", [this](std::vector<std::string> args) {
        gameWrapper->Toast("Please restart!", "Please restart your game for changes to take effect!", "", 5.0, ToastType_Warning);
    }, "", PERMISSION_ALL);

}
//Unload
void MainMenuCustomizer::onUnload()
{
    cvarManager->executeCommand("cl_mainmenu_fov 55");
}
//Toggle menu
void MainMenuCustomizer::Menu_Toggle()
{
    cvarManager->executeCommand("togglemenu MainMenuCustomizer");
}
//Backgrounds
void MainMenuCustomizer::setBackground_SaltyShores()
{
    cvarManager->executeCommand("cl_mainmenu_background 3");
    ReloadMenu();
}
void MainMenuCustomizer::setBackground_Throwback()
{
    cvarManager->executeCommand("cl_mainmenu_background 9");
    ReloadMenu();
}
void MainMenuCustomizer::setBackground_SnowyUtopia()
{
    cvarManager->executeCommand("cl_mainmenu_background 1");
    ReloadMenu();
}
void MainMenuCustomizer::setBackground_BeckwithPark()
{
    cvarManager->executeCommand("cl_mainmenu_background 7");
    ReloadMenu();
}
void MainMenuCustomizer::setBackground_NeonFields()
{
    cvarManager->executeCommand("cl_mainmenu_background 8");
    ReloadMenu();
}
void MainMenuCustomizer::setBackground_UrbanCentralSpooky()
{
    cvarManager->executeCommand("cl_mainmenu_background 5");
    ReloadMenu();
}
void MainMenuCustomizer::setBackground_Stadium()
{
    cvarManager->executeCommand("cl_mainmenu_background 0");
    ReloadMenu();
}

void MainMenuCustomizer::setBackground_ForbiddenTemple()
{
    cvarManager->executeCommand("cl_mainmenu_background 6");
    ReloadMenu();
}

void MainMenuCustomizer::setBackground_Circuit()
{
    cvarManager->executeCommand("cl_mainmenu_background 10");
    ReloadMenu();
}

void MainMenuCustomizer::setBackground_DeadeyeCanyon()
{
    cvarManager->executeCommand("cl_mainmenu_background 11");
    ReloadMenu();
}
void MainMenuCustomizer::setBackground_StarbaseArcAftermath()
{
    cvarManager->executeCommand("cl_mainmenu_background 12");
    ReloadMenu();
}
void MainMenuCustomizer::setBackground_BeckwithParkSnowy()
{
    cvarManager->executeCommand("cl_mainmenu_background 13");
    ReloadMenu();
}
void MainMenuCustomizer::setBackground_CurrentDefault()
{
    cvarManager->executeCommand("cl_mainmenu_background -1");
    cvarManager->executeCommand("MainMenuBackgroundChanger_Toast");
}
void MainMenuCustomizer::ReloadMenu()
{
    cvarManager->executeCommand("sleep 1;load_freeplay MENU_Main_P");
}

//FOV
void MainMenuCustomizer::fov_small()
{
    cvarManager->executeCommand("sleep 1;cl_mainmenu_fov 1");
}
void MainMenuCustomizer::fov_large()
{
    cvarManager->executeCommand("sleep 1;cl_mainmenu_fov 170");
}
void MainMenuCustomizer::fov_random()
{
    cvarManager->executeCommand("sleep 1;cl_mainmenu_fov (1, 170)");
}
void MainMenuCustomizer::fov_normal()
{
    cvarManager->executeCommand("sleep 1;cl_mainmenu_fov 55");
}

/*
TODO:
-Add a check to see if in menu in ReloadMenu()
    ->if not in menu just set the cvar and possibly add a toast
-Finish GUI
   -credits, polish, etc etc

*/