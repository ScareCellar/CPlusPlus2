#pragma once

namespace blood {
	class ParticleSystem {
		ParticleSystem() = default;

		bool Initialize();
		void Shutdown();

		void Update();
		void Draw(class Renderer& renderer);


	};
}