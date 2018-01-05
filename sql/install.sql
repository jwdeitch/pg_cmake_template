CREATE FUNCTION get_welcome_message(integer) RETURNS text
AS '$libdir/DemoPGExtension'
LANGUAGE C IMMUTABLE STRICT;