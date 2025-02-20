#include "TileLayer.h"
#include "TextureManager.h"



TileLayer::TileLayer(int tileSize, int rowCount, int colCount, TileMap tileMap, TilesetList tileSets) : \
m_TileSize (tileSize), m_ColCount (colCount), m_RowCount (rowCount), m_TileMap (tileMap), m_Tilesets (tileSets) {
	 	for (unsigned int i = 0; i < m_Tilesets.size(); i++) {
		TextureManager::GetInstance()->Load(m_Tilesets[i].name, "assets/maps/" + m_Tilesets[i].source);
	}
}

void TileLayer::Render()
{
	for (unsigned int i = 0; i < m_RowCount; i++) {
		for (unsigned int j = 0; j < m_ColCount; j++) {
			int tileID = m_TileMap[i][j];

			if (tileID == 0) 
				continue;
			else {
				int tileset_index{};
				if (m_Tilesets.size() > 1) {
					for (unsigned int k = 1; k < m_Tilesets.size(); k++) {
						if (tileID > m_Tilesets[k].firstID && tileID < m_Tilesets[k].lastID) {
							tileID = tileID + m_Tilesets[k].tileCount - m_Tilesets[k].lastID;
							tileset_index = k;
							break; 
						}
					}
				}
				Tileset ts = m_Tilesets[tileset_index];
				int tileRow = tileID / ts.colCount;
				int tileCol = tileID - tileRow * ts.colCount - 1;

				//if this tile is on the last column
				if (tileID % ts.colCount == 0) {
					tileRow--;
					tileCol = ts.colCount - 1;
				}

				TextureManager::GetInstance()->DrawTile(ts.name, ts.tileSize, j * ts.tileSize, i * ts.tileSize, tileRow, tileCol);
			}
		}
	}
}

void TileLayer::Update()
{
}
