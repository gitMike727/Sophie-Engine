#pragma once

#include "Layer.h"
#include <string>
#include <vector>

struct Tileset {
	int firstID, lastID;
	int rowCount, colCount;
	int tileCount, tileSize;
	std::string name, source;
};

using TilesetList = std::vector<Tileset> ;
using TileMap = std::vector<std::vector<int> >;


class TileLayer : public Layer{
public:
	TileLayer(int tileSize, int rowCount, int colCount, TileMap tileMap, TilesetList tileSets);
	virtual void Render();
	virtual void Update();
	inline TileMap GetTileMap() { return m_TileMap; }

private:
	int m_TileSize;
	int m_RowCount, m_ColCount;

	TileMap m_TileMap;
	TilesetList m_Tilesets;

};

