add_subdirectory(base)

include_directories(
    ${fmt_INCLUDE_DIRS}
    ${spdlog_INCLUDE_DIRS}
)

if(Qt6_FOUND)
    add_subdirectory(gui)
endif()