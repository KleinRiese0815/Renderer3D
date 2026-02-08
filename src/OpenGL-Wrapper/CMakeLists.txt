file(GLOB OPENGL-WRAPPER-FILES ./*.cpp)

add_library(opengl-wrapper
    STATIC
    ${OPENGL-WRAPPER-FILES}
)

target_link_libraries(opengl-wrapper
    PUBLIC
    glfw
    glad
    glm
)
