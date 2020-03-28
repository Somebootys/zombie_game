// Create background cpp 

#include<SFML/Graphics.hpp>
#include "main.h"

int createBackground(sf::VertexArray& rVA, sf::IntRect arena)
{
  //what is done to rVA is actually done to the background 
  // in the main function 
  
  //tile and tile texture size
  
  const int TILE_SIZE =50;
  const int TILE_TYPES =3; 
  const int VERTS_IN_QUAD = 4; 
  
  int worldWidth  = arena.width / TILE_SIZE;
  int worldHeight = arena.height /TILE_SIZE;
  
  //Type of pimitives udes 
  rVA.setPrimitiveType(sf::Quads);
  
  //Set size of vertex array 
  
  // Set the size of the verted array 
  rVA.resize(worldWidth*worldHeight*VERTS_IN_QUAD);
  
  //start at the beginning of the vertex array 
  int currentVertex = 0; 
  
  for (int w =0; w < worldWidth;w++)
  {
    for(int h = 0; h < worldHeight; h++)
    {
      // position each vertex in the current quad
      rVA[currentVertex + 0].position =
      sf::Vector2f(w*TILE_SIZE, h*TILE_SIZE);
      
      rVA[currentVertex + 1].position =
      sf::Vector2f((w*TILE_SIZE) + TILE_SIZE, h*TILE_SIZE);
      
      rVA[currentVertex + 2].position =
      sf::Vector2f((w*TILE_SIZE) + TILE_SIZE, (h*TILE_SIZE)+TILE_SIZE);
      
      rVA[currentVertex + 3].position =
      sf::Vector2f((w*TILE_SIZE), (h*TILE_SIZE)+TILE_SIZE);
      
      // Define the position in the texture for current quad
      // Either grasss, stone, bush or wall
      if (
      h ==0 || h == worldHeight -1 ||
      w ==0 || w ==worldWidth -1   )
      {
        // wall texture 
        rVA[currentVertex + 0 ].texCoords = 
        sf::Vector2f(0, 0 + TILE_TYPES*TILE_SIZE);
        
        rVA[currentVertex + 1 ].texCoords = 
        sf::Vector2f(TILE_SIZE, 0 + TILE_TYPES*TILE_SIZE);
        
        rVA[currentVertex + 2 ].texCoords = 
        sf::Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES*TILE_SIZE);
        
        rVA[currentVertex + 3 ].texCoords = 
        sf::Vector2f(0, TILE_SIZE  + TILE_TYPES*TILE_SIZE);
      }
      else 
      {
        //Else use random floor texture 
        srand((int)time(0)+ h*w-h);
        int mudOrGrass = (rand()%TILE_TYPES);
        int verticalOffset =mudOrGrass*TILE_SIZE;
        
        rVA[currentVertex + 0].texCoords = 
        sf::Vector2f(0,0+verticalOffset);
        
        rVA[currentVertex + 1].texCoords = 
        sf::Vector2f(TILE_SIZE,0+verticalOffset);
        
        rVA[currentVertex + 2].texCoords = 
        sf::Vector2f(TILE_SIZE,TILE_SIZE+verticalOffset);
        
        rVA[currentVertex + 3].texCoords = 
        sf::Vector2f(0,TILE_SIZE+verticalOffset);
      }
      
      
      //Posittion ready for the next for vertices 
      currentVertex =currentVertex + VERTS_IN_QUAD;
    }
  }
  
  return TILE_SIZE;
  
  
}