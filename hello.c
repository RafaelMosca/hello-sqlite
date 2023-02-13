#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT1

static void hello_sqlite(
    sqlite3_context *ctx,
    int argc,
    sqlite3_value **argv) {

    const char *text = sqlite3_value_text(argv[0]);
    char *hello = sqlite3_mprintf("Hello %s!", text);
    sqlite3_log(0, "Log: %s", hello);
    sqlite3_result_text(ctx, hello, -1, sqlite3_free);
}

#ifdef _WIN32
__declspec(dllexport)
#endif
int sqlite3_hello_init(
    sqlite3 *db, 
    char **pzErrMsg, 
    const sqlite3_api_routines *pApi) {
    
    SQLITE_EXTENSION_INIT2(pApi);
    sqlite3_create_function_v2(db, "HELLO", 1, SQLITE_UTF8, 0, hello_sqlite, 0, 0, 0);
    return SQLITE_OK;
}

