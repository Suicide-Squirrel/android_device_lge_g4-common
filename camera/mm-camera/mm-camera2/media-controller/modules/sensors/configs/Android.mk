LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE:= msm8996_camera.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := msm8996_camera.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= msm8976_camera.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := msm8976_camera.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= msm8952_camera.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := msm8952_camera.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= msm8937_camera.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := msm8937_camera.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= msm8953_camera.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := msm8953_camera.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= imx214_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := imx214_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= imx214_sub_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := imx214_sub_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= imx230_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
ifeq ($(CHROMATIX_VERSION), 0309)
LOCAL_SRC_FILES := imx230_chromatix.xml
endif
ifeq ($(CHROMATIX_VERSION), 0308E)
LOCAL_SRC_FILES := imx230_chromatix_ext.xml
endif
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= imx230_qc2002_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
ifeq ($(CHROMATIX_VERSION), 0309)
LOCAL_SRC_FILES := imx230_qc2002_chromatix.xml
endif
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= imx230_qc2002_with_gyro_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
ifeq ($(CHROMATIX_VERSION), 0309)
LOCAL_SRC_FILES := imx230_qc2002_with_gyro_chromatix.xml
endif
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti

include $(BUILD_PREBUILT)


include $(CLEAR_VARS)
LOCAL_MODULE:= csidtg_camera.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := csidtg_camera.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= csidtg_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := csidtg_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= imx258_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := imx258_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= ov4688_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := ov4688_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= ov5670_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := ov5670_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= ov5670_f5670bq_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := ov5670_f5670bq_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= ov8858_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := ov8858_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= ov8865_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := ov8865_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= ov13850_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := ov13850_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= ov13850_q13v06k_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := ov13850_q13v06k_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= s5k3m2xm_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := s5k3m2xm_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= s5k3m2xm_chromatix_bear.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := s5k3m2xm_chromatix_bear.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= s5k3m2xx_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := s5k3m2xx_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= ov5695_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := ov5695_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= imx298_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := imx298_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= s5k3l8_f3l8yam_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := s5k3l8_f3l8yam_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= s5k3l8_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := s5k3l8_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= s5k3l8_mono_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := s5k3l8_mono_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= imx318_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := imx318_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= imx258_mono_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := imx258_mono_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= ov2680_chromatix.xml
LOCAL_MODULE_CLASS := EXECUTABLES
LOCAL_SRC_FILES := ov2680_chromatix.xml
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/etc/camera
LOCAL_MODULE_OWNER := qti
include $(BUILD_PREBUILT)