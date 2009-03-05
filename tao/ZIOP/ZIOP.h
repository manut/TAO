// -*- C++ -*-

//=============================================================================
/**
 *  @file ZIOP.h
 *
 *  $Id$
 *
 *  Dynamic loader object for the ZIOP library
 *
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_ZIOP_H
#define TAO_ZIOP_H
#include /**/ "ace/pre.h"

#include "tao/ZIOP/ziop_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PI/PI.h"
#include "tao/ZIOP_Adapter.h"
#include "tao/Compression/Compression.h"
#include "tao/Policy_Validator.h"
#include "ace/Service_Config.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class TAO_ZIOP_Loader
 *
 * @brief Class that loads the BiDir library.
 */

class TAO_ZIOP_Export TAO_ZIOP_Loader : public TAO_ZIOP_Adapter
{
public:

  /// Constructor
  TAO_ZIOP_Loader (void);

  /// Destructor
  virtual ~TAO_ZIOP_Loader (void);

  virtual bool decompress (ACE_Data_Block **db, TAO_Queued_Data& qd, TAO_ORB_Core& orb_core);

  // Compress the @a stream. Starting point of the compression is rd_ptr()
  virtual bool marshal_data (TAO_OutputCDR& cdr, TAO_Stub& stub);
  virtual bool marshal_data (TAO_OutputCDR& cdr, TAO_ORB_Core& orb_core);

  /// Initialize the BiDIR loader hooks.
  virtual int init (int argc, ACE_TCHAR* []);

  virtual void load_policy_validators (TAO_Policy_Validator &validator);

  /// Used to force the initialization of the ORB code.
  static int Initializer (void);

private:

  /// Flag to indicate whether the ZIOP library has been
  /// activated.
  static bool is_activated_;

  /// Get the compression low value, returns 0 when it is not set
  CORBA::ULong compression_policy_value (CORBA::Policy_ptr policy) const;

  bool get_compressor_details (
                        ::Compression::CompressorIdLevelList *list,
                        Compression::CompressorId &compressor_id,
                        Compression::CompressionLevel &compression_level);

  bool get_compression_details(CORBA::Policy_ptr compression_enabling_policy,
                        CORBA::Policy_ptr compression_level_list_policy,
                        Compression::CompressorId &compressor_id,
                        Compression::CompressionLevel &compression_level);

  void complete_compression (Compression::Compressor_ptr compressor,
                             TAO_OutputCDR &cdr,
                             ACE_Message_Block& mb,
                             char *initial_rd_ptr,
                             CORBA::ULong low_value,
                             CORBA::Long min_ratio,
                             CORBA::ULong original_data_length,
                             Compression::CompressorId compressor_id);

  bool compress_data (TAO_OutputCDR &cdr,
                      CORBA::Object_ptr compression_manager,
                      CORBA::ULong low_value,
                      CORBA::Long min_ratio,
                      ::Compression::CompressorId compressor_id,
                      ::Compression::CompressionLevel compression_level);

  bool compress (Compression::Compressor_ptr compressor,
                 const ::Compression::Buffer &source,
                 ::Compression::Buffer &target);

  bool decompress (Compression::Compressor_ptr compressor,
                   const ::Compression::Buffer &source,
                   ::Compression::Buffer &target);
  
  CORBA::ULong get_ratio (CORBA::OctetSeq& uncompressed, 
                          CORBA::OctetSeq& compressed);

  bool check_min_ratio (const CORBA::ULong& this_ratio,
                        ::Compression::CompressionRatio overall_ratio,
                        CORBA::Long min_ratio) const;
};

static int
TAO_Requires_ZIOP_Initializer = TAO_ZIOP_Loader::Initializer ();


ACE_STATIC_SVC_DECLARE (TAO_ZIOP_Loader)
ACE_FACTORY_DECLARE (TAO_ZIOP, TAO_ZIOP_Loader)

TAO_END_VERSIONED_NAMESPACE_DECL

#define TAO_ZIOP_SAFE_INCLUDE
#include "tao/ZIOP/ZIOPC.h"
#undef TAO_ZIOP_SAFE_INCLUDE

#include /**/ "ace/post.h"
#endif /* TAO_ZIOP_H */


