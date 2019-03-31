#include "UIManager.h"
#include "Engine.h"

UIManager::UIManager()
{
	//--------------------FPS SETUP---------------------------
	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 880;  //controls the rect's x coordinate
	Message_rect.y = -10; // controls the rect's y coordinte
	Message_rect.w = 80; // controls the width of the rect
	Message_rect.h = 50; // controls the height of the rect
	SDL_Color colour = { 255,255,200,255 };
	fps = UILabel("DauntingDungeon/OpenSans-ExtraBold.ttf", 12, Message_rect, colour, "-");
	//--------------------------------------------------------
}

void UIManager::UpdateFPS(std::string msg)
{
	fps.UpdateMessage(msg);
}

void UIManager::DrawFPS()
{
	fps.Draw();
}
