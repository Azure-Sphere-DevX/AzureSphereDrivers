CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
PROJECT(rgb_lcd_driver C)

################################################################################
# Source groups
################################################################################
set(Source
    "rgb_lcd.c"
    "utils.c"
)
source_group("Source" FILES ${Source})

set(ALL_FILES
    ${Source}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
target_link_libraries (${PROJECT_NAME} applibs c)

target_include_directories(${PROJECT_NAME} PUBLIC "." )
