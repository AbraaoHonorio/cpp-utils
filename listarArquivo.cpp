#include <iostream>
#include <iostream>
#include <dirent.h>
#include <string>
#include <string.h>

void pegarDiretorio(std::string nomeDir){
    char *diretorio = NULL;
    DIR *dir = 0;
    struct dirent *entrada = 0;
    unsigned char isDir = 0x4;
    unsigned char isFile = 0x8;
    int tamanho;

    dir = opendir (nomeDir.c_str());

    if (dir == 0) {
        std::cerr << "Nao foi possivel abrir diretorio." << std::endl;
    }

    //Iterar sobre o diretorio
    while (entrada = readdir (dir)){
        //entrada->d_name
        diretorio =  new char[30];
        strcpy(diretorio, entrada->d_name);
        tamanho = strlen(diretorio);
        if((diretorio[tamanho-4]=='.')&&(diretorio[tamanho-3]=='t')&&(diretorio[tamanho-2]=='x')&&(diretorio[tamanho-1]=='t')){
           
		    std::cout<<entrada->d_name<<std::endl;
        }

    }

    closedir (dir);
}

int main(int argc, char** argv)
{
	pegarDiretorio("URL");
	return 0;
}