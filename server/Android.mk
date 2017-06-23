LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:= TestService

LOCAL_SRC_FILES:=               \
    Main_testserver.cpp           \
    TestServer.cpp

LOCAL_SHARED_LIBRARIES :=       \
    libbinder                   \
    liblog                      \
    libutils                    \
    libtestinterface

LOCAL_C_INCLUDES :=             \
    TestServer.h  \
    $(LOCAL_PATH)/../interface

include $(BUILD_EXECUTABLE)



