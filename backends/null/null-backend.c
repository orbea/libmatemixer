/*
 * Copyright (C) 2014 Michal Ratajsky <michal.ratajsky@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the licence, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include <glib.h>
#include <glib-object.h>
#include <libmatemixer/matemixer.h>
#include <libmatemixer/matemixer-private.h>

#include "null-backend.h"

#define BACKEND_NAME      "Null"
#define BACKEND_PRIORITY  0
#define BACKEND_FLAGS     MATE_MIXER_BACKEND_NO_FLAGS

G_DEFINE_DYNAMIC_TYPE (NullBackend, null_backend, MATE_MIXER_TYPE_BACKEND)

static gboolean null_backend_open (MateMixerBackend *backend);

static MateMixerBackendInfo info;

void
backend_module_init (GTypeModule *module)
{
    null_backend_register_type (module);

    info.name          = BACKEND_NAME;
    info.priority      = BACKEND_PRIORITY;
    info.g_type        = NULL_TYPE_BACKEND;
    info.backend_flags = BACKEND_FLAGS;
    info.backend_type  = MATE_MIXER_BACKEND_NULL;
}

const MateMixerBackendInfo *backend_module_get_info (void)
{
    return &info;
}

static void
null_backend_class_init (NullBackendClass *klass)
{
    MateMixerBackendClass *backend_class;

    backend_class = MATE_MIXER_BACKEND_CLASS (klass);
    backend_class->open = null_backend_open;
}

/* Called in the code generated by G_DEFINE_DYNAMIC_TYPE() */
static void
null_backend_class_finalize (NullBackendClass *klass)
{
}

static void
null_backend_init (NullBackend *null)
{
}

static gboolean
null_backend_open (MateMixerBackend *backend)
{
    _mate_mixer_backend_set_state (backend, MATE_MIXER_STATE_READY);
    return TRUE;
}
