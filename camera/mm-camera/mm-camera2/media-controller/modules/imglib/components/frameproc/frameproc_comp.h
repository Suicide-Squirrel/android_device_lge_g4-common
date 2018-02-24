/**********************************************************************
* Copyright (c) 2013-2015 Qualcomm Technologies, Inc.
* All Rights Reserved.
* Confidential and Proprietary - Qualcomm Technologies, Inc.
**********************************************************************/

#ifndef __FRAMEPROC_COMP_H__
#define __FRAMEPROC_COMP_H__

#include "img_comp_priv.h"
#include "chromatix.h"

/** frameproc_comp_t
 *   @ptr: library handle
 *   @img_algo_process: Main algo process function pointer
 *   @img_algo_init: Function pointer to create and initialize
 *                 the algorithm wrapper
 *   @img_algo_deinit: Function pointer to deinitialize and
 *                   destroy the algorithm wrapper
 *   @img_algo_frame_ind: Function pointer to indicate when an
 *             input frame is available
 *   @img_algo_meta_ind: Function pointer to indicate when an
 *             meta frame is available
 *   @img_algo_set_frame_ops: Function pointer to set frame ops
 *   @img_algo_preload: Function pointer for preload/
 *                    initialization of the algorithm parameters
 *                    before the algorithm is invoked.
 *   @img_algo_shutdown: Function pointer for deinitializing the
 *                     parameters which are done during preload
 *   @base_ops: Operation table and preload parameters for
 *            memory/thread operations
 *   @img_algo_post_process: Function pointer for post proc ops
 *
 *   Frameproc library function pointers
 **/
typedef struct {
  void *ptr;
  int (*img_algo_process)(void *p_context,
    img_frame_t *p_in_frame[],
    int in_frame_cnt,
    img_frame_t *p_out_frame[],
    int out_frame_cnt,
    img_meta_t *p_meta[],
    int meta_cnt);
  int (*img_algo_init)(void **pp_context, img_init_params_t *p_params);
  int (*img_algo_deinit)(void *p_context);
  int (*img_algo_frame_ind)(void *p_context, img_frame_t *p_frame);
  int (*img_algo_meta_ind)(void *p_context, img_meta_t *p_meta);
  int (*img_algo_set_frame_ops)(void *p_context, img_frame_ops_t *p_ops);
  int (*img_algo_preload)(img_base_ops_t *p_ops);
  int (*img_algo_shutdown)(img_base_ops_t *p_ops);
  img_base_ops_t base_ops;
  int (*img_algo_post_process)(void *p_context);
} frameproc_lib_info_t;

/** frameproc_comp_t
 *   @b: base component
 *   @p_lib: library info
 *   @p_algocontext: algorithm context
 *   @abort: Flag to indicate whether the algo is aborted
 *   @msgQ: Message queue
 *
 *   Frameproc component
 **/
typedef struct {
  /*base component*/
  img_component_t b;
  frameproc_lib_info_t *p_lib;
  void *p_algocontext;
  int8_t abort;
  img_queue_t msgQ;
} frameproc_comp_t;

#endif //__FRAMEPROC_COMP_H__
