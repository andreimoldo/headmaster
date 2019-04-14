#ifndef __EVENT_LOOP_HPP
#define __EVENT_LOOP_HPP

#include <xcb/xcb.h>

class EventLoop {
private:
  uint8_t running;
  xcb_connection_t *connection;

  void handleEvent(xcb_generic_event_t *event);

  void handleKeyRelease(xcb_key_release_event_t *event);

public:
  EventLoop(xcb_connection_t *xcb_connection);
  ~EventLoop();

  void run();
};

#endif
