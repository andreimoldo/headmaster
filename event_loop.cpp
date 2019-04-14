#include <cstdio>
#include <cstdlib>

#include <xcb/xcb.h>
#include <xcb/xcb_util.h>

#include "event_loop.hpp"

EventLoop::EventLoop(xcb_connection_t *xcb_connection) {
  running = 0;
  connection = xcb_connection;
}

EventLoop::~EventLoop() {

}

void EventLoop::run() {
  running = 1;
  xcb_generic_event_t *event;

  while (running && (event = xcb_wait_for_event(connection))) {
    switch (event->response_type) {
    case XCB_KEY_PRESS:
      running = 0;
      break;
    default:
      handleEvent(event);
    }
    free(event);
  }
}

void EventLoop::handleEvent(xcb_generic_event_t *event) {
  uint8_t responseType = XCB_EVENT_RESPONSE_TYPE(event);

  switch(responseType) {
  case XCB_KEY_RELEASE:
    handleKeyRelease((xcb_key_release_event_t *)event);
    break;
  }
}

void EventLoop::handleKeyRelease(xcb_key_release_event_t *event) {
  fprintf(stderr, "e: %s, k: %i\n", xcb_event_get_label(event->response_type), event->detail);
}
