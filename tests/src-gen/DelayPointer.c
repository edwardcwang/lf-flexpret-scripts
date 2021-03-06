#include "ctarget.h"
// Code generated by the Lingua Franca compiler from file:
// /lf-flexpret-scripts/tests/DelayPointer.lf
#define NUMBER_OF_FEDERATES 1
#include "core/reactor.c"
// =============== START reactor class Test
#line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
typedef struct {
#line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int* value;
#line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    bool is_present;
#line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int num_destinations;
#line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    lf_token_t* token;
#line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int length;
#line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
} test_in_t;
typedef struct {
    int bank_index;
    #line 27 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    interval_t start_time;
    #line 28 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    bool received_value;
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    test_in_t* __in;
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // width of -2 indicates that it is not a multiport.
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int __in__width;
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // Default input (in case it does not get connected)
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    test_in_t __default__in;
    #line 29 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    reaction_t ___reaction_0;
    #line 33 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    reaction_t ___reaction_1;
    #line 49 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    reaction_t ___reaction_2;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
    trigger_t ___shutdown;
    reaction_t* ___shutdown_reactions[1];
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    trigger_t ___in;
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    reaction_t* ___in_reactions[1];
} test_self_t;
void testreaction_function_0(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    #line 30 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // Record the logical time at the start.
    self->start_time = get_logical_time();
        
}
void testreaction_function_1(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    test_in_t* in = self->__in;
    if (in->is_present) {
        in->length = in->token->length;
        in->value = (int*)in->token->value;
    } else {
        in->length = 0;
    }
    int in_width = self->__in__width;
    #line 34 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    printf("Received: %d.\n", *(in->value));
    self->received_value = true;
    // Check the time of the input.
    instant_t current_time = get_logical_time();
    interval_t elapsed = current_time - self->start_time;
    printf("After %lld nsec of logical time.\n", elapsed);
    if (elapsed != 100000000LL) {
        printf("ERROR: Expected elapsed time to be 100000000. It was %lld.\n", elapsed);
        exit(1);
    }
    if (*(in->value) != 42) {
        printf("ERROR: Expected input value to be 42. It was %d.\n", *(in->value));
        exit(2);            
    }
        
}
void testreaction_function_2(void* instance_args) {
    test_self_t* self = (test_self_t*)instance_args;
    #line 50 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    printf("Checking that communication occurred.\n");
    if (!self->received_value) {
        printf("ERROR: No communication occurred!\n");
        exit(3);            
    }
        
}
test_self_t* new_Test() {
    test_self_t* self = (test_self_t*)calloc(1, sizeof(test_self_t));
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // Set input by default to an always absent default input.
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->__in = &self->__default__in;
    #line 29 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.number = 0;
    #line 29 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.function = testreaction_function_0;
    #line 29 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.self = self;
    #line 29 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 29 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 33 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_1.number = 1;
    #line 33 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_1.function = testreaction_function_1;
    #line 33 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_1.self = self;
    #line 33 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_1.deadline_violation_handler = NULL;
    #line 33 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_1.tardy_handler = NULL;
    #line 49 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_2.number = 2;
    #line 49 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_2.function = testreaction_function_2;
    #line 49 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_2.self = self;
    #line 49 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_2.deadline_violation_handler = NULL;
    #line 49 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_2.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
    self->___shutdown_reactions[0] = &self->___reaction_2;
    self->___shutdown.last = NULL;
    self->___shutdown.reactions = &self->___shutdown_reactions[0];
    self->___shutdown.number_of_reactions = 1;
    self->___shutdown.is_timer = false;
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___in.last = NULL;
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___in_reactions[0] = &self->___reaction_1;
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 26 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
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
    if (self->___reaction_1.output_produced != NULL) {
        free(self->___reaction_1.output_produced);
    }
    if (self->___reaction_1.triggers != NULL) {
        free(self->___reaction_1.triggers);
    }
    if (self->___reaction_1.triggered_sizes != NULL) {
        free(self->___reaction_1.triggered_sizes);
    }
    if (self->___reaction_2.output_produced != NULL) {
        free(self->___reaction_2.output_produced);
    }
    if (self->___reaction_2.triggers != NULL) {
        free(self->___reaction_2.triggers);
    }
    if (self->___reaction_2.triggered_sizes != NULL) {
        free(self->___reaction_2.triggered_sizes);
    }
    for(int i = 0; i < self->___reaction_0.num_outputs; i++) {
        free(self->___reaction_0.triggers[i]);
    }
    for(int i = 0; i < self->___reaction_1.num_outputs; i++) {
        free(self->___reaction_1.triggers[i]);
    }
    for(int i = 0; i < self->___reaction_2.num_outputs; i++) {
        free(self->___reaction_2.triggers[i]);
    }
    free(self);
}
// =============== END reactor class Test

// =============== START reactor class DelayPointer
#line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
typedef struct {
#line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int* value;
#line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    bool is_present;
#line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int num_destinations;
#line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    lf_token_t* token;
#line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int length;
#line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
} delaypointer_in_t;
#line 5 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
typedef struct {
#line 5 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int* value;
#line 5 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    bool is_present;
#line 5 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int num_destinations;
#line 5 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    lf_token_t* token;
#line 5 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int length;
#line 5 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
} delaypointer_out_t;
#line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
typedef struct {
#line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    trigger_t* trigger;
#line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int* value;
#line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    bool is_present;
#line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    bool has_value;
#line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    lf_token_t* token;
#line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
} delaypointer_a_t;
typedef struct {
    int bank_index;
    #line 3 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    interval_t delay;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    delaypointer_a_t __a;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    delaypointer_in_t* __in;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // width of -2 indicates that it is not a multiport.
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int __in__width;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // Default input (in case it does not get connected)
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    delaypointer_in_t __default__in;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    delaypointer_out_t __out;
    #line 5 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int __out__width;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    reaction_t ___reaction_0;
    #line 12 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    reaction_t ___reaction_1;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    trigger_t ___a;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    reaction_t* ___a_reactions[1];
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    trigger_t ___in;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    reaction_t* ___in_reactions[1];
} delaypointer_self_t;
void delaypointerreaction_function_0(void* instance_args) {
    delaypointer_self_t* self = (delaypointer_self_t*)instance_args;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // Expose the action struct as a local variable whose name matches the action name.
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    delaypointer_a_t* a = &self->__a;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // Set the fields of the action struct to match the current trigger.
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    a->is_present = self->___a.is_present;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    a->has_value = ((self->___a.token) != NULL && (self->___a.token)->value != NULL);
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    a->token = (self->___a.token);
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    if (a->has_value) {
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
        a->value = (int*)(self->___a.token)->value;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    }
    delaypointer_out_t* out = &self->__out;
    #line 8 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // Using SET_TOKEN delegates responsibility for
    // freeing the allocated memory downstream.
    SET_TOKEN(out, a->token);
        
}
void delaypointerreaction_function_1(void* instance_args) {
    delaypointer_self_t* self = (delaypointer_self_t*)instance_args;
    delaypointer_in_t* in = self->__in;
    if (in->is_present) {
        in->length = in->token->length;
        in->value = (int*)in->token->value;
    } else {
        in->length = 0;
    }
    int in_width = self->__in__width;
    delaypointer_a_t* a = &self->__a;
    #line 13 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // Schedule the actual token from the input rather than
    // a new token with a copy of the input value.
    schedule_token(a, self->delay, in->token);
        
}
delaypointer_self_t* new_DelayPointer() {
    delaypointer_self_t* self = (delaypointer_self_t*)calloc(1, sizeof(delaypointer_self_t));
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->__a.trigger = &self->___a;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    // Set input by default to an always absent default input.
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->__in = &self->__default__in;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.number = 0;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.function = delaypointerreaction_function_0;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.self = self;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 7 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.tardy_handler = NULL;
    #line 12 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_1.number = 1;
    #line 12 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_1.function = delaypointerreaction_function_1;
    #line 12 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_1.self = self;
    #line 12 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_1.deadline_violation_handler = NULL;
    #line 12 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_1.tardy_handler = NULL;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___a.last = NULL;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___a_reactions[0] = &self->___reaction_0;
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___a.reactions = &self->___a_reactions[0];
    #line 6 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___a.number_of_reactions = 1;
    self->___a.is_physical = false;
    self->___a.element_size = sizeof(int);
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___in.last = NULL;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___in_reactions[0] = &self->___reaction_1;
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___in.reactions = &self->___in_reactions[0];
    #line 4 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___in.number_of_reactions = 1;
    self->___in.element_size = sizeof(int);
    return self;
}
void delete_DelayPointer(delaypointer_self_t* self) {
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
// =============== END reactor class DelayPointer

// =============== START reactor class Source
#line 19 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
typedef struct {
#line 19 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int* value;
#line 19 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    bool is_present;
#line 19 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int num_destinations;
#line 19 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    lf_token_t* token;
#line 19 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int length;
#line 19 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
} source_out_t;
typedef struct {
    int bank_index;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    source_out_t __out;
    #line 19 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    int __out__width;
    #line 20 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    reaction_t ___reaction_0;
    trigger_t ___startup;
    reaction_t* ___startup_reactions[1];
} source_self_t;
void sourcereaction_function_0(void* instance_args) {
    source_self_t* self = (source_self_t*)instance_args;
    source_out_t* out = &self->__out;
    #line 21 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    SET_NEW(out);
    *(out->value) = 42;
        
}
source_self_t* new_Source() {
    source_self_t* self = (source_self_t*)calloc(1, sizeof(source_self_t));
    #line 20 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.number = 0;
    #line 20 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.function = sourcereaction_function_0;
    #line 20 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.self = self;
    #line 20 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.deadline_violation_handler = NULL;
    #line 20 "file:/lf-flexpret-scripts/tests/DelayPointer.lf"
    self->___reaction_0.tardy_handler = NULL;
    self->___startup_reactions[0] = &self->___reaction_0;
    self->___startup.last = NULL;
    self->___startup.reactions = &self->___startup_reactions[0];
    self->___startup.number_of_reactions = 1;
    self->___startup.is_timer = false;
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

// =============== START reactor class DelayPointerTest
typedef struct {
    int bank_index;
} delaypointertest_self_t;
delaypointertest_self_t* new_DelayPointerTest() {
    delaypointertest_self_t* self = (delaypointertest_self_t*)calloc(1, sizeof(delaypointertest_self_t));
    return self;
}
void delete_DelayPointerTest(delaypointertest_self_t* self) {
    free(self);
}
// =============== END reactor class DelayPointerTest

void __set_default_command_line_options() {
}
// Array of pointers to timer triggers to be scheduled in __initialize_timers().
trigger_t** __timer_triggers = NULL;
int __timer_triggers_size = 0;
// Array of pointers to timer triggers to be scheduled in __trigger_startup_reactions().
reaction_t* __startup_reactions[2];
int __startup_reactions_size = 2;
// Array of pointers to shutdown triggers.
reaction_t* __shutdown_reactions[1];
int __shutdown_reactions_size = 1;
trigger_t* __action_for_port(int port_id) {
    return NULL;
}
void __initialize_trigger_objects() {
    __tokens_with_ref_count_size = 3;
    __tokens_with_ref_count = (token_present_t*)malloc(3 * sizeof(token_present_t));
    // Create the array that will contain pointers to is_present fields to reset on each step.
    __is_present_fields_size = 3;
    __is_present_fields = (bool**)malloc(3 * sizeof(bool*));
    // ************* Instance DelayPointerTest of class DelayPointerTest
    delaypointertest_self_t* delaypointertest_self = new_DelayPointerTest();
    //***** Start initializing DelayPointerTest
    // ************* Instance DelayPointerTest.s of class Source
    source_self_t* delaypointertest_s_self = new_Source();
    //***** Start initializing DelayPointerTest.s
    // width of -2 indicates that it is not a multiport.
    delaypointertest_s_self->__out__width = -2;
    __startup_reactions[0] = &delaypointertest_s_self->___reaction_0;
    //***** End initializing DelayPointerTest.s
    // ************* Instance DelayPointerTest.d of class DelayPointer
    delaypointer_self_t* delaypointertest_d_self = new_DelayPointer();
    //***** Start initializing DelayPointerTest.d
    delaypointertest_d_self->delay = MSEC(100); 
    // width of -2 indicates that it is not a multiport.
    delaypointertest_d_self->__out__width = -2;
    // width of -2 indicates that it is not a multiport.
    delaypointertest_d_self->__in__width = -2;
    delaypointertest_d_self->___a.offset = 0;
    delaypointertest_d_self->___a.period = -1;
    delaypointertest_d_self->___a.token = __create_token(sizeof(int));
    delaypointertest_d_self->___a.is_present = false;
    __tokens_with_ref_count[0].token
            = &delaypointertest_d_self->___a.token;
    __tokens_with_ref_count[0].is_present
            = &delaypointertest_d_self->___a.is_present;
    __tokens_with_ref_count[0].reset_is_present = true;
    //***** End initializing DelayPointerTest.d
    // ************* Instance DelayPointerTest.t of class Test
    test_self_t* delaypointertest_t_self = new_Test();
    //***** Start initializing DelayPointerTest.t
    __startup_reactions[1] = &delaypointertest_t_self->___reaction_0;
    __shutdown_reactions[0] = &delaypointertest_t_self->___reaction_2;
    // width of -2 indicates that it is not a multiport.
    delaypointertest_t_self->__in__width = -2;
    delaypointertest_t_self->start_time = 0;
    static bool delaypointertest_t_initial_received_value = false;
    delaypointertest_t_self->received_value = delaypointertest_t_initial_received_value;
    //***** End initializing DelayPointerTest.t
    //***** End initializing DelayPointerTest
    // Populate arrays of trigger pointers.
    delaypointertest_self->bank_index = 0;
    delaypointertest_s_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delaypointertest_s_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (delaypointertest_s_self->___reaction_0.num_outputs > 0) {
        delaypointertest_s_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delaypointertest_s_self->___reaction_0.num_outputs);
        delaypointertest_s_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delaypointertest_s_self->___reaction_0.num_outputs);
        delaypointertest_s_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delaypointertest_s_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    delaypointertest_s_self->___reaction_0.output_produced[0]
    = &delaypointertest_s_self->__out.is_present
    ;
    // Reaction 0 of DelayPointerTest.s does not depend on one maximal upstream reaction.
    delaypointertest_s_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of DelayPointerTest.s triggers 1 downstream reactions through port DelayPointerTest.s.out.
    delaypointertest_s_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of DelayPointerTest.s, allocate an
    // array of trigger pointers for downstream reactions through port DelayPointerTest.s.out
    trigger_t** delaypointertest_s_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delaypointertest_s_self->___reaction_0.triggers[0] = delaypointertest_s_0_0;
    // Point to destination port DelayPointerTest.d.in's trigger struct.
    delaypointertest_s_0_0[0] = &delaypointertest_d_self->___in;
    delaypointertest_s_self->__out.num_destinations
    = 1;
    delaypointertest_d_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delaypointertest_d_self->___reaction_0.num_outputs = 1;
    // Allocate arrays for triggering downstream reactions.
    if (delaypointertest_d_self->___reaction_0.num_outputs > 0) {
        delaypointertest_d_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delaypointertest_d_self->___reaction_0.num_outputs);
        delaypointertest_d_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delaypointertest_d_self->___reaction_0.num_outputs);
        delaypointertest_d_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delaypointertest_d_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    delaypointertest_d_self->___reaction_0.output_produced[0]
    = &delaypointertest_d_self->__out.is_present
    ;
    // Total number of outputs produced by the reaction.
    delaypointertest_d_self->___reaction_1.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delaypointertest_d_self->___reaction_1.num_outputs > 0) {
        delaypointertest_d_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * delaypointertest_d_self->___reaction_1.num_outputs);
        delaypointertest_d_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delaypointertest_d_self->___reaction_1.num_outputs);
        delaypointertest_d_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * delaypointertest_d_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of DelayPointerTest.d does not depend on one maximal upstream reaction.
    delaypointertest_d_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 0 of DelayPointerTest.d triggers 1 downstream reactions through port DelayPointerTest.d.out.
    delaypointertest_d_self->___reaction_0.triggered_sizes[0] = 1;
    // For reaction 0 of DelayPointerTest.d, allocate an
    // array of trigger pointers for downstream reactions through port DelayPointerTest.d.out
    trigger_t** delaypointertest_d_0_0 = (trigger_t**)malloc(1 * sizeof(trigger_t*));
    delaypointertest_d_self->___reaction_0.triggers[0] = delaypointertest_d_0_0;
    // Point to destination port DelayPointerTest.t.in's trigger struct.
    delaypointertest_d_0_0[0] = &delaypointertest_t_self->___in;
    // Reaction 1 of DelayPointerTest.d does not depend on one maximal upstream reaction.
    delaypointertest_d_self->___reaction_1.last_enabling_reaction = NULL;
    delaypointertest_d_self->__out.num_destinations
    = 1;
    delaypointertest_t_self->bank_index = 0;
    // Total number of outputs produced by the reaction.
    delaypointertest_t_self->___reaction_0.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delaypointertest_t_self->___reaction_0.num_outputs > 0) {
        delaypointertest_t_self->___reaction_0.output_produced = (bool**)malloc(sizeof(bool*) * delaypointertest_t_self->___reaction_0.num_outputs);
        delaypointertest_t_self->___reaction_0.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delaypointertest_t_self->___reaction_0.num_outputs);
        delaypointertest_t_self->___reaction_0.triggered_sizes = (int*)malloc(sizeof(int) * delaypointertest_t_self->___reaction_0.num_outputs);
    }
    // Initialize the output_produced array.
    // Total number of outputs produced by the reaction.
    delaypointertest_t_self->___reaction_1.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delaypointertest_t_self->___reaction_1.num_outputs > 0) {
        delaypointertest_t_self->___reaction_1.output_produced = (bool**)malloc(sizeof(bool*) * delaypointertest_t_self->___reaction_1.num_outputs);
        delaypointertest_t_self->___reaction_1.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delaypointertest_t_self->___reaction_1.num_outputs);
        delaypointertest_t_self->___reaction_1.triggered_sizes = (int*)malloc(sizeof(int) * delaypointertest_t_self->___reaction_1.num_outputs);
    }
    // Initialize the output_produced array.
    // Total number of outputs produced by the reaction.
    delaypointertest_t_self->___reaction_2.num_outputs = 0;
    // Allocate arrays for triggering downstream reactions.
    if (delaypointertest_t_self->___reaction_2.num_outputs > 0) {
        delaypointertest_t_self->___reaction_2.output_produced = (bool**)malloc(sizeof(bool*) * delaypointertest_t_self->___reaction_2.num_outputs);
        delaypointertest_t_self->___reaction_2.triggers = (trigger_t***)malloc(sizeof(trigger_t**) * delaypointertest_t_self->___reaction_2.num_outputs);
        delaypointertest_t_self->___reaction_2.triggered_sizes = (int*)malloc(sizeof(int) * delaypointertest_t_self->___reaction_2.num_outputs);
    }
    // Initialize the output_produced array.
    // Reaction 0 of DelayPointerTest.t does not depend on one maximal upstream reaction.
    delaypointertest_t_self->___reaction_0.last_enabling_reaction = NULL;
    // Reaction 1 of DelayPointerTest.t does not depend on one maximal upstream reaction.
    delaypointertest_t_self->___reaction_1.last_enabling_reaction = NULL;
    // Reaction 2 of DelayPointerTest.t depends on one maximal upstream reaction.
    delaypointertest_t_self->___reaction_2.last_enabling_reaction = &(delaypointertest_t_self->___reaction_1);
    // doDeferredInitialize
    delaypointertest_s_self->__out.token = __create_token(sizeof(int));
    delaypointertest_d_self->__out.token = __create_token(sizeof(int));
    // Connect inputs and outputs for reactor DelayPointerTest.
    // Connect DelayPointerTest.s.out to input port DelayPointerTest.d.in
    delaypointertest_d_self->__in = (delaypointer_in_t*)&delaypointertest_s_self->__out;
    // Connect DelayPointerTest.d.out to input port DelayPointerTest.t.in
    delaypointertest_t_self->__in = (test_in_t*)&delaypointertest_d_self->__out;
    // Connect inputs and outputs for reactor DelayPointerTest.s.
    // END Connect inputs and outputs for reactor DelayPointerTest.s.
    // Connect inputs and outputs for reactor DelayPointerTest.d.
    // END Connect inputs and outputs for reactor DelayPointerTest.d.
    // Connect inputs and outputs for reactor DelayPointerTest.t.
    // END Connect inputs and outputs for reactor DelayPointerTest.t.
    // END Connect inputs and outputs for reactor DelayPointerTest.
    // Add action DelayPointerTest.d.a to array of is_present fields.
    __is_present_fields[0] 
            = &delaypointertest_d_self->__a.is_present;
    __tokens_with_ref_count[1].token
            = &delaypointertest_d_self->__in->token;
    __tokens_with_ref_count[1].is_present
            = &delaypointertest_d_self->__in->is_present;
    __tokens_with_ref_count[1].reset_is_present = false;
    __tokens_with_ref_count[2].token
            = &delaypointertest_t_self->__in->token;
    __tokens_with_ref_count[2].is_present
            = &delaypointertest_t_self->__in->is_present;
    __tokens_with_ref_count[2].reset_is_present = false;
    // Add port DelayPointerTest.s.out to array of is_present fields.
    __is_present_fields[1] = &delaypointertest_s_self->__out.is_present
    ;
    // Add port DelayPointerTest.d.out to array of is_present fields.
    __is_present_fields[2] = &delaypointertest_d_self->__out.is_present
    ;
    delaypointertest_s_self->___reaction_0.chain_id = 4;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delaypointertest_s_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delaypointertest_d_self->___reaction_0.chain_id = 9;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delaypointertest_d_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delaypointertest_d_self->___reaction_1.chain_id = 12;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    delaypointertest_d_self->___reaction_1.index = 0x7fffffffffff0001LL;
    delaypointertest_t_self->___reaction_0.chain_id = 2;
    // index is the OR of level 0 and 
    // deadline 140737488355327 shifted left 16 bits.
    delaypointertest_t_self->___reaction_0.index = 0x7fffffffffff0000LL;
    delaypointertest_t_self->___reaction_1.chain_id = 3;
    // index is the OR of level 1 and 
    // deadline 140737488355327 shifted left 16 bits.
    delaypointertest_t_self->___reaction_1.index = 0x7fffffffffff0001LL;
    delaypointertest_t_self->___reaction_2.chain_id = 3;
    // index is the OR of level 2 and 
    // deadline 140737488355327 shifted left 16 bits.
    delaypointertest_t_self->___reaction_2.index = 0x7fffffffffff0002LL;
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
