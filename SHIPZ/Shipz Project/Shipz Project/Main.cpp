#include <SFML\Graphics.hpp>
#include "SFMLRenderClass.h"



int main()
{
	SFMLRenderClass * game = new SFMLRenderClass();

	while (game->UpdateLoop());

	return 0;
}