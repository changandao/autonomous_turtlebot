# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "lidar_processing: 3 messages, 0 services")

set(MSG_I_FLAGS "-Ilidar_processing:/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Inav_msgs:/opt/ros/kinetic/share/nav_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(lidar_processing_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg" NAME_WE)
add_custom_target(_lidar_processing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lidar_processing" "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg" "lidar_processing/feature"
)

get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg" NAME_WE)
add_custom_target(_lidar_processing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lidar_processing" "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg" "lidar_processing/feature:std_msgs/Header"
)

get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg" NAME_WE)
add_custom_target(_lidar_processing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lidar_processing" "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg"
  "${MSG_I_FLAGS}"
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lidar_processing
)
_generate_msg_cpp(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg"
  "${MSG_I_FLAGS}"
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lidar_processing
)
_generate_msg_cpp(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lidar_processing
)

### Generating Services

### Generating Module File
_generate_module_cpp(lidar_processing
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lidar_processing
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(lidar_processing_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(lidar_processing_generate_messages lidar_processing_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_cpp _lidar_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_cpp _lidar_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_cpp _lidar_processing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lidar_processing_gencpp)
add_dependencies(lidar_processing_gencpp lidar_processing_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lidar_processing_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg"
  "${MSG_I_FLAGS}"
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lidar_processing
)
_generate_msg_eus(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg"
  "${MSG_I_FLAGS}"
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lidar_processing
)
_generate_msg_eus(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lidar_processing
)

### Generating Services

### Generating Module File
_generate_module_eus(lidar_processing
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lidar_processing
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(lidar_processing_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(lidar_processing_generate_messages lidar_processing_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_eus _lidar_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_eus _lidar_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_eus _lidar_processing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lidar_processing_geneus)
add_dependencies(lidar_processing_geneus lidar_processing_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lidar_processing_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg"
  "${MSG_I_FLAGS}"
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lidar_processing
)
_generate_msg_lisp(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg"
  "${MSG_I_FLAGS}"
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lidar_processing
)
_generate_msg_lisp(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lidar_processing
)

### Generating Services

### Generating Module File
_generate_module_lisp(lidar_processing
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lidar_processing
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(lidar_processing_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(lidar_processing_generate_messages lidar_processing_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_lisp _lidar_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_lisp _lidar_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_lisp _lidar_processing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lidar_processing_genlisp)
add_dependencies(lidar_processing_genlisp lidar_processing_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lidar_processing_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg"
  "${MSG_I_FLAGS}"
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lidar_processing
)
_generate_msg_nodejs(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg"
  "${MSG_I_FLAGS}"
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lidar_processing
)
_generate_msg_nodejs(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lidar_processing
)

### Generating Services

### Generating Module File
_generate_module_nodejs(lidar_processing
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lidar_processing
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(lidar_processing_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(lidar_processing_generate_messages lidar_processing_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_nodejs _lidar_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_nodejs _lidar_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_nodejs _lidar_processing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lidar_processing_gennodejs)
add_dependencies(lidar_processing_gennodejs lidar_processing_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lidar_processing_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg"
  "${MSG_I_FLAGS}"
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lidar_processing
)
_generate_msg_py(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg"
  "${MSG_I_FLAGS}"
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lidar_processing
)
_generate_msg_py(lidar_processing
  "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lidar_processing
)

### Generating Services

### Generating Module File
_generate_module_py(lidar_processing
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lidar_processing
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(lidar_processing_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(lidar_processing_generate_messages lidar_processing_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_py _lidar_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_py _lidar_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg" NAME_WE)
add_dependencies(lidar_processing_generate_messages_py _lidar_processing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lidar_processing_genpy)
add_dependencies(lidar_processing_genpy lidar_processing_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lidar_processing_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lidar_processing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lidar_processing
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(lidar_processing_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET nav_msgs_generate_messages_cpp)
  add_dependencies(lidar_processing_generate_messages_cpp nav_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(lidar_processing_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(lidar_processing_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(lidar_processing_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lidar_processing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lidar_processing
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(lidar_processing_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET nav_msgs_generate_messages_eus)
  add_dependencies(lidar_processing_generate_messages_eus nav_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(lidar_processing_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(lidar_processing_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(lidar_processing_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lidar_processing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lidar_processing
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(lidar_processing_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET nav_msgs_generate_messages_lisp)
  add_dependencies(lidar_processing_generate_messages_lisp nav_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(lidar_processing_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(lidar_processing_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(lidar_processing_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lidar_processing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lidar_processing
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(lidar_processing_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET nav_msgs_generate_messages_nodejs)
  add_dependencies(lidar_processing_generate_messages_nodejs nav_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(lidar_processing_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(lidar_processing_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(lidar_processing_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lidar_processing)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lidar_processing\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lidar_processing
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(lidar_processing_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET nav_msgs_generate_messages_py)
  add_dependencies(lidar_processing_generate_messages_py nav_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(lidar_processing_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(lidar_processing_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(lidar_processing_generate_messages_py geometry_msgs_generate_messages_py)
endif()
