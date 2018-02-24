/*
 * Copyright (c) 2014-2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
*/

#ifndef __LTM44_H__
#define __LTM44_H__

/* isp headers */
#include "isp_sub_module_common.h"
#include "ltm_reg.h"
#include "ltm_algo.h"


#define LTM_DS_HEIGHT     240
#define LTM_DS_WIDTH      320
#define LTM_DS_SPLIT_WIDTH 506
#define LTM_H_CELLS       13
#define LTM_H_CELLS_SPLIT 20
#define LTM_V_CELLS       10
#define LTM_DC_CELLWIDTH  27 //(Ceil((LTM_DS_WIDTH/(LTM_H_CELLS-1)) ~= 27 )

#define LA_TBL_SIZE       64
#define TEMPORAL_WEIGHT   0.1f

#define LINEAR_INTERPOLATION_LTM(v1, v2, ratio) \
  ( ((v1)*(1-ratio)) + ((ratio) * (v2)) )

#define CLAMP_LTM(x, t1, t2) (((x) < (t1))? (t1): ((x) > (t2))? (t2): (x))

#define LA_SCALE(v, out_min, out_max, in_min, in_max) \
    (((float)((v) - in_min) * (float)(out_max - out_min)) / \
      ((float)(in_max) - (float)(in_min)) + (float)(out_min))

typedef enum {
  LTM_REGION_INDEX_INIT,
  LTM_DARK_BOOST_INDEX_FOUND,
  LTM_BRIGHT_REGION_FOUND
} LTM_dark_high_reg_state_t;

typedef uint32_t master_curve_lut_t[LTM_HW_LUT_SIZE];
typedef uint32_t master_scale_lut_t[LTM_HW_LUT_SIZE];
typedef uint32_t shift_curve_lut_t[LTM_HW_LUT_SIZE];
typedef uint32_t shift_scale_lut_t[LTM_HW_LUT_SIZE];
typedef uint32_t weight_lut_t[LTM_HW_W_LUT_SIZE];
typedef uint32_t mask_curve_lut_t[LTM_HW_LUT_SIZE];

typedef struct {
  LTM_light_type    tr_index;
  float             ratio;
  uint8_t           ltm_region_enable;
} LTM_trigger_index_t;

typedef boolean (*find_ltm_rgn)(chromatix_LTM_type *chromatix_ltm,
        aec_update_t *aec_update, LTM_trigger_index_t *ltm_tr_idx);

typedef struct {
  find_ltm_rgn find_rgn;
} ltm_ext_override_func;

/* Data Structures for ltm*/
/**ltm47_t
 * @reg: Register to config ltm module
 * @frame_number: frame counter
 * @isp_ltm_algo: not used now
 * @isp_ltm_session: not used now
 * @hw_master_curve: master tone curve
 * @hw_master_scale: master scale curve
 * @hw_shift_curve: shift tone curve
 * @hw_shift_scale: shift scale curve
 * @hw_mask_curve: mask curve
 * @hw_weight: weight curve
 * @algo_mask_curve: algo output
 * @weight_curve: algo output
 * @algo_master_curve: algo output
 * @algo_master_scale: algo output
 * @algo_shift_curve: algo output
 * @algo_shift_scale: algo output
 * @bankSel: dmi bank select to flip between 0 and 1
 * @aec_update: aec update from 3A
 * @asd_update: asd update from 3A
 * @sensor_out_info: sensor output info
 * @backlight_comp_update: backlight compensation
 * @enable_backlight_compensation: enable backlight
 * @backlight_severity: back light severity
 * @trigger_ratio: trigger ratio
 * @la_8k_algo_parm: used for histogram calculation
 **/
typedef struct {
  isp_ltm_reg_t             reg;
  /* track frame number to set enable on IP */
  uint64_t                  frame_number;
  uint8_t                   ltm_enable;

  /* LUT packed tables */
  uint32_t                  hw_master_curve[LTM_HW_LUT_SIZE];
  uint32_t                  hw_master_scale[LTM_HW_LUT_SIZE];
  uint32_t                  hw_shift_scale[LTM_HW_LUT_SIZE];
  uint32_t                  hw_shift_curve[LTM_HW_LUT_SIZE];
  uint32_t                  hw_mask_curve[LTM_HW_LUT_SIZE];
  uint32_t                  hw_weight[LTM_HW_W_LUT_SIZE];
  uint32_t                  hw_sat_curve[LTM_HW_LUT_SIZE];
  /* unpacked chromatix master scale, shift scale and saturation curve*/
  int                       unpacked_master_scale[LTM_HW_LUT_SIZE + 1];
  int                       unpacked_shift_scale[LTM_HW_LUT_SIZE + 1];
  int                       unpacked_sat_curve[LTM_HW_LUT_SIZE + 1];
  /* curves needed for sending back to module */
  double                    algo_master_curve[LTM_MC_TBL_SIZE];
  double                    algo_master_scale[LTM_MS_TBL_SIZE];
  double                    algo_shift_curve[LTM_SC_TBL_SIZE];
  double                    algo_shift_scale[LTM_SS_TBL_SIZE];
  uint32_t                  algo_mask_curve[LTM_MASK_TBL_SIZE];
  uint16_t                  weight_curve[LTM_W_TBL_SIZE];
  float                     cell_overlap_factor;
  float                     ratio;
  float                     exp_based_ratio;
  float                     bsd_ratio;
  boolean                   disable_ip;

  ltm_ext_override_func     *ext_func_table;

  uint8_t                   bankSel;
  aec_update_t              aec_update;
  asd_update_t              asd_update;
  sensor_out_info_t         sensor_out_info;
  ispif_out_info_t          ispif_out_info;
  isp_out_info_t            isp_out_info;

  int32_t                   backlight_comp_update;
  int32_t                   enable_backlight_compensation;
  uint32_t                  backlight_severity;
  trigger_ratio_t           trigger_ratio;
  int32_t                   prev_exp_idx;
  int32_t                   exp_idx;
  isp_la_8k_type            la_8k_algo_parm;
  int32_t                   nGlobalToneStrength;
  int32_t                   nGlobalToneContrast;
  int32_t                   nGlobalToneWeight;
  int32_t                   nLocalToneStrength;
  int32_t                   nLocalToneContrast;
  float                     fixed_content_low;
  float                     fixed_content_high;
  chromatix_LTM_type        *pChromatix_LTM;
  LTM_trigger_index_t       normal_idx;
  LTM_trigger_index_t       backlit_idx;
  isp_effects_params_t      effects;
  boolean                   init_aec_settled;
  boolean                   effect_applied;
  int32_t                   dark_boost_thr_index;
  int32_t                   highlight_sup_thr_index;
  cam_exp_bracketing_t      ae_bracketing;
  boolean                   skip_ip;
  ltm_algo_t                ltm_adrc_algo;
  boolean                   enable_adrc;
} ltm47_t;

#if OVERRIDE_FUNC
boolean ltm47_fill_func_table_ext(ltm47_t *ltm);
#define FILL_LTM_FUNC_TABLE(field) ltm47_fill_func_table_ext(field)
#else
boolean ltm47_fill_func_table(ltm47_t *ltm);
#define FILL_LTM_FUNC_TABLE(field) ltm47_fill_func_table(field)
#endif


boolean ltm47_init(mct_module_t *module,
  isp_sub_module_t *isp_sub_module);

void ltm47_destroy(mct_module_t *module,
  isp_sub_module_t *isp_sub_module);

boolean ltm47_streamon(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_streamoff(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_set_stream_config(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_trigger_enable(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_reset(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_trigger_update(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_handle_set_chromatix_ptr(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_algo_curve_update(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_stats_aec_update(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_stats_asd_update(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_update_min_stripe_overlap(
  isp_sub_module_t *isp_sub_module, void *data);

boolean ltm47_set_stripe_info(
  isp_sub_module_t *isp_sub_module, void *data);

boolean ltm47_set_split_info(isp_sub_module_t *isp_sub_module,
  void *data);

boolean ltm47_set_frame_skip(isp_sub_module_t *isp_sub_module,
  void *data);

boolean ltm47_set_spl_effect(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_set_hdr(mct_module_t *module,
  isp_sub_module_t *isp_sub_module, mct_event_t *event);

boolean ltm47_set_flash_mode(isp_sub_module_t *isp_sub_module,
  void *data);

#endif //__LTM44_H__
