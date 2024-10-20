#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

namespace FruitComponent {
    void Init(glm::vec2 window_size, glm::vec2 grid_size, int grid_count);
    void Update(float deltaTime);
    void Render(sre::SpriteBatch::SpriteBatchBuilder& builder);
}