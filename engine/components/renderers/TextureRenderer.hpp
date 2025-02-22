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
     * @brief The renderable rectangle used for mapping
     */
    std::shared_ptr<SDL_FRect> renderable = nullptr;
    /**
     * @brief The texture to be rendered
     */
    SDL_Texture *texture = nullptr;
    /**
     * @brief The size of the renderer
     */
    std::shared_ptr<Vector2> size = std::make_shared<Vector2>(0, 0);

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

    void setSize(std::shared_ptr<Vector2> value) { size = value; }
    std::shared_ptr<Vector2> getSize() const { return size; }

    void OnTick() override;
    void OnStart() override;
};

#endif // TEXTURERENDERER_HPP
