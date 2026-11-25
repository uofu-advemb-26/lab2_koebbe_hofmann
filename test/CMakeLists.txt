add_executable(mytest
  test_logic.c
  unity_config.c
  ${CMAKE_SOURCE_DIR}/src/blink.c
  ${CMAKE_SOURCE_DIR}/src/case_swap.c
)

target_link_libraries(mytest PRIVATE
  pico_stdlib
  unity
)

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
# The CI runner reads the test results from the debug probe UART.
pico_enable_stdio_uart(mytest 1)
pico_enable_stdio_usb(mytest 0)
pico_add_extra_outputs(mytest)

find_program(OPENOCD openocd)
find_program(PICOTOOL picotool)

add_custom_target(flash_test ${PICOTOOL} load -f $<TARGET_FILE:mytest> DEPENDS mytest)
add_custom_target(openocd_test ${OPENOCD} -s ${OPENOCD_PATH} -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c 'adapter speed 5000' -c 'program "$<TARGET_FILE:mytest>" verify reset exit' DEPENDS mytest)
