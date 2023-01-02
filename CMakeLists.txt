project(
        HashMap
        LANGUAGES CXX)

add_library(MyLib Linkedlist.cpp Linkedlist.h Hashmap.cpp Hashmap.h)

add_executable(Hashmap main.cpp)

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(Hashmap PRIVATE MyLib)