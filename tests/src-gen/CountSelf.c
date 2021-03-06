#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/CountSelf.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Test
#line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
typedef struct {
#line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    int value;
#line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    bool is_present;
#line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    int num_destinations;
#line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
} test_in_t;
typedef struct {
    int bank_index;
    #line 20 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    int count;
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    test_in_t* __in;
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    // width of -2 indicates that it is not a multiport.
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    int __in__width;
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    // Default input (in case it does not get connected)
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    test_in_t __default__in;
    #line 21 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    reaction_t ___reaction_0;
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    trigger_t ___in;
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    reaction_t* ___in_reactions[1];
} test_self_t;
void testreaction_function_0(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    test_in_t* in = self->__in;
    int in_width = self->__in__width;
    #line 22 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    printf("Received: %d.\n", in->value);
    if (in->value != self->count) {
        fprintf(stderr, "ERROR: Expected %d.\n", self->count);
        exit(1);
    }
    self->count++;
        
}
test_self_t* new_Test() {
    test_self_t* self = (test_self_t*)calloc(1, sizeof(test_self_t));
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    // Set input by default to an always absent default input.
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->__in = &self->__default__in;
    #line 21 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_0.number = 0;
    #line 21 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_0.function = testreaction_function_0;
    #line 21 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_0.self = self;
    #line 21 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 21 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___in.last = NULL;
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___in_reactions[0] = &self->___reaction_0;
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 19 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(int);
    return self;
}
void delete_Test(test_self_t* self) {
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
// =============== END reactor class Test

// =============== START reactor class CountSelf
#line 7 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
typedef struct {
#line 7 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    int value;
#line 7 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    bool is_present;
#line 7 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    int num_destinations;
#line 7 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
} countself_out_t;
#line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
typedef struct {
#line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    trigger_t* trigger;
#line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    int value;
#line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    bool is_present;
#line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    bool has_value;
#line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    lf_token_t* token;
#line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
} countself_a_t;
typedef struct {
    int bank_index;
    #line 6 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    interval_t delay;
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    countself_a_t __a;
    #line 7 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    countself_out_t __out;
    #line 7 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    int __out__width;
    #line 9 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    reaction_t ___reaction_0;
    #line 13 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    reaction_t ___reaction_1;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    trigger_t ___a;
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    reaction_t* ___a_reactions[1];
} countself_self_t;
void countselfreaction_function_0(void* instance_args) {
    countself_self_t* self = (countself_self_t*)instance_args;
    countself_a_t* a = &self->__a;
    countself_out_t* out = &self->__out;
    #line 10 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    SET(out, 0);
    schedule_int(a, self->delay, 1);
        
}
void countselfreaction_function_1(void* instance_args) {
    countself_self_t* self = (countself_self_t*)instance_args;
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    // Expose the action struct as a local variable whose name matches the action name.
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    countself_a_t* a = &self->__a;
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    // Set the fields of the action struct to match the current trigger.
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    a->is_present = self->___a.is_present;
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    a->has_value = ((self->___a.token) != NULL && (self->___a.token)->value != NULL);
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    a->token = (self->___a.token);
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    if (a->has_value) {
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
        a->value = *(int*)(self->___a.token)->value;
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    }
    countself_out_t* out = &self->__out;
    #line 14 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    SET(out, a->value);
    schedule_int(a, self->delay, a->value + 1);
        
}
countself_self_t* new_CountSelf() {
    countself_self_t* self = (countself_self_t*)calloc(1, sizeof(countself_self_t));
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->__a.trigger = &self->___a;
    #line 9 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_0.number = 0;
    #line 9 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_0.function = countselfreaction_function_0;
    #line 9 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_0.self = self;
    #line 9 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 9 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 13 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_1.number = 1;
    #line 13 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_1.function = countselfreaction_function_1;
    #line 13 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_1.self = self;
    #line 13 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_1.deadline_violation_handler = NULL;
    #line 13 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___reaction_1.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___a.last = NULL;
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___a_reactions[0] = &self->___reaction_1;
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___a.reactions = &self->___a_reactions[0];
    #line 8 "file:/lf-flexpret-scripts/tests/CountSelf.lf"
    self->___a.number_of_reactions = 1;
    self->___a.is_physical = false;
    self->___a.element_size = sizeof(int);
    return self;
}
void delete_CountSelf(countself_self_t* self) {
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
// =============== END reactor class CountSelf

// =============== START reactor class DelayInt
typedef struct {
    int bank_index;
} delayint_self_t;
delayint_self_t* new_DelayInt() {
    delayint_self_t* self = (delayint_self_t*)calloc(1, sizeof(delayint_self_t));
    return self;
}
void delete_DelayInt(delayint_self_t* self) {
    free(self);
}
// =============== END reactor class DelayInt

char* __default_argv[] = {"X", "-f", "true", "-o", "1", "sec"};
void __set_default_command_line_options() {
    default_argc = 6;
    default_argv = __default_argv;
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t** __timer_triggers = NULL;
int __timer_triggers_size = 0;
// Array of pointers to timer triggers to be scheduled in __trigger_startup_reactions().
reaction_t* __startup_reactions[1];
int __startup_reactions_size = 1;
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
    __is_present_fields_size = 2;
    __is_present_fields = (bool**)malloc(2 * sizeof(bool*));
    // ************* Instance DelayInt of class DelayInt
    delayint_self_t* delayint_self = new_DelayInt();
    //***** Start initializing DelayInt
    // ************* Instance DelayInt.d of class CountSelf
    countself_self_t* delayint_d_self = new_CountSelf();
    //***** Start initializing DelayInt.d
    delayint_d_self->delay = MSEC(100); 
    // width of -2 indicates that it is not a multiport.
    delayint_d_self->__out__width = -2;
    __startup_reactions[0] = &delayint_d_self->___reaction_0;
    delayint_d_self->___a.offset = 0;
    delayint_d_self->___a.period = -1;
    delayint_d_self->___a.token = __create_token(sizeof(int));
    delayint_d_self->___a.is_present = false;
    __tokens_with_ref_count[0].token
            = &delayint_d_self->___a.token;
    __tokens_with_ref_count[0].is_present
            = &delayint_d_self->___a.is_present;
    __tokens_with_ref_count[0].reset_is_present = true;
    //***** End initializing DelayInt.d
    // ************* Instance DelayInt.t of class Test
    test_self_t* delayint_t_self = new_Test();
    //***** Start initializing DelayInt.t
    // width of -2 indicates that it is not a multiport.
    delayint_t_self->__in__width = -2;
    static int delayint_t_initial_count = 0;
    delayint_t_self->count = delayint_t_initial_count;
    //***** End initializing DelayInt.t
    //***** End initializing DelayInt
    // Populate arrays of trigger pointers.
    delayint_self->bank_index = 0;
    delayint_d_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delayint_d_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (delayint_d_self->___reaction_0.num_outputs > 0) {
        delayint_d_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delayint_d_self->___reaction_0.num_outputs);
        delayint_d_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayint_d_self->___reaction_0.num_outputs);
        delayint_d_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delayint_d_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    delayint_d_self->___reaction_0.output_produced[0]
    = &delayint_d_self->__out.is_present
    ;
    // Total number of outputs produced by the reaction.
    delayint_d_self->___reaction_1.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (delayint_d_self->___reaction_1.num_outputs > 0) {
        delayint_d_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * delayint_d_self->___reaction_1.num_outputs);
        delayint_d_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayint_d_self->___reaction_1.num_outputs);
        delayint_d_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * delayint_d_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    delayint_d_self->___reaction_1.output_produced[0]
    = &delayint_d_self->__out.is_present
    ;
    // Reaction 0 of DelayInt.d does not depend on one maximal upstream reaction.
    delayint_d_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of DelayInt.d triggers 1 downstream reactions through port DelayInt.d.out.
    delayint_d_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of DelayInt.d, allocate an
    // array of trigger pointers for downstream reactions through port DelayInt.d.out
    trigger_t** delayint_d_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delayint_d_self->___reaction_0.triggers[0] = delayint_d_0_0;
    // Point to destination port DelayInt.t.in's trigger struct.
    delayint_d_0_0[0] = &delayint_t_self->___in;
    // Reaction 1 of DelayInt.d depends on one maximal upstream reaction.
    delayint_d_self->___reaction_1.last_enabling_reaction = &(delayint_d_self->___reaction_0);
    // Reaction 1 of DelayInt.d triggers 1 downstream reactions through port DelayInt.d.out.
    delayint_d_self->___reaction_1.triggered_sizes[0] = 1;
    // For reaction 1 of DelayInt.d, allocate an
    // array of trigger pointers for downstream reactions through port DelayInt.d.out
    trigger_t** delayint_d_1_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delayint_d_self->___reaction_1.triggers[0] = delayint_d_1_0;
    // Point to destination port DelayInt.t.in's trigger struct.
    delayint_d_1_0[0] = &delayint_t_self->___in;
    delayint_d_self->__out.num_destinations
    = 1;
    delayint_t_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delayint_t_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delayint_t_self->___reaction_0.num_outputs > 0) {
        delayint_t_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delayint_t_self->___reaction_0.num_outputs);
        delayint_t_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayint_t_self->___reaction_0.num_outputs);
        delayint_t_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delayint_t_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of DelayInt.t depends on one maximal upstream reaction.
    delayint_t_self->___reaction_0.last_enabling_reaction = &(delayint_d_self->___reaction_1);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor DelayInt.
    // Connect DelayInt.d.out to input port DelayInt.t.in
    delayint_t_self->__in = (test_in_t*)&delayint_d_self->__out;
    // Connect inputs and outputs for reactor DelayInt.d.
    // END Connect inputs and outputs for reactor DelayInt.d.
    // Connect inputs and outputs for reactor DelayInt.t.
    // END Connect inputs and outputs for reactor DelayInt.t.
    // END Connect inputs and outputs for reactor DelayInt.
    // Add action DelayInt.d.a to array of is_present fields.
    __is_present_fields[0] 
            = &delayint_d_self->__a.is_present;
    // Add port DelayInt.d.out to array of is_present fields.
    __is_present_fields[1] = &delayint_d_self->__out.is_present
    ;
    delayint_d_self->___reaction_0.chain_id = 3;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayint_d_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delayint_d_self->___reaction_1.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayint_d_self->___reaction_1.index = 0x7fffffffffff0001LL;
    delayint_t_self->___reaction_0.chain_id = 3;
    // index is the OR of level 2 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayint_t_self->___reaction_0.index = 0x7fffffffffff0002LL;
}
void __trigger_startup_reactions() {
    
    for (int i = 0; i < __startup_reactions_size; i++) {
        if (__startup_reactions[i] != NULL) {
            _lf_enqueue_reaction(__startup_reactions[i]);
        }
    }
}
void __initialize_timers() {
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
