#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Iwa.h"
#include "Interpreter.h"
#include "ReadFile.h"
#include "ReadFileLines.h"
#include "Contains.h"
#include "PointerChecks.h"
#include "Replace.h"
#include "Structures.h"
#include "Dictionary.h"

void Parse_User_Arguments(int ArgumentsCount, char* Arguments[]){
    for (int Iteration = 1; Iteration < ArgumentsCount; Iteration++) {
        size_t ArgumentLength = strlen(Arguments[Iteration]) + 3;
        ArgumentBufferPointer = malloc(ArgumentLength * sizeof(char));
        String_Pointer_Check(ArgumentBufferPointer, "ArgumentBuffer");
        snprintf(ArgumentBufferPointer, ArgumentLength, "%s", Arguments[Iteration]);
        if (Iteration == 1){
            File_Name_Check(FileNamePointer, ArgumentBufferPointer, ArgumentLength, WorkingDirectoryLength);
        }
        free(ArgumentBufferPointer);
    }
}

int main(int ArgumentsCount, char* Arguments[]) {
    if (getcwd(WorkingDirectory, sizeof(WorkingDirectory)) == NULL) {
        perror("Failed to obtain current working directory.");
        return EXIT_FAILURE;
    }
    WorkingDirectoryLength = strlen(WorkingDirectory);

    Parse_User_Arguments(ArgumentsCount, Arguments);

    if (Contains(FileNamePointer, "\\")){
        FileNamePointer = Replace(FileNamePointer, "\\", "/");
        puts(FileNamePointer);
        FinalWorkingDirectory = Replace(WorkingDirectory, "\\", "/");
        size_t FinalFileNameLength = strlen(FinalWorkingDirectory) + strlen(FileNamePointer) + 2;
        char* FinalFileName = malloc(FinalFileNameLength + 1 * sizeof(char));
        strcpy(FinalFileName, FinalWorkingDirectory);
        strcat(FinalFileName, FileNamePointer);
        SourceCode = Parse_Source_Code(FinalFileName);
    } else {
        SourceCode = Parse_Source_Code(FileNamePointer);
    }

    for (int Iteration = 0; Iteration < SourceCode->ElementCount; Iteration++){
        printf("%s", SourceCode->List[Iteration]);
    }

    free(SourceCode);
    free(FileNamePointer);
    return 0;
}
