/*
Para el Archivo del ejercicio (a)
contar la cantidad de palabras que hay x línea, luego
mostrar la cantidad total y el promedio de palabras x línea.
*/

#include <iostream>     //permite usar funciones como cout
#include <fstream>      //flujo de archivos
#include <string>       //cadenas de caracteres
using namespace std;    // evitar usar el operador de ambito y std

void error(string message, string message2 = "")
{
    cerr << message << ' ' << message2 << endl;
    exit(EXIT_FAILURE);
}

ifstream openFile(string path)      //abrir archivo y verificar si hay error al abrir
{
    ifstream in;
    in.open(path);
    bool isCorruptFile = (!in.is_open() || !in.good());
    if (isCorruptFile) error("Error opening file");
    return in;
}

void closeFile(ifstream& file)          //cierra el archivo
{
    if (file.is_open()) file.close();
}

int countWords(string sentence)         //funcion para contar espacios
{
    int i = 0;
    int counter = 1;

    while (i < sentence.length())
    {
        if (sentence[i] == ' ' && isalpha(sentence[i]))
        {
            counter++;
        }
       if (isalpha(sentence[i])) i++;
    }
    return counter;
}

void showWordsOf(ifstream& file)        //contamos las palabras
{
    int sentecesNumber = 0;
    int totalWords = 0;

    while (!file.eof())
    {
        string sentence;
        getline(file, sentence);
        int wordsPerSentence = countWords(sentence);
        cout << "La frase número " << sentecesNumber + 1 << " tiene " << wordsPerSentence << " palabras" << endl;

        totalWords += wordsPerSentence; //totalWords = totalWords + wordsPerSentence;
        sentecesNumber++;
    }

    cout << "Cantidad total de palabras " << totalWords << endl;
    float averageOfWords = float(totalWords) / float(sentecesNumber);
    cout << "Promedio de palabras por línea " << averageOfWords << endl;
}

int main()      //llamamos a las funciones que utilizaremos
{
    /*
        IMPORTANTE PRESTAR ATENCIÓN AL PASO POR REFERENCIA
        EN LAS FUNCIONES showQuotesOf y closeFile
        NO SE PUEDE INCIALIZAR UN OBJETO ifstream CON OTRO
        Y LUEGO PASARLO POR VALOR PORQUE ifstream TIENE
        UN CONSTRUCTOR COPIA ELIMINADO, POR ESO NO SE PUEDE COPIAR
    */
    ifstream textFile = openFile("QuotesOfBjarne.txt");
    showWordsOf(textFile);
    closeFile(textFile);
    return 0;
}
