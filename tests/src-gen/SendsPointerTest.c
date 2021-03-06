#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/SendsPointerTest.lf
typedef int* int_pointer;
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Print
#line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
typedef struct {
#line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    int_pointer value;
#line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    bool is_present;
#line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    int num_destinations;
#line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
} print_in_t;
typedef struct {
    int bank_index;
    #line 15 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    int expected;
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    print_in_t* __in;
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    // width of -2 indicates that it is not a multiport.
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    int __in__width;
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    // Default input (in case it does not get connected)
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    print_in_t __default__in;
    #line 17 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    reaction_t ___reaction_0;
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    trigger_t ___in;
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    reaction_t* ___in_reactions[1];
} print_self_t;
void printreaction_function_0(void* instance_args) {
    print_self_t* self = (print_self_t*)instance_args;
    print_in_t* in = self->__in;
    int in_width = self->__in__width;
    #line 18 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    printf("Received: %d\n", *in->value);
    if (*in->value != self->expected) {
        printf("ERROR: Expected value to be %d.\n", self->expected);
        exit(1);
    }
        
}
print_self_t* new_Print() {
    print_self_t* self = (print_self_t*)calloc(1, sizeof(print_self_t));
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    // Set input by default to an always absent default input.
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->__in = &self->__default__in;
    #line 17 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___reaction_0.number = 0;
    #line 17 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___reaction_0.function = printreaction_function_0;
    #line 17 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___reaction_0.self = self;
    #line 17 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 17 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___in.last = NULL;
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___in_reactions[0] = &self->___reaction_0;
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 16 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(int_pointer);
    return self;
}
void delete_Print(print_self_t* self) {
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
// =============== END reactor class Print

// =============== START reactor class SendsPointer
#line 8 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
typedef struct {
#line 8 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    int_pointer value;
#line 8 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    bool is_present;
#line 8 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    int num_destinations;
#line 8 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
} sendspointer_out_t;
typedef struct {
    int bank_index;
    #line 8 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    sendspointer_out_t __out;
    #line 8 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    int __out__width;
    #line 9 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    reaction_t ___reaction_0;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} sendspointer_self_t;
void sendspointerreaction_function_0(void* instance_args) {
    sendspointer_self_t* self = (sendspointer_self_t*)instance_args;
    sendspointer_out_t* out = &self->__out;
    #line 10 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    static int my_constant = 42;
    SET(out, &my_constant);
        
}
sendspointer_self_t* new_SendsPointer() {
    sendspointer_self_t* self = (sendspointer_self_t*)calloc(1, sizeof(sendspointer_self_t));
    #line 9 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___reaction_0.number = 0;
    #line 9 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___reaction_0.function = sendspointerreaction_function_0;
    #line 9 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___reaction_0.self = self;
    #line 9 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 9 "file:/lf-flexpret-scripts/tests/SendsPointerTest.lf"
    self->___reaction_0.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
    return self;
}
void delete_SendsPointer(sendspointer_self_t* self) {
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
// =============== END reactor class SendsPointer

// =============== START reactor class SendsPointerTest
typedef struct {
    int bank_index;
} sendspointertest_self_t;
sendspointertest_self_t* new_SendsPointerTest() {
    sendspointertest_self_t* self = (sendspointertest_self_t*)calloc(1, sizeof(sendspointertest_self_t));
    return self;
}
void delete_SendsPointerTest(sendspointertest_self_t* self) {
    free(self);
}
// =============== END reactor class SendsPointerTest

void __set_default_command_line_options() {
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
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 1;
    __is_present_fields = (bool**)malloc(1 * sizeof(bool*));
    // ************* Instance SendsPointerTest of class SendsPointerTest
    sendspointertest_self_t* sendspointertest_self = new_SendsPointerTest();
    //***** Start initializing SendsPointerTest
    // ************* Instance SendsPointerTest.s of class SendsPointer
    sendspointer_self_t* sendspointertest_s_self = new_SendsPointer();
    //***** Start initializing SendsPointerTest.s
    // width of -2 indicates that it is not a multiport.
    sendspointertest_s_self->__out__width = -2;
    __startup_reactions[0] = &sendspointertest_s_self->___reaction_0;
    //***** End initializing SendsPointerTest.s
    // ************* Instance SendsPointerTest.p of class Print
    print_self_t* sendspointertest_p_self = new_Print();
    //***** Start initializing SendsPointerTest.p
    sendspointertest_p_self->expected = 42; 
    // width of -2 indicates that it is not a multiport.
    sendspointertest_p_self->__in__width = -2;
    //***** End initializing SendsPointerTest.p
    //***** End initializing SendsPointerTest
    // Populate arrays of trigger pointers.
    sendspointertest_self->bank_index = 0;
    sendspointertest_s_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    sendspointertest_s_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (sendspointertest_s_self->___reaction_0.num_outputs > 0) {
        sendspointertest_s_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * sendspointertest_s_self->___reaction_0.num_outputs);
        sendspointertest_s_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * sendspointertest_s_self->___reaction_0.num_outputs);
        sendspointertest_s_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * sendspointertest_s_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    sendspointertest_s_self->___reaction_0.output_produced[0]
    = &sendspointertest_s_self->__out.is_present
    ;
    // Reaction 0 of SendsPointerTest.s does not depend on one maximal upstream reaction.
    sendspointertest_s_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of SendsPointerTest.s triggers 1 downstream reactions through port SendsPointerTest.s.out.
    sendspointertest_s_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of SendsPointerTest.s, allocate an
    // array of trigger pointers for downstream reactions through port SendsPointerTest.s.out
    trigger_t** sendspointertest_s_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    sendspointertest_s_self->___reaction_0.triggers[0] = sendspointertest_s_0_0;
    // Point to destination port SendsPointerTest.p.in's trigger struct.
    sendspointertest_s_0_0[0] = &sendspointertest_p_self->___in;
    sendspointertest_s_self->__out.num_destinations
    = 1;
    sendspointertest_p_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    sendspointertest_p_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (sendspointertest_p_self->___reaction_0.num_outputs > 0) {
        sendspointertest_p_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * sendspointertest_p_self->___reaction_0.num_outputs);
        sendspointertest_p_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * sendspointertest_p_self->___reaction_0.num_outputs);
        sendspointertest_p_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * sendspointertest_p_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of SendsPointerTest.p depends on one maximal upstream reaction.
    sendspointertest_p_self->___reaction_0.last_enabling_reaction = &(sendspointertest_s_self->___reaction_0);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor SendsPointerTest.
    // Connect SendsPointerTest.s.out to input port SendsPointerTest.p.in
    sendspointertest_p_self->__in = (print_in_t*)&sendspointertest_s_self->__out;
    // Connect inputs and outputs for reactor SendsPointerTest.s.
    // END Connect inputs and outputs for reactor SendsPointerTest.s.
    // Connect inputs and outputs for reactor SendsPointerTest.p.
    // END Connect inputs and outputs for reactor SendsPointerTest.p.
    // END Connect inputs and outputs for reactor SendsPointerTest.
    // Add port SendsPointerTest.s.out to array of is_present fields.
    __is_present_fields[0] = &sendspointertest_s_self->__out.is_present
    ;
    sendspointertest_s_self->___reaction_0.chain_id = 1;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    sendspointertest_s_self->___reaction_0.index = 0x7fffffffffff0000LL;
    sendspointertest_p_self->___reaction_0.chain_id = 1;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    sendspointertest_p_self->___reaction_0.index = 0x7fffffffffff0001LL;
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
