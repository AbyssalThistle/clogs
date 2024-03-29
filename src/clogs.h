#pragma once

#ifdef CLOG_NO_COLOR
	#define ANSI_COLOR_RED     ""
	#define ANSI_COLOR_GREEN   ""
	#define ANSI_COLOR_YELLOW  ""
	#define ANSI_COLOR_BLUE    ""
	#define ANSI_COLOR_MAGENTA ""
	#define ANSI_COLOR_CYAN    ""
	#define ANSI_COLOR_RESET   ""
#else
	#define ANSI_COLOR_RED     "\x1b[31m"
	#define ANSI_COLOR_GREEN   "\x1b[32m"
	#define ANSI_COLOR_YELLOW  "\x1b[33m"
	#define ANSI_COLOR_BLUE    "\x1b[34m"
	#define ANSI_COLOR_MAGENTA "\x1b[35m"
	#define ANSI_COLOR_CYAN    "\x1b[36m"
	#define ANSI_COLOR_RESET   "\x1b[0m"
#endif

#define CLOG(format, ...)\
	clogs_put(CLOGS_INFO, __func__, format, ##__VA_ARGS__)
#define CLOG_WARN(format, ...)\
	clogs_put(CLOGS_WARN, __func__, format, ##__VA_ARGS__)
#ifdef DEBUG
	#define CLOG_DEBUG(format, ...)\
		clogs_put(CLOGS_DEBUG, __func__, format, ##__VA_ARGS__)
#else
	#define CLOG_DEBUG(format, ...)
#endif
#define CLOG_ERR(format, ...)\
	clogs_put(CLOGS_ERR, __func__, format, ##__VA_ARGS__)

#define COUT(format, ...)\
	clogs_out(CLOGS_INFO, __func__, format, ##__VA_ARGS__)
#define COUT_WARN(format, ...)\
	clogs_out(CLOGS_WARN, __func__, format, ##__VA_ARGS__)
#ifdef DEBUG
	#define COUT_DEBUG(format, ...)\
		clogs_out(CLOGS_DEBUG, __func__, format, ##__VA_ARGS__)
#else
	#define COUT_DEBUG(format, ...)
#endif
#define COUT_ERR(format, ...)\
	clogs_out(CLOGS_ERR, __func__, format, ##__VA_ARGS__)

#define TODO(format, ...)\
	clogs_out(CLOGS_WARN, __func__, "TODO: " format, ##__VA_ARGS__)
#define TTODO(format, ...)\
	clogs_put(CLOGS_WARN, __func__, "TODO: " format, ##__VA_ARGS__)

#include <stdio.h>

struct clogs;

enum clogs_level
{
	CLOGS_INFO = 0,
	CLOGS_WARN,
#ifdef DEBUG
	CLOGS_DEBUG,
#endif
	CLOGS_ERR
};

void clogs_init(const char* logfile);
void clogs_update();
void clogs_flush();
void clogs_close();
void clogs_put(enum clogs_level l, const char* func, const char* format, ...);
void clogs_out(enum clogs_level l, const char* func, const char* format, ...);
