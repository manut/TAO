//$Id$
//
// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    RT_Properties.h
//
// = DESCRIPTION
//     Defines a series of "real time" property that an Object
//     or a POA created on a RT-ORB can have.
//
// = AUTHOR
//     Angelo Corsaro <corsaro@cs.wustl.edu>
//
// ============================================================================

#ifndef RT_PROPERTIES_H_
#define RT_PROPERTIES_H_

#include "tao/corba.h"
#include <tao/RT_ORB.h>

#if (TAO_HAS_RT_CORBA == 1)


class RT_Properties
{
public:
  // -- Ctor/Dtor --
  RT_Properties (void);
  ~RT_Properties (void);

  static RT_Properties * read_from (const char *file_name,
                                    CORBA::Environment &ACE_TRY_ENV);

  // -- Accessor Methods --
  void priority (RTCORBA::Priority priority);
  RTCORBA::Priority priority (void);

  void priority_bands (const RTCORBA::PriorityBands& priority_bands);
  const RTCORBA::PriorityBands& priority_bands (void);

  void ior_source (const char *s);
  const char* ior_source (void);

private:

  RTCORBA::Priority priority_;
  RTCORBA::PriorityBands priority_bands_;
  char ior_source_[256];
};

#endif /* (TAO_HAS_RT_CORBA == 1) */

#endif /* RT_PROPERTIES_H_ */
