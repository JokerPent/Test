#ifndef TIME_SHARING_INCLUDED
#define TIME_SHARING_INCLUDED
#define NOT_FOUND    -1
#define OK            0 
#define LIST_isEMPTY  1
#define NO_SPACE      2
#define NOT_FUNCTION -2

int write_num();
    //Escrever um número

typedef struct Job TJob;
    //Estrutura de um Job

typedef struct Process TProcess;
//Estrutura de um processo

typedef struct SimpleList TSimpleList;
    //Estrutura de uma lista encadeada simples

typedef struct CircleList TCircleList;
    //Estrutura de lista circular simples com cabeça

typedef enum {FALSE=1, TRUE=0} boolean;
//Criação de uma tipo boolean

void init_job(TProcess *process);
    //Criação dos Jobs

void init_simple_list(TSimpleList *list, int id_class);
    //Criação da lista simples

void init_simple_list_2(TSimpleList *list);
    //Criação da lista simples 2

int init_circle_list(TCircleList *list);
    //Criação da lista circular com cabeça

boolean veriry_if_isEmpty_on_circle_list(TCircleList *list);
    //Verificar se a lista circular está vazia

boolean veriry_if_isEmpty_on_simple_list(TSimpleList *list);
    //Verificar se a lista simples está vazia

int generate_random_num(int init, int end);
    //Gerar números automáticos

int insert_on_end_of_simple_list(TSimpleList *list, TProcess *process);
    //Inserção no final na lista simples


int insert_on_end_of_circle_list(TCircleList *list, TProcess *process);
    //Inserção no final na lista circular com cabeça

int insert_on_beggin_of_circle_list(TCircleList *list, TProcess *process);
    //Inserção no início na lista circular com cabeça

TProcess *remove_on_simple_list(TSimpleList *list);
    //Remoção no início na lista simples

TProcess *remove_in_list_circle(TCircleList *list);
    //Remoção no início da lista circular com cabeça

void generate_job(TSimpleList *list, TProcess *process, int init_proc_time, int end_proc_time, int init_line, int end_line);
    //Gerar um job

int insert_job_in_class(TSimpleList *class_1, TSimpleList *class_2, TProcess *process);
    //Inserir o job à classe

void code_information(int cod);
    //Especificação de cada código de erro

void show(TSimpleList *list);
    //Mostrar as informações ao terminar a informação do Job

#endif