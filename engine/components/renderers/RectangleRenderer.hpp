#ifndef RECTANGLERENDERER_HPP
#define RECTANGLERENDERER_HPP

#include "../../Vector2.hpp"
#include "Renderer.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <memory>

/**
 * @class RectangleRenderer
 * @brief A renderer for simple rectangles
 *
 */
class RectangleRenderer : public Renderer {
  protected:
    /**
     * @brief The renderable SDL_FRect
     */
    std::shared_ptr<SDL_FRect> renderable = NULL;
    /**
     * @brief The size of the renderer
     */
    std::shared_ptr<Vector2> size = std::make_shared<Vector2>(0, 0);
    /**
     * @brief The color of the rectangle
     */
    std::shared_ptr<SDL_Color> color = std::make_shared<SDL_Color>();

  public:
    RectangleRenderer(float width, float height);
    ~RectangleRenderer();

    /**
     * @brief Set the color of the rectangle
     *
     * @param r The red color component
     * @param g The green color component
     * @param b The blue color component
     * @param a The alpha color component
     */
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    void setSize(std::shared_ptr<Vector2> value) { size = value; }
    std::shared_ptr<Vector2> getSize() const { return size; }

    void OnTick() override;
    void OnStart() override;
};

#endif // RECTANGLERENDERER_HPP
