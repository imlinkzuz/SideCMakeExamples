include(${SIDECMAKE_DIR}/SCInstall.cmake)

sc_install_executable(
  TARGET_NAME console
  PRIVATE_SOURCES
    main.cpp
  PRIVATE_DEPENDENCIES
    libTime
    spdlog
)
