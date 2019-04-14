#include <cstdio>
#include <cstdlib>

#include <xcb/xcb.h>
#include <xcb/xcb_util.h>

#include "event_loop.hpp"
#include "manager.hpp"

Manager::Manager(const char* display) {
  connection = xcb_connect(display, NULL);

  const xcb_setup_t     *setup  = xcb_get_setup (connection);
  xcb_screen_iterator_t iter    = xcb_setup_roots_iterator (setup);

  screen = iter.data;

  const uint32_t select_input_val[] = {
    XCB_EVENT_MASK_KEY_RELEASE
  };

  xcb_change_window_attributes(connection, screen->root, XCB_CW_EVENT_MASK, select_input_val);
  xcb_flush(connection);

  eventLoop = new EventLoop(connection);
}

Manager::~Manager() {
  xcb_disconnect(connection);
}

void Manager::run() {
  eventLoop->run();
}

void Manager::createWindow(int x, int y) {
  xcb_window_t window = xcb_generate_id (connection);
  xcb_create_window (connection,
                     XCB_COPY_FROM_PARENT,
                     window,
                     screen->root,
                     x, y,
                     250, 250,
                     1,
                     XCB_WINDOW_CLASS_INPUT_OUTPUT,
                     screen->root_visual,
                     0, NULL);

  xcb_map_window (connection, window);
  xcb_flush (connection);
}
