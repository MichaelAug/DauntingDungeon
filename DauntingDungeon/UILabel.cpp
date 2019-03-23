#include "UILabel.h"
#include "Engine.h"

UILabel::UILabel()
{
}

UILabel::UILabel(std::string fontName, int fontSize, SDL_Rect pos, SDL_Color col, std::string message) :
	colour(col), text("FPS: " + message), position(pos)
{
	font = TTF_OpenFont(fontName.c_str(), fontSize); //this opens a font style and sets a size
	if (font == NULL) { printf("Unable to open font! SDL_ttf Error: %s\n", TTF_GetError()); }
	else { printf("Font Loaded successfully!\n"); }
}

void UILabel::Draw()
{
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), colour);

	SDL_Texture* Message = SDL_CreateTextureFromSurface(Engine::renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);

	SDL_RenderCopy(Engine::renderer, Message, NULL, &position);
	SDL_DestroyTexture(Message);
}

void UILabel::UpdateMessage(std::string msg)
{
	text = "FPS: " + msg;
}
