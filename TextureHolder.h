#pragma once 

#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include <map>

class TextureHolder
{
      private:
      //A map container from the STL,
      // That holds related pairs of String and Texture
      std::map<std::string, sf::Texture> m_Textures;
      
      //A pointer as the same type as the class itself
      // the one and only instance
      static TextureHolder* m_s_Instance;
      
      
      public: 
     TextureHolder(); 
     static sf::Texture& GetTexture(std::string const& filename); 



};









#endif