/******************************************************************************
  @file    maintain_db.h
  @brief   Header file for the database maintainer, required to update the package
           database and file based on the recent launch.

  ---------------------------------------------------------------------------
  Copyright (c) 2015 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ---------------------------------------------------------------------------
******************************************************************************/
#ifndef __MAINTAIN_DB_H__
#define __MAINTAIN_DB_H__

#include "dblayer.h"

/* Public API */
static int db_maintainer_init();
static int db_maintainer_cleanup_schedule();
static int db_maintainer_update_pkg(char *pkg_name);

#endif //__MAINTAIN_DB_H__
