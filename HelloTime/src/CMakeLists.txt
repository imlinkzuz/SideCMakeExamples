include(${SIDECMAKE_DIR}/SCInstall.cmake)

sc_install_executable(
  TARGET_NAME HelloTime
  PRIVATE_SOURCES
    main.cpp
  PRIVATE_DEPENDENCIES
    spdlog
    ShowTime::libTime
)