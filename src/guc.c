#include "guc.h"

void _guc_init(void) {
	DefineCustomStringVariable("demopgextension.message_txt",
							   "message text to this sample guc",
							   NULL,
							   NULL,
							   "Hello there:",
							   PGC_USERSET,
							   0,
							   NULL,
							   NULL,
							   NULL);
}