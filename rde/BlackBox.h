#ifndef DEBUG_BLACKBOX_H
#define DEBUG_BLACKBOX_H

// Enabled by default.
#ifndef RDE_BLACKBOX_ENABLED
#	define RDE_BLACKBOX_ENABLED	1
#endif

#define RDE_BLACKBOX_STANDALONE	1

namespace rde
{
namespace BlackBox
{
#if RDE_BLACKBOX_ENABLED
void AddMessage(const char* message);
void AddMessagef(const char* fmt, ...);
#else
inline void AddMessage(const char*) {}
inline void AddMessagef(const char *, ...) {}
#endif
long GetNumMessages();
const char* GetMessage(long index, int& threadId);
}
}

#endif
