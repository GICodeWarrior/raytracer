#include "World.h"

World::World()
{
}

World::~World()
{
}

void World::addLight(Light l)
{
	lights.push_back(l);
}
