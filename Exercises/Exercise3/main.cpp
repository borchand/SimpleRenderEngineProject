// the easy way
// modified from 00_hello-engine.cpp
#include "sre/SDLRenderer.hpp"
void handle_mouse(SDL_Event& e) { /* do stuff */; }
int main() {
 sre::SDLRenderer r;
 r.init();
 r.mouseEvent = handle_mouse;
 r.frameRender = []{
 sre::RenderPass rp = sre::RenderPass::create().build();
 rp.drawLines({{0,0,0},{0,0,0}});
 rp.finish();
 };

 r.startEventLoop();
 return 0;
}