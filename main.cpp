#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <windows.h>
#include<conio.h>



using namespace std;



//Definição do significado de cada numero

#define chao 0

#define parede 1

#define voce 2

#define saida 3

#define paredeV 4

#define cantoSupDir 5

#define cantoSupEsq 6

#define cantoInfDir 7

#define cantoInfEsq 8

#define tEsq 9

#define tDir 10

#define tCima 11

#define tBaixo 12



int coluna_atual = 1,

linha_atual = 1,

coluna_atual2 = 1,

linha_atual2 = 1;

char tecla;

int mapa[26][34];

int tamanhoLinhaMapa=0, tamanhoColunaMapa=0;

ifstream inputStream;

ofstream outputStream;



//Declaração do mapa

int EscolherMapa(int dificuldade){

    switch(dificuldade){

        case(1):{

            int mapaF[10][15] = {

            6 ,1,1,1,1,12,1,1 ,1,12,1 ,1,1,1,5,

            4 ,2,0,0,0,4 ,0,0 ,0,4 ,0 ,0,0,0,4,

            4 ,0,4,0,6,7 ,0,0 ,0,4 ,0 ,6,1,0,4,

            4 ,0,4,0,0,0 ,0,12,0,8 ,1 ,7,0,0,4,

            10,1,7,0,4,0 ,0,4 ,0,0 ,0 ,0,0,0,4,

            4 ,0,0,0,4,0 ,0,8 ,1,1 ,12,1,9,0,9,

            4 ,0,1,1,7,0 ,0,0 ,0,0 ,4 ,0,0,0,4,

            4 ,0,0,0,0,0 ,1,12,1,0 ,4 ,0,0,0,4,

            4 ,0,0,0,0,0 ,0,4 ,3,0 ,4 ,0,0,0,4,

            8 ,1,1,1,1,1 ,1,11,1,1 ,11,1,1,1,7,

            };

        for(int i=0; i<10; i++){

            for(int j=0; j<15; j++){

                mapa[i][j] = mapaF[i][j];

            }

        }

        tamanhoLinhaMapa = 10;

        tamanhoColunaMapa = 15;

        break;}

        case(2):{

                int mapaN[15][20] = {

                6 ,1,1,12,1,1,1 ,1,1 ,1,1,1 ,1,1,1,1 ,1,1 ,1 ,5,

                4 ,2,0,4 ,0,0,0 ,0,0 ,0,0,0 ,0,0,0,0 ,0,0 ,0 ,4,

                4 ,0,0,4 ,0,0,0 ,0,4 ,0,0,0 ,0,0,0,0 ,0,0 ,0 ,4,

                4 ,0,0,10,1,1,1 ,1,9 ,0,0,0 ,6,1,1,12,1,1 ,12,9,

                4 ,0,0,4 ,0,0,0 ,0,4 ,0,0,0 ,4,0,0,4 ,0,0 ,4 ,4,

                4 ,0,0,4 ,0,0,0 ,0,0 ,0,0,0 ,4,0,0,4 ,0,0 ,4 ,4,

                4 ,0,0,8 ,1,1,1 ,1,1 ,0,0,0 ,4,0,0,4 ,0,0 ,4 ,9,

                4 ,0,0,0 ,0,0,0 ,0,0 ,0,0,0 ,4,0,0,4 ,0,0 ,4 ,4,

                4 ,0,0,6 ,1,1,1 ,1,5 ,0,0,6 ,7,0,0,10,0,1 ,11,4,

                4 ,0,0,4 ,0,0,0 ,0,4 ,0,0,4 ,0,0,0,4 ,0,0 ,0 ,4,

                4 ,0,0,4 ,0,0,0 ,0,4 ,0,0,10,1,1,0,4 ,0,0 ,0 ,4,

                4 ,0,0,8 ,1,1,1 ,0,4 ,0,0,4 ,0,0,0,4 ,0,0 ,0 ,4,

                4 ,0,0,0 ,0,0,0 ,0,4 ,0,0,0 ,0,0,0,0 ,0,0 ,0 ,4,

                8 ,1,1,11,1,1,11,1,1 ,1,1,1 ,1,1,1,1 ,1,1 ,1 ,7,

                };

            for(int i=0; i<15; i++){

                for(int j=0; j<20; j++){

                    mapa[i][j] = mapaN[i][j];

                }

            }

            tamanhoLinhaMapa = 15;

            tamanhoColunaMapa = 20;

            break;}

        case(3):{

            int mapaD[26][34] = {

            6 ,1,1,12,1,1,1 ,1,1 ,1,1,1 ,1,1,1,1 ,1,1 ,1 ,1,12,1,1 ,1,1,1 ,1,1,1 ,1,1,1,1,5,

            4 ,2,0,4 ,0,0,0 ,0,0 ,0,0,0 ,0,0,0,0 ,0,0 ,0 ,0,4 ,0,0 ,0,0,0 ,0,0,0 ,0,0,0,0,4,

            4 ,0,0,4 ,0,0,0 ,0,4 ,0,0,0 ,0,0,0,0 ,0,0 ,0 ,0,4 ,0,0 ,0,0,0 ,0,0,4 ,0,0,0,0,4,

            4 ,0,0,10,1,1,1 ,1,9 ,0,0,0 ,6,1,1,12,1,1 ,12,1,11,1,12,1,1,0 ,0,0,10,1,1,1,1,9,

            4 ,0,0,4 ,0,0,0 ,0,4 ,0,0,0 ,4,0,0,4 ,0,0 ,4 ,0,0 ,0,0 ,0,0,0 ,0,0,0 ,0,0,0,0,4,

            4 ,0,0,4 ,0,0,0 ,0,0 ,0,0,0 ,4,0,0,4 ,0,0 ,4 ,0,0 ,0,4 ,0,0,0 ,0,0,4 ,0,0,0,0,4,

            4 ,0,0,8 ,1,1,1 ,1,1 ,0,0,0 ,4,0,0,4 ,0,0 ,4 ,0,0 ,0,4 ,0,0,0 ,0,0,8 ,1,1,1,1,9,

            4 ,0,0,0 ,0,0,0 ,0,0 ,0,0,0 ,4,0,0,4 ,0,0 ,4 ,0,0 ,0,4 ,0,0,0 ,0,0,0 ,0,0,0,0,4,

            4 ,0,0,6 ,1,1,1 ,1,5 ,0,0,6 ,7,0,0,10,0,1 ,11,1,0 ,1,9 ,0,0,0 ,0,0,0 ,0,0,0,0,4,

            4 ,0,0,4 ,0,0,0 ,0,4 ,0,0,4 ,0,0,0,4 ,0,0 ,0 ,0,0 ,0,10,1,1,1 ,1,1,1 ,5,0,0,0,4,

            4 ,0,0,4 ,0,0,0 ,0,4 ,0,0,10,1,1,0,4 ,0,0 ,0 ,0,0 ,0,4 ,0,0,0 ,0,0,0 ,4,0,0,0,4,

            4 ,0,0,8 ,1,1,1 ,0,4 ,0,0,4 ,0,0,0,4 ,0,0 ,0 ,0,0 ,0,0 ,0,0,0 ,0,0,0 ,4,0,0,0,4,

            4 ,0,0,0 ,0,0,0 ,0,4 ,0,0,0 ,0,0,0,0 ,0,0 ,0 ,0,0 ,0,0 ,0,0,0 ,0,0,0 ,4,0,0,0,4,

            10,1,1,5 ,0,0,4 ,0,8 ,1,1,1 ,1,1,1,12,1,1 ,1 ,5,0 ,0,6 ,1,1,1 ,1,1,1 ,7,0,0,0,4,

            4 ,0,0,4 ,0,0,4 ,0,0 ,0,0,0 ,0,0,0,4 ,0,0 ,0 ,4,0 ,0,4 ,0,0,0 ,0,0,0 ,0,0,0,0,4,

            4 ,0,0,4 ,0,0,4 ,0,6 ,1,1,1 ,1,1,0,4 ,0,0 ,0 ,4,0 ,0,4 ,0,0,1 ,1,1,1 ,1,1,1,1,9,

            4 ,0,0,0 ,0,0,4 ,0,4 ,0,0,0 ,0,0,0,4 ,0,0 ,0 ,4,0 ,0,4 ,0,0,0 ,0,0,0 ,0,0,0,0,4,

            10,1,1,5 ,0,0,4 ,0,10,1,1,1 ,1,1,1,7 ,0,0 ,0 ,4,0 ,0,4 ,0,0,0 ,0,0,0 ,0,0,0,3,4,

            4 ,0,0,4 ,0,0,4 ,0,4 ,0,0,0 ,0,0,0,0 ,0,0 ,0 ,4,0 ,0,10,1,1,12,1,1,1 ,1,1,1,1,9,

            4 ,0,0,4 ,0,0,4 ,0,4 ,0,0,0 ,0,4,0,0 ,0,0 ,0 ,4,0 ,0,4 ,0,0,4 ,0,0,0 ,0,0,0,0,4,

            4 ,0,0,4 ,0,0,4 ,0,10,1,1,1 ,1,9,0,0 ,0,0 ,0 ,4,0 ,0,4 ,0,0,4 ,0,0,0 ,0,0,0,0,4,

            4 ,0,0,4 ,0,0,4 ,0,4 ,0,0,0 ,0,4,0,0 ,0,0 ,0 ,4,0 ,0,4 ,0,0,0 ,0,0,0 ,0,0,0,0,4,

            4 ,0,0,4 ,0,0,4 ,0,4 ,0,0,0 ,0,0,0,0 ,0,0 ,0 ,4,0 ,0,4 ,0,0,0 ,0,0,0 ,0,0,0,0,4,

            4 ,0,0,0 ,0,0,4 ,0,8 ,1,1,1 ,1,1,1,1 ,0,0 ,0 ,8,1 ,1,7 ,0,0,1 ,1,1,1 ,1,1,1,1,9,

            4 ,0,0,4 ,0,0,4 ,0,0 ,0,0,0 ,0,0,0,0 ,0,0 ,0 ,0,0 ,0,0 ,0,0,0 ,0,0,0 ,0,0,0,0,4,

            8 ,1,1,11,1,1,11,1,1 ,1,1,1 ,1,1,1,1 ,1,1 ,1 ,1,1 ,1,1 ,1,1,1 ,1,1,1 ,1,1,1,1,7,

            };

            for(int i=0; i<26; i++){

                for(int j=0; j<34; j++){

                    mapa[i][j] = mapaD[i][j];

                }

            }

            tamanhoLinhaMapa = 26;

            tamanhoColunaMapa = 34;

            break;}

    }

}



//Declaração das funções do jogo, Desenhar Mapa, Instruções e checar colisão com paredes (W,A,S,D = teclas de movimento)

int DesenharMapa(){

    int linha, coluna;

    for(linha=0;linha<tamanhoLinhaMapa;linha++){

        for(coluna=0;coluna<tamanhoColunaMapa;coluna++){

            if(mapa[linha][coluna] == chao){

                cout << " ";

            }

            if(mapa[linha][coluna] == parede){

                //cout << "*";

                cout << "─";

            }

            if(mapa[linha][coluna] == paredeV){

                //cout << "*";

                cout << "│";

            }

            if(mapa[linha][coluna] == cantoSupDir){

                //cout << "*";

                cout << "┐";

            }

            if(mapa[linha][coluna] == cantoSupEsq){

                //cout << "*";

                cout << "┌";

            }

            if(mapa[linha][coluna] == cantoInfDir){

                //cout << "*";

                cout << "┘";

            }

            if(mapa[linha][coluna] == cantoInfEsq){

                //cout << "*";

                cout << "└";

            }

            if(mapa[linha][coluna] == tDir){

                //cout << "*";

                cout << "├";

            }

            if(mapa[linha][coluna] == tEsq){

                //cout << "*";

                cout << "┤";

            }

            if(mapa[linha][coluna] == tCima){

                //cout << "*";

                cout << "┴";

            }

            if(mapa[linha][coluna] == tBaixo){

                //cout << "*";

                cout << "┬";

            }

            if((linha == linha_atual) && (coluna == coluna_atual)){

                //cout << "o";

                cout << "●";

                continue;

            }

            if(mapa[linha][coluna] == saida){

               //cout << "#";

               cout << "⌂";

                continue;

            }

        }

        cout << "\n";

    }

}

void Instrucoes(){

    cout << "Controles.\nW - Cima\nS - Baixo\nA - Esquerda\nD - Direita\n";

}

void ChecarParedeW(){

        switch(mapa[linha_atual][coluna_atual]){

            case(parede):

                linha_atual +=1;

                break;

            case(paredeV):

                linha_atual +=1;

                break;

            case(cantoSupDir):

                linha_atual +=1;

                break;

            case(cantoSupEsq):

                linha_atual +=1;

                break;

            case(cantoInfDir):

                linha_atual +=1;

                break;

            case(cantoInfEsq):

                linha_atual +=1;

                break;

            case(tCima):

                linha_atual +=1;

               break;

            case(tBaixo):

                linha_atual +=1;

               break;

            case(tEsq):

                linha_atual +=1;

                break;

            case(tDir):

                linha_atual +=1;

                break;

        }

}

void ChecarParedeA(){

        switch(mapa[linha_atual][coluna_atual]){

           case(parede):

                coluna_atual +=1;

                break;

            case(paredeV):

                coluna_atual +=1;

                break;

            case(cantoSupDir):

                coluna_atual +=1;

                break;

            case(cantoSupEsq):

                coluna_atual +=1;

                break;

            case(cantoInfDir):

                coluna_atual +=1;

                break;

            case(cantoInfEsq):

                coluna_atual +=1;

                break;

            case(tCima):

                coluna_atual +=1;

                break;

            case(tBaixo):

                coluna_atual +=1;

                break;

            case(tEsq):

                coluna_atual +=1;

                break;

            case(tDir):

                coluna_atual +=1;

                break;

        }

}

void ChecarParedeS(){

        switch(mapa[linha_atual][coluna_atual]){

            case(parede):

                linha_atual -=1;

                break;

            case(paredeV):

                linha_atual -=1;

                break;

            case(cantoSupDir):

                linha_atual -=1;

                break;

            case(cantoSupEsq):

                linha_atual -=1;

                break;

            case(cantoInfDir):

                linha_atual -=1;

                break;

            case(cantoInfEsq):

                linha_atual -=1;

                break;

            case(tCima):

                linha_atual -=1;

                break;

            case(tBaixo):

                linha_atual -=1;

                break;

            case(tEsq):

                linha_atual -=1;

                break;

            case(tDir):

                linha_atual -=1;

                break;

        }

}

void ChecarParedeD(){

        switch(mapa[linha_atual][coluna_atual]){

            case(parede):

                coluna_atual -=1;

                break;

            case(paredeV):

                coluna_atual -=1;

                break;

            case(cantoSupDir):

                coluna_atual -=1;

                break;

            case(cantoSupEsq):

                coluna_atual -=1;

                break;

            case(cantoInfDir):

                coluna_atual -=1;

                break;

            case(cantoInfEsq):

                coluna_atual -=1;

                break;

            case(tCima):

                coluna_atual -=1;

                break;

            case(tBaixo):

                coluna_atual -=1;

                break;

            case(tEsq):

                coluna_atual -=1;

                break;

            case(tDir):

                coluna_atual -=1;

                break;

        }

}

void MostrarPlacarLideres(){

    string player[30], dificuldade[30], nome;

    int movimentos[30], x;

    inputStream.open("PlacarLideres.txt");

    for(int i=0; i<30; i++){

        inputStream >> movimentos[i];

        inputStream >> player[i];

        inputStream >> dificuldade[i];

        if(player[i] == ""){break;}

    }

    for(int i=0; i<30; i++){

        if (dificuldade[i] == "Facil"){

            for(int j=0; j<30; j++){

                for(int k=j+1; k<30; k++){

                    if(movimentos[j] > movimentos[k]){

                            x=movimentos[j];

                            movimentos[j]=movimentos[k];

                            movimentos[k]=x;

                            nome=player[j];

                            player[j]=player[k];

                            player[k]=nome;

                    }

                }

            }

        }else{continue;}

        if (dificuldade[i] == "Normal"){

            for(int j=0; j<30; j++){

                for(int k=j+1; k<30; k++){

                    if(movimentos[j] > movimentos[k]){

                            x=movimentos[j];

                            movimentos[j]=movimentos[k];

                            movimentos[k]=x;

                            nome=player[j];

                            player[j]=player[k];

                            player[k]=nome;

                    }

                }

            }

        }else{continue;}

        if (dificuldade[i] == "Dificil"){

            for(int j=0; j<30; j++){

                for(int k=j+1; k<30; k++){

                    if(movimentos[j] > movimentos[k]){

                            x=movimentos[j];

                            movimentos[j]=movimentos[k];

                            movimentos[k]=x;

                            nome=player[j];

                            player[j]=player[k];

                            player[k]=nome;

                    }

                }

            }

        }else{continue;}

    }

    for(int i=0; i<30; i++){

        if(player[i] == ""){continue;}else{

            cout << "\nPlayer: " << player[i] << "\nMovimentos: " << movimentos[i] << "\nDificuldade: " << dificuldade[i] << endl;}

    }

    inputStream.close();

}



int main(){

    //Ativa as paredes do mapa

    SetConsoleOutputCP(CP_UTF8);



    int numeroDificuldade, movimentos=0;

    int opcao;

    string player, dificuldade;

    char resposta;



    cout << "\nOlá, seja bem vindo.\n";

    cout << "\nInforme o seu username: ";

    cin >> player;

    cout << "\nPor Favor, escolha a dificuldade desejada\n1 - Fácil\n2 - Normal\n3 - Difícil\nEscolha o número da dificuldade e pressione enter: ";

    cin >> numeroDificuldade;



    if(numeroDificuldade == 1){dificuldade = "Facil";}else if(numeroDificuldade == 2){dificuldade == "Normal";}else if(numeroDificuldade == 3){dificuldade == "Dificil";}

    EscolherMapa(numeroDificuldade);

    system("cls");

    //system("clear");

    DesenharMapa();

    Instrucoes();



    do{
        //cin >> tecla;
        tecla = getch();

        if(tecla == 'w' or tecla == 'W'){

            mapa[linha_atual][coluna_atual] = 0;

            linha_atual -= 1;

            if(mapa[linha_atual][coluna_atual] == saida){break;}

            ChecarParedeW();

            mapa[linha_atual][coluna_atual] = 2;

            system("cls");

            //system("clear");

            DesenharMapa();

            Instrucoes();

        }

        if(tecla == 's' or tecla == 'S'){

            mapa[linha_atual][coluna_atual] = 0;

            linha_atual += 1;

            if(mapa[linha_atual][coluna_atual] == saida){break;}

            ChecarParedeS();

            mapa[linha_atual][coluna_atual] = 2;

            system("cls");

            //system("clear");

            DesenharMapa();

            Instrucoes();

        }

        if(tecla == 'a' or tecla == 'A'){

            mapa[linha_atual][coluna_atual] = 0;

            coluna_atual -= 1;

            if(mapa[linha_atual][coluna_atual] == saida){break;}

            ChecarParedeA();

            mapa[linha_atual][coluna_atual] = 2;

            system("cls");

            //system("clear");

            DesenharMapa();

            Instrucoes();

        }

        if(tecla == 'd' or tecla == 'D'){

            mapa[linha_atual][coluna_atual] = 0;

            coluna_atual += 1;

            if(mapa[linha_atual][coluna_atual] == saida){break;}

            ChecarParedeD();

            mapa[linha_atual][coluna_atual] = 2;

            system("cls");

            //system("clear");

            DesenharMapa();

            Instrucoes();

        }

        movimentos++;

    }

    while (mapa[linha_atual][coluna_atual] != saida);

    system("cls");

    //system("clear");

    DesenharMapa();

    cout << "\nParabéns " << player <<"! Você Venceu!!" << "\nTotal de movimentos: " << movimentos;

    cout << "\nDeseja ver o Placar de Líderes (s/n)? ";

    cin >> resposta;



    //Escreve o Username, dificuldade e total de movimentos no placar de lideres

    outputStream.open("PlacarLideres.txt", ios::app);

    outputStream << "\n" << movimentos << " " << player << " " << dificuldade;

    outputStream.close();

    if(resposta == 'S' || resposta == 's'){system("cls");MostrarPlacarLideres();}

return 0;

}
