cmake_minimum_required(VERSION 3.16)
project(MyQtProject VERSION 1.0.0 LANGUAGES CXX)

# ==================== 基础配置 ====================
# 设置C++标准
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # 不使用编译器特定扩展

# 设置构建类型，默认为Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# ==================== Qt配置 ====================
# 设置Qt安装路径（如果Qt不在标准路径，请取消注释并修改）
# set(CMAKE_PREFIX_PATH "/opt/Qt/6.7.0/gcc_64")

# 查找Qt组件
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
# 如需其他组件，如Network、Sql等，在此添加

# 启用Qt自动处理（MOC, UIC, RCC）
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# ==================== 项目结构配置 ====================
# 自动收集所有源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h" "include/*.h" "include/*.hpp")
file(GLOB_RECURSE UI_FILES "ui/*.ui")
file(GLOB_RECURSE RES_FILES "resources/*.qrc")

# 打印找到的文件数量用于调试
message(STATUS "Found ${SOURCES} source files")
message(STATUS "Found ${HEADERS} header files")

# 添加包含目录
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# ==================== 链接库配置 ====================
# 自动查找lib/目录下的所有库文件
file(GLOB LIB_FILES "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.so"
                    "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.a")

# 添加可执行文件
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${RES_FILES}
)

# 链接Qt库
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Widgets
)

# 链接lib/目录下的静态/动态库
if(LIB_FILES)
    message(STATUS "Linking with libraries: ${LIB_FILES}")
    target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_FILES})
endif()

# ==================== 安装配置（可选） ====================
# 安装目标到系统
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# ==================== 编译后处理（可选） ====================
# 复制运行时依赖（如Qt插件）
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Build completed: ${PROJECT_NAME}"
)