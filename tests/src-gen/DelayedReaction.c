#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/DelayedReaction.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class __GenDelay_197ef
typedef struct {
    int value;
    bool is_present;
    int num_destinations;
} __gendelay_197ef_inp_t;
typedef struct {
    int value;
    bool is_present;
    int num_destinations;
} __gendelay_197ef_out_t;
typedef struct {
    trigger_t* trigger;
    int value;
    bool is_present;
    bool has_value;
    lf_token_t* token;
} __gendelay_197ef_act_t;
typedef struct {
    int bank_index;
    interval_t delay;
    __gendelay_197ef_act_t __act;
    __gendelay_197ef_inp_t* __inp;
    // width of -2 indicates that it is not a multiport.
    int __inp__width;
    // Default input (in case it does not get connected)
    __gendelay_197ef_inp_t __default__inp;
    __gendelay_197ef_out_t __out;
    int __out__width;
    reaction_t ___reaction_0;
    reaction_t ___reaction_1;
    trigger_t ___act;
    reaction_t* ___act_reactions[1];
    trigger_t ___inp;
    reaction_t* ___inp_reactions[1];
} __gendelay_197ef_self_t;
void __gendelay_197efreaction_function_0(void* instance_args) {
    __gendelay_197ef_self_t* self = (__gendelay_197ef_self_t*)instance_args;
    // Expose the action struct as a local variable whose name matches the action name.
    __gendelay_197ef_act_t* act = &self->__act;
    // Set the fields of the action struct to match the current trigger.
    act->is_present = self->___act.is_present;
    act->has_value = ((self->___act.token) != NULL && (self->___act.token)->value != NULL);
    act->token = (self->___act.token);
    if (act->has_value) {
        act->value = *(int*)(self->___act.token)->value;
    }
    __gendelay_197ef_out_t* out = &self->__out;
    SET(out, act->value);
}
void __gendelay_197efreaction_function_1(void* instance_args) {
    __gendelay_197ef_self_t* self = (__gendelay_197ef_self_t*)instance_args;
    __gendelay_197ef_inp_t* inp = self->__inp;
    int inp_width = self->__inp__width;
    __gendelay_197ef_act_t* act = &self->__act;
    schedule_copy(act, 0, &inp->value, 1);  // Length is 1.
}
__gendelay_197ef_self_t* new___GenDelay_197ef() {
    __gendelay_197ef_self_t* self = (__gendelay_197ef_self_t*)calloc(1, sizeof(__gendelay_197ef_self_t));
    self->__act.trigger = &self->___act;
    // Set input by default to an always absent default input.
    self->__inp = &self->__default__inp;
    self->___reaction_0.number = 0;
    self->___reaction_0.function = __gendelay_197efreaction_function_0;
    self->___reaction_0.self = self;
    self->___reaction_0.deadline_violation_handler = NULL;
    self->___reaction_0.tardy_handler = NULL;
    self->___reaction_1.number = 1;
    self->___reaction_1.function = __gendelay_197efreaction_function_1;
    self->___reaction_1.self = self;
    self->___reaction_1.deadline_violation_handler = NULL;
    self->___reaction_1.tardy_handler = NULL;
    self->___act.last = NULL;
    self->___act_reactions[0] = &self->___reaction_0;
    self->___act.reactions = &self->___act_reactions[0];
    self->___act.number_of_reactions = 1;
    self->___act.is_physical = false;
    self->___act.element_size = sizeof(int);
    self->___inp.last = NULL;
    self->___inp_reactions[0] = &self->___reaction_1;
    self->___inp.reactions = &self->___inp_reactions[0];
    self->___inp.number_of_reactions = 1;
    self->___inp.element_size = sizeof(int);
    return self;
}
void delete___GenDelay_197ef(__gendelay_197ef_self_t* self) {
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
// =============== END reactor class __GenDelay_197ef

// =============== START reactor class Sink
#line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
typedef struct {
#line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    int value;
#line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    bool is_present;
#line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    int num_destinations;
#line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
} sink_in_t;
typedef struct {
    int bank_index;
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    sink_in_t* __in;
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    // width of -2 indicates that it is not a multiport.
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    int __in__width;
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    // Default input (in case it does not get connected)
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    sink_in_t __default__in;
    #line 14 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    reaction_t ___reaction_0;
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    trigger_t ___in;
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    reaction_t* ___in_reactions[1];
} sink_self_t;
void sinkreaction_function_0(void* instance_args) {
    sink_self_t* self = (sink_self_t*)instance_args;
    sink_in_t* in = self->__in;
    int in_width = self->__in__width;
    #line 15 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    interval_t elapsed = get_elapsed_logical_time();
    printf("Nanoseconds since start: %lld.\n", elapsed);
    if (elapsed != 100000000LL) {
        printf("ERROR: Expected 100000000 but.\n");
        exit(1);
    }        
        
}
sink_self_t* new_Sink() {
    sink_self_t* self = (sink_self_t*)calloc(1, sizeof(sink_self_t));
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    // Set input by default to an always absent default input.
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->__in = &self->__default__in;
    #line 14 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___reaction_0.number = 0;
    #line 14 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___reaction_0.function = sinkreaction_function_0;
    #line 14 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___reaction_0.self = self;
    #line 14 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 14 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___in.last = NULL;
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___in_reactions[0] = &self->___reaction_0;
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 13 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(int);
    return self;
}
void delete_Sink(sink_self_t* self) {
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
// =============== END reactor class Sink

// =============== START reactor class Source
#line 5 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
typedef struct {
#line 5 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    int value;
#line 5 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    bool is_present;
#line 5 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    int num_destinations;
#line 5 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
} source_out_t;
typedef struct {
    int bank_index;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    source_out_t __out;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    int __out__width;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    reaction_t ___reaction_0;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    trigger_t ___t;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    reaction_t* ___t_reactions[1];
} source_self_t;
void sourcereaction_function_0(void* instance_args) {
    source_self_t* self = (source_self_t*)instance_args;
    source_out_t* out = &self->__out;
    #line 8 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    SET(out, 1);
        
}
source_self_t* new_Source() {
    source_self_t* self = (source_self_t*)calloc(1, sizeof(source_self_t));
    #line 7 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___reaction_0.number = 0;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___reaction_0.function = sourcereaction_function_0;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___reaction_0.self = self;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___t.last = NULL;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    #line 6 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___t_reactions[0] = &self->___reaction_0;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___t.reactions = &self->___t_reactions[0];
    #line 6 "file:/lf-flexpret-scripts/tests/DelayedReaction.lf"
    self->___t.number_of_reactions = 1;
    self->___t.is_timer = true;
    return self;
}
void delete_Source(source_self_t* self) {
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
// =============== END reactor class Source

// =============== START reactor class DelayedReaction
typedef struct {
    int bank_index;
} delayedreaction_self_t;
delayedreaction_self_t* new_DelayedReaction() {
    delayedreaction_self_t* self = (delayedreaction_self_t*)calloc(1, sizeof(delayedreaction_self_t));
    return self;
}
void delete_DelayedReaction(delayedreaction_self_t* self) {
    free(self);
}
// =============== END reactor class DelayedReaction

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
    // ************* Instance DelayedReaction of class DelayedReaction
    delayedreaction_self_t* delayedreaction_self = new_DelayedReaction();
    //***** Start initializing DelayedReaction
    // ************* Instance DelayedReaction.source of class Source
    source_self_t* delayedreaction_source_self = new_Source();
    //***** Start initializing DelayedReaction.source
    // width of -2 indicates that it is not a multiport.
    delayedreaction_source_self->__out__width = -2;
    delayedreaction_source_self->___t.offset = 0;
    delayedreaction_source_self->___t.period = 0;
    __timer_triggers[0] = &delayedreaction_source_self->___t;
    //***** End initializing DelayedReaction.source
    // ************* Instance DelayedReaction.sink of class Sink
    sink_self_t* delayedreaction_sink_self = new_Sink();
    //***** Start initializing DelayedReaction.sink
    // width of -2 indicates that it is not a multiport.
    delayedreaction_sink_self->__in__width = -2;
    //***** End initializing DelayedReaction.sink
    // ************* Instance DelayedReaction.delay of class __GenDelay_197ef
    __gendelay_197ef_self_t* delayedreaction_delay_self = new___GenDelay_197ef();
    //***** Start initializing DelayedReaction.delay
    delayedreaction_delay_self->delay = MSEC(100); 
    // width of -2 indicates that it is not a multiport.
    delayedreaction_delay_self->__out__width = -2;
    // width of -2 indicates that it is not a multiport.
    delayedreaction_delay_self->__inp__width = -2;
    delayedreaction_delay_self->___act.offset = MSEC(100);
    delayedreaction_delay_self->___act.period = -1;
    delayedreaction_delay_self->___act.token = __create_token(sizeof(int));
    delayedreaction_delay_self->___act.is_present = false;
    __tokens_with_ref_count[0].token
            = &delayedreaction_delay_self->___act.token;
    __tokens_with_ref_count[0].is_present
            = &delayedreaction_delay_self->___act.is_present;
    __tokens_with_ref_count[0].reset_is_present = true;
    //***** End initializing DelayedReaction.delay
    //***** End initializing DelayedReaction
    // Populate arrays of trigger pointers.
    delayedreaction_self->bank_index = 0;
    delayedreaction_source_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delayedreaction_source_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (delayedreaction_source_self->___reaction_0.num_outputs > 0) {
        delayedreaction_source_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delayedreaction_source_self->___reaction_0.num_outputs);
        delayedreaction_source_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayedreaction_source_self->___reaction_0.num_outputs);
        delayedreaction_source_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delayedreaction_source_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    delayedreaction_source_self->___reaction_0.output_produced[0]
    = &delayedreaction_source_self->__out.is_present
    ;
    // Reaction 0 of DelayedReaction.source does not depend on one maximal upstream reaction.
    delayedreaction_source_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of DelayedReaction.source triggers 1 downstream reactions through port DelayedReaction.source.out.
    delayedreaction_source_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of DelayedReaction.source, allocate an
    // array of trigger pointers for downstream reactions through port DelayedReaction.source.out
    trigger_t** delayedreaction_source_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delayedreaction_source_self->___reaction_0.triggers[0] = delayedreaction_source_0_0;
    // Point to destination port DelayedReaction.delay.inp's trigger struct.
    delayedreaction_source_0_0[0] = &delayedreaction_delay_self->___inp;
    delayedreaction_source_self->__out.num_destinations
    = 1;
    delayedreaction_sink_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delayedreaction_sink_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delayedreaction_sink_self->___reaction_0.num_outputs > 0) {
        delayedreaction_sink_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delayedreaction_sink_self->___reaction_0.num_outputs);
        delayedreaction_sink_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayedreaction_sink_self->___reaction_0.num_outputs);
        delayedreaction_sink_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delayedreaction_sink_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of DelayedReaction.sink depends on one maximal upstream reaction.
    delayedreaction_sink_self->___reaction_0.last_enabling_reaction = &(delayedreaction_delay_self->___reaction_0);
    delayedreaction_delay_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delayedreaction_delay_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (delayedreaction_delay_self->___reaction_0.num_outputs > 0) {
        delayedreaction_delay_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delayedreaction_delay_self->___reaction_0.num_outputs);
        delayedreaction_delay_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayedreaction_delay_self->___reaction_0.num_outputs);
        delayedreaction_delay_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delayedreaction_delay_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    delayedreaction_delay_self->___reaction_0.output_produced[0]
    = &delayedreaction_delay_self->__out.is_present
    ;
    // Total number of outputs produced by the reaction.
    delayedreaction_delay_self->___reaction_1.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delayedreaction_delay_self->___reaction_1.num_outputs > 0) {
        delayedreaction_delay_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * delayedreaction_delay_self->___reaction_1.num_outputs);
        delayedreaction_delay_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delayedreaction_delay_self->___reaction_1.num_outputs);
        delayedreaction_delay_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * delayedreaction_delay_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of DelayedReaction.delay does not depend on one maximal upstream reaction.
    delayedreaction_delay_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of DelayedReaction.delay triggers 1 downstream reactions through port DelayedReaction.delay.out.
    delayedreaction_delay_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of DelayedReaction.delay, allocate an
    // array of trigger pointers for downstream reactions through port DelayedReaction.delay.out
    trigger_t** delayedreaction_delay_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delayedreaction_delay_self->___reaction_0.triggers[0] = delayedreaction_delay_0_0;
    // Point to destination port DelayedReaction.sink.in's trigger struct.
    delayedreaction_delay_0_0[0] = &delayedreaction_sink_self->___in;
    // Reaction 1 of DelayedReaction.delay does not depend on one maximal upstream reaction.
    delayedreaction_delay_self->___reaction_1.last_enabling_reaction = NULL;
    delayedreaction_delay_self->__out.num_destinations
    = 1;
    // doDeferredInitialize
    // Connect inputs and outputs for reactor DelayedReaction.
    // Connect DelayedReaction.source.out to input port DelayedReaction.delay.inp
    delayedreaction_delay_self->__inp = (__gendelay_197ef_inp_t*)&delayedreaction_source_self->__out;
    // Connect DelayedReaction.delay.out to input port DelayedReaction.sink.in
    delayedreaction_sink_self->__in = (sink_in_t*)&delayedreaction_delay_self->__out;
    // Connect inputs and outputs for reactor DelayedReaction.source.
    // END Connect inputs and outputs for reactor DelayedReaction.source.
    // Connect inputs and outputs for reactor DelayedReaction.sink.
    // END Connect inputs and outputs for reactor DelayedReaction.sink.
    // Connect inputs and outputs for reactor DelayedReaction.delay.
    // END Connect inputs and outputs for reactor DelayedReaction.delay.
    // END Connect inputs and outputs for reactor DelayedReaction.
    // Add action DelayedReaction.delay.act to array of is_present fields.
    __is_present_fields[0] 
            = &delayedreaction_delay_self->__act.is_present;
    // Add port DelayedReaction.source.out to array of is_present fields.
    __is_present_fields[1] = &delayedreaction_source_self->__out.is_present
    ;
    // Add port DelayedReaction.delay.out to array of is_present fields.
    __is_present_fields[2] = &delayedreaction_delay_self->__out.is_present
    ;
    delayedreaction_source_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayedreaction_source_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delayedreaction_sink_self->___reaction_0.chain_id = 4;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayedreaction_sink_self->___reaction_0.index = 0x7fffffffffff0001LL;
    delayedreaction_delay_self->___reaction_0.chain_id = 6;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayedreaction_delay_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delayedreaction_delay_self->___reaction_1.chain_id = 3;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    delayedreaction_delay_self->___reaction_1.index = 0x7fffffffffff0001LL;
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
