#pragma once

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

#include "map.h"
#include "object.h"
#include "player.h"
#include "screen.h"
#include "text.h"

class GameScreen : public Screen {
  public:

    static const int kPlayerX = Graphics::kWidth / 2;
    static const int kPlayerY = Graphics::kHeight / 2;

    void init();
    bool update(Input& input, Audio& audio, Graphics& graphics, unsigned int elapsed);
    void draw(Graphics& graphics);

    Screen* next_screen();
    std::string get_music_track();

  private:

    typedef std::vector<boost::shared_ptr<Object>> ObjectSet;

    int get_score();

    void spawn_rock(int x, int y);
    void spawn_fish(int x, int y);
    void spawn_seal(int x, int y);

    float distance, x_offset;
    int score, spawn_timer;
    bool dead;

    boost::scoped_ptr<Player> player;
    boost::scoped_ptr<Text> text;
    ObjectSet objects;
    Map map;
};
