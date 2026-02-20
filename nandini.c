#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stateCount = 0;

typedef struct State {
    int id;
    struct State *out1;
    struct State *out2;
    char symbol;   // transition symbol (or 'e' for epsilon)
} State;

typedef struct NFA {
    State *start;
    State *end;
} NFA;

State* newState(char symbol) {
    State *s = (State*)malloc(sizeof(State));
    s->id = stateCount++;
    s->symbol = symbol;
    s->out1 = s->out2 = NULL;
    return s;
}

NFA* createBasicNFA(char symbol) {
    NFA *nfa = (NFA*)malloc(sizeof(NFA));
    nfa->start = newState(symbol);
    nfa->end = newState('e');
    nfa->start->out1 = nfa->end;
    return nfa;
}

NFA* concatenate(NFA *nfa1, NFA *nfa2) {
    nfa1->end->symbol = 'e';
    nfa1->end->out1 = nfa2->start;
    NFA *nfa = (NFA*)malloc(sizeof(NFA));
    nfa->start = nfa1->start;
    nfa->end = nfa2->end;
    return nfa;
}

NFA* unionNFA(NFA *nfa1, NFA *nfa2) {
    NFA *nfa = (NFA*)malloc(sizeof(NFA));
    State *start = newState('e');
    State *end = newState('e');

    start->out1 = nfa1->start;
    start->out2 = nfa2->start;

    nfa1->end->symbol = 'e';
    nfa1->end->out1 = end;

    nfa2->end->symbol = 'e';
    nfa2->end->out1 = end;

    nfa->start = start;
    nfa->end = end;
    return nfa;
}

NFA* kleeneStar(NFA *nfa1) {
    NFA *nfa = (NFA*)malloc(sizeof(NFA));
    State *start = newState('e');
    State *end = newState('e');

    start->out1 = nfa1->start;
    start->out2 = end;

    nfa1->end->symbol = 'e';
    nfa1->end->out1 = nfa1->start;
    nfa1->end->out2 = end;

    nfa->start = start;
    nfa->end = end;
    return nfa;
}

int precedence(char op) {
    if (op == '*') return 3;
    if (op == '.') return 2;
    if (op == '|') return 1;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1, k = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(')
                postfix[k++] = stack[top--];
            top--;
        }
        else {
            while (top >= 0 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = stack[top--];
            stack[++top] = c;
        }
    }

    while (top >= 0)
        postfix[k++] = stack[top--];

    postfix[k] = '\0';
}

void printNFA(State *state) {
    if (!state) return;

    if (state->out1)
        printf("State %d -- %c --> State %d\n",
               state->id, state->symbol, state->out1->id);

    if (state->out2)
        printf("State %d -- e --> State %d\n",
               state->id, state->out2->id);

    printNFA(state->out1);
    printNFA(state->out2);
}

int main() {
    char infix[MAX], postfix[MAX];
    NFA *stack[MAX];
    int top = -1;

    printf("Enter Regular Expression (use . for concatenation): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            stack[++top] = createBasicNFA(c);
        }
        else if (c == '.') {
            NFA *nfa2 = stack[top--];
            NFA *nfa1 = stack[top--];
            stack[++top] = concatenate(nfa1, nfa2);
        }
        else if (c == '|') {
            NFA *nfa2 = stack[top--];
            NFA *nfa1 = stack[top--];
            stack[++top] = unionNFA(nfa1, nfa2);
        }
        else if (c == '*') {
            NFA *nfa1 = stack[top--];
            stack[++top] = kleeneStar(nfa1);
        }
    }

    NFA *result = stack[top];

    printf("\nNFA Transitions:\n");
    printNFA(result->start);

    return 0;
}