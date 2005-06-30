// $Id$

/**
 * @file new_RepositoryManager_Impl.h
 * @author Stoyan Paunov <spaunov@isis.vanderbilt.edu>
 *
 * This class is the implementation class for the new
 * RepositoryManager
 */

#ifndef NEW_REPOSITORYMANAGERI_H_
#define NEW_REPOSITORYMANAGERI_H_

#include "new_RepositoryManagerS.h"
#include "DeploymentS.h"					//added for the deployment stuff

#include "ace/Hash_Map_Manager.h"			//for the ACE_Hash_Map_Manager
#include "ace/Null_Mutex.h"					//for ACE_Null_Mutex
#include "ace/RW_Mutex.h"					//for ACE_RW_Mutex
#include "ace/OS_NS_string.h"				//for ACE_CString
#include "ace/SString.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace
{
  ///DIRECTORY WHERE THE PACKAGES WILL BE STORED LOCALLY
  const static char* RM_STORAGE_PATH = "./RepositoryDir";
}

class  CIAO_new_RepositoryManagerDaemon_i : public virtual POA_CIAO::new_RepositoryManagerDaemon, public virtual PortableServer::RefCountServantBase
{
public:

  /// Constructor 
  CIAO_new_RepositoryManagerDaemon_i (CORBA::ORB_ptr the_orb);
  
  /// Destructor 
  virtual ~CIAO_new_RepositoryManagerDaemon_i (void);
  

  /// shutdown method to shut down the orb gracefully
  virtual
  void shutdown ()
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  /// This method allow you to install a package into the RM
  virtual
  void installPackage (const char * installationName,
                       const ::Deployment::Package & the_package,
                       ::CORBA::Boolean replace)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     ::Deployment::NameExists,
                     ::Deployment::PackageError));

  /// This method parse the depoyment plan in a package and return the 
  /// corresponding structure. You need to provide the name of the 
  /// package whose deployment plan you want to get . If no plan is
  /// found in the package, an exception is thrown
  virtual
  ::Deployment::DeploymentPlan * retrievePlan (const char * packageName)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     ::Deployment::NoPlan));
  
  /// find a package and return it if installed in the RM
  /// else throw an exception
  virtual
  ::Deployment::Package * findPackageByName (const char * name)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     ::Deployment::NoSuchName));
  
  /// find an implementation (.dll, .so) by its name and return it if installed in the RM
  /// else throw an exception. You need to specify the package in which the RM
  /// is to look for the implementation
  virtual
  ::Deployment::Implementation * findImplementationByName (const char * implementation_name,
                                                           const char * package_name)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     ::Deployment::NoSuchName));
  
  /// not implemented
  virtual
  ::Deployment::Package * findPackageByUUID (const char * UUID)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     ::Deployment::NoSuchName));
  
  ///not implemented
  virtual
  ::Deployment::Implementation * findImplementationByUUID (const char * UUID)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     ::Deployment::NoSuchName));
  
  /// get the names of all packages currently installed in the RM
  virtual
  ::CORBA::StringSeq * getAllPackageNames ()
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  /// Find out if the package was installed in the repository,
  /// delete it if found or throw and exception otherwise
  virtual
  void deletePackage (const char * installationName)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     ::Deployment::NoSuchName));


protected:

  ///function that writes out a file to a specified location on the hand disk
  ///returns 1 on success
  ///		-1 on error

  int write_to_disk (const char* full_path, 
                     const CORBA::Octet* buffer, 
                     size_t length);


  ///function that writes out a file to a specified location on the hand disk
  ///returns 1 on success
  ///		 0 on already exists and replace == false
  ///		-1 on error

  int write_to_disk (const char* full_path, 
                     ACE_Message_Block& mb,
                     bool replace = true);


  ///function to read the contents of a file from disk into a CORBA::OctetSeq
  ///returns a pointer to a CORBA::Octet buffer and updated the lenght on success 
  ///		 0 on failure

  CORBA::Octet* read_from_disk (const char* full_path, size_t &lenght);

private:
  /// Cached information about the installed packages
  /// and the Implementation Artifacts within them
  /// Key:	Package name of CString type or
  /// Value:	The location of the local copy of the package

  ///Based on the synchronization needed we can parametrize this with either 
  ///ACE_Null_Mutex or ACE_RW_Mutex

  typedef ACE_Hash_Map_Manager_Ex<ACE_CString,
                                  ACE_CString,
                                  ACE_Hash<ACE_CString>,
                                  ACE_Equal_To<ACE_CString>,
                                  ACE_RW_Mutex> RepositoryDatabase;


  typedef RepositoryDatabase::iterator RepositoryDatabase_Iterator;

  RepositoryDatabase packages_;
  CORBA::ORB_var the_orb_;

};


#endif /* NEW_REPOSITORYMANAGERI_H_  */

