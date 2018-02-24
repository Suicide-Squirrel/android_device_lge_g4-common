/* ov5645_lib.h
 *
 * DESCRIPTION
 * Auto-Generated by Sensor Driver Generator tool
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc. All Rights Reserved.
 *
 * Qualcomm Technologies Proprietary and Confidential.
 */

#ifndef __OV5645_LIB_H__
#define __OV5645_LIB_H__

#include "sensor_lib.h"
#define SENSOR_MODEL "ov5645"

#define START_REG_ARRAY \
{ \
 {0x3008, 0x02, 0x0}, \
}

#define STOP_REG_ARRAY \
{ \
 {0x3008, 0x42, 0x0}, \
}

#define AEC_ENABLE_SETTINGS_ARRAY \
{ \
 {0x3503, 0x00, 0x0}, \
 {0x3406, 0x00, 0x0}, \
}

#define AEC_DISABLE_SETTINGS_ARRAY \
{ \
 {0x3503, 0x07, 0x0}, \
 {0x3406, 0x01, 0x0}, \
}

#define INIT0_REG_ARRAY \
{ \
 {0x3103, 0x11, 0x0}, \
 {0x3008, 0x82, 0x0}, \
 {0x3008, 0x42, 0x0}, \
 {0x3103, 0x03, 0x0}, \
 {0x3503, 0x07, 0x0}, \
 {0x3002, 0x1c, 0x0}, \
 {0x3006, 0xc3, 0x0}, \
 {0x300e, 0x45, 0x0}, \
 {0x3017, 0x00, 0x0}, \
 {0x3018, 0x00, 0x0}, \
 {0x302e, 0x0b, 0x0}, \
 {0x3037, 0x13, 0x0}, \
 {0x3108, 0x01, 0x0}, \
 {0x3611, 0x06, 0x0}, \
 {0x3500, 0x00, 0x0}, \
 {0x3501, 0x01, 0x0}, \
 {0x3502, 0x00, 0x0}, \
 {0x350a, 0x00, 0x0}, \
 {0x350b, 0x3f, 0x0}, \
 {0x3620, 0x33, 0x0}, \
 {0x3621, 0xe0, 0x0}, \
 {0x3622, 0x01, 0x0}, \
 {0x3630, 0x2e, 0x0}, \
 {0x3631, 0x00, 0x0}, \
 {0x3632, 0x32, 0x0}, \
 {0x3633, 0x52, 0x0}, \
 {0x3634, 0x70, 0x0}, \
 {0x3635, 0x13, 0x0}, \
 {0x3636, 0x03, 0x0}, \
 {0x3703, 0x5a, 0x0}, \
 {0x3704, 0xa0, 0x0}, \
 {0x3705, 0x1a, 0x0}, \
 {0x3709, 0x12, 0x0}, \
 {0x370b, 0x61, 0x0}, \
 {0x370f, 0x10, 0x0}, \
 {0x3715, 0x78, 0x0}, \
 {0x3717, 0x01, 0x0}, \
 {0x371b, 0x20, 0x0}, \
 {0x3731, 0x12, 0x0}, \
 {0x3901, 0x0a, 0x0}, \
 {0x3905, 0x02, 0x0}, \
 {0x3906, 0x10, 0x0}, \
 {0x3719, 0x86, 0x0}, \
 {0x3810, 0x00, 0x0}, \
 {0x3811, 0x10, 0x0}, \
 {0x3812, 0x00, 0x0}, \
 {0x3821, 0x01, 0x0}, \
 {0x3824, 0x01, 0x0}, \
 {0x3826, 0x03, 0x0}, \
 {0x3828, 0x08, 0x0}, \
 {0x3a19, 0xf8, 0x0}, \
 {0x3c01, 0x34, 0x0}, \
 {0x3c04, 0x28, 0x0}, \
 {0x3c05, 0x98, 0x0}, \
 {0x3c07, 0x07, 0x0}, \
 {0x3c09, 0xc2, 0x0}, \
 {0x3c0a, 0x9c, 0x0}, \
 {0x3c0b, 0x40, 0x0}, \
 {0x3c01, 0x34, 0x0}, \
 {0x4001, 0x02, 0x0}, \
 {0x4514, 0x00, 0x0}, \
 {0x4520, 0xb0, 0x0}, \
 {0x460b, 0x37, 0x0}, \
 {0x460c, 0x20, 0x0}, \
 {0x4818, 0x01, 0x0}, \
 {0x481d, 0xf0, 0x0}, \
 {0x481f, 0x50, 0x0}, \
 {0x4823, 0x70, 0x0}, \
 {0x4831, 0x14, 0x0}, \
 {0x5000, 0xa7, 0x0}, \
 {0x5001, 0x83, 0x0}, \
 {0x501d, 0x00, 0x0}, \
 {0x501f, 0x00, 0x0}, \
 {0x503d, 0x00, 0x0}, \
 {0x505c, 0x30, 0x0}, \
 {0x5181, 0x59, 0x0}, \
 {0x5183, 0x00, 0x0}, \
 {0x5191, 0xf0, 0x0}, \
 {0x5192, 0x03, 0x0}, \
 {0x5684, 0x10, 0x0}, \
 {0x5685, 0xa0, 0x0}, \
 {0x5686, 0x0c, 0x0}, \
 {0x5687, 0x78, 0x0}, \
 {0x5a00, 0x08, 0x0}, \
 {0x5a21, 0x00, 0x0}, \
 {0x5a24, 0x00, 0x0}, \
 {0x3008, 0x02, 0x0}, \
 {0x3503, 0x00, 0x0}, \
 {0x5180, 0xff, 0x0}, \
 {0x5181, 0xf2, 0x0}, \
 {0x5182, 0x00, 0x0}, \
 {0x5183, 0x14, 0x0}, \
 {0x5184, 0x25, 0x0}, \
 {0x5185, 0x24, 0x0}, \
 {0x5186, 0x09, 0x0}, \
 {0x5187, 0x09, 0x0}, \
 {0x5188, 0x0a, 0x0}, \
 {0x5189, 0x75, 0x0}, \
 {0x518a, 0x52, 0x0}, \
 {0x518b, 0xea, 0x0}, \
 {0x518c, 0xa8, 0x0}, \
 {0x518d, 0x42, 0x0}, \
 {0x518e, 0x38, 0x0}, \
 {0x518f, 0x56, 0x0}, \
 {0x5190, 0x42, 0x0}, \
 {0x5191, 0xf8, 0x0}, \
 {0x5192, 0x04, 0x0}, \
 {0x5193, 0x70, 0x0}, \
 {0x5194, 0xf0, 0x0}, \
 {0x5195, 0xf0, 0x0}, \
 {0x5196, 0x03, 0x0}, \
 {0x5197, 0x01, 0x0}, \
 {0x5198, 0x04, 0x0}, \
 {0x5199, 0x12, 0x0}, \
 {0x519a, 0x04, 0x0}, \
 {0x519b, 0x00, 0x0}, \
 {0x519c, 0x06, 0x0}, \
 {0x519d, 0x82, 0x0}, \
 {0x519e, 0x38, 0x0}, \
 {0x5381, 0x1e, 0x0}, \
 {0x5382, 0x5b, 0x0}, \
 {0x5383, 0x08, 0x0}, \
 {0x5384, 0x0a, 0x0}, \
 {0x5385, 0x7e, 0x0}, \
 {0x5386, 0x88, 0x0}, \
 {0x5387, 0x7c, 0x0}, \
 {0x5388, 0x6c, 0x0}, \
 {0x5389, 0x10, 0x0}, \
 {0x538a, 0x01, 0x0}, \
 {0x538b, 0x98, 0x0}, \
 {0x5300, 0x08, 0x0}, \
 {0x5301, 0x30, 0x0}, \
 {0x5302, 0x10, 0x0}, \
 {0x5303, 0x00, 0x0}, \
 {0x5304, 0x08, 0x0}, \
 {0x5305, 0x30, 0x0}, \
 {0x5306, 0x08, 0x0}, \
 {0x5307, 0x16, 0x0}, \
 {0x5309, 0x08, 0x0}, \
 {0x530a, 0x30, 0x0}, \
 {0x530b, 0x04, 0x0}, \
 {0x530c, 0x06, 0x0}, \
 {0x5480, 0x01, 0x0}, \
 {0x5481, 0x08, 0x0}, \
 {0x5482, 0x14, 0x0}, \
 {0x5483, 0x28, 0x0}, \
 {0x5484, 0x51, 0x0}, \
 {0x5485, 0x65, 0x0}, \
 {0x5486, 0x71, 0x0}, \
 {0x5487, 0x7d, 0x0}, \
 {0x5488, 0x87, 0x0}, \
 {0x5489, 0x91, 0x0}, \
 {0x548a, 0x9a, 0x0}, \
 {0x548b, 0xaa, 0x0}, \
 {0x548c, 0xb8, 0x0}, \
 {0x548d, 0xcd, 0x0}, \
 {0x548e, 0xdd, 0x0}, \
 {0x548f, 0xea, 0x0}, \
 {0x5490, 0x1d, 0x0}, \
 {0x5580, 0x02, 0x0}, \
 {0x5583, 0x40, 0x0}, \
 {0x5584, 0x10, 0x0}, \
 {0x5589, 0x10, 0x0}, \
 {0x558a, 0x00, 0x0}, \
 {0x558b, 0xf8, 0x0}, \
 {0x5800, 0x3f, 0x0}, \
 {0x5801, 0x16, 0x0}, \
 {0x5802, 0x0e, 0x0}, \
 {0x5803, 0x0d, 0x0}, \
 {0x5804, 0x17, 0x0}, \
 {0x5805, 0x3f, 0x0}, \
 {0x5806, 0x0b, 0x0}, \
 {0x5807, 0x06, 0x0}, \
 {0x5808, 0x04, 0x0}, \
 {0x5809, 0x04, 0x0}, \
 {0x580a, 0x06, 0x0}, \
 {0x580b, 0x0b, 0x0}, \
 {0x580c, 0x09, 0x0}, \
 {0x580d, 0x03, 0x0}, \
 {0x580e, 0x00, 0x0}, \
 {0x580f, 0x00, 0x0}, \
 {0x5810, 0x03, 0x0}, \
 {0x5811, 0x08, 0x0}, \
 {0x5812, 0x0a, 0x0}, \
 {0x5813, 0x03, 0x0}, \
 {0x5814, 0x00, 0x0}, \
 {0x5815, 0x00, 0x0}, \
 {0x5816, 0x04, 0x0}, \
 {0x5817, 0x09, 0x0}, \
 {0x5818, 0x0f, 0x0}, \
 {0x5819, 0x08, 0x0}, \
 {0x581a, 0x06, 0x0}, \
 {0x581b, 0x06, 0x0}, \
 {0x581c, 0x08, 0x0}, \
 {0x581d, 0x0c, 0x0}, \
 {0x581e, 0x3f, 0x0}, \
 {0x581f, 0x1e, 0x0}, \
 {0x5820, 0x12, 0x0}, \
 {0x5821, 0x13, 0x0}, \
 {0x5822, 0x21, 0x0}, \
 {0x5823, 0x3f, 0x0}, \
 {0x5824, 0x68, 0x0}, \
 {0x5825, 0x28, 0x0}, \
 {0x5826, 0x2c, 0x0}, \
 {0x5827, 0x28, 0x0}, \
 {0x5828, 0x08, 0x0}, \
 {0x5829, 0x48, 0x0}, \
 {0x582a, 0x64, 0x0}, \
 {0x582b, 0x62, 0x0}, \
 {0x582c, 0x64, 0x0}, \
 {0x582d, 0x28, 0x0}, \
 {0x582e, 0x46, 0x0}, \
 {0x582f, 0x62, 0x0}, \
 {0x5830, 0x60, 0x0}, \
 {0x5831, 0x62, 0x0}, \
 {0x5832, 0x26, 0x0}, \
 {0x5833, 0x48, 0x0}, \
 {0x5834, 0x66, 0x0}, \
 {0x5835, 0x44, 0x0}, \
 {0x5836, 0x64, 0x0}, \
 {0x5837, 0x28, 0x0}, \
 {0x5838, 0x66, 0x0}, \
 {0x5839, 0x48, 0x0}, \
 {0x583a, 0x2c, 0x0}, \
 {0x583b, 0x28, 0x0}, \
 {0x583c, 0x26, 0x0}, \
 {0x583d, 0xae, 0x0}, \
 {0x5025, 0x00, 0x0}, \
 {0x3a0f, 0x30, 0x0}, \
 {0x3a10, 0x28, 0x0}, \
 {0x3a1b, 0x30, 0x0}, \
 {0x3a1e, 0x26, 0x0}, \
 {0x3a11, 0x60, 0x0}, \
 {0x3a1f, 0x14, 0x0}, \
 {0x0601, 0x02, 0x0}, \
 {0x3008, 0x42, 0x0}, \
}

#define RES0_REG_ARRAY \
{ \
 {0x3612, 0xab, 0x0}, \
 {0x3614, 0x50, 0x0}, \
 {0x3618, 0x04, 0x0}, \
 {0x3034, 0x18, 0x0}, \
 {0x3035, 0x11, 0x0}, \
 {0x3036, 0x54, 0x0}, \
 {0x3600, 0x08, 0x0}, \
 {0x3601, 0x33, 0x0}, \
 {0x3708, 0x63, 0x0}, \
 {0x370c, 0xc0, 0x0}, \
 {0x3800, 0x00, 0x0}, \
 {0x3801, 0x00, 0x0}, \
 {0x3802, 0x00, 0x0}, \
 {0x3803, 0x00, 0x0}, \
 {0x3804, 0x0a, 0x0}, \
 {0x3805, 0x3f, 0x0}, \
 {0x3806, 0x07, 0x0}, \
 {0x3807, 0x9f, 0x0}, \
 {0x3808, 0x0a, 0x0}, \
 {0x3809, 0x20, 0x0}, \
 {0x380a, 0x07, 0x0}, \
 {0x380b, 0x98, 0x0}, \
 {0x380c, 0x0b, 0x0}, \
 {0x380d, 0x1c, 0x0}, \
 {0x380e, 0x07, 0x0}, \
 {0x380f, 0xb0, 0x0}, \
 {0x3813, 0x06, 0x0}, \
 {0x3814, 0x11, 0x0}, \
 {0x3815, 0x11, 0x0}, \
 {0x3820, 0x47, 0x0}, \
 {0x4514, 0x88, 0x0}, \
 {0x3a02, 0x07, 0x0}, \
 {0x3a03, 0xb0, 0x0}, \
 {0x3a08, 0x01, 0x0}, \
 {0x3a09, 0x27, 0x0}, \
 {0x3a0a, 0x00, 0x0}, \
 {0x3a0b, 0xf6, 0x0}, \
 {0x3a0e, 0x06, 0x0}, \
 {0x3a0d, 0x08, 0x0}, \
 {0x3a14, 0x07, 0x0}, \
 {0x3a15, 0xb0, 0x0}, \
 {0x3a18, 0x01, 0x0}, \
 {0x4004, 0x06, 0x0}, \
 {0x4005, 0x18, 0x0}, \
 {0x4300, 0x30, 0x0}, \
 {0x4837, 0x0b, 0x0}, \
 {0x4202, 0x00, 0x0}, \
}

#define RES1_REG_ARRAY \
{ \
 {0x3612, 0xa9, 0x0}, \
 {0x3614, 0x50, 0x0}, \
 {0x3618, 0x00, 0x0}, \
 {0x3034, 0x18, 0x0}, \
 {0x3035, 0x21, 0x0}, \
 {0x3036, 0x70, 0x0}, \
 {0x3600, 0x09, 0x0}, \
 {0x3601, 0x43, 0x0}, \
 {0x3708, 0x66, 0x0}, \
 {0x370c, 0xc3, 0x0}, \
 {0x3800, 0x00, 0x0}, \
 {0x3801, 0x00, 0x0}, \
 {0x3802, 0x00, 0x0}, \
 {0x3803, 0x06, 0x0}, \
 {0x3804, 0x0a, 0x0}, \
 {0x3805, 0x3f, 0x0}, \
 {0x3806, 0x07, 0x0}, \
 {0x3807, 0x9d, 0x0}, \
 {0x3808, 0x05, 0x0}, \
 {0x3809, 0x00, 0x0}, \
 {0x380a, 0x03, 0x0}, \
 {0x380b, 0xc0, 0x0}, \
 {0x380c, 0x07, 0x0}, \
 {0x380d, 0x68, 0x0}, \
 {0x380e, 0x03, 0x0}, \
 {0x380f, 0xd8, 0x0}, \
 {0x3813, 0x06, 0x0}, \
 {0x3814, 0x31, 0x0}, \
 {0x3815, 0x31, 0x0}, \
 {0x3820, 0x47, 0x0}, \
 {0x3a02, 0x03, 0x0}, \
 {0x3a03, 0xd8, 0x0}, \
 {0x3a08, 0x01, 0x0}, \
 {0x3a09, 0xf8, 0x0}, \
 {0x3a0a, 0x01, 0x0}, \
 {0x3a0b, 0xa4, 0x0}, \
 {0x3a0e, 0x02, 0x0}, \
 {0x3a0d, 0x02, 0x0}, \
 {0x3a14, 0x03, 0x0}, \
 {0x3a15, 0xd8, 0x0}, \
 {0x3a18, 0x00, 0x0}, \
 {0x4004, 0x02, 0x0}, \
 {0x4005, 0x18, 0x0}, \
 {0x4300, 0x30, 0x0}, \
 {0x4202, 0x00, 0x0}, \
}

static sensor_lib_t sensor_lib_ptr =
{
  .sensor_slave_info =
  {
    .sensor_name = SENSOR_MODEL,
    .slave_addr = 0x78,
    .i2c_freq_mode = SENSOR_I2C_MODE_FAST,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .sensor_id_info =
    {
      .sensor_id_reg_addr = 0x300a,
      .sensor_id = 0x5645,
    },
    .power_setting_array =
    {
      .power_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VIO,
          .config_val = 0,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VANA,
          .config_val = 0,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_LOW,
          .delay = 5,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 5,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_HIGH,
          .delay = 5,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_HIGH,
          .delay = 10,
        },
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 24000000,
          .delay = 10,
        },
      },
      .size = 8,
      .power_down_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VANA,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VIO,
          .config_val = 0,
          .delay = 0,
        },
      },
      .size_down = 6,
    },
  },
  .sensor_output =
  {
    .output_format = SENSOR_YCBCR,
    .connection_mode = SENSOR_MIPI_CSI,
    .raw_output = SENSOR_8_BIT_DIRECT,
    .filter_arrangement = SENSOR_YUYV,
  },
  .output_reg_addr =
  {
    .x_output = 0,
    .y_output = 0,
    .line_length_pclk = 0,
    .frame_length_lines = 0,
  },
  .exp_gain_info =
  {
    .coarse_int_time_addr = 0,
    .global_gain_addr = 0,
    .vert_offset = 0,
  },
  .aec_info =
  {
    .min_gain = 0,
    .max_gain = 0,
    .max_analog_gain = 0,
    .max_linecount = 0,
  },
  .sensor_num_frame_skip = 3,
  .sensor_num_HDR_frame_skip = 3,
  .sensor_max_pipeline_frame_delay = 1,
  .sensor_property =
  {
    .pix_size = 1.4,
    .sensing_method = SENSOR_SMETHOD_ONE_CHIP_COLOR_AREA_SENSOR,
    .crop_factor = 1.0,
  },
  .pixel_array_size_info =
  {
    .active_array_size =
    {
      .width = 2592,
      .height = 1944,
    },
    .left_dummy = 16,
    .right_dummy = 16,
    .top_dummy = 6,
    .bottom_dummy = 6,
  },
  .sensor_stream_info_array =
  {
    .sensor_stream_info =
    {
      {
        .vc_cfg_size = 1,
        .vc_cfg =
        {
          {
            .cid = 0,
            .dt = CSI_YUV422_8,
            .decode_format = CSI_DECODE_8BIT
          },
        },
        .pix_data_fmt =
        {
          SENSOR_YCBCR,
        },
      },
      {
        .vc_cfg_size = 1,
        .vc_cfg =
        {
          {
            .cid = 1,
            .dt = CSI_EMBED_DATA,
            .decode_format = CSI_DECODE_8BIT
          },
        },
        .pix_data_fmt =
        {
          SENSOR_META
        },
      },
    },
    .size = 2,
  },
  .start_settings =
  {
    .reg_setting_a = START_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .stop_settings =
  {
    .reg_setting_a = STOP_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .embedded_data_enable_settings =
  {
    .reg_setting_a = {},
    .addr_type = 0,
    .data_type = 0,
    .delay = 0,
  },
  .embedded_data_disable_settings =
  {
    .reg_setting_a = {},
    .addr_type = 0,
    .data_type = 0,
    .delay = 0,
  },
  .aec_enable_settings =
  {
    .reg_setting_a = AEC_ENABLE_SETTINGS_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .aec_disable_settings =
  {
    .reg_setting_a = AEC_DISABLE_SETTINGS_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .init_settings_array =
  {
    .reg_settings =
    {
      {
        .reg_setting_a = INIT0_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
    },
    .size = 1,
  },
  .res_settings_array =
  {
    .reg_settings =
    {
      /* Res 0 */
      {
        .reg_setting_a = RES0_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
      /* Res 1 */
      {
        .reg_setting_a = RES1_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
    },
    .size = 2,
  },
  .out_info_array =
  {
    .out_info =
    {
      /* Res 0 */
      {
        .x_output = 2592*2,
        .y_output = 1944,
        .line_length_pclk = 2844*2,
        .frame_length_lines = 1968,
        .vt_pixel_clk = 168000000,
        .op_pixel_clk = 168000000,
        .binning_factor = 1,
        .min_fps = 15.0,
        .max_fps = 15.0,
        .mode = SENSOR_DEFAULT_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
      /* Res 1 */
      {
        .x_output = 1280*2,
        .y_output = 960,
        .line_length_pclk = 1896*2,
        .frame_length_lines = 984,
        .vt_pixel_clk = 112000000,
        .op_pixel_clk = 112000000,
        .binning_factor = 1,
        .min_fps = 30.0,
        .max_fps = 30.0,
        .mode = SENSOR_DEFAULT_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
    },
    .size = 2,
  },
  .csi_params =
  {
    .lane_cnt = 2,
    .settle_cnt = 29,
    .is_csi_3phase = 0,
  },
  .csid_lut_params_array =
  {
    .lut_params =
    {
      /* Res 0 */
      {
        .num_cid = 2,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_YUV422_8,
            .decode_format = CSI_DECODE_8BIT
          },
          {
            .cid = 1,
            .dt = CSI_EMBED_DATA,
            .decode_format = CSI_DECODE_8BIT
          },
        },
      },
      /* Res 1 */
      {
        .num_cid = 2,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_YUV422_8,
            .decode_format = CSI_DECODE_8BIT
          },
          {
            .cid = 1,
            .dt = CSI_EMBED_DATA,
            .decode_format = CSI_DECODE_8BIT
          },
        },
      },
    },
    .size = 2,
  },
  .crop_params_array =
  {
    .crop_params =
    {
      /* Res 0 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 1 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
    },
    .size = 2,
  },
};

#endif
