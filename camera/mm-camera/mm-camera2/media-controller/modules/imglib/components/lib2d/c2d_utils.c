/**********************************************************************
*  Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
*  All Rights Reserved.
*  Confidential and Proprietary - Qualcomm Technologies, Inc.
**********************************************************************/

#include <dlfcn.h>
#include <linux/msm_kgsl.h>
#include "c2d_utils.h"
#include "cam_intf.h"
#include "img_common.h"
#include "lib2d_util_interface.h"

/**
 * Function: c2d_util_get_yuv_format
 *
 * Description: Gets the C2D_YUV_FORMAT corresponds to cam_format_t
 *
 * Input parameters:
 *   cam_fmt - camera format
 *
 * Return values:
 *   C2D YUV color format
 *
 * Notes: none
 **/
static C2D_YUV_FORMAT c2d_util_get_yuv_format(cam_format_t cam_fmt)
{
  switch (cam_fmt) {
    case CAM_FORMAT_YUV_420_NV12:
    case CAM_FORMAT_YUV_420_NV12_VENUS:
    case CAM_FORMAT_YUV_420_NV12_UBWC:
      return C2D_COLOR_FORMAT_420_NV12;
    case CAM_FORMAT_YUV_420_NV21:
    case CAM_FORMAT_YUV_420_NV21_VENUS:
      return C2D_COLOR_FORMAT_420_NV21;
    case CAM_FORMAT_YUV_420_YV12:
      return C2D_COLOR_FORMAT_420_YV12;
    case CAM_FORMAT_YUV_422_NV16:
      return C2D_COLOR_FORMAT_422_UYVY;
    case CAM_FORMAT_YUV_422_NV61:
      return C2D_COLOR_FORMAT_422_UYVY;
    case CAM_FORMAT_YUV_RAW_8BIT_YUYV:
      return C2D_COLOR_FORMAT_422_YUYV;
    case CAM_FORMAT_YUV_RAW_8BIT_YVYU:
      return C2D_COLOR_FORMAT_422_YVYU;
    case CAM_FORMAT_YUV_RAW_8BIT_UYVY:
      return C2D_COLOR_FORMAT_422_UYVY;
    case CAM_FORMAT_YUV_RAW_8BIT_VYUY:
      return C2D_COLOR_FORMAT_422_VYUY;
    default:
      IDBG_ERROR("%s %d] : Invalid yuv cam_fmt = %d",
        __func__, __LINE__, cam_fmt);
      return C2D_COLOR_FORMAT_420_NV12;
  }
} /* c2d_util_get_yuv_format */

/**
 * Function: c2d_util_get_rgb_format
 *
 * Description: Gets the C2D_RGB_FORMAT corresponds to cam_format_t
 *
 * Input parameters:
 *   cam_fmt - camera format
 *
 * Return values:
 *   C2D RGB color format
 *
 * Notes: none
 **/
static C2D_RGB_FORMAT c2d_util_get_rgb_format(cam_format_t cam_fmt)
{
  switch (cam_fmt) {
    case CAM_FORMAT_8888_ARGB:
      return C2D_COLOR_FORMAT_8888_ARGB;
    default:
      IDBG_ERROR("%s %d] : Invalid rgb cam_fmt = %d",
        __func__, __LINE__, cam_fmt);
      return C2D_COLOR_FORMAT_8888_ARGB;
  }
} /* c2d_util_get_rgb_format */

/**
 * Function: is_yuv_format
 *
 * Description: Whether the given cam_format_t is yuv format or not
 *
 * Input parameters:
 *   cam_fmt - camera format
 *
 * Return values:
 *   TRUE if yuv format
 *   FALSE if rgb format
 *
 * Notes: none
 **/
static int is_yuv_format(cam_format_t cam_fmt)
{
  boolean is_yuv_format;

  switch(cam_fmt) {
    case CAM_FORMAT_YUV_420_NV12 :
    case CAM_FORMAT_YUV_420_NV21 :
    case CAM_FORMAT_YUV_420_NV21_ADRENO :
    case CAM_FORMAT_YUV_420_YV12 :
    case CAM_FORMAT_YUV_420_NV12_VENUS :
      is_yuv_format = TRUE;
      break;
    case CAM_FORMAT_8888_ARGB :
      is_yuv_format = FALSE;
      break;
    default :
      is_yuv_format = TRUE;
      break;
  }

  return is_yuv_format;
}

/**
 * Function: c2d_util_create_default_surface
 *
 * Description: Creates a default c2d surface
 *
 * Input parameters:
 *   c2d_util_handle - handle to c2d_util_handle
 *   cam_fmt - format of surface that need to be created
 *   surface - surface handle
 *
 * Return values:
 *   IMG_SUCCESS
 *   IMG_ERR_GENERAL
 *
 * Notes: none
 **/
static int32_t c2d_util_create_default_surface(c2d_util_handle *handle,
  cam_format_t cam_fmt, c2d_surface *surface)
{
  C2D_STATUS c2d_rc  = C2D_STATUS_OK;

  if (is_yuv_format(cam_fmt) == TRUE) {
    surface->surface_type            = C2D_SURFACE_YUV;
    surface->surface_bit             = (C2D_SOURCE | C2D_TARGET);
    surface->yuv_surface.format      = c2d_util_get_yuv_format(cam_fmt);
    C2D_YUV_SURFACE_DEF *surface_def = &surface->yuv_surface.surface_def;

    /* Create Dummy YUV Surface */
    surface_def->format  = surface->yuv_surface.format;
    surface_def->width   = 1 * 4;
    surface_def->height  = 1 * 4;
    surface_def->plane0  = (void*)0xaaaaaaaa;
    surface_def->phys0   = (void*)0xaaaaaaaa;
    surface_def->stride0 = 1 * 4;
    surface_def->plane1  = (void*)0xaaaaaaaa;
    surface_def->phys1   = (void*)0xaaaaaaaa;
    surface_def->stride1 = 1 * 4;
    surface_def->plane2  = (void*)0xaaaaaaaa;
    surface_def->phys2   = (void*)0xaaaaaaaa;
    surface_def->stride2 = 1 * 4;

    c2d_rc = handle->c2d_lib.c2dCreateSurface(&surface->id,
      surface->surface_bit,
      (C2D_SURFACE_TYPE)(C2D_SURFACE_YUV_HOST | C2D_SURFACE_WITH_PHYS |
      C2D_SURFACE_WITH_PHYS_DUMMY),
      surface_def);
    if (c2d_rc != C2D_STATUS_OK) {
      IDBG_ERROR("%s:%d failed. c2d_rc = %d\n", __func__, __LINE__, c2d_rc);
      return IMG_ERR_GENERAL;
    }
  } else {
    surface->surface_type            = C2D_SURFACE_RGB;
    surface->surface_bit             = (C2D_SOURCE | C2D_TARGET);
    surface->rgb_surface.format      = c2d_util_get_rgb_format(cam_fmt);
    C2D_RGB_SURFACE_DEF *surface_def = &surface->rgb_surface.surface_def;

    /* Create Dummy RGB Surface */
    surface_def->format  = surface->rgb_surface.format;
    surface_def->width   = 1 * 4;
    surface_def->height  = 1 * 4;
    surface_def->stride  = 1 * 4;
    surface_def->buffer  = (void*)0xaaaaaaaa;
    surface_def->phys    = (void*)0xaaaaaaaa;

    c2d_rc = handle->c2d_lib.c2dCreateSurface(&surface->id,
      surface->surface_bit,
      (C2D_SURFACE_TYPE)(C2D_SURFACE_RGB_HOST | C2D_SURFACE_WITH_PHYS |
      C2D_SURFACE_WITH_PHYS_DUMMY),
      surface_def);
    if (c2d_rc != C2D_STATUS_OK) {
      IDBG_ERROR("%s:%d failed. c2d_rc = %d\n", __func__, __LINE__, c2d_rc);
      return IMG_ERR_GENERAL;
    }
  }

  IDBG_MED("%s:%d] \n", __func__, __LINE__);
  return IMG_SUCCESS;
} /* c2d_create_default_yuv_surface */

/**
 * Function: c2d_util_destroy_surface
 *
 * Description: Destroys a c2d surface
 *
 * Input parameters:
 *   handle - handle to c2d_util_handle
 *   surface - surface handle
 *
 * Return values:
 *   IMG_SUCCESS
 *   IMG_ERR_GENERAL
 *
 * Notes: none
 **/
static int32_t c2d_util_destroy_surface(c2d_util_handle *handle,
  c2d_surface *surface)
{
  C2D_STATUS c2d_rc  = C2D_STATUS_OK;

  // Destroy the corresponding c2d surface handle
  c2d_rc = handle->c2d_lib.c2dDestroySurface(surface->id);
  if (c2d_rc != C2D_STATUS_OK) {
    IDBG_ERROR("%s:%d failed. c2d_rc = %d\n", __func__, __LINE__, c2d_rc);
    return IMG_ERR_GENERAL;
  }

  return IMG_SUCCESS;
}

/**
 * Function: c2d_util_update_surface
 *
 * Description: Update c2d surface.
 *
 * Input parameters:
 *   handle - handle to c2d_util_handle
 *   surface - surface handle
 *   p_frame - handle to img_frame_t with which surface need to be updated
 *
 * Return values:
 *   IMG_SUCCESS
 *   IMG_ERR_NO_MEMORY
 *   IMG_ERR_GENERAL
 *
 * Notes: none
 **/
static int32_t c2d_util_update_surface(c2d_util_handle *handle,
  c2d_surface *surface, img_frame_t *p_frame)
{
  C2D_STATUS c2d_rc  = C2D_STATUS_OK;

  // We would be mapping and unmapping for each frame.
  // This should be NULL by this time.
  // assert(surface->gpu_map_addr == NULL);

  if (surface->surface_type == C2D_SURFACE_RGB) {
    // assert(p_frame->frame[0].plane_cnt == 1);

    // RGB surface
    c2d_rgb_surface     *rgb_surface = &surface->rgb_surface;
    C2D_RGB_SURFACE_DEF *surface_def = &rgb_surface->surface_def;

    c2d_rc = handle->c2d_lib.c2dMapAddr(p_frame->frame[0].plane[0].fd,
      p_frame->frame[0].plane[0].addr, p_frame->frame[0].plane[0].length,
      p_frame->frame[0].plane[0].offset, KGSL_USER_MEM_TYPE_ION,
      &surface->gpu_map_addr);
    if (c2d_rc != C2D_STATUS_OK) {
      IDBG_ERROR("%s:%d failed c2d_rc %d\n", __func__, __LINE__, c2d_rc);
      return IMG_ERR_NO_MEMORY;
    }

    /* Update the surface */
    surface_def->width   = p_frame->frame[0].plane[0].width;
    surface_def->height  = p_frame->frame[0].plane[0].height;
    surface_def->stride  = p_frame->frame[0].plane[0].stride;
    surface_def->buffer  = (void*)
                           ((unsigned long)p_frame->frame[0].plane[0].addr +
                            p_frame->frame[0].plane[0].offset);
    surface_def->phys    = (void*)
                           ((uint8_t *)surface->gpu_map_addr +
                            p_frame->frame[0].plane[0].offset);

    c2d_rc = handle->c2d_lib.c2dUpdateSurface(surface->id,
      surface->surface_type,
      (C2D_SURFACE_TYPE)(C2D_SURFACE_RGB_HOST | C2D_SURFACE_WITH_PHYS),
      (void *)surface_def);
    if (c2d_rc != C2D_STATUS_OK) {
      IDBG_ERROR("%s, %d] : c2d_util_update_surface failed. c2d_rc = %d\n",
        __func__, __LINE__, c2d_rc);
      goto ERROR_UNMAP;
    }
  } else {
    // YUV surface
    c2d_yuv_surface     *yuv_surface = &surface->yuv_surface;
    C2D_YUV_SURFACE_DEF *surface_def = &yuv_surface->surface_def;
    uint32_t             length      = 0;
    uint32_t             plane;

    // Client has to make sure plane[1]. plane[2] do not have
    // junk values if plane_cnt is 1 or 2
    for (plane = 0; plane < p_frame->frame[0].plane_cnt; plane++) {
      length += p_frame->frame[0].plane[plane].length;
    }

    c2d_rc = handle->c2d_lib.c2dMapAddr(p_frame->frame[0].plane[0].fd,
      p_frame->frame[0].plane[0].addr, length,
      p_frame->frame[0].plane[0].offset, KGSL_USER_MEM_TYPE_ION,
      &surface->gpu_map_addr);
    if (c2d_rc != C2D_STATUS_OK) {
      IDBG_ERROR("%s:%d failed c2d_rc %d\n", __func__, __LINE__, c2d_rc);
      return IMG_ERR_NO_MEMORY;
    }

    /* Update the surface */
    surface_def->width   = p_frame->frame[0].plane[0].width;
    surface_def->height  = p_frame->frame[0].plane[0].height;

    surface_def->plane0  = (void*)
                           ((unsigned long)p_frame->frame[0].plane[0].addr +
                            p_frame->frame[0].plane[0].offset);
    surface_def->phys0   = (void*)
                           ((uint8_t *)surface->gpu_map_addr +
                            p_frame->frame[0].plane[0].offset);
    surface_def->stride0 = p_frame->frame[0].plane[0].stride;

    if (p_frame->frame[0].plane_cnt > 1) {
      surface_def->plane1  = (void*)
                             ((unsigned long)p_frame->frame[0].plane[1].addr +
                              p_frame->frame[0].plane[1].offset);
      surface_def->phys1   = (void*)
                             ((uint8_t *)surface->gpu_map_addr +
                              ((uint8_t *)surface_def->plane1 - (uint8_t *)surface_def->plane0) +
                              p_frame->frame[0].plane[1].offset);
      surface_def->stride1 = p_frame->frame[0].plane[1].stride;
    }

    if (p_frame->frame[0].plane_cnt > 2) {
      surface_def->plane2  = (void*)
                             ((unsigned long)p_frame->frame[0].plane[2].addr +
                              p_frame->frame[0].plane[2].offset);
      surface_def->phys2   = (void*)
                             ((uint8_t *)surface->gpu_map_addr +
                              ((uint8_t *)surface_def->plane2 - (uint8_t *)surface_def->plane0) +
                              p_frame->frame[0].plane[2].offset);
      surface_def->stride2 = p_frame->frame[0].plane[2].stride;
    }

    c2d_rc = handle->c2d_lib.c2dUpdateSurface(surface->id,
      surface->surface_type,
      (C2D_SURFACE_TYPE)(C2D_SURFACE_YUV_HOST | C2D_SURFACE_WITH_PHYS),
      (void *)surface_def);

    if (c2d_rc != C2D_STATUS_OK) {
      IDBG_ERROR("%s %d] : c2d_util_update_surface failed. c2d_rc = %d\n",
        __func__, __LINE__, c2d_rc);
      goto ERROR_UNMAP;
    }
  }

  return IMG_SUCCESS;

ERROR_UNMAP:
  handle->c2d_lib.c2dUnMapAddr(surface->gpu_map_addr);
  surface->gpu_map_addr = NULL;
  return IMG_ERR_GENERAL;
} /* c2d_update_surface */

/**
 * Function: c2d_util_draw_surface
 *
 * Description: Draw the surface.
 *
 * Input parameters:
 *   handle - handle to c2d_util_handle
 *   src_surface - source surface handle
 *   dst_surface - destination surface handle
 *
 * Return values:
 *   IMG_SUCCESS
 *   IMG_ERR_GENERAL
 *
 * Notes: none
 **/
static int32_t c2d_util_draw_surface(c2d_util_handle *handle,
  c2d_surface *src_surface, c2d_surface *dst_surface)
{
  C2D_STATUS c2d_rc;
  C2D_OBJECT c2dObject[1];
  memset(c2dObject, 0, sizeof(C2D_OBJECT));
  c2dObject[0].config_mask = (C2D_NO_BILINEAR_BIT | C2D_ALPHA_BLEND_NONE);
  c2dObject[0].surface_id  = src_surface->id;

  // uint32_t rotation = 0, flip = 0;
  C2D_TARGET_CONFIG target_config = C2D_TARGET_ROTATE_0;
  // target_config = c2d_get_target_rotation(rotation, flip);

  /* C2D draw */
  c2d_rc = handle->c2d_lib.c2dDraw(dst_surface->id,
    target_config, NULL, 0, 0,
    c2dObject, 1);
  if (c2d_rc != C2D_STATUS_OK) {
    IDBG_ERROR("%s:%d failed.c2d_rc %d\n", __func__, __LINE__, c2d_rc);
    return IMG_ERR_GENERAL;
  }

  /* C2D finish */
  c2d_rc = handle->c2d_lib.c2dFinish(dst_surface->id);
  if (c2d_rc != C2D_STATUS_OK) {
    IDBG_ERROR("%s:%d failed.c2d_rc %d\n", __func__, __LINE__, c2d_rc);
    return IMG_ERR_GENERAL;
  }

  return IMG_SUCCESS;
}

/**
 * Function: c2d_util_process_frame
 *
 * Description: Process the frame
 *
 * Input parameters:
 *   lib_private - handle to c2d_util_handle
 *   p_in_frame - pointer to input frame
 *   p_out_frame - pointer to output frame
 *
 * Return values:
 *   IMG_SUCCESS
 *   IMG_ERR_GENERAL
 *
 * Notes: none
 **/
int32_t c2d_util_process_frame(void *lib_private, img_frame_t *p_in_frame,
  img_frame_t *p_out_frame)
{
  int32_t rc = IMG_SUCCESS;
  c2d_util_handle *handle = (c2d_util_handle *)lib_private;

  // Check the source surface
  // if format of p_in_frame, handle->src_surface are not equal :
  //     destroy source_surface and create again with p_in_frame format.
  // similarly, dst surface

  // Update Source surface
  rc = c2d_util_update_surface(handle, &handle->src_surface, p_in_frame);
  if (rc != IMG_SUCCESS) {
    // we would have already done UNMAP, we can return here.
    return rc;
  }

  // Update Destination surface
  rc = c2d_util_update_surface(handle, &handle->dst_surface, p_out_frame);
  if (rc != IMG_SUCCESS) {
    // we would have already done UNMAP of dst_surface,
    //  but src_surface is still mapped. Unmap the src_surface first.
    handle->c2d_lib.c2dUnMapAddr(handle->src_surface.gpu_map_addr);
    handle->src_surface.gpu_map_addr = NULL;
    return rc;
  }

  // DRAW, Finish
  rc = c2d_util_draw_surface(handle, &handle->src_surface,
    &handle->dst_surface);
  if (rc != IMG_SUCCESS) {
    // Irrespective of success/failure here, we have to Unmap src, dst surfaces
    // just pring error, but do not return directly from here.
    IDBG_ERROR("%s:%d failed.rc %d\n", __func__, __LINE__, rc);
  }

  // Unmap Source surface
  handle->c2d_lib.c2dUnMapAddr(handle->src_surface.gpu_map_addr);
  handle->src_surface.gpu_map_addr = NULL;

  // Unmap Destination surface
  handle->c2d_lib.c2dUnMapAddr(handle->dst_surface.gpu_map_addr);
  handle->dst_surface.gpu_map_addr = NULL;

  IDBG_MED("%s:%d] \n", __func__, __LINE__);
  return rc;
}

/**
 * Function: c2d_util_open
 *
 * Description: function to open c2d library. Creates
 *     default source, destination surfaces.
 *
 * Input parameters:
 *   lib_private - handle to c2d_util_handle
 *
 * Return values:
 *   IMG_SUCCESS
 *   IMG_ERR_GENERAL
 *
 * Notes: none
 **/
int32_t c2d_util_open(void **lib_private)
{
  int32_t rc = IMG_SUCCESS;
  c2d_util_handle *handle = NULL;

  IDBG_MED("%s:%d] E\n", __func__, __LINE__);

  /* Validate input parameters */
  if (!lib_private) {
    IDBG_ERROR("%s:%d failed\n", __func__, __LINE__);
    return IMG_ERR_INVALID_INPUT;
  }

  /* Allcate memory for c2d control structure */
  handle = (c2d_util_handle *)malloc(sizeof(c2d_util_handle));
  if (!handle) {
    IDBG_ERROR("%s %d] : Malloc Error", __func__, __LINE__);
    return IMG_ERR_NO_MEMORY;
  }
  memset(handle, 0x0, sizeof(c2d_util_handle));

  /* Open C2D library*/
  handle->c2d_lib.ptr = dlopen("libC2D2.so", RTLD_NOW);
  if (!handle->c2d_lib.ptr) {
    IDBG_ERROR("%s %d] ERROR: couldn't dlopen libc2d2.so: %s",
        __func__, __LINE__, dlerror());
    goto ERROR1;
  }

  IDBG_MED("%s:%d] \n", __func__, __LINE__);
  /* Get function pointer for functions supported by C2D */
  *(void **)&handle->c2d_lib.c2dCreateSurface =
      dlsym(handle->c2d_lib.ptr, "c2dCreateSurface");
  *(void **)&handle->c2d_lib.c2dUpdateSurface =
      dlsym(handle->c2d_lib.ptr, "c2dUpdateSurface");
  *(void **)&handle->c2d_lib.c2dLensCorrection =
      dlsym(handle->c2d_lib.ptr, "c2dLensCorrection");
  *(void **)&handle->c2d_lib.c2dDraw =
      dlsym(handle->c2d_lib.ptr, "c2dDraw");
  *(void **)&handle->c2d_lib.c2dFinish =
      dlsym(handle->c2d_lib.ptr, "c2dFinish");
  *(void **)&handle->c2d_lib.c2dDestroySurface =
      dlsym(handle->c2d_lib.ptr, "c2dDestroySurface");
  *(void **)&handle->c2d_lib.c2dMapAddr =
      dlsym(handle->c2d_lib.ptr, "c2dMapAddr");
  *(void **)&handle->c2d_lib.c2dUnMapAddr =
      dlsym(handle->c2d_lib.ptr, "c2dUnMapAddr");
  /* c2dGetDriverCapabilities is not present in A family */
  /* *(void **)&ctrl->c2d_lib.c2dGetDriverCapabilities =
      dlsym(ctrl->c2d_lib.ptr, "c2dGetDriverCapabilities"); */

  IDBG_MED("%s:%d] \n", __func__, __LINE__);
  /* Validate function pointers for C2D library */
  if (!handle->c2d_lib.c2dCreateSurface || !handle->c2d_lib.c2dUpdateSurface ||
    !handle->c2d_lib.c2dFinish || !handle->c2d_lib.c2dDestroySurface ||
    !handle->c2d_lib.c2dLensCorrection || !handle->c2d_lib.c2dDraw ||
    !handle->c2d_lib.c2dMapAddr || !handle->c2d_lib.c2dUnMapAddr) {
    IDBG_ERROR("%s %d] : ERROR mapping symbols from libc2d2.so. "
      "c2dCreateSurface=%p, c2dUpdateSurface=%p, c2dFinish=%p, "
      "c2dDestroySurface=%p, c2dLensCorrection=%p, c2dDraw=%p, "
      "c2dMapAddr=%p, c2dUnMapAddr=%p",
      __func__, __LINE__,
      handle->c2d_lib.c2dCreateSurface, handle->c2d_lib.c2dUpdateSurface,
      handle->c2d_lib.c2dFinish, handle->c2d_lib.c2dDestroySurface,
      handle->c2d_lib.c2dLensCorrection, handle->c2d_lib.c2dDraw,
      handle->c2d_lib.c2dMapAddr, handle->c2d_lib.c2dUnMapAddr);
    goto ERROR2;
  }
  IDBG_MED("%s:%d] \n", __func__, __LINE__);

  // Start with default Soruce, Destination formats.
  // We will destroy and re-create surface upon surface format changes
  cam_format_t src_format = CAM_FORMAT_YUV_420_NV21; // NV21
  cam_format_t dst_format = CAM_FORMAT_8888_ARGB;    // ARGB

  rc = c2d_util_create_default_surface(handle, src_format,
    &handle->src_surface);
  if (rc != IMG_SUCCESS) {
    IDBG_ERROR("%s %d] ERROR: failed in creating default source surface rc=%d",
        __func__, __LINE__, rc);
    goto ERROR2;
  }

  rc = c2d_util_create_default_surface(handle, dst_format,
    &handle->dst_surface);
  if (rc != IMG_SUCCESS) {
    IDBG_ERROR("%s %d] ERROR: failed in creating default dst surface rc=%d",
        __func__, __LINE__, rc);
    c2d_util_destroy_surface(handle, &handle->src_surface);
    goto ERROR2;
  }

  /* All succeeded, expose control structure pointer to higher layer */
  *lib_private = (void *)handle;

  IDBG_MED("%s:%d] X\n", __func__, __LINE__);
  return IMG_SUCCESS;

ERROR2:
  dlclose(handle->c2d_lib.ptr);
ERROR1:
  free(handle);
  return IMG_ERR_GENERAL;
}

/**
 * Function: c2d_util_close
 *
 * Description: function to close c2d library.
 *
 * Input parameters:
 *   lib_private - handle to c2d_util_handle
 *
 * Return values:
 *   IMG_SUCCESS
 *   IMG_ERR_INVALID_INPUT
 *
 * Notes: none
 **/
int32_t c2d_util_close(void *lib_private)
{
  int32_t rc = IMG_SUCCESS;
  c2d_util_handle *handle = (c2d_util_handle *)lib_private;
  IDBG_MED("%s:%d] Enter\n", __func__, __LINE__);

  if (NULL == handle) {
    IDBG_ERROR("%s %d] ERROR: invalid input handle", __func__, __LINE__);
    return IMG_ERR_INVALID_INPUT;
  }

  rc = c2d_util_destroy_surface(handle, &handle->src_surface);
  if (rc != IMG_SUCCESS) {
    IDBG_ERROR("%s:%d failed destroying source surface. rc = %d",
      __func__, __LINE__, rc);
  }

  rc = c2d_util_destroy_surface(handle, &handle->dst_surface);
  if (rc != IMG_SUCCESS) {
    IDBG_ERROR("%s:%d failed destroying dst surface. rc = %d",
      __func__, __LINE__, rc);
  }

  dlclose(handle->c2d_lib.ptr);

  free(handle);
  IDBG_MED("%s:%d] Exit\n", __func__, __LINE__);
  return rc;
}

/**
 * Function: c2d_util_update_default_surface
 *
 * Description: Update the default surface. If the current
 *     requested format is not same as default surface's format
 *     destroy the default surface and create with current format.
 *
 * Input parameters:
 *   lib_private - handle to c2d_util_handle
 *   is_source - whether this is a source or destination surface
 *   format - format of the current surface
 *
 * Return values:
 *   IMG_SUCCESS
 *   IMG_ERR_INVALID_INPUT
 *
 * Notes: none
 **/
int32_t c2d_util_update_default_surface(void *lib_private,
  boolean is_source, cam_format_t format)
{
  int32_t rc = IMG_SUCCESS;
  c2d_util_handle *handle = (c2d_util_handle *)lib_private;
  IDBG_MED("%s:%d] Enter\n", __func__, __LINE__);

  if (NULL == handle) {
    IDBG_ERROR("%s %d] ERROR: invalid input handle", __func__, __LINE__);
    return IMG_ERR_INVALID_INPUT;
  }

  if (is_source == TRUE) {
    rc = c2d_util_destroy_surface(handle, &handle->src_surface);
    if (rc != IMG_SUCCESS) {
      IDBG_ERROR("%s, %d] : ERROR destroying surface, rc=%d",
        __func__, __LINE__, rc);
    }

    rc = c2d_util_create_default_surface(handle, format, &handle->src_surface);
    if (rc != IMG_SUCCESS) {
      IDBG_ERROR("%s, %d] : ERROR creating default surface, rc=%d",
        __func__, __LINE__, rc);
    }
  } else {
    rc = c2d_util_destroy_surface(handle, &handle->dst_surface);
    if (rc != IMG_SUCCESS) {
      IDBG_ERROR("%s, %d] : ERROR destroying surface, rc=%d",
        __func__, __LINE__, rc);
    }

    rc = c2d_util_create_default_surface(handle, format, &handle->dst_surface);
    if (rc != IMG_SUCCESS) {
      IDBG_ERROR("%s, %d] : ERROR creating default surface, rc=%d",
        __func__, __LINE__, rc);
    }
  }

  IDBG_MED("%s:%d] Exit\n", __func__, __LINE__);
  return rc;
}

