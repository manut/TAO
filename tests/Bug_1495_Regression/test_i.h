// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:887

#ifndef TESTI_H_
#define TESTI_H_

#include "testS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class  Bug1495_i : public virtual POA_Bug1495_Regression::Bug1495
{
public:
    //Constructor
    Bug1495_i (void);

    Bug1495_i (CORBA::ORB_ptr orb);


    //Destructor
    virtual ~Bug1495_i (void);

    virtual
    void get_thread_id (CORBA::Long_out thread_id ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));

    virtual
    void shutdown (void)
        ACE_THROW_SPEC ((CORBA::SystemException));
private:
    CORBA::ORB_ptr orb_;

};


#endif /* TESTI_H_  */
