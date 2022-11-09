# VPL07---CaixaEletronico

O arquivo main.cpp já estava pronto e não era para ser modificado. Porém, a função std::cin.ignore() dentro do for fazia com que as entradas a serem testadas não "entrarem" corretamente.

No arquivo intruso.hpp, foi criado um set de strings para armazenar as entradas (senhas) do programa.

A lógica utilizada no VPL foi a seguinte: é criada a primeira sequencia a partir de uma entrada, por exemplo, a entrada 1739085624BCEAEB possui a logica do caixa eletronico e a senha digitada pelo usuario. A logica do caixa eletronico é 1739085624 ; 17 corresponde a A, 39 corresponde a B, 08 corresponde a C, 56 corresponde a D e 24 a E. A partir da senha digitada pelo usuario, eu crio minha primeira sequencia que será : BCEAEB = 390824172439.
Outro exemplo, a entrada 9075846231ECCBDA vai gerar a sequencia 318484756290. Para gerar primeira sequencia é utilizado a seguinte parte do código:

std::vector<std::string>sequencias;
for(int i=0;i<letras.size();i++){
 if(letras[i]=='A') nova_associacao += associacao[0] + associacao[1];
 if(letras[i]=='B') nova_associacao += associacao[2] + associacao[3];
 if(letras[i]=='C') nova_associacao += associacao[4] + associacao[5];
 if(letras[i]=='D') nova_associacao += associacao[6] + associacao[7];
 if(letras[i]=='E') nova_associacao += associacao[8] + associacao[9];
 } 
}
sequencias.push_back(nova_associacao);

O vetor de strings vai armazenas as sequencias que foram criadas.


