#include <edidentifier.h>
__CIDENT_RCSID(cr_spdeq_c,"$Id: spdeq.c,v 1.14 2022/03/21 15:17:20 cvsuser Exp $")

/* -*- mode: c; indent-width: 4; -*- */
/* $Id: spdeq.c,v 1.14 2022/03/21 15:17:20 cvsuser Exp $
 * libsplay version 2.0 - SPLAY tree implementation.
 *
 *
 * Copyright (c) 1998 - 2022, Adam Young.
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

#include "spheaders.h"


/*  Function:           spdeq
 *      Dequeue/remove an element from the tree
 *
 *   Parameters:
 *      q - Element.
 *      tree - splay tree reference.
 *
 *  Returns:
 *      nothing
 */
void
spdeq(SPBLK * q, SPTREE * tree)
{
    _sproot *root = &tree->sp_root;

    SP_INCR(spdeq);
    if (SPLAY_REMOVE(libsplay, root, q)) {
        --tree->sp_count;
    }
}


