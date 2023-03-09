#ifndef ANIMATION_INCLUDE
#define ANIMATION_INCLUDE

  #include <vector>
  #include <SFML/Graphics/Rect.hpp>
  #include <SFML/Graphics/Texture.hpp>
  #include <SFML/System/Time.hpp>
  #include <SFML/Graphics/RenderTarget.hpp>
  #include <SFML/System/Clock.hpp>

class Animation {
  public:
    Animation();
    Animation(const sf::Texture& texture);
    // Setters
    void setIsLoop(bool isLoop);
    void setInterval(sf::Time interval);
    // Getters
    bool getIsPlaying();
    const sf::Texture* getTexture();
    void setTexture(const sf::Texture& texture);
    sf::IntRect getCurrentFrame();
    // Methods
    void start();
    void stop();

    void addFrame(sf::IntRect frame);

    void addFrames(
      unsigned int numberOfFrames, sf::IntRect firstFrame, 
      unsigned int incrementX, unsigned int incrementY = 0
    );

    void update();

  private:
    std::vector<sf::IntRect> m_frames;
    const sf::Texture* m_texture;
    sf::Clock m_clock;
    int m_currentFrame;
    sf::Time m_interval;
    bool m_isLoop;
    bool m_isPlaying;

};

#endif