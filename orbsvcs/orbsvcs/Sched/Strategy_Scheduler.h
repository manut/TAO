/* -*- C++ -*- */
// $Id$
//
// ============================================================================
//
// = LIBRARY
//    sched
//
// = FILENAME
//    Strategy_Scheduler.h
//
// = CREATION DATE
//    22 December 1997
//
// = AUTHOR
//    Chris Gill
//
// ============================================================================

#if ! defined (STRATEGY_SCHEDULER_H)
#define STRATEGY_SCHEDULER_H

#include "DynSched.h"

// forward declaration of the abstract base class for scheduler strategies
class ACE_Scheduler_Strategy;

/////////////////////////////////
// Strategized scheduler class //
/////////////////////////////////

class TAO_ORBSVCS_Export ACE_Strategy_Scheduler : public ACE_DynScheduler
  // = TITLE
  //    ACE_Strategy_Scheduler
  //
  // = DESCRIPTION
  //    Strategized scheduler implementation.  Provides an implementation
  //    of all strategy specific scheduling mechanisms, which relies on the
  //    methods of the associated strategy class.
{
// public interface
public:

  ACE_Strategy_Scheduler (ACE_Scheduler_Strategy &strategy);
    // = strategized ctor

  virtual ~ACE_Strategy_Scheduler ();
    // = virtual dtor

  status_t assign_priorities (Dispatch_Entry **dispatches, u_int count);
    // = assigns priorities to the sorted dispatch schedule,
    //   according to the strategy's priority comparison operator.

  status_t assign_subpriorities (Dispatch_Entry **dispatches, u_int count);
    // = assigns dynamic and static sub-priorities to the sorted dispatch
    //   schedule, according to the strategy's subpriority comparisons.

  virtual Preemption_Priority minimum_critical_priority ();
  // = determine the minimum critical priority number

private:

  virtual status_t schedule_timeline_entry (Dispatch_Entry &dispatch_entry,
                                            ACE_Unbounded_Queue <Dispatch_Entry *>
                                              &reschedule_queue);
  // = schedules a dispatch entry into the timeline being created

  virtual status_t sort_dispatches (Dispatch_Entry **dispatches, u_int count);
    // = sets up the schedule in the order generated by the strategy

  ACE_Scheduler_Strategy &strategy_;
    // = strategy for comparison, sorting of dispatch entries

  ACE_UNIMPLEMENTED_FUNC (ACE_Strategy_Scheduler (const ACE_Strategy_Scheduler &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Strategy_Scheduler &operator= (
    const ACE_Strategy_Scheduler &))
};



////////////////////////////////////////
// Factory for strategized schedulers //
////////////////////////////////////////

template <class STRATEGY>
class ACE_Strategy_Scheduler_Factory
  // = TITLE
  //    ACE_Strategy_Scheduler_Factory
  //
  // = DESCRIPTION
  //    Provides a type parameterized factory method that constructs
  //    and returns a scheduler that uses the given scheduling strategy
{
public:

        static ACE_Strategy_Scheduler * create (ACE_DynScheduler::Preemption_Priority minimum_critical_priority);
    // construct and return a scheduler strategized with
    // an instance of the the parameterized strategy type
};


//////////////////////////
// Scheduler Strategies //
//////////////////////////

class TAO_ORBSVCS_Export ACE_Scheduler_Strategy
  // = TITLE
  //    ACE_Scheduler_Strategy
  //
  // = DESCRIPTION
  //    Abstract Base Class for scheduling strategies: each derived class
  //    must define an ordering strategy for dispatch entries based on a specific
  //    scheduling algorithm.
{
public:

        ACE_Scheduler_Strategy (ACE_DynScheduler::Preemption_Priority minimum_critical_priority = 0);
    // ctor

  virtual int priority_comp (const Dispatch_Entry &first_entry,
                             const Dispatch_Entry &second_entry) = 0;
    // = comparison of two dispatch entries in strategy specific high to low priority
    //   ordering: returns -1 if the first Dispatch_Entry is greater in the order,
    //   0 if they are equivalent, or 1 if the second Dispatch_Entry is greater in
    //   the order

  virtual void sort (Dispatch_Entry **dispatch_entries,
                     u_int count) = 0;
    // = sort the dispatch entry link pointer array according to
    //   the specific sort order defined by the strategy

  virtual ACE_DynScheduler::Preemption_Priority minimum_critical_priority ();
    // = determine the minimum critical priority number

  virtual int dynamic_subpriority_comp (const Dispatch_Entry &first_entry,
                                        const Dispatch_Entry &second_entry) = 0;
    // = comparison of two dispatch entries in strategy specific high to low
    //   dynamic subpriority ordering: returns -1 if the first Dispatch_Entry
    //   is greater in the order, 0 if they are equivalent, or 1 if the
    //   second Dispatch_Entry is greater in the order

  virtual long dynamic_subpriority (Dispatch_Entry &entry,
                                    u_long current_time) = 0;
    // = returns a dynamic subpriority value
    //   for the given timeline entry at the current time

  virtual int static_subpriority_comp (const Dispatch_Entry &first_entry,
                                       const Dispatch_Entry &second_entry);
    // = provide a lowest level ordering based first on importance (descending),
    //   and then on the dependency topological sort finishing time (ascending).


protected:

  int sort_comp (const Dispatch_Entry &first_entry,
                 const Dispatch_Entry &second_entry);
    // = comparison of two dispatch entries using the specific priority, dynamic
    //   subpriority, and static subpriority method definitions provided by
    //   the derived strategy class to produce the strategy specific sort
    //   ordering: returns -1 if the first Dispatch_Entry is greater in the order,
    //   0 if they are equivalent, or 1 if the second Dispatch_Entry is greater in
    //   the order.  This is an example of the Template Method pattern (and also
    //   of Pree's Unification Metapattern), in which derived classes provide
    //   definitions of the methods on which the sort_comp Template Method relies.

  ACE_DynScheduler::Preemption_Priority minimum_critical_priority_;
  // = the minimum critical priority number for the strategy
};



class TAO_ORBSVCS_Export ACE_MUF_Scheduler_Strategy : public ACE_Scheduler_Strategy
  // = TITLE
  //    ACE_MUF_Scheduler_Strategy
  //
  // = DESCRIPTION
  //    Defines "schedule" method using Maximum Urgency First
  //    scheduling algorithm.
{
public:

  ACE_MUF_Scheduler_Strategy (ACE_DynScheduler::Preemption_Priority minimum_critical_priority = 0);
    // ctor

  virtual ~ACE_MUF_Scheduler_Strategy ();
  // = virtual dtor


  static ACE_MUF_Scheduler_Strategy *instance ();
    // returns an instance of the strategy

  virtual int priority_comp (const Dispatch_Entry &first_entry,
                             const Dispatch_Entry &second_entry);
    // = comparison of two dispatch entries by maximum criticality: returns -1 if the
    //   first Dispatch_Entry is greater in the order, 0 if they're equivalent, or
    //   1 if the second Dispatch_Entry is greater in the order.

  virtual void sort (Dispatch_Entry **dispatch_entries,
                     u_int count);
    // = sort the dispatch entry link pointer array in descending urgency order

  virtual ACE_DynScheduler::Preemption_Priority minimum_critical_priority ();
    // = determine the minimum critical priority number

protected:

  virtual long dynamic_subpriority (Dispatch_Entry &entry,
                                    u_long current_time);
    // = returns a dynamic subpriority value at the current time for
    //   the given timeline entry: if the operation has
    //   non-negative laxity, then the value is positive, and a lower
    //   laxity gives a higher dynamic subpriority; if the operation
    //   has negative laxity, the value is the (negative) laxity value

  virtual int dynamic_subpriority_comp (
    const Dispatch_Entry &first_entry,
    const Dispatch_Entry &second_entry);
    // = orders of two dispatch entries by ascending laxity: returns -1 if the
    //   first Dispatch_Entry is greater in the order, 0 if they're equivalent,
    //   1 if the second Dispatch_Entry is greater in the order.

private:

  static int sort_function (void *arg1, void *arg2);
    // comparison function to pass to qsort: calls instance ()->sort_comp ();

  static ACE_MUF_Scheduler_Strategy *instance_;
    // instance of the strategy
};


class TAO_ORBSVCS_Export ACE_RMS_Scheduler_Strategy : public ACE_Scheduler_Strategy
  // = TITLE
  //    ACE_RMS_Scheduler_Strategy
  //
  // = DESCRIPTION
  //    Defines "schedule" method using Rate Monotonic
  //    Scheduling algorithm.
{
public:

  ACE_RMS_Scheduler_Strategy (ACE_DynScheduler::Preemption_Priority minimum_critical_priority = 0);
    // ctor

  virtual ~ACE_RMS_Scheduler_Strategy ();
    // = virtual dtor

  static ACE_RMS_Scheduler_Strategy *instance ();
    // returns an instance of the strategy

  virtual int priority_comp (const Dispatch_Entry &first_entry,
                             const Dispatch_Entry &second_entry);
    // = comparison of two dispatch entries by minimum period: returns -1 if the
    //   first Dispatch_Entry is greater in the order, 0 if they're equivalent,
    //   or 1 if the second Dispatch_Entry is greater in the order.

  virtual void sort (Dispatch_Entry **dispatch_entries,
                     u_int count);
    // = sort the dispatch entry link pointer array in descending RMS (rate) order

  virtual ACE_DynScheduler::Preemption_Priority minimum_critical_priority ();
    // = determine the minimum critical priority number

protected:

  virtual long dynamic_subpriority (Dispatch_Entry &entry,
                                    u_long current_time);
    // = just returns 0: all operations have
    //   the same dynamic subpriority value

  virtual int dynamic_subpriority_comp
    (const Dispatch_Entry &first_entry,
     const Dispatch_Entry &second_entry);
    // = all dispatches in a given priority level have the same dynamic
    //   subpriority under RMS: just returns 0

private:

  static int sort_function (void *arg1, void *arg2);
    // comparison function to pass to qsort: calls instance ()->sort_comp ();

  static ACE_RMS_Scheduler_Strategy *instance_;
    // instance of the strategy

};





class TAO_ORBSVCS_Export ACE_MLF_Scheduler_Strategy : public ACE_Scheduler_Strategy
  // = TITLE
  //    ACE_MLF_Scheduler_Strategy
  //
  // = DESCRIPTION
  //    Defines "schedule" method using Minimum Laxity First
  //    scheduling algorithm.
{
public:

  ACE_MLF_Scheduler_Strategy (ACE_DynScheduler::Preemption_Priority minimum_critical_priority = 0);
    // = ctor

  virtual ~ACE_MLF_Scheduler_Strategy ();
    // = virtual dtor

  static ACE_MLF_Scheduler_Strategy *instance ();
    // returns an instance of the strategy

  virtual int priority_comp (const Dispatch_Entry &first_entry,
                             const Dispatch_Entry &second_entry);
    // = just returns 0, as all dispatch entries are of equivalent priority under MLF.

  virtual void sort (Dispatch_Entry **dispatch_entries,
                     u_int count);
    // = sort the dispatch entry link pointer array in ascending laxity order

protected:

  virtual long dynamic_subpriority (Dispatch_Entry &entry,
                                    u_long current_time);
    // = returns a dynamic subpriority value at the current time for
    //   the given timeline entry: if the operation has
    //   non-negative laxity, then the value is positive, and a lower
    //   laxity gives a higher dynamic subpriority; if the operation
    //   has negative laxity, the value is the (negative) laxity value

  virtual int dynamic_subpriority_comp
    (const Dispatch_Entry &first_entry,
     const Dispatch_Entry &second_entry);
    // = orders two dispatch entries by ascending laxity: returns -1 if the
    //   first Dispatch_Entry is greater in the order, 0 if they're equivalent,
    //   or 1 if the second Dispatch_Entry is greater in the order.

private:

  static int sort_function (void *arg1, void *arg2);
    // comparison function to pass to qsort: calls instance ()->sort_comp ();

  static ACE_MLF_Scheduler_Strategy *instance_;
    // instance of the strategy

};


class TAO_ORBSVCS_Export ACE_EDF_Scheduler_Strategy : public ACE_Scheduler_Strategy
  // = TITLE
  //    ACE_EDF_Scheduler_Strategy
  //
  // = DESCRIPTION
  //    Defines "schedule" method using Earliest Deadline First
  //    scheduling algorithm.
{
public:

  ACE_EDF_Scheduler_Strategy (ACE_DynScheduler::Preemption_Priority minimum_critical_priority = 0);
    // = default ctor

  virtual ~ACE_EDF_Scheduler_Strategy ();
    // = virtual dtor

  static ACE_EDF_Scheduler_Strategy *instance ();
    // returns an instance of the strategy

  virtual int priority_comp (const Dispatch_Entry &first_entry,
                             const Dispatch_Entry &second_entry);
    // = returns 0, as all dispatch entries are of equivalent priority under EDF.

  virtual void sort (Dispatch_Entry **dispatch_entries,
                     u_int count);
    // = sort the dispatch entry link pointer array in ascending deadline (period) order

protected:

  virtual long dynamic_subpriority (Dispatch_Entry &entry,
                                    u_long current_time);
    // = returns a dynamic subpriority value at the current time for the
    //   given timeline entry: if the operation has non-negative
    //   time to deadline, then value is positive, and a shorter time to
    //   deadline gives a higher dynamic subpriority; if the operation has a
    //   negative time to deadline, the value is (negative) time to deadline


  virtual int dynamic_subpriority_comp
    (const Dispatch_Entry &first_entry,
     const Dispatch_Entry &second_entry);
    // = orders two dispatch entries by ascending time to deadline: returns -1 if
    //   the first Dispatch_Entry is greater in the order, 0 if they're equivalent,
    //   or 1 if the second Dispatch_Entry is greater in the order.

private:

  static int sort_function (void *arg1, void *arg2);
    // comparison function to pass to qsort: calls instance ()->sort_comp ();

  static ACE_EDF_Scheduler_Strategy *instance_;
    // instance of the strategy

};


class TAO_ORBSVCS_Export ACE_RMS_Dyn_Scheduler_Strategy : public ACE_Scheduler_Strategy
  // = TITLE
  //    ACE_RMS_Dyn_Scheduler_Strategy
  //
  // = DESCRIPTION
  //    Defines "schedule" method using Rate Monotonic priority assignment for
  //    the critical set, single priority for the dynamic (non-critical) set.
{
public:

  ACE_RMS_Dyn_Scheduler_Strategy (ACE_DynScheduler::Preemption_Priority minimum_critical_priority = 0);
    // = ctor

  virtual ~ACE_RMS_Dyn_Scheduler_Strategy ();
    // = virtual dtor

  static ACE_RMS_Dyn_Scheduler_Strategy *instance ();
    // returns an instance of the strategy

  virtual int priority_comp (const Dispatch_Entry &first_entry,
                             const Dispatch_Entry &second_entry);
    // = comparison of two dispatch entries by maximum criticality: returns -1
    //   if the first Dispatch_Entry is greater in the order, 0 if they're
    //   equivalent, or 1 if the second Dispatch_Entry is greater in the order.

  virtual void sort (Dispatch_Entry **dispatch_entries,
                     u_int count);
    // = sort the dispatch entry pointer array in descending priority order

    virtual ACE_DynScheduler::Preemption_Priority minimum_critical_priority ();
  // = determine the minimum critical priority number

protected:

  virtual long dynamic_subpriority (Dispatch_Entry &entry,
                                    u_long current_time);
    // = returns a dynamic subpriority value at the current time for the
    //   given timeline entry: if the operation is in the
    //   critical set, the dynamic subpriority value is always 0; if the
    //   operation is non-critical and has non-negative laxity, then the
    //   dynamic subpriority value is positive, and a lower laxity gives a
    //   higher dynamic subpriority if the operation is non-critical and has
    //   negative laxity, the value is the (negative) laxity value


  virtual int dynamic_subpriority_comp
    (const Dispatch_Entry &first_entry,
     const Dispatch_Entry &second_entry);
    // = comparison of two dispatch entries within the very high and high
    //   criticality sets by minimum period (RMS) or of two dispatch entries
    //   within the medium, low, and very low criticality sets by minimum
    //   laxity: returns -1 if the first Dispatch_Entry is greater in the order,
    //   0 if they're equivalent, or 1 if the second Dispatch_Entry is greater
    //   in the order.

private:

  static int sort_function (void *arg1, void *arg2);
    // comparison function to pass to qsort: calls instance ()->sort_comp ();

  static ACE_RMS_Dyn_Scheduler_Strategy *instance_;
    // instance of the strategy

};


#if defined (__ACE_INLINE__)
#include "Strategy_Scheduler.i"
#endif /* __ACE_INLINE__ */

#endif /* STRATEGY_SCHEDULER_H */

// EOF
