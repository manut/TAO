
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl CIAO_CLIENT
// ------------------------------
#ifndef CIAO_CLIENT_EXPORT_H
#define CIAO_CLIENT_EXPORT_H

#include "ace/config-all.h"

#if !defined (CIAO_CLIENT_HAS_DLL)
#  define CIAO_CLIENT_HAS_DLL 1
#endif /* ! CIAO_CLIENT_HAS_DLL */

#if defined (CIAO_CLIENT_HAS_DLL) && (CIAO_CLIENT_HAS_DLL == 1)
#  if defined (CIAO_CLIENT_BUILD_DLL)
#    define CIAO_CLIENT_Export ACE_Proper_Export_Flag
#    define CIAO_CLIENT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CIAO_CLIENT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CIAO_CLIENT_BUILD_DLL */
#    define CIAO_CLIENT_Export ACE_Proper_Import_Flag
#    define CIAO_CLIENT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CIAO_CLIENT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CIAO_CLIENT_BUILD_DLL */
#else /* CIAO_CLIENT_HAS_DLL == 1 */
#  define CIAO_CLIENT_Export
#  define CIAO_CLIENT_SINGLETON_DECLARATION(T)
#  define CIAO_CLIENT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CIAO_CLIENT_HAS_DLL == 1 */

// Set CIAO_CLIENT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CIAO_CLIENT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CIAO_CLIENT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CIAO_CLIENT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CIAO_CLIENT_NTRACE */

#if (CIAO_CLIENT_NTRACE == 1)
#  define CIAO_CLIENT_TRACE(X)
#else /* (CIAO_CLIENT_NTRACE == 1) */
#  define CIAO_CLIENT_TRACE(X) ACE_TRACE_IMPL(X)
#endif /* (CIAO_CLIENT_NTRACE == 1) */

#endif /* CIAO_CLIENT_EXPORT_H */

// End of auto generated file.
