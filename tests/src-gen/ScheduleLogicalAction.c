#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/ScheduleLogicalAction.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class print
#line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
typedef struct {
#line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    int value;
#line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    bool is_present;
#line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    int num_destinations;
#line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
} print_x_t;
typedef struct {
    int bank_index;
    #line 21 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    interval_t expected_time;
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    print_x_t* __x;
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    // width of -2 indicates that it is not a multiport.
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    int __x__width;
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    // Default input (in case it does not get connected)
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    print_x_t __default__x;
    #line 23 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    reaction_t ___reaction_0;
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    trigger_t ___x;
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    reaction_t* ___x_reactions[1];
} print_self_t;
void printreaction_function_0(void* instance_args) {
    print_self_t* self = (print_self_t*)instance_args;
    print_x_t* x = self->__x;
    int x_width = self->__x__width;
    #line 24 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    interval_t elapsed_time = get_elapsed_logical_time();
    printf("Result is %d\n", x->value);
    printf("Current logical time is: %lld\n", elapsed_time);
    printf("Current physical time is: %lld\n", get_elapsed_physical_time());
    if (elapsed_time != self->expected_time) {
        printf("ERROR: Expected logical time to be %lld.\n", self->expected_time);
        exit(1);
    }
    self->expected_time += MSEC(500);
        
}
print_self_t* new_print() {
    print_self_t* self = (print_self_t*)calloc(1, sizeof(print_self_t));
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    // Set input by default to an always absent default input.
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->__x = &self->__default__x;
    #line 23 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.number = 0;
    #line 23 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.function = printreaction_function_0;
    #line 23 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.self = self;
    #line 23 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 23 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___x.last = NULL;
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___x_reactions[0] = &self->___reaction_0;
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___x.reactions = &self->___x_reactions[0];
    #line 22 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___x.number_of_reactions = 1;
    self->___x.element_size = sizeof(int);
    return self;
}
void delete_print(print_self_t* self) {
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
// =============== END reactor class print

// =============== START reactor class foo
#line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
typedef struct {
#line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    int value;
#line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    bool is_present;
#line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    int num_destinations;
#line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
} foo_x_t;
#line 9 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
typedef struct {
#line 9 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    int value;
#line 9 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    bool is_present;
#line 9 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    int num_destinations;
#line 9 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
} foo_y_t;
#line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
typedef struct {
#line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    trigger_t* trigger;
#line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    int* value;
#line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    bool is_present;
#line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    bool has_value;
#line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    lf_token_t* token;
#line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
} foo_a_t;
typedef struct {
    int bank_index;
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    foo_a_t __a;
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    foo_x_t* __x;
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    // width of -2 indicates that it is not a multiport.
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    int __x__width;
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    // Default input (in case it does not get connected)
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    foo_x_t __default__x;
    #line 9 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    foo_y_t __y;
    #line 9 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    int __y__width;
    #line 11 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    reaction_t ___reaction_0;
    #line 16 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    reaction_t ___reaction_1;
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    trigger_t ___a;
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    reaction_t* ___a_reactions[1];
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    trigger_t ___x;
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    reaction_t* ___x_reactions[1];
} foo_self_t;
void fooreaction_function_0(void* instance_args) {
    foo_self_t* self = (foo_self_t*)instance_args;
    foo_x_t* x = self->__x;
    int x_width = self->__x__width;
    foo_y_t* y = &self->__y;
    foo_a_t* a = &self->__a;
    #line 12 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    SET(y, 2*x->value);
    // The following uses physical time, incorrectly.
    schedule(a, MSEC(500));
        
}
void fooreaction_function_1(void* instance_args) {
    foo_self_t* self = (foo_self_t*)instance_args;
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    // Expose the action struct as a local variable whose name matches the action name.
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    foo_a_t* a = &self->__a;
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    // Set the fields of the action struct to match the current trigger.
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    a->is_present = self->___a.is_present;
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    a->has_value = ((self->___a.token) != NULL && (self->___a.token)->value != NULL);
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    a->token = (self->___a.token);
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    if (a->has_value) {
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
        a->value = (int*)(self->___a.token)->value;
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    }
    foo_y_t* y = &self->__y;
    #line 17 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    SET(y, -42);
        
}
foo_self_t* new_foo() {
    foo_self_t* self = (foo_self_t*)calloc(1, sizeof(foo_self_t));
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->__a.trigger = &self->___a;
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    // Set input by default to an always absent default input.
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->__x = &self->__default__x;
    #line 11 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.number = 0;
    #line 11 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.function = fooreaction_function_0;
    #line 11 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.self = self;
    #line 11 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 11 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 16 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_1.number = 1;
    #line 16 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_1.function = fooreaction_function_1;
    #line 16 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_1.self = self;
    #line 16 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_1.deadline_violation_handler = NULL;
    #line 16 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_1.tardy_handler = NULL;
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___a.last = NULL;
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___a_reactions[0] = &self->___reaction_1;
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___a.reactions = &self->___a_reactions[0];
    #line 10 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___a.number_of_reactions = 1;
    self->___a.is_physical = false;
    self->___a.element_size = sizeof(int);
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___x.last = NULL;
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___x_reactions[0] = &self->___reaction_0;
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___x.reactions = &self->___x_reactions[0];
    #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___x.number_of_reactions = 1;
    self->___x.element_size = sizeof(int);
    return self;
}
void delete_foo(foo_self_t* self) {
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
// =============== END reactor class foo

// =============== START reactor class top
typedef struct {
    int bank_index;
    struct {
        #line 8 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
        foo_x_t x;
    } __f;
    #line 39 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    reaction_t ___reaction_0;
    #line 38 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    trigger_t ___t;
    #line 38 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    reaction_t* ___t_reactions[1];
} top_self_t;
void topreaction_function_0(void* instance_args) {
    struct f{
        foo_x_t* x;
    } f;
    top_self_t* self = (top_self_t*)instance_args;
    f.x = &(self->__f.x);
    #line 40 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    SET(f.x, 42);
        
}
top_self_t* new_top() {
    top_self_t* self = (top_self_t*)calloc(1, sizeof(top_self_t));
    #line 39 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.number = 0;
    #line 39 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.function = topreaction_function_0;
    #line 39 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.self = self;
    #line 39 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 39 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 38 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___t.last = NULL;
    #line 38 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    #line 38 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___t_reactions[0] = &self->___reaction_0;
    #line 38 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___t.reactions = &self->___t_reactions[0];
    #line 38 "file:/lf-flexpret-scripts/tests/ScheduleLogicalAction.lf"
    self->___t.number_of_reactions = 1;
    self->___t.is_timer = true;
    return self;
}
void delete_top(top_self_t* self) {
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
// =============== END reactor class top

char* __default_argv[] = {"X", "-f", "true", "-o", "3", "sec"};
void __set_default_command_line_options() {
    default_argc = 6;
    default_argv = __default_argv;
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
    // ************* Instance top of class top
    top_self_t* top_self = new_top();
    //***** Start initializing top
    top_self->___t.offset = 0;
    top_self->___t.period = SEC(1);
    __timer_triggers[0] = &top_self->___t;
    // ************* Instance top.f of class foo
    foo_self_t* top_f_self = new_foo();
    //***** Start initializing top.f
    // width of -2 indicates that it is not a multiport.
    top_f_self->__y__width = -2;
    // width of -2 indicates that it is not a multiport.
    top_f_self->__x__width = -2;
    top_f_self->___a.offset = 0;
    top_f_self->___a.period = -1;
    top_f_self->___a.token = __create_token(sizeof(int));
    top_f_self->___a.is_present = false;
    __tokens_with_ref_count[0].token
            = &top_f_self->___a.token;
    __tokens_with_ref_count[0].is_present
            = &top_f_self->___a.is_present;
    __tokens_with_ref_count[0].reset_is_present = true;
    //***** End initializing top.f
    // ************* Instance top.p of class print
    print_self_t* top_p_self = new_print();
    //***** Start initializing top.p
    // width of -2 indicates that it is not a multiport.
    top_p_self->__x__width = -2;
    top_p_self->expected_time = 0;
    //***** End initializing top.p
    //***** End initializing top
    // Populate arrays of trigger pointers.
    top_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    top_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (top_self->___reaction_0.num_outputs > 0) {
        top_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * top_self->___reaction_0.num_outputs);
        top_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * top_self->___reaction_0.num_outputs);
        top_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * top_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    top_self->___reaction_0.output_produced[0]
    = &top_self->__f.x.is_present
    ;
    // Reaction 0 of top does not depend on one maximal upstream reaction.
    top_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of top triggers 1 downstream reactions through port top.f.x.
    top_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of top, allocate an
    // array of trigger pointers for downstream reactions through port top.f.x
    trigger_t** top_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    top_self->___reaction_0.triggers[0] = top_0_0;
    // Point to destination port top.f.x's trigger struct.
    top_0_0[0] = &top_f_self->___x;
    top_self->__f.x.
    num_destinations = 1;
    top_f_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    top_f_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (top_f_self->___reaction_0.num_outputs > 0) {
        top_f_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * top_f_self->___reaction_0.num_outputs);
        top_f_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * top_f_self->___reaction_0.num_outputs);
        top_f_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * top_f_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    top_f_self->___reaction_0.output_produced[0]
    = &top_f_self->__y.is_present
    ;
    // Total number of outputs produced by the reaction.
    top_f_self->___reaction_1.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (top_f_self->___reaction_1.num_outputs > 0) {
        top_f_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * top_f_self->___reaction_1.num_outputs);
        top_f_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * top_f_self->___reaction_1.num_outputs);
        top_f_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * top_f_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    top_f_self->___reaction_1.output_produced[0]
    = &top_f_self->__y.is_present
    ;
    // Reaction 0 of top.f depends on one maximal upstream reaction.
    top_f_self->___reaction_0.last_enabling_reaction = &(top_self->___reaction_0);
    // Reaction 0 of top.f triggers 1 downstream reactions through port top.f.y.
    top_f_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of top.f, allocate an
    // array of trigger pointers for downstream reactions through port top.f.y
    trigger_t** top_f_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    top_f_self->___reaction_0.triggers[0] = top_f_0_0;
    // Point to destination port top.p.x's trigger struct.
    top_f_0_0[0] = &top_p_self->___x;
    // Reaction 1 of top.f depends on one maximal upstream reaction.
    top_f_self->___reaction_1.last_enabling_reaction = &(top_f_self->___reaction_0);
    // Reaction 1 of top.f triggers 1 downstream reactions through port top.f.y.
    top_f_self->___reaction_1.triggered_sizes[0] = 1;
    // For reaction 1 of top.f, allocate an
    // array of trigger pointers for downstream reactions through port top.f.y
    trigger_t** top_f_1_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    top_f_self->___reaction_1.triggers[0] = top_f_1_0;
    // Point to destination port top.p.x's trigger struct.
    top_f_1_0[0] = &top_p_self->___x;
    top_f_self->__y.num_destinations
    = 1;
    top_p_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    top_p_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (top_p_self->___reaction_0.num_outputs > 0) {
        top_p_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * top_p_self->___reaction_0.num_outputs);
        top_p_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * top_p_self->___reaction_0.num_outputs);
        top_p_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * top_p_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of top.p depends on one maximal upstream reaction.
    top_p_self->___reaction_0.last_enabling_reaction = &(top_f_self->___reaction_1);
    // doDeferredInitialize
    // Connect inputs and outputs for reactor top.
    // Connect top.f.y to input port top.p.x
    top_p_self->__x = (print_x_t*)&top_f_self->__y;
    // Connect inputs and outputs for reactor top.f.
    // END Connect inputs and outputs for reactor top.f.
    // Connect inputs and outputs for reactor top.p.
    // END Connect inputs and outputs for reactor top.p.
    // Connect PortInstance top.f.x, which gets data from reaction 0
    // of top, to top.f.x.
    top_f_self->__x = (foo_x_t*)&top_self->__f.x;
    // END Connect inputs and outputs for reactor top.
    // Add action top.f.a to array of is_present fields.
    __is_present_fields[0] 
            = &top_f_self->__a.is_present;
    // Add port top.f.x to array of is_present fields.
    __is_present_fields[1] 
            = &top_self->__f.x.
            is_present;
    // Add port top.f.y to array of is_present fields.
    __is_present_fields[2] = &top_f_self->__y.is_present
    ;
    top_self->___reaction_0.chain_id = 3;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    top_self->___reaction_0.index = 0x7fffffffffff0000LL;
    top_f_self->___reaction_0.chain_id = 3;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    top_f_self->___reaction_0.index = 0x7fffffffffff0001LL;
    top_f_self->___reaction_1.chain_id = 1;
    // index is the OR of level 2 and 
    // deadline 140737488355327 shifted left 16 bits.
    top_f_self->___reaction_1.index = 0x7fffffffffff0002LL;
    top_p_self->___reaction_0.chain_id = 3;
    // index is the OR of level 3 and 
    // deadline 140737488355327 shifted left 16 bits.
    top_p_self->___reaction_0.index = 0x7fffffffffff0003LL;
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
