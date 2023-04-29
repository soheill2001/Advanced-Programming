# Online Quiz System

This is a command-line program for an online quiz system. It allows users to take a quiz with various question types, including single-answer multiple-choice questions, multiple-answer multiple-choice questions, and short-answer questions. The program reads the quiz questions and answers from a file provided as a command-line argument and outputs the final score after the user has completed the quiz.

## Input file format
The program expects the quiz questions and answers to be in a text file with the following format:

For single-answer multiple-choice questions:

+ The first line should be the question text
+ The second line should be the number of answer choices
+ The following lines should be the answer choices, with the correct answer indicated with an asterisk (*) at the beginning of the line

For multiple-answer multiple-choice questions:

+ The first line should be the question text
+ The second line should be the number of answer choices
+ The following lines should be the answer choices, with the correct answers indicated with an asterisk (*) at the beginning of the line

For short-answer questions:

+ The first line should be the question text
+ The second line should be the answer to the question