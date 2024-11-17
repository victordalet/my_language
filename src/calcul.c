#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Tree {
    char symbol;
    int number;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree* parseExpression(const char** expression, char **name_variable, int *value_variable, int count_variable);
Tree* parsePow(const char** expression, char **name_variable, int *value_variable, int count_variable);
Tree* parseTerm(const char** expression, char **name_variable, int *value_variable, int count_variable);
Tree* parseFactor(const char** expression, char **name_variable, int *value_variable, int count_variable);
Tree* createBranchSymbol(char symbol, Tree* left, Tree* right);
Tree* createBranchNumber(int number);
int evaluate(Tree* root);

Tree* createBranchSymbol(char symbol, Tree* left, Tree* right) { //création de branche pour les opérateurs elles ont chacune deux sous branches connectées
    Tree *tree = malloc(sizeof(Tree));
    tree->symbol = symbol;
    tree->number = 0;
    tree->left = left;
    tree->right = right;
    return tree;
}

Tree* createBranchNumber(int number) {  //création de branche pour les nombres elles n'ont pas besoin de sous branche
    Tree *tree = malloc(sizeof(Tree));
    tree->symbol = '\0';
    tree->number = number;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void skipSpaces(const char** expression) {
    while (**expression == ' ') {
        (*expression)++;
    }
}

/*les quatres fonctions en dessous parse l'expression en gérant les priorités des opérations de manière inversé
(addition et soustraction, multiplication et division, puissances et enfin les facteurs) car la fonction evaluate est récursive et réalise le calcul en partant des feuilles de l'arbre
*/
Tree* parseExpression(const char** expression, char **name_variable, int *value_variable, int count_variable) {
    Tree* tree = parseTerm(expression, name_variable, value_variable, count_variable);
    skipSpaces(expression);
    while (**expression == '+' || **expression == '-') {
        char symbol = *((*expression)++);
        skipSpaces(expression);
        Tree* right = parseTerm(expression, name_variable, value_variable, count_variable);
        tree = createBranchSymbol(symbol, tree, right);
        skipSpaces(expression);
    }
    return tree;
}

Tree* parseTerm(const char** expression, char **name_variable, int *value_variable, int count_variable) {
    Tree* tree = parsePow(expression, name_variable, value_variable, count_variable);
    skipSpaces(expression);
    while (**expression == '*' || **expression == '/') {
        char symbol = *((*expression)++);
        skipSpaces(expression);
        Tree* right = parsePow(expression, name_variable, value_variable, count_variable);
        tree = createBranchSymbol(symbol, tree, right);
        skipSpaces(expression);
    }
    return tree;
}

Tree* parsePow(const char** expression, char **name_variable, int *value_variable, int count_variable) {
    Tree* tree = parseFactor(expression, name_variable, value_variable, count_variable);
    skipSpaces(expression);
    while (**expression == '^') {
        char symbol = *((*expression)++);
        skipSpaces(expression);
        Tree* right = parseFactor(expression, name_variable, value_variable, count_variable);
        tree = createBranchSymbol(symbol, tree, right);
        skipSpaces(expression);
    }
    return tree;
}

Tree* parseFactor(const char** expression, char **name_variable, int *value_variable, int count_variable) {
    skipSpaces(expression);
    if (**expression == '(') {
        (*expression)++;
        Tree* tree = parseExpression(expression, name_variable, value_variable, count_variable);
        if (**expression == ')') {
            (*expression)++;
        } else {
            printf("Error: unclosed bracket \n");
            exit(1);
        }
        return tree;
    } else if (isdigit(**expression)) {
        int number = 0;
        while (isdigit(**expression)) {
            number = number * 10 + (**expression - '0');
            (*expression)++;
        }
        return createBranchNumber(number);

    } else if (**expression == '-') {
        (*expression)++;
        int number = 0;
        while (isdigit(**expression)) {
            number = number * 10 + (**expression - '0');
            (*expression)++;
        }
        return createBranchNumber(-number);

    } else {


		int var_len = 0;

        while (isalpha(**expression)) {
            var_len++;
            (*expression)++;
        }

        char *var_name = malloc(sizeof(char) * var_len + 1);
		var_len = 0;
        *expression -= var_len;

        while (isalpha(**expression)) {
            var_name[var_len] = **expression;
            var_len++;
            (*expression)++;
        }

        var_name[var_len] = '\0';

        for (int j = 0; j < count_variable; j++) {
				if (strcmp(name_variable[j], var_name) == 0) {
						return createBranchNumber(value_variable[j]);
					break;
				}
		}

        (*expression)++;



        printf("Error: unexpected character '%c'\n", **expression);
        exit(1);
    }
}

int evaluate(Tree* root) {  //réalise les calculs en remontant l'arbre en utilisant le bon opérateur
    if (root->symbol == '\0') {
        return root->number;
    }
    int leftNumber = evaluate(root->left);
    int rightNumber = evaluate(root->right);

    switch (root->symbol) {
        case '+':
            return leftNumber + rightNumber;
            break;
        case '-':
            return leftNumber - rightNumber;
            break;
        case '*':
            return leftNumber * rightNumber;
            break;
        case '^':
            int result = 1;
            for(int i = 0; i < rightNumber; i++){
                result *= leftNumber;
            }
            return result;
            break;
        case '/':
            if (rightNumber == 0) {
                printf("Error: divided by 0\n");
                exit(1);
            }
            return leftNumber / rightNumber;
        default:
            printf("Error: invalid operator '%c'\n", root->symbol);
            exit(1);
    }
}


int result_calcul(const char *string, char **name_variable, int *value_variable,
		  int count_variable) {
  Tree* root = parseExpression(&string, name_variable, value_variable, count_variable);
  return evaluate(root);

}
