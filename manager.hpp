#ifndef __MANAGER_HPP
#define __MANAGER_HPP

#include <xcb/xcb.h>

#include "event_loop.hpp"

class Manager {
private:
  EventLoop *eventLoop;

  xcb_connection_t *connection;
  xcb_screen_t *screen;

public:
  Manager(const char* display);
  ~Manager();

  void run();
  void createWindow(int x, int y);
};

#endif
