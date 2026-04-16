[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Vx057JAP)
# Project 1: Compute word frequencies in a file

You are given a file, named holmes.txt, in the GitHub repository. This file is from a paragraph of a famous Sherlock Holmes book, "A Scandal in Bohemia".

You will write a C++ code to count the frequency of the words used in the file. You should use C++ vectors to solve this problem. Make the code divided into functions to make it modular. 

Suggested functions are:

void getWords(vector<string> &words, ifstream &file) - words -> a vector of strings representing the words in the file, file -> is a reference to the ifstream object (the File).
void sortWords(vector<string> &words) - This will sort the words collected in the getWords function.
vector<pair<string, int>> getWordCounts(vector<string> &words) - this will calculate the word frequencies for each of the words.

