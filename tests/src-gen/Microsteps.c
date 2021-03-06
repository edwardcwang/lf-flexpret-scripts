#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/Microsteps.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Destination
#line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
typedef struct {
#line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    int value;
#line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    bool is_present;
#line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    int num_destinations;
#line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
} destination_x_t;
#line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
typedef struct {
#line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    int value;
#line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    bool is_present;
#line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    int num_destinations;
#line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
} destination_y_t;
typedef struct {
    int bank_index;
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    destination_x_t* __x;
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    // width of -2 indicates that it is not a multiport.
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    int __x__width;
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    // Default input (in case it does not get connected)
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    destination_x_t __default__x;
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    destination_y_t* __y;
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    // width of -2 indicates that it is not a multiport.
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    int __y__width;
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    // Default input (in case it does not get connected)
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    destination_y_t __default__y;
    #line 5 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    reaction_t ___reaction_0;
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    trigger_t ___x;
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    reaction_t* ___x_reactions[1];
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    trigger_t ___y;
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    reaction_t* ___y_reactions[1];
} destination_self_t;
void destinationreaction_function_0(void* instance_args) {
    destination_self_t* self = (destination_self_t*)instance_args;
    destination_x_t* x = self->__x;
    int x_width = self->__x__width;
    destination_y_t* y = self->__y;
    int y_width = self->__y__width;
    #line 6 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    interval_t elapsed = get_elapsed_logical_time();
    printf("Time since start: %lld.\n", elapsed);
    if (elapsed != 0LL) {
        printf("Expected elapsed time to be 0, but it was %lld.\n", elapsed);
        exit(1);
    }
    int count = 0;
    if (x->is_present) {
        printf("  x is present.\n");
        count++;
    }
    if (y->is_present) {
        printf("  y is present.\n");
        count++;
    }
    if (count != 1) {
        printf("Expected exactly one input to be present but got %d.\n", count);
        exit(1);
    }
        
}
destination_self_t* new_Destination() {
    destination_self_t* self = (destination_self_t*)calloc(1, sizeof(destination_self_t));
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    // Set input by default to an always absent default input.
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->__x = &self->__default__x;
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    // Set input by default to an always absent default input.
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->__y = &self->__default__y;
    #line 5 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_0.number = 0;
    #line 5 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_0.function = destinationreaction_function_0;
    #line 5 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_0.self = self;
    #line 5 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 5 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___x.last = NULL;
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___x_reactions[0] = &self->___reaction_0;
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___x.reactions = &self->___x_reactions[0];
    #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___x.number_of_reactions = 1;
    self->___x.element_size = sizeof(int);
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___y.last = NULL;
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___y_reactions[0] = &self->___reaction_0;
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___y.reactions = &self->___y_reactions[0];
    #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___y.number_of_reactions = 1;
    self->___y.element_size = sizeof(int);
    return self;
}
void delete_Destination(destination_self_t* self) {
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
// =============== END reactor class Destination

// =============== START reactor class Microsteps
#line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
typedef struct {
#line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    trigger_t* trigger;
#line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    bool is_present;
#line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    bool has_value;
#line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    lf_token_t* token;
#line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
} microsteps_repeat_t;
typedef struct {
    int bank_index;
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    microsteps_repeat_t __repeat;
    struct {
        #line 3 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
        destination_x_t x;
        #line 4 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
        destination_y_t y;
    } __d;
    #line 31 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    reaction_t ___reaction_0;
    #line 35 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    reaction_t ___reaction_1;
    #line 28 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    trigger_t ___start;
    #line 28 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    reaction_t* ___start_reactions[1];
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    trigger_t ___repeat;
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    reaction_t* ___repeat_reactions[1];
} microsteps_self_t;
void microstepsreaction_function_0(void* instance_args) {
    struct d{
        destination_x_t* x;
    } d;
    microsteps_self_t* self = (microsteps_self_t*)instance_args;
    d.x = &(self->__d.x);
    microsteps_repeat_t* repeat = &self->__repeat;
    #line 32 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    SET(d.x, 1);
    schedule(repeat, 0);
        
}
void microstepsreaction_function_1(void* instance_args) {
    struct d{
        destination_y_t* y;
    } d;
    microsteps_self_t* self = (microsteps_self_t*)instance_args;
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    // Expose the action struct as a local variable whose name matches the action name.
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    microsteps_repeat_t* repeat = &self->__repeat;
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    // Set the fields of the action struct to match the current trigger.
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    repeat->is_present = self->___repeat.is_present;
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    repeat->has_value = ((self->___repeat.token) != NULL && (self->___repeat.token)->value != NULL);
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    repeat->token = (self->___repeat.token);
    d.y = &(self->__d.y);
    #line 36 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    SET(d.y, 1);
        
}
microsteps_self_t* new_Microsteps() {
    microsteps_self_t* self = (microsteps_self_t*)calloc(1, sizeof(microsteps_self_t));
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->__repeat.trigger = &self->___repeat;
    #line 31 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_0.number = 0;
    #line 31 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_0.function = microstepsreaction_function_0;
    #line 31 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_0.self = self;
    #line 31 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 31 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 35 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_1.number = 1;
    #line 35 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_1.function = microstepsreaction_function_1;
    #line 35 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_1.self = self;
    #line 35 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_1.deadline_violation_handler = NULL;
    #line 35 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___reaction_1.tardy_handler = NULL;
    #line 28 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___start.last = NULL;
    #line 28 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    #line 28 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___start_reactions[0] = &self->___reaction_0;
    #line 28 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___start.reactions = &self->___start_reactions[0];
    #line 28 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___start.number_of_reactions = 1;
    self->___start.is_timer = true;
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___repeat.last = NULL;
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___repeat_reactions[0] = &self->___reaction_1;
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___repeat.reactions = &self->___repeat_reactions[0];
    #line 29 "file:/lf-flexpret-scripts/tests/Microsteps.lf"
    self->___repeat.number_of_reactions = 1;
    self->___repeat.is_physical = false;
    self->___repeat.element_size = 0;
    return self;
}
void delete_Microsteps(microsteps_self_t* self) {
    if (self->___reaction_0.output_produced != NULL) {
        free(self->___reaction_0.output_produced);
    }
    if (self->___reaction_0.triggers != NULL) {
        free(self->___reaction_0.triggers);
    }
    if (self->___reaction_0.triggered_sizes != NULL) {
        free(self->___reaction_0.triggered_sizes);
    }
    if (self->___reaction_1.output_produced != NULL) {
        free(self->___reaction_1.output_produced);
    }
    if (self->___reaction_1.triggers != NULL) {
        free(self->___reaction_1.triggers);
    }
    if (self->___reaction_1.triggered_sizes != NULL) {
        free(self->___reaction_1.triggered_sizes);
    }
    for(int i = 0; i < self->___reaction_0.num_outputs; i++) {
        free(self->___reaction_0.triggers[i]);
    }
    for(int i = 0; i < self->___reaction_1.num_outputs; i++) {
        free(self->___reaction_1.triggers[i]);
    }
    free(self);
}
// =============== END reactor class Microsteps

void __set_default_command_line_options() {
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t* __timer_triggers[1];
int __timer_triggers_size = 1;
// Array of pointers to reactions to be scheduled in __trigger_startup_reactions().
reaction_t** __startup_reactions = NULL;
int __startup_reactions_size = 0;
// Empty array of pointers to shutdown triggers.
reaction_t** __shutdown_reactions = NULL;
int __shutdown_reactions_size = 0;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    __tokens_with_ref_count_size = 1;
    __tokens_with_ref_count = (token_present_t*)malloc(1 * sizeof(token_present_t));
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 3;
    __is_present_fields = (bool**)malloc(3 * sizeof(bool*));
    // ************* Instance Microsteps of class Microsteps
    microsteps_self_t* microsteps_self = new_Microsteps();
    //***** Start initializing Microsteps
    microsteps_self->___start.offset = 0;
    microsteps_self->___start.period = 0;
    __timer_triggers[0] = &microsteps_self->___start;
    microsteps_self->___repeat.offset = 0;
    microsteps_self->___repeat.period = -1;
    microsteps_self->___repeat.token = __create_token(0);
    microsteps_self->___repeat.is_present = false;
    __tokens_with_ref_count[0].token
            = &microsteps_self->___repeat.token;
    __tokens_with_ref_count[0].is_present
            = &microsteps_self->___repeat.is_present;
    __tokens_with_ref_count[0].reset_is_present = true;
    // ************* Instance Microsteps.d of class Destination
    destination_self_t* microsteps_d_self = new_Destination();
    //***** Start initializing Microsteps.d
    // width of -2 indicates that it is not a multiport.
    microsteps_d_self->__x__width = -2;
    // width of -2 indicates that it is not a multiport.
    microsteps_d_self->__y__width = -2;
    //***** End initializing Microsteps.d
    //***** End initializing Microsteps
    // Populate arrays of trigger pointers.
    microsteps_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    microsteps_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (microsteps_self->___reaction_0.num_outputs > 0) {
        microsteps_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * microsteps_self->___reaction_0.num_outputs);
        microsteps_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * microsteps_self->___reaction_0.num_outputs);
        microsteps_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * microsteps_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    microsteps_self->___reaction_0.output_produced[0]
    = &microsteps_self->__d.x.is_present
    ;
    // Total number of outputs produced by the reaction.
    microsteps_self->___reaction_1.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (microsteps_self->___reaction_1.num_outputs > 0) {
        microsteps_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * microsteps_self->___reaction_1.num_outputs);
        microsteps_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * microsteps_self->___reaction_1.num_outputs);
        microsteps_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * microsteps_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    microsteps_self->___reaction_1.output_produced[0]
    = &microsteps_self->__d.y.is_present
    ;
    // Reaction 0 of Microsteps does not depend on one maximal upstream reaction.
    microsteps_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of Microsteps triggers 1 downstream reactions through port Microsteps.d.x.
    microsteps_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of Microsteps, allocate an
    // array of trigger pointers for downstream reactions through port Microsteps.d.x
    trigger_t** microsteps_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    microsteps_self->___reaction_0.triggers[0] = microsteps_0_0;
    // Point to destination port Microsteps.d.x's trigger struct.
    microsteps_0_0[0] = &microsteps_d_self->___x;
    // Reaction 1 of Microsteps depends on one maximal upstream reaction.
    microsteps_self->___reaction_1.last_enabling_reaction = &(microsteps_self->___reaction_0);
    // Reaction 1 of Microsteps triggers 1 downstream reactions through port Microsteps.d.y.
    microsteps_self->___reaction_1.triggered_sizes[0] = 1;
    // For reaction 1 of Microsteps, allocate an
    // array of trigger pointers for downstream reactions through port Microsteps.d.y
    trigger_t** microsteps_1_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    microsteps_self->___reaction_1.triggers[0] = microsteps_1_0;
    // Point to destination port Microsteps.d.y's trigger struct.
    microsteps_1_0[0] = &microsteps_d_self->___y;
    microsteps_self->__d.x.
    num_destinations = 1;
    microsteps_self->__d.y.
    num_destinations = 1;
    microsteps_d_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    microsteps_d_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (microsteps_d_self->___reaction_0.num_outputs > 0) {
        microsteps_d_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * microsteps_d_self->___reaction_0.num_outputs);
        microsteps_d_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * microsteps_d_self->___reaction_0.num_outputs);
        microsteps_d_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * microsteps_d_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of Microsteps.d depends on one maximal upstream reaction.
    microsteps_d_self->___reaction_0.last_enabling_reaction = &(microsteps_self->___reaction_1);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor Microsteps.
    // Connect inputs and outputs for reactor Microsteps.d.
    // END Connect inputs and outputs for reactor Microsteps.d.
    // Connect PortInstance Microsteps.d.x, which gets data from reaction 0
    // of Microsteps, to Microsteps.d.x.
    microsteps_d_self->__x = (destination_x_t*)&microsteps_self->__d.x;
    // Connect PortInstance Microsteps.d.y, which gets data from reaction 1
    // of Microsteps, to Microsteps.d.y.
    microsteps_d_self->__y = (destination_y_t*)&microsteps_self->__d.y;
    // END Connect inputs and outputs for reactor Microsteps.
    // Add port Microsteps.d.x to array of is_present fields.
    __is_present_fields[0] 
            = &microsteps_self->__d.x.
            is_present;
    // Add port Microsteps.d.y to array of is_present fields.
    __is_present_fields[1] 
            = &microsteps_self->__d.y.
            is_present;
    // Add action Microsteps.repeat to array of is_present fields.
    __is_present_fields[2] 
            = &microsteps_self->__repeat.is_present;
    microsteps_self->___reaction_0.chain_id = 3;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    microsteps_self->___reaction_0.index = 0x7fffffffffff0000LL;
    microsteps_self->___reaction_1.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    microsteps_self->___reaction_1.index = 0x7fffffffffff0001LL;
    microsteps_d_self->___reaction_0.chain_id = 3;
    // index is the OR of level 2 and 
    // deadline 140737488355327 shifted left 16 bits.
    microsteps_d_self->___reaction_0.index = 0x7fffffffffff0002LL;
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
void logical_time_complete(instant_t timestep, microstep_t microstep) {
}
tag_t next_event_tag(instant_t time, microstep_t microstep) {
    return (tag_t) {  .time = time, .microstep = microstep };
}
bool __trigger_shutdown_reactions() {                          
    for (int i = 0; i < __shutdown_reactions_size; i++) {
        if (__shutdown_reactions[i] != NULL) {
            _lf_enqueue_reaction(__shutdown_reactions[i]);
        }
    }
    // Return true if there are shutdown reactions.
    return (__shutdown_reactions_size > 0);
}
void __termination() {stop_trace();}
