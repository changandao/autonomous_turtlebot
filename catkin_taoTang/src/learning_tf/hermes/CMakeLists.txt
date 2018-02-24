set(MOC_H
  hermes.h
  referee.h
)

set(SRC_H
  hermescodes.h
  hermes.h
  referee.h
)

set(SRC_CPP
  hermes.cpp
  referee.cpp
)

QT4_WRAP_CPP( MOC_CPP ${MOC_H} )


add_library( referee STATIC
	${SRC_CPP}
	${SRC_H}
	${MOC_CPP}
)

target_link_libraries ( referee
	${QT_LIBRARIES}
)

###### Begin GIT support ######
# Version control system magic, used to create a revision number for Doxygen
IF(EXISTS ${PROJECT_SOURCE_DIR}/.git)
# Probably a GIT workspace, determine revision level
	FIND_PROGRAM(GIT_EXECUTABLE git DOC "git command line client")
	IF(GIT_EXECUTABLE)
		EXECUTE_PROCESS(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
			WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
			OUTPUT_VARIABLE GIT_REVISION
			OUTPUT_STRIP_TRAILING_WHITESPACE)
		MESSAGE("Current revision of ${CMAKE_PROJECT_NAME} is ${GIT_REVISION}")
	ELSE(GIT_EXECUTABLE)
		SET(GIT_REVISION git)
	ENDIF(GIT_EXECUTABLE)
ENDIF(EXISTS ${PROJECT_SOURCE_DIR}/.git)
###### End GIT support ######

###### Begin doc target ######
FIND_PACKAGE(Doxygen)
IF (DOXYGEN_FOUND)
	# Parse Doxyfile.in and put output into build directory
	CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/referee.doxy ${CMAKE_CURRENT_BINARY_DIR}/referee.doxy)
	# adds doc target to Makefile
	ADD_CUSTOM_TARGET(referee-doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/referee.doxy)
ENDIF (DOXYGEN_FOUND)
###### End doc target ######
