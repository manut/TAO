#include "LB_Pull_Handler.h"
#include "LB_LoadManager.h"

#include "tao/debug.h"


ACE_RCSID (LoadBalancing,
           LB_Pull_Handler,
           "$Id$")


TAO_LB_Pull_Handler::TAO_LB_Pull_Handler (void)
  : monitor_map_ (0),
    load_manager_ (0)
{
}

void
TAO_LB_Pull_Handler::initialize (TAO_LB_MonitorMap * monitor_map,
                                 TAO_LB_LoadManager * load_manager)
{
  this->monitor_map_ = monitor_map;
  this->load_manager_ = load_manager;
}

int
TAO_LB_Pull_Handler::handle_timeout (
  const ACE_Time_Value & /* current_time */,
  const void * /* arg */)
{
  // @todo Fix the race condtions in this method.

  TAO_LB_MonitorMap::iterator begin = this->monitor_map_->begin ();
  TAO_LB_MonitorMap::iterator end   = this->monitor_map_->end ();

  if (begin == end)
    return 0;       // No work to be done.

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Iterate over all registered load monitors.
      //
      // @todo This could be potentially very slow.  Improve concurrent
      //       operation at some point in the near future.
      for (TAO_LB_MonitorMap::iterator i = begin; i != end; ++i)
        {
          const PortableGroup::Location & location = (*i).ext_id_;
          CosLoadBalancing::LoadMonitor_var & monitor = (*i).int_id_;

          // The load monitor reference should never be nil since the
          // LoadManager prevents nil load monitor references from
          // being registered.
          CosLoadBalancing::LoadList_var load_list =
            monitor->loads (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;

          this->load_manager_->push_loads (location,
                                           load_list.in ()
                                           ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

//               ACE_DEBUG ((LM_DEBUG,
//                           "LOCATION = %s\tLOAD = %f\n",
//                           (*i).ext_id_[0].id.in (),
//                           location->load_list[0].value));
        }
    }
  ACE_CATCHANY
    {
      // Catch the exception and ignore it.
      
      if (TAO_debug_level > 0)
        ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                             "(%P|%t) PullHandler::handle_timeout()\n");
    }
  ACE_ENDTRY;

  return 0;
}
