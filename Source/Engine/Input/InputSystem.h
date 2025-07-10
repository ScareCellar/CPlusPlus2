#pragma once
#include <vector>
#include "../Core/Math/Vector2.h"
#include <array>


namespace blood {
	class InputSystem {
	public:
		InputSystem() = default;

		bool Initialize();
		void ShutDown();

		void Update();

		//keyboard input
		bool GetKeyDown(uint8_t key) { return m_keyboardState[key]; }
		bool GetPreviosKeyDown(uint8_t key) { return m_prevKeyboardState[key]; }
		bool GetKeyPressed(uint8_t key) { return !m_prevKeyboardState[key] && m_keyboardState[key]; }
		bool GetKeyReleased(uint8_t key) { return m_prevKeyboardState[key] && !m_keyboardState[key]; }


		//Mouse Input
		bool GetMouseButtonDown(uint8_t button) { assert(button < 3); return m_mouseButtonState[button]; }

		const vec2& GetMousePosition() const { return m_mousePosition; }
		const vec2& GetPrevMousePosition() const { return m_prevMousePosition; }



	private:
		std::vector<bool> m_keyboardState;
		std::vector<bool> m_prevKeyboardState;

		vec2 m_mousePosition{ 0,0 };
		vec2 m_prevMousePosition{ 0,0 };

		std::array<bool, 3> m_mouseButtonState{ false, false, false };
		std::array<bool, 3> m_prevMouseButtonState{ false, false, false };
		
	};
}
