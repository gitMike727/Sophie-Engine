#pragma once

class Engine
{
public:
	// Singleton
	static Engine* GetInstance() {
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
	}

	void Init();
	bool Clean();
	void Quit();

	void Update();
	void Render();
	void Event();

	inline bool IsRunning() { return m_IsRunning; }

private:
	Engine() {}
	bool m_IsRunning;
	static Engine* s_Instance;
	
};

