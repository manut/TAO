// $Id$

#include "testC.h"
#if (TAO_HAS_SMART_PROXIES == 1)
class Smart_Test_Factory : public virtual TAO_Test_Default_Proxy_Factory
{
public:

  Smart_Test_Factory (void);
  
  virtual Test_ptr create_proxy (Test_ptr proxy,
                                 CORBA::Environment &env = 
                                 TAO_default_environment ());
  // This method will create the smart_proxy.   
};

class Smart_Test_Proxy : public virtual TAO_Test_Smart_Proxy_Base 
{
public:
  Smart_Test_Proxy (Test_ptr proxy);

  virtual CORBA::Short box_prices(CORBA::Environment &ACE_TRY_ENV = 
                               TAO_default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException)); 
  // "Smartify" the method call!

 private:
  CORBA::Short price_;
};
#endif /*(TAO_HAS_SMART_PROXIES == 1)*/
