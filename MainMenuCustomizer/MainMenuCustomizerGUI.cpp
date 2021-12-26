#include "pch.h"
#include "MainMenuCustomizer.h"
#include "imgui/imgui_internal.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

// Do ImGui rendering here

void MainMenuCustomizer::Render()
{
	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, ImGuiWindowFlags_None))
	{

		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;

	}
    //ImGUI Content
    if (ImGui::BeginTabBar("MenuCustomizerTabBar", ImGuiTabBarFlags_None)) {
        if (ImGui::BeginTabItem("Backgrounds")) {

			//buttons for backgrounds
			static int clicked = 0;
			if (ImGui::Button("Current Default", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_CurrentDefault");

			}
			if (ImGui::Button("DFH Stadium", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_Stadium");
			}

			if (ImGui::Button("Snowy Utopia", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_SnowyUtopia");
			}

			if (ImGui::Button("Salty Shores", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_SaltyShores");
			}

			if (ImGui::Button("Urban Central Spooky", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_UrbanCentralSpooky");
			}

			if (ImGui::Button("Forbidden Temple", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_ForbiddenTemple");
			}
			
			if (ImGui::Button("Beckwith Park", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_BeckwithPark");
			}

			if (ImGui::Button("Neon Fields", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_NeonFields");
			}

			if (ImGui::Button("Throwback Stadium Snowy", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_Throwback");
			}

			if (ImGui::Button("DFH Stadium Racing", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_Circuit");
			}

			if (ImGui::Button("Deadeye Canyon", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_DeadeyeCanyon");
			}

			if (ImGui::Button("Starbase Arc Aftermath", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_StarbaseArcAftermath");
			}

			if (ImGui::Button("Beckwith Park Snowy", { 200.f,30.f }))
			{
				cvarManager->executeCommand("setBackground_BeckwithParkSnowy");
			}

            ImGui::EndTabItem();
        }
       
		if (ImGui::BeginTabItem("Camera")) {
			
			if (ImGui::Button("Small FOV", { 200.f,30.f }))
			{
				cvarManager->executeCommand("fov_small");
			}
			
			if (ImGui::Button("Large FOV", { 200.f,30.f }))
			{
				cvarManager->executeCommand("fov_large");
			}
			
			if (ImGui::Button("Random FOV", { 200.f,30.f }))
			{
				cvarManager->executeCommand("fov_random");
			}
			
			if (ImGui::Button("Normal FOV", { 200.f,30.f }))
			{
				
				cvarManager->executeCommand("fov_normal");
			}
			
			static float FOV { 55 };
			static float v_min = 1;
			static float v_max = 170;

			if (ImGui::DragFloat("FOV Slider", &FOV, 1, v_min, v_max))
			{
				cvarManager->executeCommand("sleep 1;cl_mainmenu_fov " + std::to_string(FOV));
			}

			static Rotator rotation{ -300, 27000, 0 };
			static Vector focus{ 0, 0, 15 };
			if (ImGui::DragInt3("Rotation (Pitch,Yaw,Roll)", &rotation.Pitch, 10))
			{
				cvarManager->executeCommand(fmt::format("cl_mainmenu_camera_rotation Y {}", rotation.Yaw), false);
				cvarManager->executeCommand(fmt::format("cl_mainmenu_camera_rotation P {}", rotation.Pitch), false);
				cvarManager->executeCommand(fmt::format("cl_mainmenu_camera_rotation R {}", rotation.Roll), false);
			}
			if (ImGui::DragFloat3("Focus(X,Y,Z)", &focus.X))
			{
				cvarManager->executeCommand(fmt::format("cl_mainmenu_camera_focus X {}", focus.X), false);
				cvarManager->executeCommand(fmt::format("cl_mainmenu_camera_focus Y {}", focus.Y), false);
				cvarManager->executeCommand(fmt::format("cl_mainmenu_camera_focus Z {}", focus.Z), false);
			}
           
			ImGui::EndTabItem();
			
        }
		if (ImGui::BeginTabItem("credits idk")) {
			/*
			come back when done lol
			*/
		}

       
        ImGui::EndTabBar();
    }

	ImGui::End();

	if (!isWindowOpen_)
	{
		cvarManager->executeCommand("togglemenu " + GetMenuName());

	}

}

// Name of the menu that is used to toggle the window.
std::string MainMenuCustomizer::GetMenuName()
{
	return "MainMenuCustomizer";
}

// Title to give the menu
std::string MainMenuCustomizer::GetMenuTitle()
{
	return menuTitle_;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void MainMenuCustomizer::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool MainMenuCustomizer::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool MainMenuCustomizer::IsActiveOverlay()
{
	return true;
}

// Called when window is opened
void MainMenuCustomizer::OnOpen()
{
	isWindowOpen_ = true;
	
}

// Called when window is closed
void MainMenuCustomizer::OnClose()
{
	isWindowOpen_ = false;
}
