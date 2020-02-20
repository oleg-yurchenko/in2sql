#include<stdio.h>
#include<unistd.h>

/* Input Specifications
    -n: name - the name of the table you are querying
    -v: number of values - the number of values the table has
    -t: types of values - s = string, i = integer, b = boolean, f = float
    command-line arguments: the names of each value, corresponding to the number of values, where the first letter is the type

    Eg.
    Table Name: myTable
    Values: (name, password, location, age)
    file with values: values.txt
    input: in2sql -n myTable -v 4 -t sssi name password location age values.txt

*/

int main(int argc, char *argv[]){
    char *tableName;
    char numValues;
    char *type;
    int opt;
    char *fileName;

    while((opt = getopt(argc, argv, "n:v:t:")) != -1){
        switch(opt){
            case 'n':
                tableName = optarg;
            case 'v':
                numValues = *optarg;
            case 't':
                type = optarg;
        }
    }
    numValues = numValues-'0';
    argc-=optind;
    argv+=optind;

    //Initialize Params to numValues
    char *params[numValues];

    //Declare the values
    for(size_t count = 0; count<numValues; count++){
        params[count] = argv[count];
    }

    //Get the filename to opena  file stream
    fileName = argv[argc-1];

    FILE *fileWithValues = fopen(fileName, "r");


    fclose(fileWithValues);
    return 1;
}