#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include "BaseComponent.hpp"
#include "FruitComponent.hpp"

namespace FruitComponent {
	sre::Sprite _sprite;
	std::shared_ptr<sre::SpriteAtlas> _atlas;
	int _grid_count;
	float _time = 0;
	glm::vec2 _grid_pos_idx;


	void FruitComponent::Render(sre::SpriteBatch::SpriteBatchBuilder& builder) {
		builder.addSprite(_sprite);
	}

	void FruitComponent::Init(int grid_count) {
		_grid_count = grid_count;

		_atlas = sre::SpriteAtlas::create("data/snake.json", "data/snake.png");
		_sprite = _atlas->get("berry.png");
		FruitComponent::SetGridPosition();
	}

    void FruitComponent::Update(float deltaTime) {  
		FruitComponent::SetGridPosition();
    }

	void FruitComponent::SetGridPosition() {
		// Update position randomly 0 to 24
		int grid_x = rand() % _grid_count;
		int grid_y = rand() % _grid_count;
		_grid_pos_idx = glm::vec2(grid_x, grid_y);
		
		glm::vec2 grid_pos_pix = BaseComponent::GetGridPosition(_grid_pos_idx);
		_sprite.setPosition(grid_pos_pix);
	}
}