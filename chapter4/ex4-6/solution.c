/* --- MAIN MODULE --- */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOKEN_SIZE_MAX 100
#define NUMBER '0'
#define COMMAND '1'
#define FUNCTION '2'

int token_type_get(char token[]);
void calc_stack_push(double value);
double calc_stack_pop(void);
void calc_stack_execute_command(char command[]);
void calc_stack_execute_function(char function[]);

/* reverse Polish calculator */
int main(void) 
{
    int i, token_type, last_read_value = 0;
    double operand, last_printed_value;
    char token[TOKEN_SIZE_MAX];             /* stores a token parsed from input, split by ' ', '\t', or '\n' */
    double variables[26];                   /* stores the values of variables 'A'-'Z', mapped to indices 0-25 */

    for (i = 0; i < 26; i++)
        variables[i] = 0.0;

    while ((token_type = token_type_get(token)) != EOF) {
        switch (token_type) {
        case NUMBER:
            calc_stack_push(atof(token));
            break;
        case '+':
            calc_stack_push(calc_stack_pop() + calc_stack_pop());
            break;
        case '*':
            calc_stack_push(calc_stack_pop() * calc_stack_pop());
            break;
        case '-':
            operand = calc_stack_pop();
            calc_stack_push(calc_stack_pop() - operand);
            break;
        case '/':
            operand = calc_stack_pop();
            if (operand != 0.0)
                calc_stack_push(calc_stack_pop() / operand);
            else
                printf("error: zero divisor \n");
            break;
        case '%':
            operand = calc_stack_pop();
            if (operand != 0.0)
                calc_stack_push(fmod(calc_stack_pop(), operand));
            else
                printf("error: zero divisor\n");
            break;
        case '\n':          /* end of calc, pop result from stack */
            last_printed_value = calc_stack_pop();
            printf("\t%.8g\n", last_printed_value);
            break;
        case COMMAND:       /* execute a command on the stack */
            calc_stack_execute_command(token);
            break;
        case FUNCTION:      /* calculate math function on stack values */ 
            calc_stack_execute_function(token);
            break;
        case '=':           /* assign a value to a variable - expression is in the form: value variable = */
            calc_stack_pop();
            if (last_read_value >= 'A' && last_read_value <= 'Z') {
                operand = calc_stack_pop();
                variables[last_read_value - 'A'] = operand;
                calc_stack_push(operand);
            }
            else
                printf("error: unknown input\n");
            break;
        default:
            if (token_type >= 'A' && token_type <= 'Z') {
                calc_stack_push(variables[token_type - 'A']);  
            } else if (token_type == '$') {
                calc_stack_push(last_printed_value);
            } else {
                printf("error: unknown input %s\n", token);
                break;
            }
        }
        last_read_value = token_type;
    }
    return 0;
}

/* --- INPUT MODULE --- */
#include <string.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int is_command(char candidate[]);
int is_function(char candidate[]);

/* read a token from input and store into token, return token type */
int token_type_get(char token[])
{
    int i, c;

    while ((token[0] = c = getch()) == ' ' || c == '\t')        /* skip whitespace */
        ;
    token[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-' && !isalpha(c))
        return c;           /* not a number, command, function or variable */
    if (isalpha(c)) {       /* command, function, or variable */
        while (isalpha(token[++i] = c = getch()))       
            ;
        token[i] = '\0';        /* overwrite the non-alphabet char with termination symbol */
        if (c != EOF)
            ungetch(c);
        if (strlen(token) == 1) {
            return token[0];    /* may be a variable */
        } else if (is_command(token)) {
            return COMMAND;
        } else if (is_function(token)) {
            return FUNCTION;
        } else {
            return '?';         /* unknown alphabet */
        }
    }
    if (c == '-') {         /* negative number or subtraction operator */
        if (isdigit(c = getch()) || c == '.')
            token[++i] = c;     /* negative number */
        else {
            if (c != EOF)
                ungetch(c);
            return '-';         /* subtraction operator */
        }
    }
    if (isdigit(c))         /* collect integer portion */
        while (isdigit(token[++i] = c = getch()))
            ;
    if (c == '.')           /* collect fraction portion */
        while(isdigit(token[++i] = c = getch()))
            ;
    token[i] = '\0';        /* overwrite non-digit */
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFFER_SIZE_MAX 100

char input_buffer[BUFFER_SIZE_MAX];     /* stores chars that we have un-read */
int input_buffer_position = 0;          /* next free position in the buffer */

/* get a (posibly un-read/pushed-back) character */
int getch(void)
{
    return (input_buffer_position > 0) ? input_buffer[--input_buffer_position] : getchar();
}

/* un-read, push character back onto input */
void ungetch(int c)
{
    if (input_buffer_position < BUFFER_SIZE_MAX)
        input_buffer[input_buffer_position++] = c;
    else
        printf("error: too many characters\n");
}

/* --- STACK MODULE --- */
#define STACK_SIZE_MAX 100

double calc_stack[STACK_SIZE_MAX];
int calc_stack_position = 0;        /* stores the next free position in the stack */

/* push value onto stack */
void calc_stack_push(double value)
{
    if (calc_stack_position < STACK_SIZE_MAX)
        calc_stack[calc_stack_position++] = value;
    else
        printf("error: stack full, can't push %g\n", value);
}

/* pop and return top value from stack */
double calc_stack_pop(void)
{
    if (calc_stack_position > 0)
        return calc_stack[--calc_stack_position]; 
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* commands to be executed on the stack */
#define PEEK "peek"
#define DUPLICATE "duplicate"
#define SWAP "swap"
#define CLEAR "clear"

/* execute commands on the stack */
void calc_stack_execute_command(char command[])
{
    double top, second;

    if (strcmp(command, PEEK) == 0) {
        if (calc_stack_position > 0) {
            printf("peek: %g at the top of the stack\n", calc_stack[calc_stack_position - 1]);
        } else 
            printf("error: can't peek into empty stack\n");
    } else if (strcmp(command, DUPLICATE) == 0) {
        if (calc_stack_position > 0) {
            top = calc_stack[calc_stack_position - 1];     /* peek into stack */ 
            calc_stack_push(top);
            printf("duplicate: %g duplicated at the top of stack\n", top); 
        } else 
            printf("error: can't duplicate top of empty stack\n");
    } else if (strcmp(command, SWAP) == 0) {
        if (calc_stack_position > 1) {
            top = calc_stack_pop();
            second = calc_stack_pop();
            calc_stack_push(top);
            calc_stack_push(second);
            printf("swap: swapped %g and %g, %g at top of stack now\n", top, second, second);
        } else
            printf("error: can't swap when stack has fewer than two elements\n");
    } else if (strcmp(command, CLEAR) == 0) {
            calc_stack_position = 0;
            printf("clear: cleared stack\n");
    } else {
        printf("error: unkown command\n");
    }
}

/* math functions to be executed on values from the stack */
#define SIN "sin"
#define EXP "exp"
#define POW "pow"

/* execute math functions on values in the stack */
void calc_stack_execute_function(char function[])
{
    double top, second;

    if (calc_stack_position < 1) {
        printf("error: not enough values in stack\n");
        return;
    }
    if (strcmp(function, SIN) == 0) {
       top = calc_stack_pop();
       calc_stack_push(sin(top));
    } else if (strcmp(function, EXP) == 0 ) {
        top = calc_stack_pop();
        calc_stack_push(exp(top));
    } else if (strcmp(function, POW) == 0) {
        if (calc_stack_position > 1) {
            top = calc_stack_pop();
            second = calc_stack_pop();
            calc_stack_push(pow(second, top));
        } else
            printf("error: not enough values in stack to compute pow\n");
    } else {
        printf("error: unkown function\n");
    }
}

/* returns 1 if candidate matches a valid command, 0 otherwise */
int is_command(char candidate[])
{
    return (strcmp(candidate, PEEK) == 0 
        || strcmp(candidate, DUPLICATE) == 0 
        || strcmp(candidate, SWAP) == 0 
        || strcmp(candidate, CLEAR) == 0);
}

/* returns 1 if candidate matches a valid function, 0 otherwise */
int is_function(char candidate[])
{
    return (strcmp(candidate, SIN) == 0 
        || strcmp(candidate, EXP) == 0 
        || strcmp(candidate, POW) == 0);
}
