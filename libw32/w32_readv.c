#include <edidentifier.h>
__CIDENT_RCSID(gr_w32_readv_c,"$Id: w32_readv.c,v 1.2 2021/10/15 12:35:03 cvsuser Exp $")

/* -*- mode: c; indent-width: 4; -*- */
/*
 * win32 readv() implementation
 *
 * Copyright (c) 2018 - 2021, Adam Young.
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
 * ==end==
 *
 * Notice: Portions of this text are reprinted and reproduced in electronic form. from
 * IEEE Portable Operating System Interface (POSIX), for reference only. Copyright (C)
 * 2001-2003 by the Institute of. Electrical and Electronics Engineers, Inc and The Open
 * Group. Copyright remains with the authors and the original Standard can be obtained
 * online at http://www.opengroup.org/unix/online.html.
 * ==extra==
 */

#ifndef _WIN32_WINNT
#define _WIN32_WINNT        0x0501              /* enable xp+ features */
#endif

#include "win32_internal.h"
#include "win32_misc.h"

#include <sys/uio.h>
#include <unistd.h>

#pragma comment(lib, "Ws2_32.lib")

LIBW32_API int /*ssize_t*/ 
readv(int fildes, const struct iovec *iov, int iovcnt)
{
    SOCKET s = (SOCKET)-1;
    int i, ret = -1;

    if (fildes < 0) {
        errno = EBADF;

    } else if (NULL == iov || iovcnt <= 0){
        errno = EINVAL;

    } else if (w32_issockfd(fildes, &s)) {
        ret = 0;
        for (i = 0; i < iovcnt; ++i) {
#undef recvfrom
            const int cnt = recvfrom(s, iov[i].iov_base, iov[i].iov_len, 0, NULL, 0);
            if (cnt > 0) {
                ret += cnt;
            } else if (0 == cnt) {
                break;
            } else {
                if (0 == ret) {
                    w32_neterrno_set();
                    ret = -1;
                }
                break;
            }
        }

    } else {
        ret = 0;
        for (i = 0; i < iovcnt; ++i) {
            const int cnt = _read(fildes, iov[i].iov_base, iov[i].iov_len);
            if (cnt > 0) {
                ret += cnt;
            } else if (0 == cnt) {
                break;
            } else if (errno == EINTR) {
                continue;
            } else {
                if (ret == 0) ret = -1;
                break;
            }
        }
    }
    return ret;
}

/*end*/
