#ifndef VECTOR2_HPP
#define VECTOR2_HPP

/**
 * @class Vector2
 * @brief A Vector representing floating point coordinates in two dimensions
 *
 */
class Vector2 {
  protected:
    /**
     * @brief The x element of the vector
     */
    float x = 0;
    /**
     * @brief The y element of the vector
     */
    float y = 0;

  public:
    float getX() const { return x; };
    void setX(float value) { x = value; };
    float getY() const { return y; };
    void setY(float value) { y = value; };

    /**
     * @brief Return the magnitude of the vector
     *
     * @return The magnitude of the vector
     */
    float getMaginitude();

    Vector2();
    /**
     * @brief Create a new Vector2 with x and y set to the parameter values
     *
     * @param x The X coordinate of the vector
     * @param y The Y coordinate of the vector 
     */
    Vector2(float x, float y);
    ~Vector2();
};

#endif // VECTOR2_HPP
