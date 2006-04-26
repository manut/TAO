
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl Service_Config_ORB_DLL
// ------------------------------
#ifndef SERVICE_CONFIG_ORB_DLL_EXPORT_H
#define SERVICE_CONFIG_ORB_DLL_EXPORT_H

#include "ace/config-all.h"

#if !defined (SERVICE_CONFIG_ORB_DLL_HAS_DLL)
#  define SERVICE_CONFIG_ORB_DLL_HAS_DLL 1
#endif /* ! SERVICE_CONFIG_ORB_DLL_HAS_DLL */

#if defined (SERVICE_CONFIG_ORB_DLL_HAS_DLL) && (SERVICE_CONFIG_ORB_DLL_HAS_DLL == 1)
#  if defined (SERVICE_CONFIG_ORB_DLL_BUILD_DLL)
#    define Service_Config_ORB_DLL_Export ACE_Proper_Export_Flag
#    define SERVICE_CONFIG_ORB_DLL_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define SERVICE_CONFIG_ORB_DLL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* SERVICE_CONFIG_ORB_DLL_BUILD_DLL */
#    define Service_Config_ORB_DLL_Export ACE_Proper_Import_Flag
#    define SERVICE_CONFIG_ORB_DLL_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define SERVICE_CONFIG_ORB_DLL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* SERVICE_CONFIG_ORB_DLL_BUILD_DLL */
#else /* SERVICE_CONFIG_ORB_DLL_HAS_DLL == 1 */
#  define Service_Config_ORB_DLL_Export
#  define SERVICE_CONFIG_ORB_DLL_SINGLETON_DECLARATION(T)
#  define SERVICE_CONFIG_ORB_DLL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* SERVICE_CONFIG_ORB_DLL_HAS_DLL == 1 */

// Set SERVICE_CONFIG_ORB_DLL_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (SERVICE_CONFIG_ORB_DLL_NTRACE)
#  if (ACE_NTRACE == 1)
#    define SERVICE_CONFIG_ORB_DLL_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define SERVICE_CONFIG_ORB_DLL_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !SERVICE_CONFIG_ORB_DLL_NTRACE */

#if (SERVICE_CONFIG_ORB_DLL_NTRACE == 1)
#  define SERVICE_CONFIG_ORB_DLL_TRACE(X)
#else /* (SERVICE_CONFIG_ORB_DLL_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define SERVICE_CONFIG_ORB_DLL_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (SERVICE_CONFIG_ORB_DLL_NTRACE == 1) */

#endif /* SERVICE_CONFIG_ORB_DLL_EXPORT_H */

// End of auto generated file.
