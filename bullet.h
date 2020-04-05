#pragma once
#include <SFML/Graphics.hpp>

class Bullet 
{
private: 
/*Bullet location*/
sf::Vector2f m_Position;

/*Bullet shape*/
sf::RectangleShape m_BulletShape;

//Bullet in air or no ? 
bool m_InFlight =false;

//Bullet travel speed 
float m_BulletSpeed = 1000; 

/* what fraction of a pix does a bulle travel 
Horizontally or vertically ? These values can be derived from
the bullet speed */

float m_BulletDistanceX;
float m_BulletDistanceY;

// Boundaries to stop the bullet from flying 4eva and thus saving memory
float m_MaxX, m_MinX, m_MaxY, m_MinY;



// Public function prototypes go here 
public: 

//the bullet constructor 
Bullet();

//stopping the bullet 
void stop();

//in flight getter 
bool  isInFlight();

// fire a new bullet 
void shoot(float startX, float startY, 
float xTarget, float yTarget);

  // Tell the calling code where the bullet is in the world
sf::FloatRect getPosition();

//Shape getter 
sf::RectangleShape getShape();

//Update bullet pr frame

void update(float elapsedTime);



};