#pragma once

#include "Data.h"

void Data_Entry(Data* (&d), int& n);
void Data_Reading(Data* (&d), int& n, string file_name);
void Print(Data* d, int n);
void Data_Change(Data* d, int n);
void Copy(Data *d_n, Data *d_o, int n);
void Add_Data(Data* (&d), int& n);
void Delete_Data(Data* (&d), int& n);
void Sorting_Data(Data *d, int& n);
void Save_Data(Data *d, int n, string file_name);