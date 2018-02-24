# Install script for directory: /nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lidar_processing/msg" TYPE FILE FILES
    "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/feature.msg"
    "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArray.msg"
    "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/msg/featureArrayH.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lidar_processing/cmake" TYPE FILE FILES "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/build/lidar_processing/catkin_generated/installspace/lidar_processing-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/devel/include/lidar_processing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/devel/share/roseus/ros/lidar_processing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/devel/share/common-lisp/ros/lidar_processing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/devel/share/gennodejs/ros/lidar_processing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/devel/lib/python2.7/dist-packages/lidar_processing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/devel/lib/python2.7/dist-packages/lidar_processing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/build/lidar_processing/catkin_generated/installspace/lidar_processing.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lidar_processing/cmake" TYPE FILE FILES "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/build/lidar_processing/catkin_generated/installspace/lidar_processing-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lidar_processing/cmake" TYPE FILE FILES
    "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/build/lidar_processing/catkin_generated/installspace/lidar_processingConfig.cmake"
    "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/build/lidar_processing/catkin_generated/installspace/lidar_processingConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lidar_processing" TYPE FILE FILES "/nas/ei/home/ga62reh/workspace/gruppe2/catkin_shangyin_v1.1/src/lidar_processing/package.xml")
endif()

