# add_subdirectory(cef)
add_subdirectory(json)

set(INJA_BUILD_TESTS OFF CACHE BOOL "Do not build inja's internal tests" FORCE)
set(INJA_USE_EMBEDDED_JSON OFF CACHE BOOL "Use project nlohmann/json target" FORCE)
set(INJA_INSTALL OFF CACHE BOOL "Do not install inja from this project" FORCE)
set(INJA_EXPORT OFF CACHE BOOL "Do not export inja to the user package registry" FORCE)
add_subdirectory(inja)