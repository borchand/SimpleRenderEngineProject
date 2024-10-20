#include "sre/SDLRenderer.hpp"

namespace SnakeEngine {
    void Init();
    void ProcessEvents(SDL_Event& event);
    void Update(float deltaTime);
    void Render();
    glm::vec2 GetWindowSize();
}
