// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -d -s TAO_PortableGroup_Simple
// ------------------------------
#ifndef TAO_PORTABLEGROUP_SIMPLE_EXPORT_H
#define TAO_PORTABLEGROUP_SIMPLE_EXPORT_H

#include "ace/config-all.h"

#if defined (TAO_AS_STATIC_LIBS) && !defined (TAO_PORTABLEGROUP_SIMPLE_HAS_DLL)
#  define TAO_PORTABLEGROUP_SIMPLE_HAS_DLL 0
#endif /* TAO_AS_STATIC_LIBS && TAO_PORTABLEGROUP_SIMPLE_HAS_DLL */

#if !defined (TAO_PORTABLEGROUP_SIMPLE_HAS_DLL)
#  define TAO_PORTABLEGROUP_SIMPLE_HAS_DLL 1
#endif /* ! TAO_PORTABLEGROUP_SIMPLE_HAS_DLL */

#if defined (TAO_PORTABLEGROUP_SIMPLE_HAS_DLL) && (TAO_PORTABLEGROUP_SIMPLE_HAS_DLL == 1)
#  if defined (TAO_PORTABLEGROUP_SIMPLE_BUILD_DLL)
#    define TAO_PortableGroup_Simple_Export ACE_Proper_Export_Flag
#    define TAO_PORTABLEGROUP_SIMPLE_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define TAO_PORTABLEGROUP_SIMPLE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* TAO_PORTABLEGROUP_SIMPLE_BUILD_DLL */
#    define TAO_PortableGroup_Simple_Export ACE_Proper_Import_Flag
#    define TAO_PORTABLEGROUP_SIMPLE_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define TAO_PORTABLEGROUP_SIMPLE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* TAO_PORTABLEGROUP_SIMPLE_BUILD_DLL */
#else /* TAO_PORTABLEGROUP_SIMPLE_HAS_DLL == 1 */
#  define TAO_PortableGroup_Simple_Export
#  define TAO_PORTABLEGROUP_SIMPLE_SINGLETON_DECLARATION(T)
#  define TAO_PORTABLEGROUP_SIMPLE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* TAO_PORTABLEGROUP_SIMPLE_HAS_DLL == 1 */

#endif /* TAO_PORTABLEGROUP_SIMPLE_EXPORT_H */

// End of auto generated file.
