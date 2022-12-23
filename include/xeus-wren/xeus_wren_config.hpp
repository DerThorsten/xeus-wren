/***************************************************************************
* Copyright (c) 2021,                                          
*                                                                          
* Distributed under the terms of the BSD 3-Clause License.                 
*                                                                          
* The full license is in the file LICENSE, distributed with this software. 
****************************************************************************/
#ifndef XEUS_WREN_CONFIG_HPP
#define XEUS_WREN_CONFIG_HPP

// Project version
#define XEUS_WREN_VERSION_MAJOR 0
#define XEUS_WREN_VERSION_MINOR 4
#define XEUS_WREN_VERSION_PATCH 0

// Composing the version string from major, minor and patch
#define XEUS_WREN_CONCATENATE(A, B) XEUS_WREN_CONCATENATE_IMPL(A, B)
#define XEUS_WREN_CONCATENATE_IMPL(A, B) A##B
#define XEUS_WREN_STRINGIFY(a) XEUS_WREN_STRINGIFY_IMPL(a)
#define XEUS_WREN_STRINGIFY_IMPL(a) #a

#define XEUS_WREN_VERSION XEUS_WREN_STRINGIFY(XEUS_WREN_CONCATENATE(XEUS_WREN_VERSION_MAJOR,   \
                 XEUS_WREN_CONCATENATE(.,XEUS_WREN_CONCATENATE(XEUS_WREN_VERSION_MINOR,   \
                                  XEUS_WREN_CONCATENATE(.,XEUS_WREN_VERSION_PATCH)))))

#ifdef _WIN32
    #ifdef XEUS_WREN_EXPORTS
        #define XEUS_WREN_API __declspec(dllexport)
    #else
        #define XEUS_WREN_API __declspec(dllimport)
    #endif
#else
    #define XEUS_WREN_API
#endif

#endif
