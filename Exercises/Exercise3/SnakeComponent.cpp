#include <list>
#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include "BaseComponent.hpp"
#include "SnakeComponent.hpp"

namespace SnakeComponent {
	std::list<sre::Sprite> _sprites;
	sre::Sprite _sprite;
	std::shared_ptr<sre::SpriteAtlas> _atlas;
	std::list<glm::vec2> _snake_body; 

	void SnakeComponent::Render(sre::SpriteBatch::SpriteBatchBuilder& builder) {
		for each (sre::Sprite sprite in _sprites)
		{
			builder.addSprite(sprite);
		}
	}
	void SnakeComponent::Init(glm::vec2 start_grid_pos_idx) {

		_atlas = sre::SpriteAtlas::create("data/snake.json", "data/snake.png");
		// Head
		_sprite = _atlas->get("snake-body.png");
		
		_sprites.push_back(_sprite);
		_snake_body.push_back(start_grid_pos_idx);
		// Add 2 more body parts
		_sprites.push_back(_sprite);
		_sprites.push_back(_sprite);
		_snake_body.push_back(glm::vec2(start_grid_pos_idx.x - 1, start_grid_pos_idx.y));
		_snake_body.push_back(glm::vec2(start_grid_pos_idx.x - 2, start_grid_pos_idx.y));


		SnakeComponent::SetGridPosition();
	}

	void SnakeComponent::Update(float deltaTime, glm::vec2 direction) {
		// Get current head position
		glm::vec2 grid_pos_idx = _snake_body.front();
		// Remove tail
		_snake_body.pop_back();
		// Add new head
		grid_pos_idx = glm::vec2(grid_pos_idx.x + direction.x, grid_pos_idx.y + direction.y);
		_snake_body.push_front(grid_pos_idx);
		SnakeComponent::SetGridPosition();
	}

	void SnakeComponent::SetGridPosition() {
		std::list<glm::vec2>::iterator it1 = _snake_body.begin();
		std::list<sre::Sprite>::iterator it2 = _sprites.begin();

		while (it1 != _snake_body.end() && it2 != _sprites.end()) {

			glm::vec2 grid_pos_pix = BaseComponent::GetGridPosition(*it1);
			(*it2).setPosition(grid_pos_pix);

			it1++;
			it2++;
		}
	}
}