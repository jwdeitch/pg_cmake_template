#include "guc.h"

void _guc_init() {
	DefineCustomBoolVariable("demopgextension.message_txt", "message text to this sample guc",
							 NULL,
							 false, // guc disable optimizations
							 false,
							 PGC_USERSET,
							 0,
							 NULL,
							 NULL,
							 NULL);
}