/* precompiled header! */

#ifndef _INCLUDE_SIGSEGV_COMMON_H_
#define _INCLUDE_SIGSEGV_COMMON_H_


#if defined __cplusplus


//#if !defined __GNUC__
//#define __attribute__(...)
//#endif


class IVEngineServer;
class IServerGameDLL;
class ICvar;
class ISpatialPartition;
class IEngineTrace;
class IStaticPropMgrServer;
class IGameEventManager2;
class IEngineSound;
class IVDebugOverlay;
class ISoundEmitterSystemBase;
class IMaterialSystem;
class CGlobalVars;
class CBaseEntityList;
class IBaseClientDLL;
namespace SourcePawn {
	class ISourcePawnEngine;
}
namespace SourceMod {
	class IExtensionManager;
}

extern IVEngineServer *engine;
extern IServerGameDLL *gamedll;
extern ICvar *icvar;
extern ISpatialPartition *partition;
extern IEngineTrace *enginetrace;
extern IStaticPropMgrServer *staticpropmgr;
extern IGameEventManager2 *gameeventmanager;
extern IEngineSound *enginesound;
extern IVDebugOverlay *debugoverlay;

extern ISoundEmitterSystemBase *soundemitterbase;

extern IMaterialSystem *g_pMaterialSystem;

extern CGlobalVars *gpGlobals;
extern CBaseEntityList *g_pEntityList;

extern IBaseClientDLL *clientdll;

extern SourcePawn::ISourcePawnEngine *g_pSourcePawn;
extern SourceMod::IExtensionManager *smexts;


/* C++ standard library */
#include <algorithm>
#include <functional>
#include <memory>
#include <mutex>
#include <regex>
#include <string>
#include <thread>
#include <type_traits>
#include <typeinfo>
#include <utility>


/* STL */
#include <list>
#include <map>
#include <set>
#include <vector>


/* AMTL */
#include <amtl/am-string.h>


/* Boost */
//#include <boost/thread.hpp>


/* Posix specific */
#if defined _LINUX || defined _OSX

#include <unistd.h>
#include <sys/mman.h>
#include <libunwind.h>
#define HAVE_DECL_BASENAME 1
#include <libiberty/demangle.h>
#include <libelf.h>

#endif


/* Windows specific */
#if defined _WINDOWS

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#pragma warning(disable:4091)
#include <Dbghelp.h>
#pragma warning(default:4091)

/* namespace clash between Windows CreateEvent macro and IGameEventManager2::CreateEvent */
#if defined CreateEvent
#undef CreateEvent
#endif

#endif


/* Capstone */
#include <capstone.h>


/* Source SDK */
#include <string_t.h>
#include "sdk2013/annotations.h"
#include "sdk2013/basetypes.h"
#include <tier0/dbg.h>
#include <tier1/convar.h>
#include "sdk2013/fmtstr.h"
#include <tier1/KeyValues.h>
#include <tier1/utlvector.h>
#include <shareddefs.h>
#include <ehandle.h>
#include <datamap.h>
#include <predictioncopy.h>
#include <takedamageinfo.h>
#include <iserverunknown.h>
#include <iserverentity.h>
#include <edict.h>
#include <IEngineTrace.h>
#include <IStaticPropMgr.h>
#include <ivdebugoverlay.h>
#include "sdk2013/debugoverlay_shared.h"
#include "sdk2013/util_shared.h"
#include <ai_activity.h>
#include <usercmd.h>
#include <npcevent.h>
#include <dt_send.h>
#include <eiface.h>
#include <ispatialpartition.h>
#include <random.h>
#include <ai_activity.h>
#include <igameevents.h>
#include <inetmessage.h>
#include <inetchannel.h>
#include <irecipientfilter.h>
//#include <usermessages.h>
#include <interface.h>
#include <cdll_int.h>
#include <iclientnetworkable.h>
#include <tier1/utldict.h>
#include <mp_shareddefs.h>
#include <materialsystem/imaterialsystem.h>
#include <materialsystem/imaterial.h>
#include <particle_parse.h>
#include <SoundEmitterSystem/isoundemittersystembase.h>
#include <IEngineSound.h>
#include <igamesystem.h>

#define DECLARE_PREDICTABLE()
#include <collisionproperty.h>


/* MetaMod */

/* SourceMod */
#include <compat_wrappers.h>
#include <ISDKTools.h>
#include "sm/MemoryUtils.h"

//extern SourceMod::ISDKTools *g_pSDKTools;


/* this extension */
#include <smsdk_ext.h>


#define bf_write old_bf_write
#define bf_read old_bf_read


#endif


#endif
