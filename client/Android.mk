LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:= testClient

LOCAL_SRC_FILES:=               \
    TestClient.cpp           \

LOCAL_SHARED_LIBRARIES :=       \
    libbinder                   \
    liblog                      \
    libutils                    \
    libtestinterface

LOCAL_C_INCLUDES :=             \
    $(LOCAL_PATH)/../interface/

include $(BUILD_EXECUTABLE)
