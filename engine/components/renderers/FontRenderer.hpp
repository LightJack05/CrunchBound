#ifndef FONTRENDERER_HPP
#define FONTRENDERER_HPP

#include "Renderer.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
class FontRenderer : public Renderer {
  protected:
    std::string text = "";
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;
    TTF_Font *font = nullptr;
    /**
     * @brief The size of the renderer
     */
    std::shared_ptr<Vector2> size = std::make_shared<Vector2>(0, 0);
    /**
     * @brief The renderable rectangle used for mapping
     */
    std::shared_ptr<SDL_FRect> renderable = nullptr;
    /**
     * @brief The color of the font
     */
    std::shared_ptr<SDL_Color> color = std::make_shared<SDL_Color>();

  public:
    FontRenderer(std::string pathToFont, float size);
    ~FontRenderer();
    void setText(std::string value) { text = value; }
    std::string getText() const { return text; }
    /**
     * @brief Set the color of the rectangle
     *
     * @param r The red color component
     * @param g The green color component
     * @param b The blue color component
     * @param a The alpha color component
     */
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void OnTick() override;
    void OnStart() override;
};

#endif // FONTRENDERER_HPP
