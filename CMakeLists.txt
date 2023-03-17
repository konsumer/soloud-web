cmake_minimum_required(VERSION 3.17)

project(
  WebSoloud
  VERSION 0.0.0
  DESCRIPTION "Make sound with soloud, on the web"
)

set (CMAKE_CXX_STANDARD 17)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_library(${PROJECT_NAME} SHARED
  soloud/src/backend/sdl2_static/soloud_sdl2_static.cpp
  soloud/src/c_api/soloud_c.cpp

  # this uses a DLL and will not work in wasm
  soloud/src/audiosource/openmpt/soloud_openmpt_dll.c

  soloud/src/core/soloud.cpp
  soloud/src/core/soloud_audiosource.cpp
  soloud/src/core/soloud_bus.cpp
  soloud/src/core/soloud_core_3d.cpp
  soloud/src/core/soloud_core_basicops.cpp
  soloud/src/core/soloud_core_faderops.cpp
  soloud/src/core/soloud_core_filterops.cpp
  soloud/src/core/soloud_core_getters.cpp
  soloud/src/core/soloud_core_setters.cpp
  soloud/src/core/soloud_core_voicegroup.cpp
  soloud/src/core/soloud_core_voiceops.cpp
  soloud/src/core/soloud_fader.cpp
  soloud/src/core/soloud_fft.cpp
  soloud/src/core/soloud_fft_lut.cpp
  soloud/src/core/soloud_file.cpp
  soloud/src/core/soloud_filter.cpp
  soloud/src/core/soloud_misc.cpp
  soloud/src/core/soloud_queue.cpp
  soloud/src/core/soloud_thread.cpp
  soloud/src/audiosource/ay/chipplayer.cpp
  soloud/src/audiosource/ay/sndbuffer.cpp
  soloud/src/audiosource/ay/sndchip.cpp
  soloud/src/audiosource/ay/sndrender.cpp
  soloud/src/audiosource/ay/soloud_ay.cpp
  soloud/src/audiosource/monotone/soloud_monotone.cpp
  soloud/src/audiosource/noise/soloud_noise.cpp
  soloud/src/audiosource/openmpt/soloud_openmpt.cpp
  soloud/src/audiosource/sfxr/soloud_sfxr.cpp
  soloud/src/audiosource/speech/darray.cpp
  soloud/src/audiosource/speech/klatt.cpp
  soloud/src/audiosource/speech/resonator.cpp
  soloud/src/audiosource/speech/soloud_speech.cpp
  soloud/src/audiosource/speech/tts.cpp
  soloud/src/audiosource/tedsid/sid.cpp
  soloud/src/audiosource/tedsid/soloud_tedsid.cpp
  soloud/src/audiosource/tedsid/ted.cpp
  soloud/src/audiosource/vic/soloud_vic.cpp
  soloud/src/audiosource/vizsn/soloud_vizsn.cpp
  soloud/src/audiosource/wav/dr_impl.cpp
  soloud/src/audiosource/wav/soloud_wav.cpp
  soloud/src/audiosource/wav/soloud_wavstream.cpp
  soloud/src/filter/soloud_bassboostfilter.cpp
  soloud/src/filter/soloud_biquadresonantfilter.cpp
  soloud/src/filter/soloud_dcremovalfilter.cpp
  soloud/src/filter/soloud_duckfilter.cpp
  soloud/src/filter/soloud_echofilter.cpp
  soloud/src/filter/soloud_eqfilter.cpp
  soloud/src/filter/soloud_fftfilter.cpp
  soloud/src/filter/soloud_flangerfilter.cpp
  soloud/src/filter/soloud_freeverbfilter.cpp
  soloud/src/filter/soloud_lofifilter.cpp
  soloud/src/filter/soloud_robotizefilter.cpp
  soloud/src/filter/soloud_waveshaperfilter.cpp

  openmpt/include/stb_vorbis/stb_vorbis.c
)
target_include_directories(${PROJECT_NAME} PUBLIC soloud/include)
target_include_directories(${PROJECT_NAME} PUBLIC stb/include)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_include_directories(${PROJECT_NAME} PUBLIC openmpt/)
target_include_directories(${PROJECT_NAME} PUBLIC openmpt/src/)
target_include_directories(${PROJECT_NAME} PUBLIC openmpt/common/)
target_compile_definitions(${PROJECT_NAME} PUBLIC WITH_SDL2_STATIC)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
