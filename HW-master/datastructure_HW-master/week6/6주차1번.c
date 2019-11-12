#pragma warning (disable: 4996) 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#define MAX_POLYS 100 
#define BUFFER_LENGTH 20 

struct term
{
	int coef;
	int expo;
	struct term *next;
};
typedef struct term Term;

typedef struct polynomial
{
	char name;
	Term *first;
	int size;
} Polynomial;
Polynomial *polys[MAX_POLYS] = { 0, };
int n = 0;

Term *create_term_instance();
Polynomial *create_polynomial_instance(char name);
void add_term(int c, int e, Polynomial *poly);
int eval_poly(Polynomial *poly, int x);
int eval_term(Term *term, int x);
void print_poly(Polynomial *p);
void print_term(Term *pTerm); //과제 
void process_command();
void handle_print(char name);//채울것 
void handle_calc(char name, char *x_str);//채울것 
void handle_definition(char *expression);
void erase_blanks(char *expression);//채울것 
int parse_and_add_term(char *expr, int begin, int end, Polynomial *p_poly);
void insert_polynomial(Polynomial *ptr_poly);
void destroy_polynomial(Polynomial *ptr_poly);
Polynomial *create_by_add_two_polynomials(char name, char f, char g); //채울것 
int read_line(FILE * fp, char str[], int n);
Polynomial *create_by_parse_polynomial(char name, char *body);
void HELP();
//추가로 만드는것 
void printall();
Polynomial *create_by_mult_two_polynomials(char name, char f, char g);

int main()
{
	printf("도움말은 명령어 help \n");
	process_command();

	return 0;
}
/* ********************************************************************************************* */

Term *create_term_instance()
{
	Term *t = (Term *)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	t->next = NULL;
	return t;
}

Polynomial *create_polynomial_instance(char name)
{
	Polynomial *ptr_poly = (Polynomial *)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

void add_term(int c, int e, Polynomial *poly)
{
	if (c == 0)
		return;
	Term *p = poly->first, *q = NULL;
	while (p != NULL && p->expo > e)
	{
		q = p;
		p = p->next;
	}
	if (p != NULL && p->expo == e)
	{
		p->coef += c;
		if (p->coef == 0)
		{
			if (q == NULL)
				poly->first = p->next;
			else
				q->next = p->next;
			poly->size--;
			free(p);
		}
		return;
	}
	Term *term = create_term_instance();
	term->coef += c;
	term->expo += e;
	if (q == NULL)
	{
		term->next = poly->first;
		poly->first = term;
	}
	else
	{
		term->next = p;
		q->next = term;
	}
	poly->size++;
}

int eval_poly(Polynomial *poly, int x)
{
	int result = 0;
	Term *t = poly->first;
	while (t != NULL)
	{
		result += eval_term(t, x);
		t = t->next;
	}
	return result;
}
int eval_term(Term *term, int x)
{
	int result = term->coef;
	for (int i = 0; i < term->expo; i++)
	{
		result *= x;
	}
	return result;
}

void print_poly(Polynomial *p)
{
	printf("%c=", p->name);
	Term *t = p->first;
	while (t != NULL)
	{
		print_term(t);
		t = t->next;
	}
	printf("\n");
}
void print_term(Term *pTerm) //과제 
{
	if (pTerm->coef == 1 && pTerm->expo == 1) //계수가 1일때  
		printf("x");
	else if (pTerm->coef == 1 && pTerm->expo != 0) //계수가 1일때  
		printf("x^{%d}", pTerm->expo);
	else if (pTerm->expo == 1)
		printf("%dx", pTerm->coef);
	else if (pTerm->expo != 0)
		printf("%dx^{%d}", pTerm->coef, pTerm->expo);
	else//자연수 
		printf("%d", pTerm->coef);

	if (pTerm->next != NULL &&pTerm->next->coef > 0)
		printf("+");

}
void process_command()
{
	char command_line[BUFFER_LENGTH];
	char copied[BUFFER_LENGTH];
	char *command, *arg1, *arg2;
	while (1)
	{
		printf("$ ");
		if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
			continue;
		strcpy(copied, command_line);
		command = strtok(command_line, " ");

		if (strcmp(command, "help") == 0)
		{
			HELP();
		}
		else if (strcmp(command, "print") == 0)
		{
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL)
			{
				printf("Invalid arguments.\n");
				continue;
			}
			handle_print(arg1[0]);
		}
		else if (strcmp(command, "printall") == 0)
		{
			printall();
		}
		else if (strcmp(command, "calc") == 0)
		{
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL)
			{
				printf("Invalid arguments.\n");
				continue;
			}
			arg2 = strtok(NULL, " ");
			if (arg2 == NULL)
			{
				printf("Invalid arguments.\n");
				continue;
			}
			handle_calc(arg1[0], arg2);
		}
		else if (strcmp(command, "exit") == 0)
			break;
		else
		{
			handle_definition(copied);
		}
	}
}
void handle_print(char name)
{
	for (int i = 0; polys[i] != NULL; i++)//poly순회 
	{
		if (polys[i]->name == name)
		{
			print_poly(polys[i]);
			return;
		}
	}
	printf("Not exist\n");
}
void handle_calc(char name, char *x_str)
{
	/* left as exercise */
	int x = 0;
	int i = 0;
	while (*(x_str + i) >= '0' && *(x_str + i) <= '9')//문자열숫자 정수화 atoi로도가능 
	{
		x = x * 10 + (int)(*(x_str + i) - '0'); //문제 
		i++;
	}
	for (int i = 0; polys[i] != NULL; i++)//poly순회 
	{
		if (polys[i]->name == name)
		{
			printf("%d\n", eval_poly(polys[i], x));
			return;
		}
	}
}
void handle_definition(char *expression)
{
	erase_blanks(expression); //공백떼기 
	char *f_name = strtok(expression, "=");  // = 앞 토큰 
	if (f_name == NULL || strlen(f_name) != 1)
	{
		printf("Unsupported command.\n");
		return;
	}
	char *exp_body = strtok(NULL, "=");
	if (exp_body == NULL || strlen(exp_body) <= 0)
	{
		printf("Invalid expression format.--\n");
		return;
	}
	if (exp_body[0] >= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x')
	{
		char *former = strtok(exp_body, "+");
		if (former == NULL || strlen(former) != 1)
		{// + -> * 분기점 
			char *multiformer = strtok(exp_body, "*");
			if (multiformer == NULL || strlen(multiformer) != 1)
			{
				printf("Invalid expression format.\n");
				return;
			}
			char *later = strtok(NULL, "+");
			if (later == NULL || strlen(later) != 1)
			{
				printf("Invalid expression format.\n");
				return;
			}
			Polynomial *pol = create_by_mult_two_polynomials(f_name[0], former[0], later[0]);
			if (pol == NULL)
			{
				printf("Invalid expression format.\n");
				return;
			}
			insert_polynomial(pol);
			return;
		}
		char *later = strtok(NULL, "+");
		if (later == NULL || strlen(later) != 1)
		{
			printf("Invalid expression format.\n");
			return;
		}
		Polynomial *pol = create_by_add_two_polynomials(f_name[0], former[0], later[0]);
		if (pol == NULL)
		{
			printf("Invalid expression format.\n");
			return;
		}
		insert_polynomial(pol);
		/* ********************************************************************************************* */

	}
	else
	{
		Polynomial *pol = create_by_parse_polynomial(f_name[0], exp_body);
		if (pol == NULL)
		{
			printf("Invalid expression format.\n");
			return;
		}
		insert_polynomial(pol);
	}
}
void erase_blanks(char *expression)
{
	/* left as exercise */
	int r = 0;
	for (int i = 0; i < (int)strlen(expression); i++)
	{
		if (expression[i] != ' ')
			expression[r++] = expression[i];
	}
	expression[r] = 0;//NULL삽입 

}

Polynomial *create_by_parse_polynomial(char name, char *body)
{
	Polynomial *ptr_poly = create_polynomial_instance(name);
	int i = 0, begin_term = 0;
	while (i < (int)strlen(body))
	{
		if (body[i] == '+' || body[i] == '-')
			i++;
		while (i < (int)strlen(body) && body[i] != '+' &&body[i] != '-')
			i++;
		int result = parse_and_add_term(body, begin_term, i, ptr_poly);
		if (result == 0)
		{
			destroy_polynomial(ptr_poly);
			return NULL;
		}
		begin_term = i;
	}
	return ptr_poly;
}

int parse_and_add_term(char *expr, int begin, int end, Polynomial *p_poly)
{
	int i = begin;
	int sign_coef = 1, coef = 0, expo = 1;
	if (expr[i] == '+')
		i++;
	else if (expr[i] == '-')
	{
		sign_coef = -1;
		i++;
	}

	while (i < end && expr[i] >= '0' && expr[i] <= '9')
	{
		coef = coef * 10 + (int)(expr[i] - '0');
		i++;
	}
	if (coef == 0)
		coef = sign_coef;
	else
		coef *= sign_coef;
	if (i >= end)
	{
		add_term(coef, 0, p_poly);
		return 1;
	}
	if (expr[i] != 'x')
		return 0;
	i++;
	if (i >= end)
	{
		add_term(coef, 1, p_poly);
		return 1;
	}
	if (expr[i] != '^')
		return 0;
	i++;
	expo = 0;
	while (i < end && expr[i] >= '0' && expr[i] <= '9')
	{
		expo = expo * 10 + (int)(expr[i] - '0');
		i++;
	}
	add_term(coef, expo, p_poly);
	return 1;
}
void insert_polynomial(Polynomial *ptr_poly)
{
	for (int i = 0; i < n; i++)
	{
		if (polys[i]->name == ptr_poly->name)
		{
			destroy_polynomial(polys[i]);
			polys[i] = ptr_poly;
			return;
		}
	}
	polys[n++] = ptr_poly;
}
void destroy_polynomial(Polynomial *ptr_poly)
{
	if (ptr_poly == NULL)
		return;
	Term *t = ptr_poly->first, *tmp;
	while (t != NULL)
	{
		tmp = t;
		t = t->next;
		free(tmp);
	}
	free(ptr_poly);
}

Polynomial *create_by_add_two_polynomials(char name, char f, char g)//해결해야하는거 
{
	/* left as exercise */
	Polynomial *empty = create_polynomial_instance(name);
	Term *funtion1 = NULL;
	Term *funtion2 = NULL;

	for (int i = 0; polys[i] != NULL; i++)//poly순회 
	{
		if (polys[i]->name == f)
		{
			funtion1 = polys[i]->first;
		}
		if (polys[i]->name == g)
		{
			funtion2 = polys[i]->first;
		}
	}
	while (funtion1 != NULL && funtion2 != NULL)
	{
		if (funtion1 != NULL)
		{
			add_term(funtion1->coef, funtion1->expo, empty);
			funtion1 = funtion1->next;
		}if (funtion2 != NULL)
		{
			add_term(funtion2->coef, funtion2->expo, empty);
			funtion2 = funtion2->next;
		}
	}

	return empty;
}
int read_line(FILE * fp, char str[], int n)
{
	int ch, i = 0;
	while ((ch = fgetc(fp)) != '\n' && ch != EOF)
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}

void printall()
{
	for (int i = 0; polys[i] != NULL; i++)//poly순회 
	{
		print_poly(polys[i]);
	}
}
Polynomial *create_by_mult_two_polynomials(char name, char f, char g)//해결해야하는거 
{
	Polynomial *empty = create_polynomial_instance(name);
	Term *funtion1 = NULL;
	Term *funtion2 = NULL;

	for (int i = 0; polys[i] != NULL; i++)//poly순회 
	{
		if (polys[i]->name == f)
		{
			funtion1 = polys[i]->first;
		}
		if (polys[i]->name == g)
		{
			funtion2 = polys[i]->first;
		}
	}//add_two와같음 
	while (funtion1 != NULL)
	{
		Term *subfuntion = funtion2;
		while (subfuntion != NULL)
		{
			add_term(funtion1->coef*subfuntion->coef, funtion1->expo + subfuntion->expo, empty);
			subfuntion = subfuntion->next;
		}
		funtion1 = funtion1->next;
	}
	return empty;
}

void HELP()
{
	puts("함수생성 ");
	puts("형식: 함수이름(소문자한글자) = ~다항식");
	puts("이미 존재하는 함수일지 기존의것을 무시하고 새로만든다");
	puts("함수값계산");
	puts("형식: calc 함수이름 대입할x값");
	puts("예시(출력 f(2)): calc f 2");
	puts("함수간의 덧셈");
	puts("형식: 함수 = 존재하는 함수+존재하는함수  ");
	puts("이미 존재하는 함수일지 기존의것을 무시하고 새로만든다");
	puts("함수간의 곱셈");
	puts("형식: 함수 = 존재하는 함수*존재하는함수  ");
	puts("이미 존재하는 함수일지 기존의것을 무시하고 새로만든다");
	puts("함수 출력");
	puts("형식: print 존재하는함수");
	puts("모든 함수 출력");
	puts("형식:printall");
}
