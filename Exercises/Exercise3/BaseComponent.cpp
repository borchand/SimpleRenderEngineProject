#include "sre/SDLRenderer.hpp"
#include "BaseComponent.hpp"

namespace BaseComponent {
	glm::vec2 _window_size;
	glm::vec2 _grid_size;

	void BaseComponent::Init(glm::vec2 window_size, glm::vec2 grid_size) {
		_window_size = window_size;
		_grid_size = grid_size;
	}

	glm::vec2 BaseComponent::GetGridPosition(glm::vec2 grid_pos_idx) {

		std::cout << "grid_x: " << grid_pos_idx.x << " grid_y: " << grid_pos_idx.y << std::endl;

		int pos_x = _window_size.x - (_grid_size.x * grid_pos_idx.x) - _grid_size.x / 2;
		int pos_y = _window_size.y - (_grid_size.y * grid_pos_idx.y) - _grid_size.y / 2;

		return glm::vec2(pos_x, pos_y);
	}
}