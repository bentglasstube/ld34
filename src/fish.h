#pragma once

#include <boost/scoped_ptr.hpp>

#include "object.h"
#include "sprite.h"

class Fish : public Object {
  public:

    Fish(float x, float y);

    void update(const unsigned int elapsed, Audio& audio, const Map::Terrain t, const float vx, const float vy);
    void draw(Graphics& graphics, const Map::Terrain t);
    void collide(Player& player, Audio& audio);

  private:

    float dx, dy;
    int color;
    boost::scoped_ptr<Sprite> sprite;

    int value();
};
