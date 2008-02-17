/*
  This file is part of Rusty's Raytracer.

  Rusty's Raytracer is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version.

  Rusty's Raytracer is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  Rusty's Raytracer.  If not, see <http://www.gnu.org/licenses/>.

  Copyright 2008 Rusty Burchfield
*/

#ifndef WORLD_H_
#define WORLD_H_

#include "models/CompositeModel.h"
#include "common.h"

#include "Light.h"

class World : public CompositeModel
{
public:
	World();
	virtual ~World();
	void addLight(const Light *l);
	const vector<const Light*>* getLights() const;
private:
	vector<const Light*> lights;
	DISALLOW_EVIL_CONSTRUCTORS(World);
};

#endif /*WORLD_H_*/
