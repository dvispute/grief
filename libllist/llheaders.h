#ifndef GR_LLHEADERS_H_INCLUDED
#define GR_LLHEADERS_H_INCLUDED
#include <edidentifier.h>
__CIDENT_RCSID(cr_llheaders_h,"$Id: llheaders.h,v 1.11 2024/04/17 15:57:12 cvsuser Exp $")
__CPRAGMA_ONCE

/* -*- mode: c; indent-width: 4; -*- */
/* -*- indent-width: 2; -*- */
/* $Id: llheaders.h,v 1.11 2024/04/17 15:57:12 cvsuser Exp $
 *
 *
 *
 * Copyright (c) 1998 - 2024, Adam Young.
 * All rights reserved.
 *
 * This file is part of the GRIEF Editor.
 *
 * The GRIEF Editor is free software: you can redistribute it
 * and/or modify it under the terms of the GRIEF Editor License.
 *
 * Redistributions of source code must retain the above copyright
 * notice, and must be distributed with the license document above.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, and must include the license document above in
 * the documentation and/or other materials provided with the
 * distribution.
 *
 * The GRIEF Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * License for more details.
 * ==end==
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#ifdef STDC_HEADERS
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#else
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#define LLIST_STATS 1
#include <libllist.h>
#include <vm_alloc.h>

extern vmpool_t ll_freelist;

#endif /*GR_LLHEADERS_H_INCLUDED*/
