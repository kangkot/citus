/*-------------------------------------------------------------------------
 *
 * citus_version.c
 *	  Routines related to the version of the Citus binaries
 *
 * Copyright (c) 2012-2016, Citus Data, Inc.
 *
 *-------------------------------------------------------------------------
 */

#include "postgres.h"

#include "fmgr.h"

#include "citus_version.h"
#include "utils/builtins.h"


/* exports for SQL callable functions */
PG_FUNCTION_INFO_V1(citus_running_version);

#if !defined(CITUS_BINARY_VERSION)
#error Something went wrong, CITUS_BINARY_VERSION is not set!
#endif

/*
 * citus_running_version returns the version string the currently running code was built
 * with.
 */
Datum
citus_running_version(PG_FUNCTION_ARGS)
{
	text *versionText = cstring_to_text(CITUS_BINARY_VERSION);

	PG_RETURN_TEXT_P(versionText);
}
