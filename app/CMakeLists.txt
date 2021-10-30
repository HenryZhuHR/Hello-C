include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(" BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/bin)

add_executable(main main.c)
add_executable(memory memory.c)



# file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libstdc++-6.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
# file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libwinpthread-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
# file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libgcc_s_seh-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)