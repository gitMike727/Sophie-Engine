 #pragma once

#include "Layer.h"
#include <vector>

class GameMap {
public:
	void Render() {
		for (unsigned int i = 0; i < m_MapLayers.size(); i++)
			m_MapLayers[i]->Render();
	}

	void Update() {
		for (unsigned int i = 0; i < m_MapLayers.size(); i++)
			m_MapLayers[i]->Update();
	}

	std::vector<Layer*> GetMapLayers() { return m_MapLayers; }

private:
	friend class MapParser;
	std::vector<Layer*> m_MapLayers;
};
