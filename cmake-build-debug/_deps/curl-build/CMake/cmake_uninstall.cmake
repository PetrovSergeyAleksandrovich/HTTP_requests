if(NOT EXISTS "C:/Users/info/CLionProjects/HTTP_requests/cmake-build-debug/_deps/curl-build/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: C:/Users/info/CLionProjects/HTTP_requests/cmake-build-debug/_deps/curl-build/install_manifest.txt")
endif()

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/HTTP_requests")
endif()
message(${CMAKE_INSTALL_PREFIX})

file(READ "C:/Users/info/CLionProjects/HTTP_requests/cmake-build-debug/_deps/curl-build/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling $ENV{DESTDIR}${file}")
  if(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    exec_program(
      "D:/installed_soft/CLion 2021.1.1/bin/cmake/win/bin/cmake.exe" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing $ENV{DESTDIR}${file}")
    endif()
  else()
    message(STATUS "File $ENV{DESTDIR}${file} does not exist.")
  endif()
endforeach()
