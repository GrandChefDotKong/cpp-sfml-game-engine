#ifndef CHARACTER_INCLUDE
#define CHARACTER_INCLUDE

  #include "AnimatedSprite.hpp"
  #include <iostream>

  const unsigned short int SPEED = 7;
  enum Direction { UP, DOWN, LEFT, RIGHT };

class Character: public AnimatedSprite {
  public:
    Character();
    Character(sf::Texture& texture);
    void move();

    void update();

  private:
    Direction m_direction;
    int m_speedX;
    int m_speedY;
  
};

#endif