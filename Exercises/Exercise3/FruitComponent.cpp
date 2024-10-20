#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include "FruitComponent.hpp"
#include <cstdlib>

namespace FruitComponent {
	sre::Sprite _sprite;
	std::shared_ptr<sre::SpriteAtlas> _atlas;
	glm::vec2 _window_size;
	int _grid_count;
	glm::vec2 _grid_size;
	float _time = 0;


	void FruitComponent::Render(sre::SpriteBatch::SpriteBatchBuilder& builder) {
		builder.addSprite(_sprite);
	}

	void FruitComponent::Init(glm::vec2 window_size, glm::vec2 grid_size, int grid_count) {
		_window_size = window_size;
		_grid_size = grid_size;
		_grid_count = grid_count;

		_atlas = sre::SpriteAtlas::create("data/snake.json", "data/snake.png");
		_sprite = _atlas->get("berry.png");

	}

    void FruitComponent::Update(float deltaTime) {  

		_time += deltaTime;

		if (_time < 1) {
			return;
		}

		_time = 0;

		// Update position randomly 0 to 24
		int grid_x = rand() % _grid_count;
        int grid_y = rand() % _grid_count;

		std::cout << "grid_x: " << grid_x << " grid_y: " << grid_y << std::endl;

		int pos_x = _window_size.x - (_grid_size.x * grid_x) - _grid_size.x / 2;
		int pos_y = _window_size.y - (_grid_size.y * grid_y) - _grid_size.y / 2;

		glm::vec2 new_pos = glm::vec2(pos_x, pos_y);
		_sprite.setPosition(new_pos);  
    }
}