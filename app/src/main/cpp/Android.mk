LOCAL_PATH := $(call my-dir)

LOCAL_SO_HEADER_PATH := $(LOCAL_PATH)/../../../../lib_sdl_spine/src/main/cpp
LOCAL_SO_PATH := $(LOCAL_PATH)/../../../../lib_sdl_spine/build/intermediates/ndkBuild/ndkDebug/obj/local/$(TARGET_ARCH_ABI)

include $(CLEAR_VARS)
LOCAL_MODULE := SDL2
LOCAL_SRC_FILES := $(LOCAL_SO_PATH)/libSDL2.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := SDL2_image
LOCAL_SRC_FILES := $(LOCAL_SO_PATH)/libSDL2_image.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := SDL2_spine
LOCAL_SRC_FILES := $(LOCAL_SO_PATH)/libSDL2_spine.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := SDL2_main

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_SO_HEADER_PATH)/SDL/include
LOCAL_C_INCLUDES += $(LOCAL_SO_HEADER_PATH)/SDL_image
LOCAL_C_INCLUDES += $(LOCAL_SO_HEADER_PATH)/Spine_cpp/spine-cpp/include
LOCAL_C_INCLUDES += $(LOCAL_SO_HEADER_PATH)/SDL_spine/include

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

LOCAL_SRC_FILES := src/main.cpp

# 引用三方动态库或静态库，使用预构建
# https://developer.android.com/ndk/guides/prebuilts?hl=zh-cn
LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_spine

LOCAL_CFLAGS += -DGL_GLEXT_PROTOTYPES -Wall -Wextra -pedantic -std=c89

LOCAL_CFLAGS += -Wall -Wextra -Wnon-virtual-dtor -pedantic -std=c++11 -fno-exceptions -fno-rtti

include $(BUILD_SHARED_LIBRARY)
