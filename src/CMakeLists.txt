add_subdirectory(base)

if(Qt5_FOUND OR Qt6_FOUND)
    add_subdirectory(gui)
endif()