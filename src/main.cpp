#include <chrono>
#include <cstdint>
#include <iostream>

#include "graphics/DisplayWrapper.h"
using namespace pixeler;

sf::RenderWindow _window{sf::VideoMode({TFT_WIDTH, TFT_HEIGHT}), WINDOW_TITLE};

#ifdef _WIN32
#include <windows.h>
#define CP_UTF8 65001
#endif

void activate_utf8_on_windows()
{
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
#endif
}

int main()
{
  activate_utf8_on_windows();

  _display.init(&_window);

  while (_window.isOpen())
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(UI_UPDATE_DELAY));

    while (auto event = _window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
        _window.close();

      if (event->is<sf::Event::KeyPressed>())
      {
        if (event->getIf<sf::Event::KeyPressed>()->scancode == sf::Keyboard::Scancode::Space)
        {
          // обробка натискання пробілу
          _display.fillScreen(COLOR_BLUE);
          _display.drawRect(10, 10, 50, 50, COLOR_RED);
          _display.fillRect(11, 11, 48, 48, COLOR_WHITE);

          _display.drawRoundRect(10, 70, 50, 50, 10, COLOR_BLACK);
          _display.fillRoundRect(11, 71, 48, 48, 10, COLOR_ORANGE);

          _display.drawCircle(150, 50, 40, COLOR_GREEN);
          _display.fillCircle(150, 50, 39, COLOR_CYAN);

          _display.setTextColor(COLOR_YELLOW);
          _display.setFont(font_10x20);
          _display.setTextSize(1);
          _display.setCursor(10, 200);
          _display.print("Слава Україні!");
        }
      }
    }

    _display.__flush();
  }

  return 0;
}
