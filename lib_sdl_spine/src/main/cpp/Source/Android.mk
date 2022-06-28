LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../spine_sdl/include \
		$(LOCAL_PATH)/../spine/spine-cpp/include \
		$(LOCAL_PATH)/../SDL/include \
		$(LOCAL_PATH)/../SDL_image \

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

LOCAL_SRC_FILES := $(NDK_OUT)/local/$(TARGET_ARCH_ABI)/libSpine.a
# Add your application source files here...
#LOCAL_SRC_FILES := YourSourceHere.cpp

LOCAL_SRC_FILES := main.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_spine

#LOCAL_CFLAGS += -DGL_GLEXT_PROTOTYPES -Wall -Wextra -pedantic -std=c89

#LOCAL_CFLAGS += -Wall -Wextra -Wnon-virtual-dtor -pedantic -std=c++11 -fno-exceptions -fno-rtti

include $(BUILD_SHARED_LIBRARY)
