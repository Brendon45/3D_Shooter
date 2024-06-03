#ifndef EVENTS_H
#define EVENTS_H

int keyboard_events(keys *);
void check_key_release_events(SDL_Event, keys *);
int check_key_press_events(SDL_Event, keys *);

#endif /* EVENTS_H */
