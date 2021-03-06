cmake_minimum_required(VERSION 3.10.3)
project(Linpop C)

set(CMAKE_C_STANDARD 99)

add_executable(server server/main.c common/srcs/socket_utils.c common/srcs/rio.c server/login_reg_server.h server/login_reg_server.c

        server/friend_group_server.c server/friend_group_server.h server/database.c common/include/database.h client/update_info.c
       )


add_executable(client client/list.c client/login.c client/main.c client/sign.c client/sign_success.c common/srcs/rio.c
        common/srcs/socket_utils.c client/add_friend.c client/chat_new.c client/emoji.c client/tools.c client/tools.h client/set.c
        client/select_portrait.c client/update_info.c client/add_groups.c client/set_background.c client/group_chat.c client/change_password.c
        client/select_portrait.c client/update_info.c client/thread_recv_msg.c common/srcs/client_utils.c)

add_executable(client_chat common/srcs/socket_utils.c common/srcs/rio.c)



include_directories(/common/include/)

target_link_libraries(server pthread)
#target_link_libraries(client_chat pthread)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-2.0)

INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
target_link_libraries(server libmysqlclient.so)
TARGET_LINK_LIBRARIES(client ${GTK3_LIBRARIES} pthread)