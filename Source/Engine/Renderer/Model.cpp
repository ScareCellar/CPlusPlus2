#pragma once
#include "Model.h"
#include "Renderer.h"
namespace blood {

	void Model::Draw(class Renderer& renderer) {

		if (m_points.empty()) return;
		renderer.SetColor(m_color.r, m_color.g, m_color.b);


		//iterate through points and draw connecting lines
		for (int i = 0; i < m_points.size() - 1; i++) {
			vec2 p1 = m_points[i];
			vec2 p2 = m_points[i+1];

			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);

		}
	}
}