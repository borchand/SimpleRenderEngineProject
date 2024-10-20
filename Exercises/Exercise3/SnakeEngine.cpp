// SnakeEngine.cpp
#include "SnakeEngine.hpp"
#include "FruitComponent.hpp"
#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

namespace SnakeEngine {
	sre::SDLRenderer renderer;
	sre::Camera _camera;
	glm::vec2 window_size = glm::vec2(700, 700);
	int grid_count = 25;
	glm::vec2 grid_size = glm::vec2(window_size.x / grid_count, window_size.y / grid_count);


	void SnakeEngine::Init() {
		// setup terminal for realtime game
		renderer.frameRender = Render;
		renderer.frameUpdate = Update;
		renderer.keyEvent = ProcessEvents;
		renderer.setWindowSize(window_size);
		renderer.init();
		_camera.setWindowCoordinates();

		FruitComponent::Init(window_size, grid_size, grid_count);

		renderer.startEventLoop();
	}

	void SnakeEngine::ProcessEvents(SDL_Event& event) { }

	void SnakeEngine::Update(float deltaTime) { 
		FruitComponent::Update(deltaTime);
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