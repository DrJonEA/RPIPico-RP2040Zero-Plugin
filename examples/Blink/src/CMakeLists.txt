add_executable(${NAME}
    main.cpp
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} 
	pico_stdlib
)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# enable stdio
pico_enable_stdio_usb(${NAME} 0)
pico_enable_stdio_uart(${NAME} 1)