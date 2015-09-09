#pragma once

#include "Game.h"
#include "Files.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string>
#include <list>
#include <map>
#include <Windows.h>

using namespace std;

void help();
void print_list(fstream &fout, list<string> &words);
void print_list_con(list<string> &words);
void print_list_1b(string &try_word, list<string> &words);
void information(fstream &fout, list<string> words, string &word);