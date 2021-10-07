set(CURRENT_MOD_NAME ${PROJECT_NAME}_base)

file(GLOB CURRENT_MOD_SRCS *.cc *.h)

add_library(${CURRENT_MOD_NAME}
    ${CURRENT_MOD_SRCS}
    )

target_link_libraries(
    ${CURRENT_MOD_NAME}
    ${CMAKE_THREAD_LIBS_INIT}
    Qt5::Core
)