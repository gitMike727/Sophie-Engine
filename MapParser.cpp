#include "MapParser.h"

MapParser* MapParser::s_Instance = nullptr;

bool MapParser::Load()
{
	if (!Parse("MainMap", "assets/maps/main_Map.tmx"))
		return false;
	return true;
}


bool MapParser::Parse(std::string id, std::string source)
{
	TiXmlDocument xml;
	xml.LoadFile(source);

	if (xml.Error()) {
		std::cerr << "Failed to load: " << source << std::endl;
		return false;
	}

	TiXmlElement* root = xml.RootElement();
	
	int rowCount{}, colCount{}, tileSize = 0;

	root->Attribute("width", &colCount);
	root->Attribute("height", &rowCount);
	root->Attribute("tilewidth", &tileSize);

	//Parse Tilesets
	TilesetList tilesets;
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("tileset")) {
			tilesets.push_back(ParseTileset(e));
		}
	}

	//Parse TileLayers
    GameMap* gameMap = new GameMap();
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("layer")) {
			TileLayer* tileLayer = ParseTileLayer(e, tilesets, tileSize, rowCount, colCount);
			gameMap->m_MapLayers.push_back(tileLayer);
		}
	}

	m_MapDict[id] = gameMap;
	return true;
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
	TiXmlElement* data{};
	for (TiXmlElement* e = xmlTileLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("data")) {
			data = e;
			break;
		}
	}

	if (!data) {
		std::cerr << "No data element found in tile layer." << std::endl;
		return nullptr;
	}

	std::string matrix(data->GetText());
	std::istringstream iss(matrix);
	std::string id;

	TileMap tileMap(rowCount, std::vector<int>(colCount, 0));

	for (int row = 0; row < rowCount; row++) {
		for (int col = 0; col < colCount; col++) {
			getline(iss, id, ',');
			std::stringstream convertor(id);
			convertor >> tileMap[row][col];

			if (!iss.good()) {
				break;
			}
		}
	}

	return (new TileLayer(tileSize, rowCount, colCount, tileMap, tileSets)); 
}

void MapParser::Clean()
{
	std::map<std::string, GameMap*>::iterator it;
	for (it = m_MapDict.begin(); it != m_MapDict.end(); it++) {
		it->second = nullptr;
	}

	m_MapDict.clear();
}