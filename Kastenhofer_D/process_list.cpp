/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			grade_list.c
 * Author:			P. Bauer
 * Due Date:		November 18, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of grade_list.h.
 * ----------------------------------------------------------
 */
#include "process_list.h"


  bool add_entries (struct ProcessList *pl, struct ProcessListEntry *e[], int n){
    if (get_length(pl) + n <= MAX_LIST_ENTRIES) {
      for (int i = 0; i < n; i++) {
        pl->processes[get_length(pl)+i] = e[i];     //schleife neu gemacht
      }
      pl->length+=n;
      return true;
    }
    return false;
  }
   bool add_entry (struct ProcessList *pl, struct ProcessListEntry *e){//Methode neu gemacht
      if (get_length(pl)>MAX_LIST_ENTRIES) return false;
      pl->processes[get_length(pl)]=e;
      pl->length++;
      return true;
   }
   void	init_process_list (struct ProcessList *pl){
     pl->length = 0;
   }
   int get_length (const struct ProcessList *pl){
     return pl->length;
   }
   int get_process_with_id (const struct ProcessList *pl, int id, struct ProcessListEntry *result_list[]){
     int counter = 0;
     for (int i = 0; i < get_length(pl); i++) {
       if (id==pl->processes[i]->pid) {
         result_list[counter] = pl->processes[i];
         counter++;
       }
     }
     return counter;
     return 0;
   }

   int get_processes_with_state (const ProcessList *pl, enum ProcessState state, struct ProcessListEntry *result_list[]){
     int return_value = 0;
     int counter = 0;
     for (int i = 0; i < get_length(pl); i++) {
      if (state==pl->processes[i]->state) {
        result_list[counter] = pl->processes[i];
        counter++;
        return_value++;
      }
    }
     return return_value;
     return 0;
   }
   struct ProcessListEntry * get_process_with_highest_cpu_consumption (const struct ProcessList *pl){//Methode gemacht
     if(get_length(pl)<1)return 0;
     int indexOfHighest=0;
     for (int i = 0; i < get_length(pl); i++) {
       if (pl->processes[i]->cpu_usage> pl->processes[indexOfHighest]->cpu_usage) {
         indexOfHighest=i;
       }
     }
     return  pl->processes[indexOfHighest];
   }
   struct ProcessListEntry * get_process_with_lowest_cpu_consumption (const struct ProcessList *pl){//Methode gemacht
     if(get_length(pl)<1)return 0;
     int indexOfLowest=0;
     for (int i = 0; i < get_length(pl); i++) {
       if (pl->processes[i]->cpu_usage< pl->processes[indexOfLowest]->cpu_usage) {
         indexOfLowest=i;
       }
     }
     return  pl->processes[indexOfLowest];
   }
   int get_top_n_processes_cpu (const struct ProcessList *pl, int n, struct ProcessListEntry *result_list[]){
     return 0;
   }
   int get_bottom_n_processes_cpu (const struct ProcessList *pl, int n, struct ProcessListEntry *result_list[]){
     return 0;
   }
