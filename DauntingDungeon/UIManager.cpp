#include "UIManager.h"
#include "Engine.h"

UIManager::UIManager()
{
	//--------------------FPS SETUP---------------------------
	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 880;  //controls the rect's x coordinate
	Message_rect.y = 0; // controls the rect's y coordinte
	Message_rect.w = 80; // controls the width of the rect
	Message_rect.h = 50; // controls the height of the rect
	SDL_Color colour = { 255,255,200,255 };
	fps = UILabel("OpenSans-ExtraBold.ttf", 12, Message_rect, colour, "FPS: -");
	//--------------------------------------------------------


	Message_rect.w = 120; // controls the width of the rect
	Message_rect.h = 50;
	Message_rect.x = 400;
	score = UILabel("OpenSans-ExtraBold.ttf", 12, Message_rect, colour, "SCORE: 0");

	healthHeart = TextureManager::GetTexture("DauntingDungeon/Assets/map/dungeon.png");
	heartDistance = 40;
	healthSrcRect = { 288, 257, 16,16 };
	heatlhDestRect = { 0,10,38,38 };
}

void UIManager::UpdateFPS(std::string msg)
{
	fps.UpdateMessage(msg);
}

void UIManager::UpdateScore(std::string msg)
{
	score.UpdateMessage(msg);
}
void UIManager::DrawUI(int hearts)
{
	fps.Draw();
	score.Draw();

	for (int i = 0; i < hearts; ++i) {
		heatlhDestRect.x = heartDistance * i;
		TextureManager::Draw(healthHeart, healthSrcRect, heatlhDestRect, 0, SDL_FLIP_NONE);
	}
}
