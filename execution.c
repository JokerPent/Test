#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "interface.h"
#define NOT_FOUND    -1
#define OK            0 
#define LIST_isEMPTY  1
#define NO_SPACE      2
#define NOT_FUNCTION -2


//Função para digitar o tempo de simulação
int write_num(){
    int n;
    while(1){
        printf("Digite o tempo de processamento: \n");
        scanf("%d", &n);
        if(n>=0) break;
        else
            printf("ERRO: O tempo não pode ser negativo\n\n");
    }
    return n;
}

struct Job{
    int id;
    int id_class;
    int temp_process;
    int num_lines;
};

struct Process{
    TJob *job;
    struct Process *prox;
};

struct SimpleList{
    int id_class_list;
    int id_prox_job; 
    TProcess *first;
    TProcess *last;
};

struct CircleList{
    TProcess *head;
};
 
//Criação dos Jobs
void init_job(TProcess *process){
    process->job->id = 0;
    process->job->id_class = 0;
    process->job->num_lines = 0;
    process->job->temp_process = 0;
}

//Criação da lista simples
void init_simple_list(TSimpleList *list, int id_class){
    list->id_class_list = id_class;
    list->id_prox_job = 0;
    list->first = NULL;
    list->last = NULL;
}

//Criação da lista simples 2
void init_simple_list_2(TSimpleList *list){
    list->id_class_list = 0;
    list->id_prox_job = 0;
    list->first = NULL;
    list->last = NULL;
}

//Criação da lista circular com cabeça
int init_circle_list(TCircleList *list){
    TProcess *pnovo = (TProcess*) malloc(sizeof(TProcess));
    if(pnovo == NULL) return NO_SPACE;
    list->head = pnovo;
    list->head->prox = list->head;
    return OK;
}

//Verificar se a lista circular está vazia
boolean veriry_if_isEmpty_on_circle_list(TCircleList *list){
    return (list->head->prox == NULL);
}

//Verificar se a lista simples está vazia
boolean veriry_if_isEmpty_on_simple_list(TSimpleList *list){
    return (list->first == NULL);
}

//Gerar números automáticos
int generate_random_num(int init, int end){
    return (init + (rand() % end));
}

//Inserção no final na lista simples
int insert_on_end_of_simple_list(TSimpleList *list, TProcess *process){
    process = (TProcess*) malloc(sizeof(TProcess));
    if(process == NULL) return NO_SPACE;
    if(!veriry_if_isEmpty_on_simple_list(list))
        list->last->prox = process;
    else
        list->first = process;

    list->last = process;
    process->prox = NULL;
    return OK;
}

//Inserção no final na lista circular com cabeça
int insert_on_end_of_circle_list(TCircleList *list, TProcess *process){
    process = (TProcess*) malloc(sizeof(TProcess));
    if(process == NULL) return NO_SPACE;
    if(!veriry_if_isEmpty_on_circle_list(list)){
        TProcess *paux = list->head->prox;

        while(paux->prox!=list->head){
            paux = paux->prox;
        }
        paux->prox = process;
        process->job->temp_process-=5;
    }
    else {
        list->head->prox = process;
        process->job->temp_process-=5;
    }
    process->prox = list->head;
    printf("Classe%d-%d\nNúmero de Linhas: %d\nTempo de Processamento: %d\n", process->job->id_class, process->job->id, process->job->num_lines,process->job->temp_process);
    printf("===================================================================================================================\n");
    return OK;
}
/*//Inserção no início na lista circular com cabeça
int insert_on_beggin_of_circle_list(TCircleList *list, TProcess *process){
    process = (TProcess*) malloc(sizeof(TProcess));
    if(process == NULL) return NO_SPACE;
    if(!veriry_if_isEmpty_on_circle_list(list))
        process->prox = list->head->prox;
    else
        process->prox = list->head;
    list->head->prox = process;
    return OK;
}*/

//Remoção no início na lista simples
TProcess *remove_on_simple_list(TSimpleList *list){
    if(!veriry_if_isEmpty_on_simple_list(list)){
        TProcess *pdel = list->first;
        list->first->prox = NULL;
        list->first = pdel->prox;
        free(pdel);
        return pdel;
    }
    return NULL;
}

//Remoção no início da lista circular com cabeça
TProcess *remove_in_list_circle(TCircleList *list){
    TProcess *pdel = list->head->prox;
    if(!veriry_if_isEmpty_on_circle_list(list)){
        list->head->prox = pdel->prox;
        list->head->prox->prox = NULL;
        free(pdel);
        return pdel; 
    }
    return NULL;
}

//Gerar um job
void generate_job(TSimpleList *list, TProcess *process, int init_proc_time, int end_proc_time, int init_line, int end_line){
    list->id_prox_job++;
    process->job->id = list->id_prox_job;
    process->job->temp_process = generate_random_num (init_proc_time, end_proc_time);
    process->job->num_lines = generate_random_num(init_line, end_line);
}

//Inserir o job à classe
int insert_job_in_class(TSimpleList *class_1, TSimpleList *class_2, TProcess *process){
    int cod = -2;
    /*process = (TProcess*) malloc(sizeof(TProcess));
    if(process == NULL) return NO_SPACE*/
    //init_job(process);

    process->job->id_class = generate_random_num(1,2);
    if(process->job->id_class == 1){
        generate_job(class_1, process, 1, 5, 1, 500);
        cod = insert_on_end_of_simple_list(class_1, process);
        /*printf("Classe%d-%d\nNúmero de Linhas: %d\nTempo de Processamento: %d\n", process->job->id_class, process->job->id, process->job->num_lines,process->job->temp_process);
        printf("===================================================================================================================\n");*/
    }

    else{
        generate_job(class_2, process, 1, 30, 1, 10000);
        cod = insert_on_end_of_simple_list(class_2, process);
       /*printf("Classe%d-%d\nNúmero de Linhas: %d\nTempo de Processamento: %d\n", process->job->id_class, process->job->id, process->job->num_lines,process->job->temp_process);
        printf("===================================================================================================================\n");*/
    }

    return cod;
}

void code_information(int cod){
    switch(cod){
        case NOT_FOUND:
            printf("Processo não encontrado\n");
        break;
        case OK:
            printf("Funcionando\n");
        break;
        case LIST_isEMPTY:
            printf("A lista está vazia\n");
        break;
        case NO_SPACE:
            printf("Sem espaço para alocar\n");
        break;
        case NOT_FUNCTION:
            printf("Não está funcionando\n");
        break;
    }
}

void show_structure(TSimpleList *list){
    for(TProcess *paux = list->first; paux!=NULL; paux=paux->prox)
        printf("Classe%d-%d\nNúmero de Linhas: %d\nTempo de Processamento: %d\n", paux->job->id_class, paux->job->id, paux->job->num_lines,paux->job->temp_process);       
}