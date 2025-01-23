add_subdirectory(base)
add_subdirectory(plugin_manager)

if(Qt5_FOUND OR Qt6_FOUND)
    add_subdirectory(gui)
endif()