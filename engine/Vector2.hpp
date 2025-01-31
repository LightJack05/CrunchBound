#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
      protected:
        float x = 0;
        float y = 0;

      public:
        float getX() const { return x; };
        void setX(float value) { x = value; };
        float getY() const { return y; };
        void setY(float value) { y = value; };

        float getMaginitude();

        Vector2();
        Vector2(float x, float y);
        ~Vector2();
};

#endif // VECTOR2_HPP
