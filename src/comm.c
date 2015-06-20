#include "comm.h"

static void in_recv_handler(DictionaryIterator *iter, void *context) {
  Tuple *t = dict_read_first(iter);
  while(t) {
    if (t->key == PERSIST_KEY_THEME) {
      
      if (strcmp(t->value->cstring, "blue") == 0) {
        persist_write_int(t->key, THEME_BLUE);
      }
      else if (strcmp(t->value->cstring, "green") == 0) {
        persist_write_int(t->key, THEME_GREEN);
      }
      else if (strcmp(t->value->cstring, "red") == 0) {
        persist_write_int(t->key, THEME_RED);
      }
      else if (strcmp(t->value->cstring, "purple") == 0) {
        persist_write_int(t->key, THEME_PURPLE);
      }
      
    }
    else {
      persist_write_bool(t->key, strcmp(t->value->cstring, "true") == 0 ? true : false);
    }
    t = dict_read_next(iter);
  }

  // Refresh live store
  config_init();
  vibes_short_pulse();
}

void comm_init() {
  app_message_register_inbox_received(in_recv_handler);
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
}