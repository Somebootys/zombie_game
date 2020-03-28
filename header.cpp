#pragma once
#inlcude<SFML/Graphics.hpp>

class Player
{
  private:   
  const float START_SPEED = 200;   
  const float START_HEALTH = 100; 
  
  // Where is the player   
  Vector2f m_Position;   
 
  Sprite m_Sprite;   
  
  Texture m_Texture;   

  // What is the screen resolution   
  Vector2f m_Resolution;   

  // What size is the current arena   
  IntRect m_Arena;   

  // How big is each tile of the arena   
  int m_TileSize;   

   
  //Movement 
  bool m_UpPressed;   
  bool m_DownPressed;   
  bool m_LeftPressed;   
  bool m_RightPressed;

  // player stat / variables 
  int m_Health;   
  int m_MaxHealth;    
  Time m_LastHit;   
  float m_Speed;

public:
  Player();
  void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);
  void resetPlayerstats();
  
  bool hit(sf::Time timehit);
  sf::Time getLastHitTime();
  
  sf::FloatRect getPosition();
  // Where is the center of the player
  sf::Vector2f getCenter();
  // what way is player facing
  float getPlayerRotation();
  
  //copy sprite to main function
  sf::Sprite getSprite();

  //Player movement functions
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();

  void stopleft();
  void stopRight();
  void stopUp();
  void stopDown();

  //We will call this function once every frame
  void update(float elapsedTime, sf::Vector2i mousePosition);

  //speed, health- bonus
  void upgradeHealth();

  void increaseHealth(int amount);

  int getPlayerHealth();

};
