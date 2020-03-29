#include<iostream>
#include<math.h>
#include<SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime> 
#include<math.h>
//#include "createHorde.h"
#include "main.h"
#include "player.h"
#include "TextureHolder.h"
#include "Zombie.h"




int main()
{
  TextureHolder holder; 
  //The has four states and will always be in 1 of four states
  enum class State
    {
     PAUSED, LEVELING_UP,GAME_OVER,PLAYING
    };

  
  // The GAME OVER STATE
  State state = State::GAME_OVER;

  //Get screen resolution and creat an SFML window
  sf::Vector2f resolution;
  resolution.x = sf::VideoMode::getDesktopMode().width;
  resolution.y = sf::VideoMode::getDesktopMode().height;

sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y),
			"Zombie Game", sf::Style::Fullscreen);

//Create an SFML window for main action
sf::View mainView(sf::FloatRect(0,0,resolution.x,resolution.y));

sf::Clock clock;

//how long has the PLAYING_STATE been active
sf::Time gameTimeTotal;

//Where is the mouse in relation to the world coordinations
sf::Vector2f mouseWorldPosition;
// where is the mouse in relation to the screen coordinates
sf::Vector2i mouseScreenPosition;

// Create an instance of the Player class
Player player;

//The boundaries of the arena
sf::IntRect arena;

//Create the background 
sf::VertexArray background;
//Load the texture for our background vertex array
sf::Texture textureBackground;
textureBackground.loadFromFile("graphics/background_sheet.png");

// Prepare Zombies
int numZombies;
int numZombiesAlive;
Zombie* zombies = nullptr; 


// the main game loop ------------------------------------------
while (window.isOpen())
  {
     //Put game stuff here like last time "Time stamp 3min:23sec in totutial 
    
    sf::Event event;
    while (window.pollEvent(event))
    {
    if (event.type == sf::Event::KeyPressed)
      {
      if(event.type==sf::Keyboard::Return && 
      state== State::PLAYING)
      {
        state== State::PAUSED;
        //restarting the clock to avoid frame skip
        clock.restart();
      }
      
      else if(event.key.code ==sf::Keyboard::Return && 
      state == State::GAME_OVER)
      {
        state = State::LEVELING_UP;
      }
      if (state ==State::PLAYING)
      {
        //the main game here 
      }
  
      } 
     } // end of while  (pollEvent)
    // How to quit 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      window.close();
    }
    if (state == State::PLAYING)
    {
      // WASD keys 
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      {
      player.moveUp();
      }
      else
      {
        player.stopUp();
      }
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      {
        player.moveDown();
      }
      else
      {
        player.stopDown();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      {
        player.moveLeft();
      }
      else
      {
      player.stopLeft();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      {
      player.moveRight();
      }
      else
      {
      player.stopRight();
      }
    }  //end wasd while playing 
    
      // Handle the player leveling up 
    if (state == State::LEVELING_UP)
    {
    if (event.key.code == sf::Keyboard::Num1)
    {
      state = State::PLAYING;
    }
     if (event.key.code == sf::Keyboard::Num2)
    {
      state = State::PLAYING;
    }
     if (event.key.code == sf::Keyboard::Num3)
    {
      state = State::PLAYING;
    }
     if (event.key.code == sf::Keyboard::Num4)
    {
      state = State::PLAYING;
    }
     if (event.key.code == sf::Keyboard::Num5)
    {
      state = State::PLAYING;
    }
     if (event.key.code == sf::Keyboard::Num6)
    {
      state = State::PLAYING;
    }
    
    if (state == State::PLAYING)
    {
      //Prepare level
      arena.width  =1000;
      arena.height = 1000; 
      arena.left   = 0;
      arena.top    = 0; 
      
      
      // Pass the vertx array by reference
      //to the createBackground function
      int tileSize = createBackground(background, arena);

      
      //Spawning the player in the middle of the arena 
      player.spawn(arena, resolution, tileSize);
      // Reset the clock so there isn't a frame jump 
      
         // Create a horde of zombies
   numZombies = 10;

   // Delete the previously allocated memory (if it exists)
  delete[] zombies;
   zombies = createHorde(numZombies, arena);
   numZombiesAlive = numZombies; 
 
   // Reset the clock so there isn't a frame jump 
   clock.restart(); 
    }
    } /// End Handle LEVELING 
    
    /*
   ****************
   UPDATE THE FRAME
   ****************
   */
   if ( state == State::PLAYING)
   {
    //update the delta time 
    sf::Time dt =clock.restart();
    
    //Update the total game time
    gameTimeTotal += dt; 
    
    //Make decimal fraction of 1 from the delta time 
    float dtAsSeconds = dt.asSeconds();
    
    //Where is the mouse pointer 
    mouseScreenPosition = sf::Mouse::getPosition();
    
    // convert mouse posiotin to world coordinates of mainView
    mouseWorldPosition = window.mapPixelToCoords(sf::Mouse::getPosition(),
    mainView);
    
    //update the player
    player.update(dtAsSeconds, sf::Mouse::getPosition());
    
    // make a note of the players new position 
    sf::Vector2f playerPosition(player.getCenter());
    
    //Make the view centre around the player 
    mainView.setCenter(player.getCenter());
    
    // Loop through each zombie and update them 
    for ( int i = 0; i < numZombies; i++)
    {
      if (zombies[i].isAlive())
      {
        zombies[i].update(dt.asSeconds(), playerPosition);
      }
    }
   
   }// End updating scen 
        /*
     **************
     Draw the scene
     **************
     */
     if (state == State::PLAYING)
     {
        window.clear();

        // set the mainView to be displayed in the window
        // And draw everything related to it
        window.setView(mainView);
        
        //draw the bakground / arena 
        window.draw(background, &textureBackground);
        
        //Draw the zombies 
        for (int i = 0 ; i < numZombies ; i++)
        {
          window.draw(zombies[i].getSprite());
        }

        // Draw the player
        window.draw(player.getSprite());
          }

     if (state == State::LEVELING_UP)
     {
     }
     if (state == State::PAUSED)
     {
     }
     if (state == State::GAME_OVER)
     {
     
     }
     window.display(); 
  }// end game loop 
  return 0; 
  
  }