// auto generated by LoggerBuilder
#pragma once

#include <string.h>
#include <stdio.h>

#include <Core/Macro/ProgramMacro.h>

namespace Log
{

enum class Level : T_UINT32
{
  Fatal,
  Error,
  Warn,
  Info,
  Debug,
  Trace,
  Assert
};

static const char* LEVEL_NAMES[] =
{
  "Fatal",
  "Error",
  "Warn",
  "Info",
  "Debug",
  "Trace",
  "Assert"
};

void Out(Level level, const char* message);

template <typename ... Args>
static GG_INLINE void Out(Level level, const char* message, const char* format, Args const & ... args)
{
  char buf[1024];
  sprintf(buf, format, message, args ...);
  Out(level, buf);
}

static GG_INLINE void Fatal(const char* message)
{
  Out(Level::Fatal, message);
  __debugbreak();
}
template <typename ... Args>
static GG_INLINE void Fatal(const char* message, const char* format, Args const & ... args)
{
  Out(Level::Fatal, message);
  __debugbreak();
}

static GG_INLINE void Error(const char* message)
{
  Out(Level::Error, message);
  __debugbreak();
}
template <typename ... Args>
static GG_INLINE void Error(const char* message, const char* format, Args const & ... args)
{
  Out(Level::Error, message);
  __debugbreak();
}

static GG_INLINE void Warn(const char* message)
{
  Out(Level::Warn, message);
}
template <typename ... Args>
static GG_INLINE void Warn(const char* message, const char* format, Args const & ... args)
{
  Out(Level::Warn, message);
}

static GG_INLINE void Info(const char* message)
{
  Out(Level::Info, message);
}
template <typename ... Args>
static GG_INLINE void Info(const char* message, const char* format, Args const & ... args)
{
  Out(Level::Info, message);
}

static GG_INLINE void Debug(const char* message)
{
#ifdef _DEBUG
  Out(Level::Debug, message);
#endif
}
template <typename ... Args>
static GG_INLINE void Debug(const char* message, const char* format, Args const & ... args)
{
#ifdef _DEBUG
  Out(Level::Debug, message);
#endif
}

static GG_INLINE void Trace(const char* message)
{
#ifdef _DEBUG
  Out(Level::Trace, message);
#endif
}
template <typename ... Args>
static GG_INLINE void Trace(const char* message, const char* format, Args const & ... args)
{
#ifdef _DEBUG
  Out(Level::Trace, message);
#endif
}

static GG_INLINE void Assert(const char* message)
{
#ifdef _DEBUG
  Out(Level::Assert, message);
  __debugbreak();
#endif
}
template <typename ... Args>
static GG_INLINE void Assert(const char* message, const char* format, Args const & ... args)
{
#ifdef _DEBUG
  Out(Level::Assert, message);
  __debugbreak();
#endif
}

} // namespace Log
