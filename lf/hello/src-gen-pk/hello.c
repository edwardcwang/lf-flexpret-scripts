// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/lf/hello/hello.lf
#include "ctarget.h"
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Minimal
typedef struct {
    int bank_index;
    #line 5 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    reaction_t ___reaction_0;
    #line 4 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    trigger_t ___t;
    #line 4 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    reaction_t* ___t_reactions[1];
} minimal_self_t;
void minimalreaction_function_0(void* instance_args) {
    minimal_self_t* self = (minimal_self_t*)instance_args;
    #line 6 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    printf("Hello world.\n");
        
}
minimal_self_t* new_Minimal() {
    minimal_self_t* self = (minimal_self_t*)calloc(1, sizeof(minimal_self_t));
    #line 5 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    self->___reaction_0.function = minimalreaction_function_0;
    #line 5 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    self->___reaction_0.self = self;
    #line 5 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 5 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 4 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    self->___t.last = NULL;
    #line 4 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    #line 4 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    self->___t_reactions[0] = &self->___reaction_0;
    #line 4 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    self->___t.reactions = &self->___t_reactions[0];
    #line 4 "file:/lf-flexpret-scripts/lf/hello/hello.lf"
    self->___t.number_of_reactions = 1;
    self->___t.is_timer = true;
    return self;
}
void delete_Minimal(minimal_self_t* self) {
    if (self->___reaction_0.output_produced != NULL) {
        free(self->___reaction_0.output_produced);
    }
    if (self->___reaction_0.triggers != NULL) {
        free(self->___reaction_0.triggers);
    }
    if (self->___reaction_0.triggered_sizes != NULL) {
        free(self->___reaction_0.triggered_sizes);
    }
    for(int i = 0; i < self->___reaction_0.num_outputs; i++) {
        free(self->___reaction_0.triggers[i]);
    }
    free(self);
}
// =============== END reactor class Minimal

void __set_default_command_line_options() {
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t* __timer_triggers[1];
int __timer_triggers_size = 1;
// Array of pointers to reactions to be scheduled in __trigger_startup_reactions().
reaction_t** __startup_reactions = NULL;
int __startup_reactions_size = 0;
// Empty array of pointers to shutdown triggers.
trigger_t** __shutdown_triggers = NULL;
int __shutdown_triggers_size = 0;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    // ************* Instance Minimal of class Minimal
    minimal_self_t* minimal_self = new_Minimal();
    //***** Start initializing Minimal
    minimal_self->___t.offset = 0;
    minimal_self->___t.period = 0;
    __timer_triggers[0] = &minimal_self->___t;
    //***** End initializing Minimal
    // Populate arrays of trigger pointers.
    minimal_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    minimal_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (minimal_self->___reaction_0.num_outputs > 0) {
        minimal_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * minimal_self->___reaction_0.num_outputs);
        minimal_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * minimal_self->___reaction_0.num_outputs);
        minimal_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * minimal_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of Minimal does not depend on one maximal upstream reaction.
    minimal_self->___reaction_0.last_enabling_reaction = NULL;
    // doDeferredInitialize
    // Connect inputs and outputs for reactor Minimal.
    // END Connect inputs and outputs for reactor Minimal.
    
    minimal_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    minimal_self->___reaction_0.index = 0x7fffffffffff0000LL;
}
void __trigger_startup_reactions() {
    
}
void __initialize_timers() {
    for (int i = 0; i < __timer_triggers_size; i++) {
        if (__timer_triggers[i] != NULL) {
            _lf_initialize_timer(__timer_triggers[i]);
        }
    }
}
void logical_time_complete(instant_t time) {
}
instant_t next_event_time(instant_t time) {
    return time;
}
bool __wrapup() {
    __start_time_step();  // To free memory allocated for actions.
    for (int i = 0; i < __shutdown_triggers_size; i++) {
        __schedule(__shutdown_triggers[i], 0LL, NULL);
    }
    // Return true if there are shutdown actions.
    return (__shutdown_triggers_size > 0);
}
void __termination() {}
