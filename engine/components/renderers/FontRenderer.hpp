#ifndef FONTRENDERER_HPP
#define FONTRENDERER_HPP

#include "Renderer.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
/**
 * @class FontRenderer
 * @brief A component to render text to the screen on a GameObject
 *
 */
class FontRenderer : public Renderer {
  protected:
    /**
     * @brief The text to render
     */
    std::string text = "";
    /**
     * @brief The surface created from the text
     */
    SDL_Surface *surface = nullptr;
    /**
     * @brief The texture created from the surface
     */
    SDL_Texture *texture = nullptr;
    /**
     * @brief The font to use to draw the text
     */
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
    void setSize(std::shared_ptr<Vector2> value) { size = value; }
    std::shared_ptr<Vector2> getSize() const { return size; }
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
