#include "Texture.h"

eng::Texture::Texture(const filepath& path)
{
	
	if(mTexture.loadFromFile(path) == -1)
	{
		std::cerr << "Error: Textur konnte nicht gefunden werden" << std::endl;
	}
}