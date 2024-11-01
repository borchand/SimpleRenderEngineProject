#include "sre/SDLRenderer.hpp"

namespace SnakeComponent {
	void Init(glm::vec2 start_grid_pos_idx);
	void Update(float deltaTime, glm::vec2 direction);
	void Render(sre::SpriteBatch::SpriteBatchBuilder& builder);
	void SetGridPosition();
}