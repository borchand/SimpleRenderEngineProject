// SnakeEngine.cpp
#include "SnakeEngine.hpp"
#include "BaseComponent.hpp"
#include "FruitComponent.hpp"
#include "SnakeComponent.hpp"
#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

namespace SnakeEngine {
	sre::SDLRenderer renderer;
	sre::Camera _camera;
	glm::vec2 window_size = glm::vec2(700, 700);
	int grid_count = 25;
	float time = 0;
	glm::vec2 grid_size = glm::vec2(window_size.x / grid_count, window_size.y / grid_count);
	glm::vec2 _direction = glm::vec2(1, 0);


	void SnakeEngine::Init() {
		// setup terminal for realtime game
		renderer.frameRender = Render;
		renderer.frameUpdate = Update;
		renderer.keyEvent = ProcessEvents;
		renderer.setWindowSize(window_size);
		renderer.init();
		_camera.setWindowCoordinates();

		BaseComponent::Init(window_size, grid_size);
		SnakeComponent::Init(glm::vec2(grid_count / 2, grid_count / 2));
		FruitComponent::Init(grid_count);

		renderer.startEventLoop();
	}

	void SnakeEngine::ProcessEvents(SDL_Event& event) { 
		switch (event.key.keysym.sym) {
			case SDLK_w: case SDLK_UP:
				if (_direction != glm::vec2(0, 1))
				{
					_direction = glm::vec2(0, -1);
				}
				break;
			case SDLK_s: case SDLK_DOWN:
				if (_direction != glm::vec2(0, -1)) {
					_direction = glm::vec2(0, 1);
				}
				break;
			case SDLK_a: case SDLK_LEFT:
				if (_direction != glm::vec2(-1, 0)) {
					_direction = glm::vec2(1, 0);
				}
				break;
			case SDLK_d: case SDLK_RIGHT:
				if (_direction != glm::vec2(1, 0)) {
					_direction = glm::vec2(-1, 0);
				}
				break;
		}
	}

	void SnakeEngine::Update(float deltaTime) { 
		time += deltaTime;
		if (time > .5) {
			time = 0;
			SnakeComponent::Update(deltaTime, _direction);
			FruitComponent::Update(deltaTime);
		}
	}

	void SnakeEngine::Render()
	{
		sre::RenderPass renderPass = sre::RenderPass::create()
			.withCamera(_camera)
			.withClearColor(true, { .3f, .3f, 1, 1 })
			.build();
		sre::SpriteBatch::SpriteBatchBuilder spriteBatchBuilder = sre::SpriteBatch::create();
		// send spriteBatchBuilder to your game elements, so that
		// they can add their sprites for rendering
		
		SnakeComponent::Render(spriteBatchBuilder);
		FruitComponent::Render(spriteBatchBuilder);
		

		// create grid lines
		for (int i = 0; i < window_size.x; i += grid_size.x) {
			renderPass.drawLines({ { i, 0, 0 }, { i, window_size.y, 0} });
		}

		for (int i = 0; i < window_size.y; i += grid_size.y) {
			renderPass.drawLines({ { 0, i, 0 }, { window_size.x, i, 0} });
		}

		auto spriteBatch = spriteBatchBuilder.build();
		renderPass.draw(spriteBatch);
	}

	glm::vec2 SnakeEngine::GetWindowSize() {
		return window_size;
	}
}