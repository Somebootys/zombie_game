#include "TextureHolder.h"
#include<assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;
TextureHolder::TextureHolder()
{
  assert(m_s_Instance == nullptr);
  m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename) 
{
// get a reference to m_Textures using m_s_Instance
auto& m = m_s_Instance ->m_Textures;
// auto is the equivalent of map<string, Textures>

/*Create an iterator to hold a key-value pair (kvp)
and search fro the required kvp using the passed in filename */

auto keyValuePair =m.find(filename);

//Match found ? 
if (keyValuePair != m.end())
{
  /*true return the texture, the second part
                  of the kvp, the texture */
  return keyValuePair->second; 

}
else 
{
  // Filename not found. Create a new key value pair using the filename 
  auto& texture = m[filename];
  texture.loadFromFile(filename);
  
  
  return texture;
  
}


}