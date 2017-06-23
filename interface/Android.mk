LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:= libtestinterface

LOCAL_SRC_FILES:=               \
    ITestServer.cpp           \

LOCAL_SHARED_LIBRARIES :=       \
    libbinder                   \
    libutils                    \

LOCAL_C_INCLUDES :=             \
    ITestServer.h

include $(BUILD_SHARED_LIBRARY)



