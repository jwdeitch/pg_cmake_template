#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"
#include "guc.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(base36_encode);

void
_PG_init(void) {
	_guc_init();
	elog(INFO, "loaded DemoPGExtension extension");
}

Datum
base36_encode(PG_FUNCTION_ARGS) {
	int32 arg = PG_GETARG_INT32(0);
	if (arg < 0)
		ereport(ERROR,
				(
						errcode(ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE),
								errmsg("negative values are not allowed"),
								errdetail("value %d is negative", arg),
								errhint("should be positive")
				)
		);

	char *message_txt = GetConfigOptionByName("demopgextension.message_txt", NULL,
											  true);

	if (message_txt == NULL)
		message_txt = "hello";

	// You've entered
	char *result = sprintf("%s: %i", message_txt, arg);

	PG_RETURN_TEXT_P(cstring_to_text(&result));
}