#include <stdio.h>
#include <locale.h>
#include "execution.c"
#include "interface.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    TSimpleList *class1 = (TSimpleList *)malloc(sizeof(TSimpleList));

    if (class1 == NULL)
        return NO_SPACE;

    TSimpleList *class2 = (TSimpleList *)malloc(sizeof(TSimpleList));

    if (class2 == NULL)
        return NO_SPACE;

    TSimpleList *printer = (TSimpleList *)malloc(sizeof(TSimpleList));

    if (printer == NULL)
        return NO_SPACE;

    TCircleList *cpu = (TCircleList *)malloc(sizeof(TCircleList));

    if (cpu == NULL)
        return NO_SPACE;

    /**TJob *jobs = (TJob*) malloc(sizeof(TJob));
    if(jobs == NULL) return NO_SPACE;*/

    int code = -2;
    init_simple_list(class1, 1);
    init_simple_list(class2, 2);
    init_simple_list_2(printer);
    code = init_circle_list(cpu);

    int num_simulation;
    int cod = -2;
    // TProcess *output = NULL;

    // O tempo de simulação digitado pelo usuário
    num_simulation = write_num();

    /*
    for(int i = 1; i <= num_simulation; i++){
        if(i % 12 == 0){
            cod = insert_job_in_class(class1, class2, process);
            if(cod == 0){
                if(process->job->id_class == 1){
                    cod = -2;
                    output = remove_on_simple_list(class1);
                    cod = insert_on_end_of_circle_list(cpu, output);
                    if(cod  == 0 && output->job->temp_process == 0){
                        cod = -2;
                        output = NULL;
                        output = remove_in_list_circle(cpu);
                        cod = insert_on_end_of_simple_list(printer, output);
                    }

                    else if(output->job->temp_process!=0){
                        cod = -2;
                        output = NULL;
                        output = remove_in_list_circle(cpu);
                        cod = insert_on_end_of_circle_list(cpu, output);
                    }
                }
                else{
                    cod = -2;
                    output = remove_on_simple_list(class2);
                    cod = insert_on_end_of_circle_list(cpu, output);
                    if(cod  == 0 && output->job->temp_process == 0){
                        cod = -2;
                        output = NULL;
                        output = remove_in_list_circle(cpu);
                        cod = insert_on_end_of_simple_list(printer, output);
                    }

                    else if(output->job->temp_process!=0){
                        cod = -2;
                        output = NULL;
                        output = remove_in_list_circle(cpu);
                        cod = insert_on_end_of_circle_list(cpu, output);
                    }
                }
            }
        }
    }*/

    // Rascunho
    for (int i = 1; i <= num_simulation; i++)
    {
        if (i % 12 == 0)
        {
            TProcess *process = (TProcess *)malloc(sizeof(TProcess));
            if (process == NULL)
                return NO_SPACE;

            init_job(process);

            cod = insert_job_in_class(class1, class2, process);

            if (process->job->id_class == 1)
                // rintf("1\n");
                show_structure(class1);
            else if (process->job->id_class == 2)
                // printf("2\n");
                show_structure(class2);
        }
    }
    return 0;
}