#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <map>

class Graphics {
  public:

    Graphics();
    ~Graphics();

    static const int kWidth = 640;
    static const int kHeight = 480;

    void blit(const std::string& file, const SDL_Rect* srect, const SDL_Rect* drect);
    void flip();
    void clear();

    SDL_Texture* load_image(const std::string& file);

  private:

    typedef std::map<std::string, SDL_Texture*> TextureMap;
    TextureMap textures;
    SDL_Window* window;
    SDL_Renderer* renderer;
};
