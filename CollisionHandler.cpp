#include "CollisionHandler.h"
#include "Engine.h"

CollisionHandler::CollisionHandler()
{
	m_CollisionLayer = (TileLayer*)Engine::GetInstance()->GetMap()->GetMapLayers().back();
	m_CollisionTileMap = m_CollisionLayer->GetTileMap();
}

bool CollisionHandler::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	bool x_Overlaps = (a.x < b.x + b.w) && (a.x + a.w > b.x);
	bool y_Overlaps = (a.y < b.y + b.h) && (a.y + a.h > b.y);
	return (x_Overlaps && y_Overlaps);
}

bool CollisionHandler::MapCollision(SDL_Rect a)
{
	int tileSize = 32;
	int rowCount = 50;
	int colCount = 40;

	int left_Tile = a.x / tileSize;
	int right_Tile = (a.x + a.w) / tileSize;

	int top_Tile = a.y / tileSize;
	int bottom_Tile = (a.y + a.h) / tileSize;

	if (left_Tile < 0) { left_Tile = 0; }
	if (right_Tile > colCount) { right_Tile = colCount; }

	if (top_Tile < 0) { top_Tile = 0; }
	if (bottom_Tile > rowCount) { bottom_Tile = rowCount; }

	for (int i = left_Tile; i <= right_Tile; ++i) {
		for (int j = top_Tile; j <= bottom_Tile; ++j) {
			if (m_CollisionTileMap[j][i] > 0) {
				return true;
			}	
		}
	}
	return false;
}


