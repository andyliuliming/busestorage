# FindCasablanca package
#
# Tries to find the Casablanca (C++ REST SDK) library
#

find_package(PkgConfig)

pkg_check_modules(_CASABLANCA QUIET casablanca)

find_path(CASABLANCA_INCLUDE_DIR
	NAMES
	 cpprest/http_client.h
	 cpprest/json.h
	 HINTS
	 ${_CASABLANCA_ROOT_HINTS_AND_PATHS}
	 PATH_SUFFIXES
	  include
	  include/cpprest
	  include/pplx
	  include/compat
	  include/casablanca
	  include/casablanca/cpprest
	  include/casablanca/pplx
	  include/casablanca/compat
)

find_library(LIB_CASABLANCA
			NAMES
			 cpprest
			HINTS
			 ${_CASABLANCA_LIBDIR}
			${_CASABLANCA_ROOT_HINTS_AND_PATHS}
			PATH_SUFFIXES
			 lib
			)

mark_as_advanced(LIB_CASABLANCA)

set(CASABLANCA_LIBRARIES ${LIB_CASABLANCA})

mark_as_advanced(CASABLANCA_INCLUDE_DIR CASABLANCA_LIBRARIES)

