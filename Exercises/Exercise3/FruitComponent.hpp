#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

namespace FruitComponent {
    void Init(int grid_count);
    void Update(float deltaTime);
    void Render(sre::SpriteBatch::SpriteBatchBuilder& builder);
	void SetGridPosition();
}