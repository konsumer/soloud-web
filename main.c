#include <stdio.h>

#include <SDL2/SDL.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "soloud_c.h"

// this is a little tester for native EXE
int main() {
  SDL_Init(SDL_INIT_AUDIO);
  Soloud* soloud = Soloud_create();
  Soloud_initEx(soloud, SOLOUD_CLIP_ROUNDOFF | SOLOUD_ENABLE_VISUALIZATION, SOLOUD_AUTO, SOLOUD_AUTO, SOLOUD_AUTO, SOLOUD_AUTO);
  Speech* speech = Speech_create();
  Speech_setText(speech, "Hello from soloud.");
  Soloud_setGlobalVolume(soloud, 4);
  Soloud_play(soloud, speech);

  while (Soloud_getVoiceCount(soloud) > 0) {
  }
  Speech_destroy(speech);

  return 0;
}