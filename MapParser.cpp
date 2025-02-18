#include "MapParser.h"

bool MapParser::Load()
{
	return Parse("Level1", "assets/maps/main_Map.tmx");
}

void MapParser::Clean()
{
}

inline GameMap* MapParser::GetMaps()
{
	return nullptr;
}

bool MapParser::Parse(std::string id, std::string source)
{
	return false;
}

Tileset MapParser::ParseTileset(TiXmlElement* xmlTileset)
{
	Tileset tileSet;
	tileSet.name = xmlTileset->Attribute("name");
	xmlTileset->Attribute("firstgid", &tileSet.firstID);

	xmlTileset->Attribute("tilecount", &tileSet.tileCount);
	tileSet.lastID = (tileSet.firstID + tileSet.tileCount) - 1;

	xmlTileset->Attribute("columns", &tileSet.colCount);
	tileSet.rowCount = tileSet.tileCount / tileSet.tileCount;
	xmlTileset->Attribute("tilewidth", &tileSet.tileSize);

	TiXmlElement* image = xmlTileset->FirstChildElement();
	tileSet.source = image->Attribute("source");

	return tileSet;
}

TileLayer* MapParser::ParseTileLayer(TiXmlElement* xmlTileLayer, TilesetList tileSets, int tileSize, int rowCount, int colCount)
{
	return nullptr;
}
