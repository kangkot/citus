/* citus--6.2-1--6.2-2.sql */

SET search_path = 'pg_catalog';

CREATE FUNCTION citus_running_version()
  RETURNS text
  LANGUAGE C IMMUTABLE
  AS 'MODULE_PATHNAME', $$citus_running_version$$;
COMMENT ON FUNCTION citus_running_version()
  IS 'get the version of the loaded citus module';

RESET search_path;
