#include <Arduboy2.h>

#define OK B_BUTTON
#define CANCEL A_BUTTON

#define DEV

Arduboy2 arduboy;
int counter = 200;

void setup()
{
#if defined(DEV)
  // Skip the boot logo to save time when developing
  arduboy.setFrameRate(15);
  arduboy.boot();
  arduboy.display();
  arduboy.flashlight();
  arduboy.systemButtons();
  arduboy.audio.begin();
  // arduboy.bootLogo();
  arduboy.waitNoButtons();
#else
  // This is a shortcut to run all the commands below
  arduboy.begin();
#endif
}

void update()
{
  arduboy.pollButtons();
  if (arduboy.justPressed(OK))
  {
    counter++;
  }
  else if (arduboy.justPressed(CANCEL))
  {
    counter--;
  }
}

void draw()
{
  arduboy.clear();
  arduboy.print("Hey! ");
  arduboy.print(counter);
  arduboy.display();
}

void loop()
{
  if (arduboy.nextFrame())
  {
    update();
    draw();
  }
}
