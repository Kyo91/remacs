/* Portable API for dynamic loading.

Copyright 2015 Free Software Foundation, Inc.

This file is part of GNU Emacs.

GNU Emacs is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GNU Emacs is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef DYNLIB_H
#define DYNLIB_H

#include <stdbool.h>

typedef void *dynlib_handle_ptr;
dynlib_handle_ptr dynlib_open (const char *path);
void *dynlib_sym (dynlib_handle_ptr h, const char *sym);
typedef struct dynlib_function_ptr_nonce *(*dynlib_function_ptr) (void);
dynlib_function_ptr dynlib_func (dynlib_handle_ptr h, const char *sym);
bool dynlib_addr (void *ptr, const char **path, const char **sym);
const char *dynlib_error (void);
int dynlib_close (dynlib_handle_ptr h);

#endif /* DYNLIB_H */
