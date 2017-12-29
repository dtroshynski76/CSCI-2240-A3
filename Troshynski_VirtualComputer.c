/*
Name: Donovan Troshynski
Assignment #: 3
Due Date: 5 April 2016
Description: This program creates a "virtual computer" in which different commands can be read in and executed in the custom programming language. It includes memory manipulation and "compiling" code then executing it.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compile(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand, int *wordMemory);
int execute(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand, int *wordMemory);
void dump(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand, int *wordMemory);

int main(void)
{
    int accumulator = 0;
    int instructionCounter = 0;
    int instructionRegister = 0;
    int operationCode = 0;
    int operand = 0;
    int wordMemory[100] = {0};

    if(compile(&accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand, wordMemory) != 0)
    {
        return 1;
    }
    stdin = fopen("/dev/tty", "r");
    if(execute(&accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand, wordMemory) != 0)
        return 1;
    return 0;
}

int compile(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand, int *wordMemory)
{
    char word[10];
    memset(word, 0, 10);
    *operationCode = 0;

    *accumulator = scanf("%d %s %d", instructionCounter, word, operand);
    while(*accumulator != EOF)
    {
        if(*accumulator == 3)
        {
            /*READ*/
            if(strncmp(word, "READ", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 1000 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-READ*/

            /*WRIT*/
            else if(strncmp(word, "WRIT", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 1100 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-WRIT*/

            /*PRNT*/
            else if(strncmp(word, "PRNT", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 1200 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-PRNT*/

            /*LOAD*/
            else if(strncmp(word, "LOAD", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 2000 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-LOAD*/

            /*STOR*/
            else if(strncmp(word, "STOR", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 2100 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-STOR*/

            /*SET*/
            else if(strncmp(word, "SET", 5) == 0)
            {
                if( (*operand / 100) == 0 || (*operand / 100) == 10 || (*operand / 100) >= 65 || (*operand / 100) <= 90)
                {
                    wordMemory[*instructionCounter] = (*operand / 100) * 100;
                }
                else
                {
                    printf("Word Overflow\n");
                    return 1;
                }

                if((*operand % 100) == 0 || (*operand % 100) == 10 || (*operand % 100) >= 65 || (*operand % 100) <= 90)
                {
                    wordMemory[*instructionCounter] = wordMemory[*instructionCounter] + (*operand % 100);
                }
                else
                {
                    printf("Word Overflow\n");
                    return 1;
                }
            }

            /*ADD*/
            else if(strncmp(word, "ADD", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 3000 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-ADD*/

            /*SUB*/
            else if(strncmp(word, "SUB", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 3100 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-SUB*/

            /*DIV*/
            else if(strncmp(word, "DIV", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 3200 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-DIV*/

            /*MULT*/
            else if(strncmp(word, "MULT", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 3300 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-MULT*/

            /*MOD*/
            else if(strncmp(word, "MOD", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 3400 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-MOD*/

            /*BRAN*/
            else if(strncmp(word, "BRAN", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 4000 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-BRAN*/

            /*BRNG*/
            else if(strncmp(word, "BRNG", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 4100 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-BRNG*/

            /*BRZR*/
            else if(strncmp(word, "BRZR", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 4200 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
            }/*end if-BRZR*/

            /*HALT*/
            else if(strncmp(word, "HALT", 5) == 0)
            {
                if(*operand > 99)
                {
                    printf("Word Overflow\n");
                    return 1;
                }
                *instructionRegister = 9900 + *operand;
                wordMemory[*instructionCounter] = *instructionRegister;
                *operationCode = 1;
            }/*end if-HALT*/

            /*unknown command word*/
            else
            {
                printf("Unknown command word\n");
                return 1;
            }
        }
        else
            return 1;

        memset(word, 0, 10);
        *accumulator = scanf("%d %s %d", instructionCounter, word, operand);
    }/*end while*/

    if(*operationCode != 1)
    {
        printf("No HALT error\n");
        return 1;
    }

    *operationCode = 0;
    *instructionCounter = 0;
    return 0;
}

int execute(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand, int *wordMemory)
{
    /*check valid range of instructionCounter*/
    if((*instructionCounter > 99) || (*instructionCounter < 0))
    {
        printf("Segmentation faulst\n");
        dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
        return 1;
    }
    *instructionCounter = 0;

    while(*instructionCounter <= 99)
    {
        *instructionRegister = wordMemory[*instructionCounter];
        *operationCode = *instructionRegister / 100;
        *operand = *instructionRegister % 100;
        if((*operand > 99) || (*operand < 0))
        {
            printf("Segmentation fault\n");
            dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
            return 1;
        }

        /*READ operation*/
        if(*operationCode == 10)
        {
            scanf("%d", accumulator);
            if((*accumulator < -9999) || (*accumulator > 9999))
            {
                printf("Word overflow\n");
                dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
                return 1;
            }
            wordMemory[*operand] = *accumulator;
        }

        /*WRIT operation*/
        else if(*operationCode == 11)
        {
            printf("%d\n", wordMemory[*operand]);
        }

        /*PRNT operation*/
        else if(*operationCode == 12)
        {
            while(*operationCode != 0)
            {
                *operationCode = wordMemory[*operand] / 100;

                /*Unknown character error*/
                if((*operationCode != 0 && *operationCode != 10) && (*operationCode < 65 || *operationCode > 90))
                {
                    printf("Unknown character\n");
                    dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
                    return 1;
                }

                if((*operationCode != 0) && (*operationCode != 10))
                    printf("%c", *operationCode);
                else if(*operationCode == 10)
                    printf("\n");

                *operationCode = wordMemory[*operand] % 100;

                /*Unknown character error*/
                if((*operationCode != 0 && *operationCode != 10) && (*operationCode < 65 || *operationCode > 90))
                {
                    printf("Unknown character\n");
                    dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
                    return 1;
                }

                if((*operationCode != 0) && (*operationCode != 10))
                    printf("%c", *operationCode);
                else if(*operationCode == 10)
                    printf("\n");

                *operand = *operand + 1;
            }
        }

        /*LOAD operation*/
        else if(*operationCode == 20)
        {
            *accumulator = wordMemory[*operand];
        }

        /*STOR operation*/
        else if(*operationCode == 21)
        {
            wordMemory[*operand] = *accumulator;
        }

        /*SET operation already completed at compilation time*/

        /*ADD operation*/
        else if(*operationCode == 30)
        {
            *accumulator = *accumulator + wordMemory[*operand];
            if((*accumulator < -9999) || (*accumulator > 9999))
            {
                printf("Word overflow\n");
                dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
                return 1;
            }
        }

        /*SUB operation*/
        else if(*operationCode == 31)
        {
            *accumulator = *accumulator - wordMemory[*operand];
            if((*accumulator < -9999) || (*accumulator > 9999))
            {
                printf("Word overflow\n");
                dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
                return 1;
            }
        }

        /*DIV operation*/
        else if(*operationCode == 32)
        {
            if(wordMemory[*operand] == 0)
            {
                printf("Division by 0 attempted\n");
                dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
                return 1;
            }
            *accumulator = *accumulator / wordMemory[*operand];
            if((*accumulator < -9999) || (*accumulator > 9999))
            {
                printf("Word overflow\n");
                dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
                return 1;
            }
        }

        /*MULT operation*/
        else if(*operationCode == 33)
        {
            *accumulator = *accumulator * wordMemory[*operand];
            if((*accumulator < -9999) || (*accumulator > 9999))
            {
                printf("Word overflow\n");
                dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
                return 1;
            }
        }

        /*MOD operation*/
        else if(*operationCode == 34)
        {
            *accumulator = *accumulator % wordMemory[*operand];
            if((*accumulator < -9999) || (*accumulator > 9999))
            {
                printf("Word overflow\n");
                dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
                return 1;
            }
        }

        /*BRAN operation*/
        else if(*operationCode == 40)
        {
            *instructionCounter = *operand - 1;
        }

        /*BRNG operation*/
        else if(*operationCode == 41)
        {
            if(*accumulator < 0)
                *instructionCounter = *operand - 1;
        }

        /*BRZR operation*/
        else if(*operationCode == 42)
        {
            if(*accumulator == 0)
                *instructionCounter = *operand - 1;
        }

        /*HALT operation*/
        else if(*operationCode == 99)
        {
            dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
            return 0;
        }

        else if(*operationCode == 0){}
        
        /*unknown command*/
        else
        {
            printf("Unknown Command\n");
            dump(accumulator, instructionCounter, instructionRegister, operationCode, operand, wordMemory);
            return 1;
        }
        *instructionCounter = *instructionCounter + 1;
    }/*end while*/
    return 0;
}

void dump(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand, int *wordMemory)
{
    printf("REGISTERS:\n%-25s", "accumulator");
    if(*accumulator >= 0)
        printf("+%04d\n", *accumulator);
    else if(*accumulator < 0)
        printf("-%04d\n", abs(*accumulator));
    printf("%-28s%02d\n", "instructionCounter", *instructionCounter);
    if(*instructionRegister >= 0)
        printf("%-25s+%04d\n", "instructionRegister", *instructionRegister);
    else
        printf("%-25s-%04d\n", "instructionRegister", abs(*instructionRegister));
    printf("%-28s%02d\n", "operationCode", *operationCode);
    printf("%-28s%02d\n", "operand", *operand);
    printf("MEMORY:\n");
    printf("%8d%6d%6d%6d%6d%6d%6d%6d%6d%6d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

    for(*accumulator = 0; *accumulator < 10; *accumulator = *accumulator + 1)
    {
        printf("%2d", *accumulator * 10);
        for(*operand = 0; *operand < 10; *operand = *operand + 1)
        {
            printf("%s", " ");
            if(wordMemory[(*accumulator * 10) + *operand] < 0)
                printf("-%04d", abs(wordMemory[(*accumulator * 10) + *operand]));
            else
                printf("+%04d", wordMemory[(*accumulator * 10) + *operand]);
        }
        printf("\n");
    }
}
