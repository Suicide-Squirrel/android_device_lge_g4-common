MM_V4L2_DRIVER_LIST += msm8994
MM_V4L2_DRIVER_LIST += msm8992

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := \
    system/media/camera/include/system

LOCAL_SRC_FILES := \
    CameraWrapper.cpp

LOCAL_SHARED_LIBRARIES := \
    libhardware liblog libcamera_client libgui libutils

LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_MODULE := camera.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_TAGS := optional
LOCAL_PROPRIETARY_MODULE := true

LOCAL_32_BIT_ONLY := true
include $(BUILD_SHARED_LIBRARY)
