#ifndef __EVENT_LOOP_HPP
#define __EVENT_LOOP_HPP

#include <xcb/xcb.h>

class EventLoop {
public:
  EventLoop(xcb_connection_t *connection);
  ~EventLoop();

  void run();
};

#endif
