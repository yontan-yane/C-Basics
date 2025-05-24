/* --- MAIN MODULE --- */
#include <stdio.h>

#define LINE_SIZE_MAX 100

char my_getline(char line[], int line_size_max);
void line_calculate(char line[]);

/* reverse Polish calculator */
int main(void)
{
    char line[LINE_SIZE_MAX];

    while((my_getline(line, LINE_SIZE_MAX)) > 0) {
        line_calculate(line);
    }
    return 0;
}

/* read line, return length */
char my_getline(char line[], int line_size_max)
{
    int c, i;

    i = 0;
    while (i < line_size_max - 1 && ((c = getchar()) != EOF) && c !='\n') {
        line[i++] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

/* --- CALCULATION MODULE -- */
#include <math.h>
#include <stdlib.h>

#define TOKEN_SIZE_MAX LINE_SIZE_MAX
#define NUMBER '0'
#define COMMAND '1'
#define FUNCTION '2'

int line_index = -1;        /* indexes the last character that has been read from line */
double variables[26];       /* stores the values of variables 'A' - 'Z', mapped to indices 0 - 25 */
double last_printed_value;  /* result from the previous expression / line */

int token_type_get(char line[], char token[]);
void calc_stack_push(double value);
double calc_stack_pop(void);
void calc_stack_execute_command(char command[]);
void calc_stack_execute_function(char function[]);

/* compute the expression stored in line */
void line_calculate(char line[])
{
    int token_type, last_read_value = 0;     
    double operand;
    char token[TOKEN_SIZE_MAX];     /* blank-separated string of characters */

    while ((token_type = token_type_get(line, token)) != '\0') {      /* for each token in the line... */
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
        case FUNCTION:      /* evaluate math function on stack value(s) */
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
    line_index = -1;        /* reset for next line */
}

/* --- INPUT MODULE ---*/
#include <string.h>
#include <ctype.h>

int is_command(char candidate[]);
int is_function(char candidate[]);

/* read a token from line and store into token, return token type */
int token_type_get(char line[], char token[])
{
    int c, token_index;

    while ((token[0] = c = line[++line_index]) == ' ' || c == '\t')        /* skip whitespace */
        ;
    token[1] = '\0';
    token_index = 0;
    if (!isdigit(c) && c != '.' && c != '-' && !isalpha(c))
        return c;           /* not a number, command, function or variable */
    if (isalpha(c)) {       /* command, function, or variable */
        while (isalpha(token[++token_index] = c = line[++line_index]))       
            ;
        token[token_index] = '\0';      /* overwrite the non-alphabet char with termination symbol */
        --line_index;                   /* back off of the char we over-read */
        if (strlen(token) == 1) {
            return token[0];            /* may be a variable */
        } else if (is_command(token)) {
            return COMMAND;
        } else if (is_function(token)) {
            return FUNCTION;
        } else {
            return '?';                 /* unknown alphabet */
        }
    }
    if (c == '-') {         /* negative number or subtraction operator */
        if (isdigit(c = line[++line_index]) || c == '.')
            token[++token_index] = c;   /* negative number */
        else {
            --line_index;
            return '-';                 /* subtraction operator */
        }
    }
    if (isdigit(c))         /* collect integer portion */
        while (isdigit(token[++token_index] = c = line[++line_index]))
            ;
    if (c == '.')           /* collect fraction portion */
        while(isdigit(token[++token_index] = c = line[++line_index]))
            ;
    token[token_index] = '\0';  /* overwrite non-digit */
    --line_index;
    return NUMBER;
}

/* --- STACK MODULE --- */
#define CALC_STACK_SIZE_MAX 100

double calc_stack[CALC_STACK_SIZE_MAX];
int calc_stack_position = 0;        /* stores the next free position in the stack */

/* push value onto the stack */
void calc_stack_push(double value)
{
    if (calc_stack_position < CALC_STACK_SIZE_MAX)
        calc_stack[calc_stack_position++] = value;
    else
        printf("error: stack full, can't push %g\n", value);
}

/* pop and return value from the stack */
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

/* execute math functions on the values from the stack */
void calc_stack_execute_function(char function[])
{
    double top, second;

    if (calc_stack_position < 1) {
        printf("error: not enough values in calc stack\n");
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

/* returns 1 if candidate is a valid stack command, 0 otherwise */
int is_command(char candidate[])
{
    return (strcmp(candidate, PEEK) == 0 
        || strcmp(candidate, DUPLICATE) == 0 
        || strcmp(candidate, SWAP) == 0 
        || strcmp(candidate, CLEAR) == 0);
}

/* returns 1 if candidate is a valid math function, 0 otherwise */
int is_function(char candidate[])
{
    return (strcmp(candidate, SIN) == 0 
        || strcmp(candidate, EXP) == 0 
        || strcmp(candidate, POW) == 0);
}
