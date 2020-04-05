#include "bullet.h"

// Constructor 
Bullet::Bullet()
  {
    m_BulletShape.setSize(sf::Vector2f(2,2));
    
  }
  
  void Bullet::shoot(float startX, float startY, 
  float targetX, float targetY )
  {
    // keep tract of the bullet 
    m_InFlight = true;
    m_Position.x = startX; 
    m_Position.y = startY;
    
    /* Calc gradient/slope of the flight path */
    float gradient = (startX-targetX) / ( startY - targetY);
    
    // If the gradient is less than 0 should increment negativelyt 
    if (gradient < 0)
    {
      gradient *= -1;
    }
     // I have commented this out because I think this is wrong 
    
    
       // Calculate the ratio between x and y 
   float ratioXY = m_BulletSpeed / (1 + gradient); 
    // Set the "speed" horizontally and vertically 
   m_BulletDistanceY = ratioXY; 
   m_BulletDistanceX = ratioXY * gradient; 
   
   
   if (targetX < startX)
   {
    m_BulletDistanceY *=-1;
    
   }
   // Set a max range of 1000 pixels 
   float range = 1000; 
   m_MinX = startX - range; 
   m_MaxX = startX + range; 
   m_MinY = startY - range; 
   m_MaxY = startY + range; 
   
      // Position the bullet ready to be drawn 
   m_BulletShape.setPosition(m_Position); 
   }
   
   
   void Bullet::update(float elapsedTime)
   {
    m_Position.x+=m_BulletDistanceX * elapsedTime;
    m_Position.y+=m_BulletDistanceY * elapsedTime;
    
    //Move bullet 
    m_BulletShape.setPosition(m_Position);
    
    //Bullet in or out of range 
    if (m_Position.x > m_MinX || m_Position.x > m_MaxX ||
        m_Position.y < m_MinY || m_Position.y > m_MaxY)
        {
          m_InFlight = false;
        }
    
    }
    
    
    
    void Bullet::stop() 
{ 
   m_InFlight = false; 
} 
 
bool Bullet::isInFlight() 
{ 
   return m_InFlight; 
} 
 
sf::FloatRect Bullet::getPosition() 
{ 
   return m_BulletShape.getGlobalBounds(); 
} 
 
sf::RectangleShape Bullet::getShape() 
{ 
   return m_BulletShape; 

    
    
    
   }
   
   
   
   
   
   
   
  