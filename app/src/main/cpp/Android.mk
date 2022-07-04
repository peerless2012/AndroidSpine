LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := SDL2_main

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

LOCAL_SRC_FILES := src/main.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_spine

LOCAL_CFLAGS += -DGL_GLEXT_PROTOTYPES -Wall -Wextra -pedantic -std=c89

LOCAL_CFLAGS += -Wall -Wextra -Wnon-virtual-dtor -pedantic -std=c++11 -fno-exceptions -fno-rtti

include $(BUILD_SHARED_LIBRARY)
