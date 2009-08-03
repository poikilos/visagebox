# cmake macro to test LibV4L2

# Copyright (c) 2009, Jaroslav Reznik <jreznik@redhat.com>
#
# LIBV4L2_FOUND
# LIBV4L2_INCLUDE_DIR
# LIBV4L2_LIBRARY
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

INCLUDE (FindPackageHandleStandardArgs)

IF (LIBV4L2_INCLUDE_DIR AND LIBV4L2_LIBRARY)
    # Already in cache, be silent
    SET (LIBV4L2_FIND_QUIETLY TRUE)
ENDIF (LIBV4L2_INCLUDE_DIR AND LIBV4L2_LIBRARY)

IF (NOT LIBV4L2_FOUND)
  FIND_PATH (LIBV4L2_INCLUDE_DIR libv4l2.h)
  FIND_LIBRARY (LIBV4L2_LIBRARY NAMES v4l2)

  IF (LIBV4L2_INCLUDE_DIR AND LIBV4L2_LIBRARY)
    SET (LIBV4L2_FOUND TRUE)
  ENDIF( LIBV4L2_INCLUDE_DIR AND LIBV4L2_LIBRARY )
ENDIF ( NOT LIBV4L2_FOUND)

IF( LIBV4L2_FOUND )
  IF( NOT LIBV4L2_FIND_QUIETLY )
    MESSAGE( STATUS "Found LIBV4L2: ${LIBV4L2_LIBRARY}")
  ENDIF( NOT LIBV4L2_FIND_QUIETLY )
ENDIF( LIBV4L2_FOUND )
