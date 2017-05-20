/*
  File: acl_set_file.c

  Copyright (C) 1999, 2000
  Andreas Gruenbacher, <a.gruenbacher@bestbits.at>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include "config.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include "libacl.h"

#include "__acl_set_file.h"

/* 23.4.22 */
int
acl_set_file(const char *path_p, acl_type_t type, acl_t acl)
{
	return __acl_set_file(path_p, type, acl, setxattr);
}
