# Copyright (c) 2010-2015, Panasonic Corporation.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

cmake_minimum_required( VERSION 3.0 )
project( testEnqueue )

find_package (dof-pcr-dev REQUIRED)
find_package (dof-pcr REQUIRED)
find_package (dof-oal REQUIRED)
find_package (dof-inet REQUIRED)

include_directories(${PCR_DEV_INCLUDE_DIRS} ${PCR_INCLUDE_DIRS} ${DOF_OAL_INCLUDE_DIRS} ${DOF_INET_INCLUDE_DIRS})
add_executable(testEnqueue enqueueTest.c)
target_link_libraries( testEnqueue PRIVATE  ${DOF_OAL_LIBRARIES} ${DOF_PCR_LIBRARIES} ${DOF_INET_LIBRARIES})
