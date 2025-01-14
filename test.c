#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int data;
    struct s_stack *next;
} t_stack;

// Helper function to create a new node
t_stack *create_node(int value) {
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return NULL;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Helper function to print the stack
void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d -> ", stack->data);
        stack = stack->next;
    }
    printf("NULL\n");
}

// Corrected push function
static void push(t_stack **dst, t_stack **src) {
    t_stack *push_node;

    if (!src || !*src) // Check if `src` is NULL or empty
        return;

    push_node = *src;        // Get the top node of `src`
    *src = (*src)->next;     // Update the top of `src` to the next node
    push_node->next = *dst;  // Link the current node to the top of `dst`
    *dst = push_node;        // Update the top of `dst`
}

// pa and pb functions
void pa(t_stack **a, t_stack **b) {
    push(a, b);
    printf("pa\n");
}

void pb(t_stack **b, t_stack **a) {
    push(b, a);
    printf("pb\n");
}

// Test the push function
int main() {
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    // Create stack_a with some elements
    stack_a = create_node(3);
    stack_a->next = create_node(2);
    stack_a->next->next = create_node(1);

    printf("Initial stacks:\n");
    printf("Stack A: ");
    print_stack(stack_a);
    printf("Stack B: ");
    print_stack(stack_b);

    // Push elements from stack_a to stack_b
    pb(&stack_b, &stack_a);
    pb(&stack_b, &stack_a);

    printf("\nAfter pushing:\n");
    printf("Stack A: ");
    print_stack(stack_a);
    printf("Stack B: ");
    print_stack(stack_b);

    return 0;
}
