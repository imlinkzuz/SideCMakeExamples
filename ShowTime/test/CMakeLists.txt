include(${SIDECMAKE_DIR}/SCTest.cmake)

sc_add_unit_test(
  TEST_NAME unit_test 
  VERSION_MATCHES
  TARGETS
      console
      libTime    
  TEST_SOURCES
      main.cpp
)