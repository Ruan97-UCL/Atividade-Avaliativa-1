//AtAv1-Questão 4-Programação Aplicada-Ruan Pardinho

#include <iostream>
#include <string>
#include <math.h> 
using namespace std;

//Função recursiva para para retornar a conversão até dar 1
int GetValorPosicao(int bit) {
    if (bit == 1) return 1;


    return pow(2, bit - 1);
}

//Função pra converter de Binário para decimal
int BinPraDec(string binario)
{
    int decimal = 0;

    for (size_t i = 0; i < binario.length(); i++)
    {
        if ((binario[i]) == '1') {
            decimal += GetValorPosicao(8 - i);
        }
    }

    return decimal;
}

//Função pra converter de decimal para Binário
string DecPraBin(int decimal)
{
    string binario = "";

    for (size_t i = 16; i >= 1; i--)
    {
        if (decimal / GetValorPosicao(i) == 1) {
            decimal -= GetValorPosicao(i);
            binario = binario + "1";
        }
        else
        {
            if (i > 8 && binario.length() == 0) continue;

            binario = binario + "0";
        }
    }

    return binario;
}

//Definindo as funções para fazer as operações solicitadas
int soma(int a, int b) {
    int soma;
    soma = a + b;
    return soma;
}

int sub(int a, int b) {
    int sub;
    sub = a - b;
    return sub;
}

int mult(int a, int b) {
    int mult;
    mult = a * b;
    return mult;
}

int divi(int a, int b) {
    int div;
    div = a / b;
    return div;
}

int resto(int a, int b) {
    int rest;
    rest = a % b;
    return rest;
}

int main() {

    //Definindo as variáveis do processo e solicitando a operação e o número em binário a ser utilizado
    int x;
    string n1, n2;
    int resultadoDec;
    string resultadoBin;
    string op;

  //incluindo o do-while para que se pessoa digitar valores não aceitáveis, emitir a mensagem
  do{

    cout << "Informe a operação desejada (+, -, *, /, %): " << endl;
    cin >> op;

      do{
        if((op!="+") && (op!="-") && (op!="*") && (op!="/") && (op!="%")){
          cout << "Caracter inválido!" << endl;
          cout << "Informe a operação desejada (+, -, *, /, %): "<< endl;
          cin >> op;
        }
     }

    while((op!="+") && (op!="-") && (op!="*") && (op!="/") && (op!="%"));

    cout << "Informe dois números binarios de 8 bits: " << endl;
    cin >> n1;
    cin >> n2;

    //Chamando as funções para fazer as operações 
    int decimal1 = BinPraDec(n1);
    int decimal2 = BinPraDec(n2);

    if (op == "+") {
        resultadoDec = soma(decimal1, decimal2);
        resultadoBin = DecPraBin(resultadoDec);
        cout << "O resultado da soma: "<< resultadoBin;
    }

    if(op == "-"){
      resultadoDec = sub(decimal1, decimal2); 
      resultadoBin = DecPraBin(resultadoDec);
      cout << "O resultado da subtração: " << resultadoBin;
    }

    if(op == "*"){
      resultadoDec = mult(decimal1, decimal2); 
      resultadoBin = DecPraBin(resultadoDec);
      cout << "O resultado da multiplicação: " << resultadoBin;
    }

    if(op == "/"){
      resultadoDec = divi(decimal1, decimal2); 
      resultadoBin = DecPraBin(resultadoDec);
      cout << "O resultado da divisão: " << resultadoBin;
    }

    if(op == "%"){
      resultadoDec = resto(decimal1, decimal2); 
      resultadoBin = DecPraBin(resultadoDec);
      cout << "O resultado do resto: " << resultadoBin;
    }

    //Verificando se a pessoa deseja fazer outra operação
    cout << endl;
    cout << "Deseja fazer outra operação? (Digite 0 pra SIM ou 1 pra NÃO)" << endl;
    cin >> x;

}while(x!=1);

}