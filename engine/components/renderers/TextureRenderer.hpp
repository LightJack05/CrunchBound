#ifndef TEXTURERENDERER_HPP
#define TEXTURERENDERER_HPP

#include "Renderer.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <memory>

/**
 * @class TextureRenderer
 * @brief A renderer for textures
 *
 */
class TextureRenderer : public Renderer {
  protected:
    /**
     * @brief The renderable texture
     */
    std::shared_ptr<SDL_FRect> renderable = nullptr;
    SDL_Texture *texture = nullptr;
    /**
     * @brief The size of the renderer
     */
    std::shared_ptr<Vector2> size = std::make_shared<Vector2>(0, 0);
    /**
     * @brief The color of the rectangle
     */
    std::shared_ptr<SDL_Color> color = std::make_shared<SDL_Color>();

  public:
    /**
     * @brief Create a new texture renderer
     *
     * @param width The width of the new renderer
     * @param height The height of the new renderer
     * @param pathToTexture The path to the texture
     */
    TextureRenderer(float width, float height, std::string pathToTexture);
    ~TextureRenderer();

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

#endif // TEXTURERENDERER_HPP
