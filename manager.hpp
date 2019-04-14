#ifndef __MANAGER_HPP
#define __MANAGER_HPP

extern "C" {
  #include <xcb/xcb.h>
}

class Manager {
private:
  xcb_connection_t *connection;
  xcb_screen_t *screen;

  void handleEvent(xcb_generic_event_t *event);

  void handleKeyRelease(xcb_key_release_event_t *event);

public:
  Manager(const char* display);

  void run();
  void createWindow(int x, int y);

  ~Manager();
};

#endif
