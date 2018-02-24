IMX091_CHROMATIX_PREVIEW_PATH := $(call my-dir)

# ---------------------------------------------------------------------------
#                      Make the shared library (libchromatix_imx091_preview)
# ---------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_PATH := $(IMX091_CHROMATIX_PREVIEW_PATH)
LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS:= \
        -DAMSS_VERSION=$(AMSS_VERSION) \
        $(mmcamera_debug_defines) \
        $(mmcamera_debug_cflags) \
        -include camera_defs_i.h

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../hardware/sensor
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../common
LOCAL_C_INCLUDES += $(TARGET_DEVICE)/camera
LOCAL_C_INCLUDES += $(TARGET_OUT_HEADERS)/mm-still/jpeg
LOCAL_C_INCLUDES += chromatix_imx091_preview.h

LOCAL_SRC_FILES:= chromatix_imx091_preview.c

LOCAL_MODULE           := libchromatix_imx091_preview
LOCAL_SHARED_LIBRARIES := libcutils
include $(LOCAL_PATH)/../../../../../../local_additional_dependency.mk

ifeq ($(MM_DEBUG),true)
LOCAL_SHARED_LIBRARIES += liblog
endif

LOCAL_MODULE_OWNER := qcom
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)
