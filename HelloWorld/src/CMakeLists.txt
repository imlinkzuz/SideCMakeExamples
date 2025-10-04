include(${SIDECMAKE_DIR}/SCInstall.cmake)

sc_install_executable(
  TARGET_NAME HelloWorld 
  PRIVATE_SOURCES
    main.cpp
)