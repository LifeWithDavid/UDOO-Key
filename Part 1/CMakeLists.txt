cmake_minimum_required(VERSION 3.19.8)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)


project(RPIcomm1
)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()



add_executable(RPIcomm1
        RPIcomm1B.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(RPIcomm1 pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(RPIcomm1)

# add url via pico_set_program_url
#example_auto_set_url(RPIcomm1)


# Hardware-specific examples in subdirectories:
#add_subdirectory(adc)
#add_subdirectory(clocks)
#add_subdirectory(cmake)
#add_subdirectory(divider)
#add_subdirectory(dma)
#add_subdirectory(flash)
#add_subdirectory(gpio)
#add_subdirectory(i2c)
#add_subdirectory(interp)
#add_subdirectory(multicore)
#add_subdirectory(picoboard)
#add_subdirectory(pio)
#add_subdirectory(pwm)
#add_subdirectory(reset)
#add_subdirectory(rtc)
#add_subdirectory(spi)
#add_subdirectory(system)
#add_subdirectory(timer)
#add_subdirectory(uart)
#add_subdirectory(usb)
#add_subdirectory(watchdog)

