// $Id$
// Multi_Priority_Mapping.h,v 1.0

// ============================================================================
//
// = LIBRARY
//   TAO
//
// = FILENAME
//   Multi_Priority_Mapping.h
//
// = DESCRIPTION
//   Declares a priority mapping to support cross platform communication.
//
// = AUTHOR
//   Brian Mendel (brian.r.mendel@boeing.com)
//
// ============================================================================

#ifndef TAO_MULTI_PRIORITY_MAPPING_H
#define TAO_MULTI_PRIORITY_MAPPING_H

#include "tao/orbconf.h"

#include "tao/RTCORBA/Priority_Mapping.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0

/**
 * @class TAO_Multi_Priority_Mapping
 *
 * @brief An implementation of the Priority_Mapping interface for communication
 * between different platforms
 *
 * This implementation uses a custom mapping between the range of
 * priorities for a given scheduling class (ACE_SCHED_OTHER,
 * ACE_SCHED_FIFO, ACE_SCHED_RR) and the valid range of CORBA
 * priorities (0...32767)
 */
class TAO_RTCORBA_Export TAO_Multi_Priority_Mapping : public TAO_Priority_Mapping
{
public:
  /// Default constructor
  /**
   * @param base_native_priority The native priority to use for the highest
   * priority endpoint.
   * @param base_corba_priority The corba priority to use for the highest
   * priority endpoint
   * @param priority_spacing The priority increment to use between endpoints
   * @param priorities_contiguous Some platforms do use contiguous priorities
   * @param policy The scheduling policy to use.
   */
  TAO_Multi_Priority_Mapping (int base_native_priority,
                              int base_corba_priority,
                              int priority_spacing = 1,
                              int priorities_contiguous = 1,
                              int policy = ACE_SCHED_FIFO);

  /// The destructor
  virtual ~TAO_Multi_Priority_Mapping (void);

  virtual CORBA::Boolean
      to_native (RTCORBA::Priority corba_priority,
                 RTCORBA::NativePriority &native_priority);
  virtual CORBA::Boolean
      to_CORBA (RTCORBA::NativePriority native_priority,
                RTCORBA::Priority &corba_priority);

private:

  int base_native_priority_;
  int base_corba_priority_;
  // The base settings

  const int priority_spacing_;
  const int priorities_contiguous_;

  /// The scheduling policy
  int policy_;

  int min_;
  int max_;
  // The range
};

#if defined (__ACE_INLINE__)
# include "tao/RTCORBA/Multi_Priority_Mapping.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_HAS_CORBA_MESSAGING && TAO_HAS_CORBA_MESSAGING != 0 */

#endif /* TAO_MULTI_PRIORITY_MAPPING_H */
