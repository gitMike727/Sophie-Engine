#include "Camera.h"

Camera* Camera::s_Instance = nullptr;

void Camera::Update(float dt)
{
	if(m_Target != nullptr) {
		m_CamView.x = m_Target->X - SCREEN_WIDTH / 2;
		m_CamView.y = m_Target->Y - SCREEN_HEIGHT / 2;

		if(m_CamView.x < 0) {
			m_CamView.x = 0;
		}

		if (m_CamView.y < 0) {
			m_CamView.y = 0;
		}

		if(m_CamView.x > (2 * SCREEN_WIDTH - m_CamView.w)) {
			m_CamView.x = (2 * SCREEN_WIDTH - m_CamView.w);
		}

		if (m_CamView.y > (SCREEN_HEIGHT - m_CamView.h)) {
			m_CamView.y = (SCREEN_HEIGHT - m_CamView.h);
		}



		m_Position = Vector2D(m_CamView.x, m_CamView.y);
	}
}
